#ifndef DBHEPLER_VALUE_H
#define DBHEPLER_VALUE_H

#include <vector>
#include <string>
#include <utility>
#include <QString>
#include <QVariant>

namespace dbhelper
{

class Value
{    
    std::vector<std::pair<QString, QVariant>> values;
public:
    Value() = default;
    Value(const Value &v) = default;
    Value(Value &&v) = default;
    ~Value() = default;

    Value& operator=(const Value &v) = default;
    Value& operator=(Value &&v) = default;

    Value& operator()(const QString &column, const char *s);
    Value& operator()(QString &&column, const char *s);
    template<typename V>
    Value& operator()(const QString &column, const V &value)
    {
        values.push_back({column, QVariant::fromValue(value)});
        return *this;
    }
    template<typename V>
    Value& operator()(QString &&column, V &&value)
    {
        values.push_back({column, QVariant::fromValue(value)});
        return *this;
    }

    inline size_t size() const noexcept { return values.size(); }
    QVariant valueAt(const QString &column) const noexcept;

    auto begin() const noexcept { return values.cbegin(); }
    auto end() const noexcept { return values.cend(); }
};

template<>
Value& Value::operator()<QChar>(const QString &column, const QChar &value);

template<>
Value& Value::operator()<QChar>(QString &&column, QChar &&value);

template<>
Value& Value::operator()<QString>(const QString &column, const QString &value);

template<>
Value& Value::operator()<QString>(QString &&column, QString &&value);

template<>
Value& Value::operator()<std::string>(const QString &column, const std::string &value);

template<>
Value& Value::operator()<std::string>(QString &&column, std::string &&value);

}

#endif // DBHEPLER_VALUE_H
