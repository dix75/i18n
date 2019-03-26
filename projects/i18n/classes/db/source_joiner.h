/**
 * \file      perfect/main/db/maindb_source/source_joiner.h
 * \brief     MainDbSourceJoiner source class
 * \author    S.Panin <dix75@mail.ru>
 * \copyright S.Panin, 2006 - 2018
 * \version   v.2.8
 * \created   April (the) 29(th), 2015, 20:01 MSK
 * \updated   June  (the) 07(th), 2016, 13:09 MSK
 * \TODO
**/
#pragma once
#include <QString>
#include <QStringList>
#include <ps2/qt/db/source_program_info.h>
#include <main/program.h>
#include "user/user_source.h"
#include "exercise/exercise_source.h"
#include "records/personal_record/personal_record_source.h"
#include "records/simple_record/simple_record_source.h"
#include "records/body_measurement/msbody_source.h"
#include "records/blood_measurement/msblood_source.h"
#include "trainings/train_info/train_info_source.h"
#include "trainings/train_item/train_item_source.h"
#include "trainings/cycle/cycle_source.h"

class MainDbSourceJoiner final {
public:
    using class_name = MainDbSourceJoiner;

public:
    static QStringList join() noexcept {
        using namespace program::db;

        QStringList list;
        list << ps2::SourceProgramInfo::get(program::name()
                                      , main::name(), main::version());
        list << source::User::get();
        list << source::Exercise::get();
        list << source::PersonalRecord::get();
        list << source::SimpleRecord::get();
        list << source::BloodMeasurement::get();
        list << source::BodyMeasurement::get();
        list << source::Cycle::get();
        list << source::TrainInfo::get();
        list << source::TrainingItem::get();
        return list;
    }
};

