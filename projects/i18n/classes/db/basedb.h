/**
 * \file      c:/projects/thei18n/projects/i18n/classes/db/basedb.h 
 * \brief     The Basedb class provides 
 * \author    S.Panin <dix75@mail.ru>
 * \copyright S.Panin, 2006 - 2019 
 * \version   v.1.0
 * \created   March     (the) 11(th), 2019, 18:45 MSK
 * \updated   March     (the) 11(th), 2019, 18:45 MSK
 * \TODO      
**/
#pragma once
#include <QString>
#include <QStringList>
#include <program.h>
#include <main/settings/settings.h>
#include <main/log.h>
#include <ps2/qt/db/sqlite_db.h>

class BaseDb: public ps2::SqliteDb {
public:
    using class_name = BaseDb;
    using inherited  = ps2::SqliteDb;

protected:
    virtual QString doConnectionName() const = 0;
    virtual QStringList doScriptList() const = 0;
    virtual QString doSettingPath() const    = 0;
    virtual QString  doExt() const           = 0;

    bool setForeignKeySupport(bool is = true) noexcept {
        QSqlQuery query(inherited::db());
        if(is) query.prepare(QStringLiteral("PRAGMA foreign_keys = ON;"));
        else query.prepare(QStringLiteral("PRAGMA foreign_keys = OFF;"));
        return query::exec(query);
    }

public:
    BaseDb()  = default;
    ~BaseDb() = default;
    BaseDb(QString const& file, QString const& connectionName) noexcept {
        if(inherited::connect(program::name(), file, connectionName))
            setForeignKeySupport();
    }
    bool checkConnect(QString const& file) {
        return inherited::checkConnect(program::name(), file, doConnectionName());
    }
    bool connect(QString const& file) {
        auto is = inherited::connect(program::name(), file, doConnectionName());
        if(is) setForeignKeySupport();
        return is;
    }
    bool reconnect(QString const& file) {
        return connect(file);
    }
    bool createDatabase(QString const& file) {
        return inherited::createAndFillDatabase(program::name()
                            , doScriptList(), file, doConnectionName());
    }
    bool reconnectAndSave(QString const& file) {
        if(!reconnect(file)) return false;

        auto const& spath = doSettingPath();
        if(!spath.isEmpty())
            Settings().setValue(spath, file);
        return true;
    }
    QString ext() const {
        return doExt();
    }
};
