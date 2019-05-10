#include "include/purequery.h"
#include <QtDebug>

using namespace dbhelper;
using namespace __dbhelper_private;

PureQuery::PureQuery(const QSqlDatabase &d, const QString &query) :
    Query(d),
    stream(forStream())
{
    setTextQuery(query);
}

bool PureQuery::exec()
{
    valid = sql.exec();
    if (!valid)
        qCritical() << "PureQuery::exec() failed!";
    return valid;
}
