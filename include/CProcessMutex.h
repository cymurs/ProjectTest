/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CProcessMutex.h
 * Author: root
 *
 * Created on 2018年3月9日, 上午11:00
 */

#ifndef CPROCESSMUTEX_H
#define CPROCESSMUTEX_H

#ifdef WIN32
#include <Windows.h>
#endif
 
#ifdef linux
#include <unistd.h>
#include <semaphore.h>
#include <stdio.h>
#include <fcntl.h>
#include <signal.h>
#include <string.h>
#include <memory.h>
#endif
 
class CProcessMutex
{
public:
    /* 默认创建匿名的互斥 */
    CProcessMutex(const char* name = nullptr);
    ~CProcessMutex();
 
    bool Lock();
    bool UnLock();
private:
#ifdef WIN32
    void* m_pMutex;
#endif
#ifdef linux
    sem_t* m_pSem;
#endif
    char m_cMutexName[30];
};

#endif /* CPROCESSMUTEX_H */

