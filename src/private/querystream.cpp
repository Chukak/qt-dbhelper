#include "private/querystream.h"

using namespace __dbhelper_private;

QueryStream::QueryStream(QString *string) :
    stream(string)
{
}

QueryStream::~QueryStream()
{
}

void QueryStream::convert(QVariant &&value)
{
    switch (static_cast<QMetaType::Type>(value.type()))
    {
    case QMetaType::Short:
    case QMetaType::Int:
        stream << value.toInt();
        break;
    case QMetaType::Bool:
        // todo
        stream << value.toBool();
        break;
    case QMetaType::UChar:
    case QMetaType::SChar:
    case QMetaType::Char:
        stream << value.toChar();
        break;
    case QMetaType::UShort:
    case QMetaType::UInt:
        stream << value.toUInt();
        break;
    case QMetaType::Double:
        stream << value.toDouble();
        break;
    case QMetaType::Float:
        stream << value.toFloat();
        break;
    case QMetaType::Long:
    case QMetaType::LongLong:
        stream << value.toLongLong();
        break;
    case QMetaType::ULong:
    case QMetaType::ULongLong:
        stream << value.toULongLong();
        break;
    // todo
    case QMetaType::QTime:
    case QMetaType::QDate:
    case QMetaType::QDateTime:
        break;
    default:
        break;
    }
}

QueryStream& QueryStream::operator<<(const char *s)
{
    stream << s;
    return *this;
}
