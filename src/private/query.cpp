#include "private/query.h"
#include <utility>

using namespace __dbhelper_private;

Query::Query(const QSqlDatabase &d) :
    db(d),
    sql(d),
    valid(true)
{
}

Query::~Query()
{
}

void Query::setTextQuery(const QString &text) noexcept
{
    textQuery = text;
}

bool Query::prepare()
{
    valid = sql.prepare(textQuery);
    return valid;
}
