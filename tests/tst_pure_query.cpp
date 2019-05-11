#include <purequery.h>
#include <gtest/gtest.h>
#include "sql.h"

using namespace dbhelper;

TEST(TestDBHelper_, PureQuery)
{
    PureQuery q(SQL::getDatabase(),
                "SELECT COUNT(id), AVG(salary) FROM employee");
    EXPECT_TRUE(q.prepare());
    EXPECT_TRUE(q.exec());
    EXPECT_TRUE(q.next());
    EXPECT_TRUE(q.size() == 1);
}
