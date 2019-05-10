#include "select.h"
#include <QtDebug>

using namespace dbhelper;
using namespace __dbhelper_private;

Select::Select(const QSqlDatabase &d, const ColumnList &columns, const From &from) :
    Query(d),
    stream(forStream())
{
    stream << "SELECT ";
    size_t count = 0;
    for (const auto &val : columns) {
        ++count;
        stream << val << (count < columns.size() ? " , " : " ");
    }
    stream << from.fromStream() << " ";
}

void Select::addWhere(const Where &where)
{
    stream << where.fromStream() << " ";
}

void Select::limit(size_t number)
{
    // todo: only postgresql and mysql
    if (db.driverName() == "QMYSQL" || db.driverName() == "QPSQL")
        stream << " LIMIT " << number;
}

bool Select::exec()
{
    valid = sql.exec();
    if (!valid)
        qCritical() << "Select::exec() failed!";
    return valid;
}
