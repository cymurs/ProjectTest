/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Singleton.h
 * Author: root
 *
 * Created on 2018年3月12日, 上午9:21
 */

#ifndef SINGLETON_H
#define SINGLETON_H

#include <boost/thread/mutex.hpp>

class Singleton {
public:
    static Singleton* GetInstance();
    virtual ~Singleton();
private:
    Singleton();
    Singleton(const Singleton& orig);
    Singleton& operator=(const Singleton& orig);    
private:
    static Singleton *m_pInstance;
    static boost::mutex m_mtx;
};

#endif /* SINGLETON_H */

