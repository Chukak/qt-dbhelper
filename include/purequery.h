#ifndef DBHEPLER_QUERY_H
#define DBHEPLER_QUERY_H

#include "private/querystream.h"
#include "private/query.h"

namespace dbhelper
{

class PureQuery : public __dbhelper_private::Query
{
    __dbhelper_private::QueryStream stream;
public:
    PureQuery(const QSqlDatabase &d, const QString &query);
    PureQuery(const PureQuery &q) = delete;
    PureQuery(PureQuery &&q) = delete;
    ~PureQuery() final = default;

    PureQuery& operator=(const PureQuery &q) = delete;
    PureQuery& operator=(PureQuery &&q) = delete;

    bool exec() override;

    inline bool next() noexcept { return sql.next(); }
    inline QVariant value(int index) noexcept { return sql.value(index); }
    inline int size() const noexcept { return sql.size(); }
    inline QSqlQuery& pureQuery() noexcept { return sql; }
};

}

#endif // DBHEPLER_QUERY_H
