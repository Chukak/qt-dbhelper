#ifndef DBHEPLER_COLUMNLIST_H
#define DBHEPLER_COLUMNLIST_H

#include <QStringList>

namespace dbhelper
{

class ColumnList
{
    QStringList list;
public:
    ColumnList() = default;
    ColumnList(const ColumnList &l) = default;
    ColumnList(ColumnList &&l) = default;
    ~ColumnList() = default;

    ColumnList& operator=(const ColumnList &l) = default;
    ColumnList& operator=(ColumnList &&l) = default;

    ColumnList& operator<<(const QString &s) noexcept;
    ColumnList& operator<<(QString &&s) noexcept;

    inline size_t size() const noexcept { return list.size(); }
#if __cplusplus < 201402L
    QStringList::ConstIterator
#else
    auto
#endif
    begin() const noexcept { return list.cbegin(); }
#if __cplusplus < 201402L
    QStringList::ConstIterator
#else
    auto
#endif
    end() const noexcept { return list.cend(); }
};

}

#endif // DBHEPLER_COLUMNLIST_H
