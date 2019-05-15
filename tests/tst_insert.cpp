#include <insert.h>
#include <select.h>
#include <querytype.h>
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

TEST(TestDBHelper_, InsertWithTimestampAndSelect)
{
    QDateTime dt = QDateTime::fromString("2010-04-17 16:30", "yyyy-MM-dd hh:mm");

    Value v;
    v("first_name", "Anton")("last_name", "Rublev")("age", 41)("city", "Moscow")
            ("post", "programmer")("salary", 156700.00)("date_created", Timestamp(dt));
    Insert i(SQL::getDatabase(), "employee", v);
    EXPECT_TRUE(i.prepare());
    EXPECT_TRUE(i.exec());

    // check inserted data
    ColumnList list;
    list << "first_name" << "last_name" << "age" << "city" << "post" << "salary" << "date_created";

    From f;
    f << "employee";

    // set datetime format
    DateFormat::setDateTimeFormat("yyyy-MM-dd hh:mm");

    Where w;
    w << "date_created = " << dt << "";

    Select s(SQL::getDatabase(), list, f);
    s.addWhere(w);
    EXPECT_TRUE(s.prepare());
    EXPECT_TRUE(s.exec());
    EXPECT_EQ(s.size(), 1);
    EXPECT_TRUE(s.next());
    EXPECT_EQ(s.value(0).toString(), "Anton");
    EXPECT_EQ(s.value(1).toString(), "Rublev");
    EXPECT_EQ(s.value(2).toInt(), 41);
    EXPECT_EQ(s.value(3).toString(), "Moscow");
    EXPECT_EQ(s.value(4).toString(), "programmer");
    EXPECT_EQ(s.value(5).toDouble(), 156700.00);
    EXPECT_EQ(s.value(6).toDateTime(), dt);
}
