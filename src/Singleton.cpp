/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Singleton.cpp
 * Author: root
 * 
 * Created on 2018年3月12日, 上午9:21
 */

#include "Singleton.h"

Singleton* Singleton::m_pInstance = nullptr;
boost::mutex Singleton::m_mtx;
Singleton::Singleton() {
}

Singleton::Singleton(const Singleton& orig) {
}

Singleton& Singleton::operator =(const Singleton& orig) {    
}

Singleton::~Singleton() {
    if (nullptr != m_pInstance) {
        delete m_pInstance;
        m_pInstance = nullptr;
    }
}

Singleton* Singleton::GetInstance() {
    if (nullptr == m_pInstance) {
        boost::mutex::scoped_lock lock(m_mtx);
        if (nullptr == m_pInstance) {
            m_pInstance = new Singleton();
        }
    }
    return m_pInstance;
}