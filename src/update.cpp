#include "include/update.h"
#include <QtDebug>

using namespace dbhelper;
using namespace __dbhelper_private;

Update::Update(const QSqlDatabase &d, const QString &table, const Value &values) :
    Query(d),
    stream(forStream())
{
    stream << "UPDATE " << table << " SET ";
    size_t count = 0;
#if __cplusplus < 201402L
    for (const std::pair<QString, QVariant> &val : values) {
#else
    for (const auto &val : values) {
#endif
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
