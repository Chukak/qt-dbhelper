#ifndef DBHEPLER_QUERYTYPE_H
#define DBHEPLER_QUERYTYPE_H

#include <QDateTime>
#include <QMetaType>
#include <QLoggingCategory>

namespace dbhelper
{

enum DbType
{
    POSTGRESQL_T,
    MYSQL_T,
    MSSQL_T, // todo
    ORACLE_T, // todo
    UNKNOWN_DB_TYPE_T
};

struct DateFormat
{
    DateFormat() = delete;
    DateFormat(const DateFormat &df) = delete;
    DateFormat(DateFormat &&df) = delete;
    ~DateFormat() = delete;

    DateFormat& operator=(const DateFormat &ts) = delete;
    DateFormat& operator=(DateFormat &&ts) = delete;

    static void setDateTimeFormat(const QString &f);
    static void setDateFormat(const QString &f);
    static void setTimeFormat(const QString &f);

    static inline QString getDateTimeFormat() noexcept { return dateTimeFormat; }
    static inline QString getDateFormat() noexcept { return dateFormat; }
    static inline QString getTimeFormat() noexcept { return timeFormat; }

private:
    static QString dateTimeFormat;
    static QString dateFormat;
    static QString timeFormat;
};

struct Timestamp
{
    Timestamp();
    Timestamp(const QDateTime &dt, DbType t = UNKNOWN_DB_TYPE_T);
    Timestamp(const QDate &dt, DbType t = UNKNOWN_DB_TYPE_T);
    Timestamp(const Timestamp &ts) = default;
    Timestamp(Timestamp &&ts) = default;
    ~Timestamp() = default;

    Timestamp& operator=(const Timestamp &ts) = default;
    Timestamp& operator=(Timestamp &&ts) = default;

    template<typename Stream>
    void toStream(Stream &stream)
    {
        switch (type) {
        case POSTGRESQL_T:
            stream << "'" << date << "'" << "::timestamp";
            break;
        case MYSQL_T:
            stream << "'" << date << "'";
            break;
        // todo
        case MSSQL_T:
        case ORACLE_T:
        case UNKNOWN_DB_TYPE_T:
            qWarning() << "Unknown DB type! Will use ISO date format ('YYYY-MM-DD HH:MM:SS')";
            stream << "'" << date << "'";
            break;
        }
    }

private:
    QString date;
    DbType type;
};

}

Q_DECLARE_METATYPE(dbhelper::Timestamp);

#endif // DBHEPLER_QUERYTYPE_H
