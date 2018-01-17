/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TestSharedPtr.hpp
 * Author: root
 *
 * Created on 2018年1月16日, 下午5:27
 */

#ifndef TESTSHAREDPTR_HPP
#define TESTSHAREDPTR_HPP

#include "share.h"

class tsp {
public:
    void Print() {
        printf("This is a demo for testing shared_ptr\n");
        for (int n=0; n<50; ++n) {
            char *del = new char[6*1024*1024*1024L];
//            auto del = std::make_shared<std::array<char, 1024*1024> >();
            strcpy(del, "demo");
            m_num = 1024 * 1024;
            m_str.assign("Just a test, relax...");
            
            delete [] del;
        }
    }
    
private:
    long m_num;
    string m_str;
};

void TestSharedPtr() {
    shared_ptr<tsp> tst(new tsp()); //= std::make_shared<tsp>();
    tst->Print();
}

#endif /* TESTSHAREDPTR_HPP */

