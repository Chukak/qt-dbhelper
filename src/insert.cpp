#include "include/insert.h"
#include <QtDebug>

using namespace dbhelper;
using namespace __dbhelper_private;

Insert::Insert(const QSqlDatabase &d, const QString &table, const Value &values) :
    Query(d),
    stream(forStream())
{
    stream << "INSERT INTO " << table << " ( ";
    size_t count = 0;
#if __cplusplus < 201402L
    for (const std::pair<QString, QVariant> &val : values) {
#else
    for (const auto& val : values) {
#endif
        count++;
        stream << val.first << (count < values.size() ? " , " : " ");
    }
    stream << " ) VALUES ( ";
    count = 0;
#if __cplusplus < 201402L
    for (const std::pair<QString, QVariant> &val : values) {
#else
    for (const auto& val : values) {
#endif
        count++;
        stream << val.second << (count < values.size() ? " , " : " ");
    }
    stream << " ) ";
}

bool Insert::exec()
{
    valid = sql.exec();
    if (!valid)
        qCritical() << "Insert::exec() failed!";
    return valid;
}
