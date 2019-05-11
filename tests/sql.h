#ifndef SQL_H
#define SQL_H

#include <QSqlDatabase>
#include <QSqlError>

#define NO_MULTIPLE_STATIC_SQL_DB QSqlDatabase SQL::db;

struct SQL
{

    static inline bool initDatabase() noexcept
    {
        db = QSqlDatabase::addDatabase(DB_DRIVER);
        db.setHostName(DB_HOST);
        db.setPort(DB_PORT);
        db.setUserName(DB_USER);
        db.setPassword(DB_PASSWORD);
        db.setDatabaseName(DB_DATABASE_NAME);

        return db.open();
    }
    static inline QString error() noexcept { return db.lastError().text(); }
    static inline QSqlDatabase& getDatabase() noexcept { return db; }
    static inline void removeDatabase() noexcept
    {
        db.close();
        QSqlDatabase::removeDatabase(db.connectionName());
    }
private:
    static QSqlDatabase db;
};

//QSqlDatabase SQL::db;

#endif // SQL_H
