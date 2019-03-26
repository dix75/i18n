/**
 * \file      c:/projects/thei18n/projects/i18n/program.h 
 * \brief     The Program class provides 
 * \author    S.Panin <dix75@mail.ru>
 * \copyright S.Panin, 2006 - 2019 
 * \version   v.1.0
 * \created   March     (the) 11(th), 2019, 18:46 MSK
 * \updated   March     (the) 11(th), 2019, 18:46 MSK
 * \TODO      
**/
#pragma once
#include <QDir>
#include <QDate>
#include <QSettings>
#include <QFileInfo>
#include <QStringList>
#include <QApplication>
#include <QStandardPaths>

#define I18N_APP_PATH(str) QCoreApplication::applicationDirPath() + QStringLiteral(str);
#define I18N_HOME_PATH(str) program::homeFolder() + QStringLiteral(str);
/**
 * \code
 *      program::fullName();
 * \endcode
**/
namespace program {
    inline QString setupName() noexcept {
        return QStringLiteral("i18n.exe");
    }
    inline QString name() noexcept {
        return QStringLiteral("I18n BFM");
    }
    inline QString version() noexcept {
        return QStringLiteral("2.21");
    }
    inline QString fullName() noexcept {
        return QStringLiteral("%1 %2")
               .arg(name())
               .arg(version());
    }
    inline QString date() noexcept {
        return QDate(2017,07,01).toString(Qt::ISODate);
    }
    inline QString build() noexcept {
        return QStringLiteral("3339");
    }
    inline QString fullVersion() noexcept {
        return QStringLiteral("%1 %2, build %3 (%4)")
                .arg(name())
                .arg(version())
                .arg(build())
                .arg(date());
    }
    inline QString organizationName() noexcept {
        return QStringLiteral("FiveSoft");
    }
    inline QString organizationDomain() noexcept {
        return QStringLiteral("irondoom.ru");
    }
    inline QString homeFolder() noexcept {
        QSettings s(QSettings::IniFormat, QSettings::UserScope, QStringLiteral(".irondoom"), QStringLiteral(""));
        return QFileInfo(s.fileName()).absolutePath() + QStringLiteral("/.irondoom");
    }
    inline QString help() noexcept {
        return APP_PATH("/Help/Help.chm");
    }
    inline QString author() noexcept {
        return QStringLiteral("Sergey Panin");
    }
    inline QString copyright() noexcept {
        return QStringLiteral("Copyright (c) 2005-2017, S.Panin. All rights reserved.");
    }
    inline QString homepage() noexcept {
        return QStringLiteral("http://www.irondoom.ru");
    }
    static inline QString logFile() noexcept {
        return HOME_PATH("/log.txt");
    }
    inline QString supportMail() noexcept {
        return QStringLiteral("support@irondoom.ru");
    }
    /** \namespace registry */
    namespace registry {
        static inline QString software() noexcept {
            return QStringLiteral("HKEY_CURRENT_USER\\SOFTWARE");
        }
        static inline QString irondoomOld() noexcept {
            return QStringLiteral("HKEY_CURRENT_USER\\SOFTWARE\\IRoNDooM");
        }
        static inline QString irondoom() noexcept {
            return QStringLiteral("HKEY_CURRENT_USER\\SOFTWARE\\FiveSoft\\IRoNDooM BFM");
        }
        static inline QString irondoom2() noexcept {
            return QStringLiteral("HKEY_CURRENT_USER\\SOFTWARE\\FiveSoft\\IRoNDooM2");
        }
    } // end namespace registry
    /**
     * \code
     *      program::norms::ext();
     * \endcode
    **/
    namespace norms {
        static inline QString name() noexcept {
            return QStringLiteral("Norm");
        }
        static inline uint version() noexcept {
            return 1u;
        }
    }
    /**
     * \code
     *      program::body_measurements::ext();
     * \endcode
    **/
    namespace body_measurements {
        static inline QString name() noexcept {
            return QStringLiteral("BodyMeasurement");
        }
        static inline uint version() noexcept {
            return 1u;
        }
    }
    /**
     * \code
     *      program::db::main::version();
     * \endcode
    **/
    namespace db {
        namespace main {
            inline QString file() noexcept {
                return HOME_PATH("/main.ldb");
            }
            inline QString version() noexcept {
                return QStringLiteral("1");
            }
            inline QString name() noexcept {
                return QStringLiteral("Main");
            }
        }
        namespace base {
            inline QString file() noexcept {
                return HOME_PATH("/base1.ldb");
            }
            inline QString version() noexcept {
                return QStringLiteral("2.0");
            }
            inline QString name() noexcept {
                return QStringLiteral("Base");
            }
        }
        namespace eg {
            inline QString file() noexcept {
                return HOME_PATH("/eg.teg");
            }
            inline QString version() noexcept {
                return QStringLiteral("1");
            }
            inline QString name() noexcept {
                return QStringLiteral("Eg");
            }
        }
        namespace bp {
            inline QString version() noexcept {
                return QStringLiteral("1");
            }
            inline QString name() noexcept {
                return QStringLiteral("Bp");
            }
        }
        namespace foods {
            inline QString version() noexcept {
                return QStringLiteral("1");
            }
            inline QString name() noexcept {
                return QStringLiteral("Foods");
            }
            inline QString file() noexcept {
                return HOME_PATH("/foods.tfo");
            }
        }
        namespace ird_diary {
            inline QString name() noexcept {
                return QStringLiteral("Base");
            }
            inline QString file() noexcept {
                return HOME_PATH("/Base.mdb");
            }
        }
    }
    /**
     * \code
     *      program::web::new_version::info();
     * \endcode
    **/
    namespace web {
        static inline QString calcs() noexcept {
            return QStringLiteral("http://www.irondoom.ru/calcs");
        }
        static inline QString buy() noexcept {
            return QStringLiteral("http://irondoom.ru/price.html");
        }
        static inline QString wiki() noexcept {
            return QStringLiteral("http://irondoom.ru/wiki/index.html");
        }
        static inline QString norms() noexcept {
            return QStringLiteral("http://irondoom.ru/irondoom/soft/norms/");
        }
        static inline QString measurements() noexcept {
            return QStringLiteral("http://irondoom.ru/irondoom/soft/measurements/");
        }
        static inline QString languages() noexcept {
            return QStringLiteral("http://irondoom.ru/2008/04/02/language.html");
        }
        namespace new_version {
            inline QString info() noexcept {
                return QStringLiteral("http://www.irondoom.ru/uploads/version.xml");
            }
            inline QString file() noexcept {
                return QStringLiteral("http://www.irondoom.ru/uploads/Setup.exe");
            }
            inline QString wrapUrl() noexcept {
                return QStringLiteral("http://www.irondoom.ru");
            }
        }
    }
    namespace old_program {
        inline QString ini_file() noexcept {
            return HOME_PATH("/irondoom.ini");
        }
        inline QString calcs_file_data() noexcept {
            return HOME_PATH("/calcs.ini");
        }
        inline QString name() noexcept {
            return QStringLiteral("the Perfect");
        }
    }
    namespace ext {
        static inline QString body_measurements() noexcept {
            return QStringLiteral("tbm");
        }
        static inline QString norms() noexcept {
            return QStringLiteral("tnm");
        }
        static inline QString settingsDb() noexcept {
            return QStringLiteral("*.lsdb *.lsdb2 *.lsdb3");
        }
        static inline QString baseDb() noexcept {
            return QStringLiteral("*.ldb *.ldb2 *.ldb3");
        }
        static inline QString exerciseGuideDb() noexcept {
            return QStringLiteral("*.legdb *.legdb2 *.legdb3");
        }
        static inline QString translation() noexcept {
            return QStringLiteral("*.qm");
        }
        inline QString mainDB() noexcept {
            return QStringLiteral("ldb");
        }
        inline QString egDb() noexcept {
            return QStringLiteral("teg");
        }
        inline QString foods() noexcept {
            return QStringLiteral("tfo");
        }
        inline QString ird_diary() noexcept {
            return QStringLiteral("mdb");
        }
    }
    namespace default_file {
        inline QString exerciseGuideDb() noexcept {
            return HOME_PATH("/exercises.legdb");
        }
        inline QString settingsDb() noexcept {
            return HOME_PATH("/settings.lsdb");
        }
        inline QString baseDb() noexcept {
            return HOME_PATH("/base1.ldb");
        }
    }
    namespace script {
        inline QString exerciseGuideDb() noexcept {
            return QLatin1String("bde54.scr");
        }
        inline QString settingsDb() noexcept {
            return QLatin1String("bds02.scr");
        }
        inline QString baseDb() noexcept {
            return QLatin1String("bdb23.scr");
        }
    }
    namespace paths {
        static inline QString proportion() noexcept {
            return APP_PATH("/Resource/Proportion/");
        }
        static inline QString translation() noexcept {
            return APP_PATH("/Resource/Language/");
        }
        static inline QString exercisesGuides() noexcept {
            return APP_PATH("/Resource/ExercisesGuides/");
        }
        static inline QString langs() noexcept {
            return APP_PATH("/langs");
        }
        static inline QString calcs() noexcept {
            return APP_PATH("/calcs");
        }
        static inline QString norms() noexcept {
            return APP_PATH("/norms");
        }
        static inline QString foods() noexcept {
            return APP_PATH("/foods");
        }
        static inline QString body_measurements() noexcept {
            return APP_PATH("/measurements/body/");
        }
        static inline QString path() noexcept {
            return APP_PATH("/norms");
        }
    }
    /**
     * \code
     *      program::data::maindbEn();
     * \endcode
    **/
    namespace data {
        static inline QString maindbEn() noexcept {
            return APP_PATH("/data/mdben.data");
        }
        static inline QString maindbRu() noexcept {
            return APP_PATH("/data/mdbru.data");
        }
    }
}
