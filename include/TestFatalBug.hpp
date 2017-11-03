/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TestFatalBug.hpp
 * Author: root
 *
 * Created on 2017年11月1日, 下午4:42
 */

#ifndef TESTFATALBUG_HPP
#define TESTFATALBUG_HPP
#include <thread>
#include <mutex>

#include "share.h"

namespace trit {
    std::mutex mtx;
    
    void TestResizeInEmptyVector(vector<float>& other) {
        mtx.lock();        
        cout << std::this_thread::get_id() << " :" << other.size() << endl;        
        mtx.unlock();
        
        for (int i=0; i<1000*1000; ++i) {
            mtx.lock();
            other.resize(500);
            mtx.unlock();
//            other.assign(200, 0.0);
            other.clear();
        }
    }
    
    void TestResizeInEmptyVectorMT() {
        vector<float> emp;
        
        std::thread first(TestResizeInEmptyVector, std::ref(emp));
        std::thread second(TestResizeInEmptyVector, std::ref(emp));
        
        first.join();
        second.join();
            
    }
}

#endif /* TESTFATALBUG_HPP */

