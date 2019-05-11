#ifndef DBHEPLER_FROM_H
#define DBHEPLER_FROM_H

#include "private/querystream.h"

namespace dbhelper
{

class From : public __dbhelper_private::QueryStream
{
    QString text;
public:
    From();
    From(const From &w) = delete;
    From(From &&w) = delete;
    ~From() final = default;

    From& operator=(const From &w) = delete;
    From& operator=(From &&w) = delete;

    inline QString fromStream() const noexcept { return text; }
};

}

#endif // DBHEPLER_FROM_H
