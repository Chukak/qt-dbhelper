#include <gtest/gtest.h>
#include <sstream>
#include <sys/types.h>
#include <sys/stat.h>

using namespace std;

struct stat info_shutdown;

TEST(ShutdownTests, DropTables)
{
    ASSERT_TRUE(stat("sql", &info_shutdown) == 0);
    ASSERT_TRUE(stat("sql/drop.sql", &info_shutdown) == 0);
    ostringstream command;
    command << "mysql -u " << DB_USER << " -p" << DB_PASSWORD << " < sql/drop.sql";
    system(command.str().data());
}
