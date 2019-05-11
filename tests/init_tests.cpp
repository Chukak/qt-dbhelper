#include <gtest/gtest.h>
#include <sstream>
#include <sys/types.h>
#include <sys/stat.h>

using namespace std;

struct stat info_init;

static void dump(string &&file)
{
    ostringstream command;
    command << "mysql -u " << DB_USER << " -p" << DB_PASSWORD << " < " << file;
    system(command.str().data());
}

TEST(InitTests, RemoveOldTables)
{
    ASSERT_TRUE(stat("sql", &info_init) == 0);
    ASSERT_TRUE(stat("sql/drop.sql", &info_init) == 0);
    dump("sql/drop.sql");
}

TEST(InitTests, CreateTables)
{
    ASSERT_TRUE(stat("sql", &info_init) == 0);
    ASSERT_TRUE(stat("sql/create.sql", &info_init) == 0);
    dump("sql/create.sql");
}

TEST(InitTests, LoadData)
{
    ASSERT_TRUE(stat("sql/data.sql", &info_init) == 0);
    ostringstream command;
    dump("sql/data.sql");
}
