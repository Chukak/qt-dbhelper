#include "statements/from.h"

using namespace dbhelper;
using namespace __dbhelper_private;

From::From() :
    QueryStream(&text),
    text(" FROM ")
{
}
