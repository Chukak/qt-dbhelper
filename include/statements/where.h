#ifndef DBHEPLER_WHERE_H
#define DBHEPLER_WHERE_H

#include "private/querystream.h"

namespace dbhelper
{

class Where : public __dbhelper_private::QueryStream
{
    QString text;
public:
    Where();
    Where(const Where &w) = delete;
    Where(Where &&w) = delete;
    ~Where() final;

    Where& operator=(const Where &w) = delete;
    Where& operator=(Where &&w) = delete;

    inline QString fromStream() const noexcept { return text; }
};

}

#endif // DBHEPLER_WHERE_H
