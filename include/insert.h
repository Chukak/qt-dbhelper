#ifndef DBHEPLER_INSERT_H
#define DBHEPLER_INSERT_H

#include "private/querystream.h"
#include "private/query.h"
#include "value.h"

namespace dbhelper
{

class Insert : public __dbhelper_private::Query
{
    __dbhelper_private::QueryStream stream;
public:
    Insert(const QSqlDatabase &d, const QString &table, const Value &values);
    Insert(const Insert &i) = delete;
    Insert(Insert &&i) = delete;
    ~Insert() final;

    Insert& operator=(const Insert &i) = delete;
    Insert& operator=(Insert &&i) = delete;

    bool exec() override;
    inline QSqlQuery& pureQuery() noexcept { return sql; }
};

}

#endif // DBHEPLER_INSERT_H
