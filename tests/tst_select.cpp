#include <select.h>
#include <gtest/gtest.h>
#include "sql.h"

using namespace dbhelper;

TEST(TestDBHelper_, Select)
{
    ColumnList list;
    list << "id" << "first_name" << "last_name" << "age" << "city" << "post"
         << "salary" << "date_created";

    From f;
    f << "employee";

    Select s(SQL::getDatabase(), list, f);
    EXPECT_TRUE(s.prepare());
    EXPECT_TRUE(s.exec());
    for (int i = 0; i < s.size(); ++i) {
        EXPECT_TRUE(s.next());
    }
}

TEST(TestDBHelper_, SelectWithWhere)
{
    ColumnList list;
    list << "id" << "first_name" << "last_name" << "age" << "city" << "post"
         << "salary" << "date_created";

    From f;
    f << "employee";

    Where w;
    w << "age < " << 35;

    Select s(SQL::getDatabase(), list, f);
    s.addWhere(w);
    s.orderBy("id");
    EXPECT_TRUE(s.prepare());
    EXPECT_TRUE(s.exec());
    for (int i = 0; i < s.size(); ++i) {
        EXPECT_TRUE(s.next());
    }
}

TEST(TestDBHelper_, SelectJoinAndLimit)
{
    ColumnList list;
    list << "first_name" << "last_name" << "age" << "city" << "post"
         << "salary" << "date_created" << "has";

    From f;
    f << "employee JOIN has_privileges ON employee.id = has_privileges.id_emp";

    Select s(SQL::getDatabase(), list, f);
    s.limit(3);
    EXPECT_TRUE(s.prepare());
    EXPECT_TRUE(s.exec());
    EXPECT_EQ(s.size(), 3);
}
