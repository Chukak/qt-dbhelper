#include "statements/where.h"

using namespace dbhelper;
using namespace __dbhelper_private;

Where::Where() :
    QueryStream(&text),
    text(" WHERE ")
{
}
