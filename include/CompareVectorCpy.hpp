/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CompareVectorCpy.hpp
 * Author: root
 *
 * Created on 2017年10月16日, 上午11:39
 */

#ifndef COMPAREVECTORCPY_HPP
#define COMPAREVECTORCPY_HPP
#include "share.h"

void CompareCpyToVector() {
    BPT::ptime time_start, time_end;
    BPT::millisec_posix_time_system_config::time_duration_type time_elapse;
    
    time_start = BPT::microsec_clock::universal_time();
    
    float a[150];
    for (int i = 0; i < 150; ++i)
        a[i] = i+1;
    vector<float> vecf(10, 1.0);
    vecf.reserve(10);
    for (int i = 0; i < 10; ++i)  {
        vecf.push_back(a[i]);
    }
//    memcpy(&vecf[0], &a[0], 10 *sizeof(float));
//    vecf.assign(&a[0], &a[150]);
    std::copy(vecf.begin(), vecf.end(), std::ostream_iterator<float>(cout, " "));
    cout << endl;
    
//    boost::this_thread::sleep(BPT::microsec(100));
    
    time_end = BPT::microsec_clock::universal_time();
    time_elapse = time_end - time_start;
    
    cout << "execution interval tick: " << time_elapse.ticks() << endl;
}

#endif /* COMPAREVECTORCPY_HPP */

