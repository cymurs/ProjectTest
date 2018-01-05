/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TestIgnite.hpp
 * Author: root
 *
 * Created on 2017年12月14日, 下午3:43
 */

#ifndef TESTIGNITE_HPP
#define TESTIGNITE_HPP

#include "share.h"
#include <ignite/ignite.h>
#include <ignite/ignition.h>


using namespace ignite;
using namespace ignite::cache;
using namespace ignite::cache::query;

const char* SCAN_TEST_CACHE = "ScanTest";

void TestIgnite() {
    IgniteConfiguration cfg;
    cfg.springCfgPath = "/home/==ProjectTest==/config/query-example.xml";
    
    try {
        // Start a node.
        Ignite ignite = Ignition::Start(cfg);
        
        std::cout << std::endl;
        std::cout << ">>> Cache query example started." << std::endl;
        std::cout << std::endl;
        
        // Get testing cache instance.
        Cache<int32_t, std::string> testingCache = ignite.GetCache<int32_t, std::string>(SCAN_TEST_CACHE);
        
        testingCache.Put(1, "hello");
        testingCache.Put(2, "world");
        
        IgniteError e;
        QueryCursor<int32_t, std::string> testingCursor = testingCache.Query(ScanQuery(), e);
        printf("Result is %d(%s)\n\n", e.GetCode(), e.GetText());
        
        while (testingCursor.HasNext()) {
            IgniteError ie;
            CacheEntry<int32_t, std::string> testingEntry = testingCursor.GetNext(ie);
            printf("testingCursor::GetNext:%d(%s)\n", ie.GetCode(), ie.GetText());
            
            cout << "Current Entry:" << testingEntry.GetKey() << "=" << testingEntry.GetValue() << endl << endl;
        }
        
        
    } catch (IgniteError& err) {
        printf("An error occurred: %d(%s)\n", err.GetCode(), err.GetText());
    }
    
    
}


#endif /* TESTIGNITE_HPP */

