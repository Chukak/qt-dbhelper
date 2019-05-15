#include "querytype.h"

using namespace dbhelper;

QString DateFormat::dateTimeFormat("yyyy-MM-dd hh:mm:ss");
QString DateFormat::dateFormat("yyyy-MM-dd");
QString DateFormat::timeFormat("hh:mm:ss");

void DateFormat::setDateTimeFormat(const QString &f)
{
    dateTimeFormat = f;
    qWarning() << "DateTime format: " << f;
}

void DateFormat::setDateFormat(const QString &f)
{
    dateFormat = f;
    qWarning() << "Date format: " << f;
}

void DateFormat::setTimeFormat(const QString &f)
{
    timeFormat = f;
    qWarning() << "Time format: " << f;
}

Timestamp::Timestamp() :
    date("''"),
    type(UNKNOWN_DB_TYPE_T)
{
}

Timestamp::Timestamp(const QDateTime &dt, DbType t) :
    date(dt.toString("yyyy-MM-dd hh:mm:ss")),
    type(t)
{
}

Timestamp::Timestamp(const QDate &dt, DbType t) :
    date(dt.toString("yyyy-MM-dd")),
    type(t)
{
}
