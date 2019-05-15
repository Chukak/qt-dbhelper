#include "private/querystream.h"
#include "querytype.h"
#include <QDateTime>
#include <QtDebug>

using namespace __dbhelper_private;
using namespace dbhelper;

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
        stream << (value.toBool() ? "true" : "false");
        break;
    case QMetaType::UChar:
    case QMetaType::SChar:
    case QMetaType::Char:
    case QMetaType::QChar:
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
    case QMetaType::QString:
        stream << value.toString();
        break;
    case QMetaType::QTime:
        stream << "'" << value.toTime().toString(DateFormat::getTimeFormat()) << "'";
        break;
    case QMetaType::QDate:
        stream << "'" << value.toDate().toString(DateFormat::getDateFormat()) << "'";
        break;
    case QMetaType::QDateTime:
        stream << "'" << value.toDateTime().toString(DateFormat::getDateTimeFormat()) << "'";
        break;
    case QMetaType::User:
        if (value.canConvert<Timestamp>())
            value.value<Timestamp>().toStream(stream);
        else
            qCritical() << "Custom type not supported!";
        break;
    default:
        qCritical() << "Type not supported!";
        break;
    }
}

QueryStream& QueryStream::operator<<(const char *s)
{
    stream << s;
    return *this;
}
