#include <update.h>
#include <insert.h>
#include <select.h>
#include <gtest/gtest.h>
#include "sql.h"

using namespace dbhelper;

TEST(TestDBHelper_, InsertAndUpdateAndSelect)
{
    Value v;
    v("first_name", "Vasiliy")("last_name", "Mamaev")("age", 24)("city", "Tver")
            ("post", "programmer")("salary", 67100.20);
    Insert i(SQL::getDatabase(), "employee", v);
    EXPECT_TRUE(i.prepare());
    EXPECT_TRUE(i.exec());

    Value v2;
    v2("post", "admin")("salary", 53120.00);

    Where w;
    w << "first_name = 'Vasiliy' AND last_name = 'Mamaev'";

    Update u(SQL::getDatabase(), "employee", v2);
    u.addWhere(w);
    EXPECT_TRUE(u.prepare());
    EXPECT_TRUE(u.exec());

    ColumnList list;
    list << "post" << "salary";

    From f;
    f << "employee";

    Select s(SQL::getDatabase(), list, f);
    s.addWhere(w);
    EXPECT_TRUE(s.prepare());
    EXPECT_TRUE(s.exec());
    EXPECT_EQ(s.size(), 1);
    EXPECT_TRUE(s.next());
    EXPECT_EQ(s.value(0).toString(), "admin");
    EXPECT_EQ(s.value(1).toDouble(), 53120.00);
}
