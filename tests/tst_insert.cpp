#include <insert.h>
#include <select.h>
#include <gtest/gtest.h>
#include "sql.h"

using namespace dbhelper;

TEST(TestDBHelper_, Insert)
{
    Value v;
    v("first_name", "Maxim")("last_name", "Tatarov")("age", 40)("city", "Kiev")
            ("post", "designer")("salary", 56500.00);
    Insert i(SQL::getDatabase(), "employee", v);
    EXPECT_TRUE(i.prepare());
    EXPECT_TRUE(i.exec());
}


TEST(TestDBHelper_, InsertAndSelect)
{
    Value v;
    v("first_name", "Andrey")("last_name", "Gubov")("age", 33)("city", "Kiev")
            ("post", "admin")("salary", 76500.00);
    Insert i(SQL::getDatabase(), "employee", v);
    EXPECT_TRUE(i.prepare());
    EXPECT_TRUE(i.exec());

    // check inserted data
    ColumnList list;
    list << "first_name" << "last_name" << "age" << "city" << "post" << "salary";

    From f;
    f << "employee";

    Where w;
    w << "first_name = 'Andrey' AND age = " << 33;

    Select s(SQL::getDatabase(), list, f);
    s.addWhere(w);
    EXPECT_TRUE(s.prepare());
    EXPECT_TRUE(s.exec());
    EXPECT_EQ(s.size(), 1);
    EXPECT_TRUE(s.next());
    EXPECT_EQ(s.value(0).toString(), "Andrey");
    EXPECT_EQ(s.value(1).toString(), "Gubov");
    EXPECT_EQ(s.value(2).toInt(), 33);
    EXPECT_EQ(s.value(3).toString(), "Kiev");
    EXPECT_EQ(s.value(4).toString(), "admin");
    EXPECT_EQ(s.value(5).toDouble(), 76500.00);
}
