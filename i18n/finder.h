/**
 * \file      projects/i18n/i18n/finder.h 
 * \brief     The Finder class provides 
 * \author    S.Panin <dix75@mail.ru>
 * \copyright S.Panin, 2006 - 2019 
 * \version   v.1.0
 * \created   February  (the) 03(th), 2019, 13:44 MSK
 * \updated   February  (the) 03(th), 2019, 13:44 MSK
 * \TODO      
**/
#pragma once
#include <QDir>
#include <QDebug>

/** \namespace i18n */
namespace i18n {

class Finder final {
 public:
    using class_name = Finder;
    
 private: 
    uint m_id;

 public:
    explicit Finder( id) noexcept 
        : m_id(id){
    }
    virtual ~Finder() = default;
    uint id() const noexcept {
    return m_id;
}
void setId(uint id) noexcept {
    m_id = id;
}
};

}  // end namespace i18n
