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
#include "ReserveAffect.h"
#include "TestIgnite.hpp"
#include "TestScanLargeFile.hpp"
#include "TestPropertyTree.hpp"
#include "TestPropertyTreeJson.hpp"
#include "CustomHelper.h"
#include "TestSharedPtr.hpp"
#include "TestWrapMalloc.hpp"
#include "TestPrintScanfFloat.hpp"
#include "CompareUnordered_mapAndMap.hpp"
#include <cstdlib>
#include <cstdio>
#include <malloc.h>  // malloc_trim
#include <mcheck.h> // mtrace
/*
 * 
 */
int main(int argc, char** argv) {
#ifdef SUBSTITUTE_BREAKPOINT
    getchar();
#endif
    
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
    
//    shared_ptr<test_sft> ts(new test_sft());
//    shared_ptr<test_sft> other = ts->get_ptr();
    
//    TestReserveAffect();
    
//    TestIgnite();
//    for (int i=0; i<2; ++i)
//        TestScanLargeFile();
    
//    size_t cnum(0);
//    native::CustomHelper::QueryCpuNum(cnum);
    
//    TestSharedPtr();
//    for (int i=0; i<100; ++i) {
//        cout << "\rDemo " << i << std::flush;
//    }
    
//    TestRWJson();
//    TestJsonFunction();
    
//    TestWrapMalloc(5);
    
//    TestPrintScanfFloat();
    
//    setenv("MALLOC_TRACE", "memory_leak_test.log", 1);
//    mtrace();
//    {
//        CompletelyClearVector();
//    }
//    muntrace();
    
    CompareVectorAndList();
    
    cout << "\n<<< success >>>\n";
#ifdef SUBSTITUTE_BREAKPOINT
    getchar();
#endif
    
    
  
    return 0;
}

