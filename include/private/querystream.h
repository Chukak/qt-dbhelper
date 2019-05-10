#ifndef DBHEPLER_PRIVATE_QUERYSTREAM_H
#define DBHEPLER_PRIVATE_QUERYSTREAM_H

#include <QString>
#include <QTextStream>
#include <QMetaType>
#include <QVariant>

namespace __dbhelper_private
{

class QueryStream
{
    QTextStream stream;
protected:
    void convert(QVariant &&value);
public:
    QueryStream() = default;
    QueryStream(QString *string);
    QueryStream(const QueryStream &qs) = delete;
    QueryStream(QueryStream &&qs) = delete;
    virtual ~QueryStream();

    QueryStream& operator=(const QueryStream &qs) = delete;
    QueryStream& operator=(QueryStream &&qs) = delete;

    QueryStream& operator<<(const char *s);
    template<typename T>
    QueryStream& operator<<(const T &value)
    {
        convert(QVariant::fromValue(value));
        return *this;
    }
    template<typename T>
    QueryStream& operator<<(T &&value)
    {
        convert(QVariant::fromValue(value));
        return *this;
    }

    inline QTextStream& pureStream() noexcept { return stream; }
};

}

#endif // DBHEPLER_PRIVATE_QUERYSTREAM_H
