#include "columnlist.h"

using namespace dbhelper;

ColumnList& ColumnList::operator<<(const QString &s) noexcept
{
    list << s;
    return *this;
}
ColumnList& ColumnList::operator<<(QString &&s) noexcept
{
    list << s;
    return *this;
}
