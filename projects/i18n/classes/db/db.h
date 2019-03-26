/**
 * \file      perfect/main/db/maindb.h
 * \brief     Main db class
 * \author    S.Panin <dix75@mail.ru>
 * \copyright S.Panin, 2006 - 2018
 * \version   v.2.1
 * \created   April     (the) 28(th), 2015, 17:23 MSK
 * \updated   September (the) 01(th), 2015, 18:10 MSK
 * \TODO
**/
#pragma once
#include "basedb.h"
#include <main/file_types.h>
#include "maindb_source/source_joiner.h"
#include "maindb_source/db_filler.h"

/**
 * \code
 *     auto const val = settings()->value(QStringLiteral("options/maindb"), program::db::main::file());
 *     m_maindb->reConnect(val.toString());
 *
 *     DbNewTool tool(this, App::mainDb(), name());
 *     tool.exec();
 *
 *     MainDb().createDatabase(program::db::main::file());
 * \endcode
**/
class MainDb: public BaseDb {
public:
    using class_name = MainDb;
    using inherited = BaseDb;

private:
    virtual QString doConnectionName() const Q_DECL_OVERRIDE {
        return program::db::main::name();
    }
    virtual QStringList doScriptList() const Q_DECL_OVERRIDE {
        return MainDbSourceJoiner::join();
    }
    virtual QString doSettingPath() const Q_DECL_OVERRIDE {
        return settingPath();
    }
    virtual bool doFillDatabase(QSqlDatabase const& db) Q_DECL_OVERRIDE {
        return MainDbFiller::fill(db);
    }
    virtual QString doExt() const Q_DECL_OVERRIDE {
        return FileTypes::mainDatabaseFiles();
    }

public:
    MainDb() Q_DECL_EQ_DEFAULT;
    MainDb(QString const& file) noexcept
        : inherited(file, doConnectionName()) {
    }
    MainDb(QString&& file) noexcept
        : inherited(qMove(file), doConnectionName()) {
    }
    static inline QString settingPath() noexcept {
        return QStringLiteral("options/maindb");
    }
};
