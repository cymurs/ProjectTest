/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#ifndef TESTDESIGNPATTERN_HPP
#define TESTDESIGNPATTERN_HPP

#include "share.h"
#include "Singleton.h"


void ThreadFirst(int i) {
    printf("Thread %d start.\n", i);
    Singleton* pFirst = Singleton::GetInstance();
    printf("Thread %d stop.\n", i);
}

void ThreadSecond(int i) {
    printf("Thread %d start.\n", i);
    Singleton* pSecond = Singleton::GetInstance();
    printf("Thread %d stop.\n", i);
}

void TestSingleton() {
    const int total = 10;
    boost::thread_group thr_group;
    for (int i=0; i<total; ++i) {
        if (i % 2)
            thr_group.create_thread(boost::bind(ThreadFirst, i+1));
        else
            thr_group.create_thread(boost::bind(ThreadSecond, i+1));
    }
    thr_group.join_all();    
    
}

#endif