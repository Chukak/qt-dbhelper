#ifndef DBHEPLER_SELECT_H
#define DBHEPLER_SELECT_H

#include "private/querystream.h"
#include "private/query.h"
#include "statements/from.h"
#include "statements/where.h"
#include "columnlist.h"

namespace dbhelper
{

class Select : public __dbhelper_private::Query
{
    __dbhelper_private::QueryStream stream;
public:
    Select(const QSqlDatabase &d, const ColumnList &columns, const From &from);
    Select(const Select &s) = delete;
    Select(Select &&s) = delete;
    ~Select() final = default;

    Select& operator=(const Select &s) = delete;
    Select& operator=(Select &&s) = delete;

    void addWhere(const Where &where);
    template<typename ... Columns>
    void orderBy(Columns&& ... columns)
    {
        size_t count = 0, size = sizeof...(columns);
        if (size)
            stream << " ORDER BY ";
        [[maybe_unused]]int _[] = {0, ((stream << columns << (size != ++count ? " , " : "")), 0) ...};
    }
    void limit(size_t number);

    bool exec() override;

    inline bool next() noexcept { return sql.next(); }
    inline QVariant value(int index) noexcept { return sql.value(index); }
    inline int size() const noexcept { return sql.size(); }
    inline QSqlQuery& pureQuery() noexcept { return sql; }
};

}

#endif // DBHEPLER_SELECT_H
