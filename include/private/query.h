#ifndef DBHEPLER_PRIVATE_QUERY_H
#define DBHEPLER_PRIVATE_QUERY_H

#include <QString>
#include <QSqlQuery>
#include <QSqlError>

namespace __dbhelper_private
{

class Query
{
    QString textQuery;
protected:
    QSqlDatabase db;
    QSqlQuery sql;
    bool valid;
protected:
    inline QString* forStream() noexcept { return &textQuery; }
    void setTextQuery(const QString &text) noexcept;
public:
    explicit Query(const QSqlDatabase &d);
    Query(QSqlDatabase &&db) = delete;
    Query(const Query &q) = delete;
    Query(Query &&q) = delete;
    virtual ~Query();

    Query& operator=(const Query &q) = delete;
    Query& operator=(Query &&q) = delete;

    virtual bool exec() = 0;
    virtual bool prepare();
    inline QSqlError error() const noexcept { return sql.lastError(); }
    inline bool good() const noexcept { return valid; }
    inline QString text() const noexcept { return textQuery; }
};

}

#endif // DBHEPLER_PRIVATE_QUERY_H
