#include "value.h"

using namespace dbhelper;

QVariant Value::valueAt(const QString &column) const noexcept
{
#if __cplusplus < 201402L
    std::vector<std::pair<QString, QVariant>>::const_iterator
#else
    auto
#endif
   it = std::find_if(values.cbegin(), values.cend(),
                           [&column]
#if __cplusplus < 201402L
                     (const std::pair<QString, QVariant> &p)
#else
                     (const auto &p)
#endif
                    { return p.first == column; });

    if (it != values.cend())
        return (*it).second;
    return {};
}

Value& Value::operator()(const QString &column, const char *s)
{
    // todo
    values.push_back({column, QString("'%1'").arg(s)});
    return *this;
}

Value& Value::operator()(QString &&column, const char *s)
{
    // todo
    values.push_back({column, QString("'%1'").arg(s)});
    return *this;
}

template<>
Value& Value::operator()<QString>(const QString &column, const QString &value)
{
    values.push_back({column, QString("'%1'").arg(value)});
    return *this;
}

template<>
Value& Value::operator()<QString>(QString &&column, QString &&value)
{
    values.push_back({column, QString("'%1'").arg(value)});
    return *this;
}

template<>
Value& Value::operator()<std::string>(const QString &column, const std::string &value)
{
    values.push_back({column, QString("'%1'").arg(QString::fromStdString(value))});
    return *this;
}

template<>
Value& Value::operator()<std::string>(QString &&column, std::string &&value)
{
    values.push_back({column, QString("'%1'").arg(QString::fromStdString(value))});
    return *this;
}

template<>
Value& Value::operator()<QChar>(const QString &column, const QChar &value)
{
    values.push_back({column, QString("'%1'").arg(value)});
    return *this;
}

template<>
Value& Value::operator()<QChar>(QString &&column, QChar &&value)
{
    values.push_back({column, QString("'%1'").arg(value)});
    return *this;
}
