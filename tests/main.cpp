#include "sql.h"
NO_MULTIPLE_STATIC_SQL_DB

#include <gtest/gtest.h>
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    ::testing::GTEST_FLAG(filter) = "InitTests*";
    if (RUN_ALL_TESTS() != 0) {
        cerr << "Failed init tests!" << endl;
        return 1;
    }
    if (!SQL::initDatabase()) {
        cerr << "Error init database!" << endl;
        cerr << SQL::error().toStdString() << endl;
        return 1;
    }
    ::testing::GTEST_FLAG(filter) = "TestDBHelper_*";
    int result = RUN_ALL_TESTS();
    ::testing::GTEST_FLAG(filter) = "ShutdownTests*";
    if (RUN_ALL_TESTS() != 0) {
        cerr << "Shutdown tests failed!" << endl;
        return 1;
    }
    SQL::removeDatabase();
    return result;
}
