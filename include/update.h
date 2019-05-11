#ifndef DBHEPLER_UPDATE_H
#define DBHEPLER_UPDATE_H

#include "private/querystream.h"
#include "private/query.h"
#include "statements/where.h"
#include "value.h"

namespace dbhelper
{

class Update : public __dbhelper_private::Query
{
    __dbhelper_private::QueryStream stream;
public:
    Update(const QSqlDatabase &d, const QString &table, const Value &values);
    Update(const Update &u) = delete;
    Update(Update &&u) = delete;
    ~Update() final = default;

    Update& operator=(const Update &u) = delete;
    Update& operator=(Update &&u) = delete;

    void addWhere(const Where &where);

    bool exec() override;
    inline QSqlQuery& pureQuery() noexcept { return sql; }
};

}

#endif // DBHEPLER_UPDATE_H
