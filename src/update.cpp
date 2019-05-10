#include "include/update.h"
#include <QtDebug>

using namespace dbhelper;
using namespace __dbhelper_private;

Update::Update(const QSqlDatabase &d, const QString &table, const Value &values) :
    Query(d),
    stream(forStream())
{
    stream << "UPDATE " << table << " ";
    size_t count = 0;
    for (const auto &val : values) {
        ++count;
        stream << val.first << " = " << val.second << (count < values.size() ? " , " : " ");
    }
}

void Update::addWhere(const Where &where)
{
    stream << where.fromStream() << " ";
}

bool Update::exec()
{
    valid = sql.exec();
    if (!valid)
        qCritical() << "Update::exec() failed!";
    return valid;
}
