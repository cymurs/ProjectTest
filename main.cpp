/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: root
 *
 * Created on 2017年9月20日, 上午11:56
 */

#include "share.h"
#include "TestCanDel.hpp"
#include "CompareVectorCpy.hpp"
#include "CreateListOfFileInDir.hpp"
#include "TestFatalBug.hpp"
#include "TestSharedFromThis.h"

/*
 * 
 */
int main(int argc, char** argv) {
//    CompareCpyToVector();   
//    Call();
//    CreateListOfFile("/home/image/part");
    
//    vector<float> emp;   
//    trit::TestResizeInEmptyVector(emp);
//    trit::TestResizeInEmptyVectorMT();
    
//    struct A {
//        float a; int b; float c;
//    };
//    A t;
//    printf("a:%p, %p, %p\n", &t.a, &t.b, &t.c);
    
    shared_ptr<test_sft> ts(new test_sft());
    shared_ptr<test_sft> other = ts->get_ptr();
    
    cout << "success\n";
    return 0;
}
