#include "value.h"

using namespace dbhelper;

QVariant Value::valueAt(const QString &column) const noexcept
{
    auto it = std::find_if(values.cbegin(), values.cend(),
                           [&column](const auto& p) { return p.first == column; });
    if (it != values.cend())
        return (*it).second;
    return {};
}
