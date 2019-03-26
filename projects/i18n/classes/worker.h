/**
 * \file      c:/projects/thei18n/projects/i18n/worker.h 
 * \brief     The Worker class provides 
 * \author    S.Panin <dix75@mail.ru>
 * \copyright S.Panin, 2006 - 2019 
 * \version   v.1.0
 * \created   March     (the) 11(th), 2019, 18:13 MSK
 * \updated   March     (the) 11(th), 2019, 18:13 MSK
 * \TODO      
**/
#pragma once
#include <QString>

class Worker {
 public:
    using class_name = Worker;

 private:
    QString m_file;
     
 public:
    Worker(QString const& file)
        : m_file(file) {
    }
    bool operator()() {
        return true;
    }
};
