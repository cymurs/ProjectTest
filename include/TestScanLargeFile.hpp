/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TestScanLargeFile.hpp
 * Author: root
 *
 * Created on 2018年1月8日, 上午9:11
 */

#ifndef TESTSCANLARGEFILE_HPP
#define TESTSCANLARGEFILE_HPP

#include "share.h"
#include <ignite/ignite.h>
#include <ignite/ignition.h>
#include <fstream>

using namespace ignite;
using namespace ignite::cache;
using namespace ignite::cache::query;

extern const char* SCAN_TEST_CACHE;

void TestScanLargeFile() {
    IgniteConfiguration cfg;
    /*
     * 方法1
     *      
    cfg.jvmInitMem = 2000;
    cfg.jvmMaxMem = 3000;//6144;
     */
//    /*
//     * 方法2
//     *      
    cfg.jvmOpts.emplace_back("-Xms1g");
    cfg.jvmOpts.emplace_back("-Xmx3g");
//     */
    cfg.springCfgPath = "/home/==ProjectTest==/config/query-example.xml";
    std::string inputPath= "/home/==CanDel/18_50_sift/";
    std::string outputPath = "/home/==CanDel/50_sift";
    
    try {
        // Start a node.
        Ignite ignite = Ignition::Start(cfg);
        
        std::cout << std::endl;
        std::cout << ">>> Cache query example started." << std::endl;
        std::cout << std::endl;
        
        // Get testing cache instance.
        Cache<int32_t, std::string> testingCache = ignite.GetCache<int32_t, std::string>(SCAN_TEST_CACHE);
        
        std::set<int32_t> key_set;
        /*
        int count = 0;
        while (count < 50) {
       */
        boost::filesystem::recursive_directory_iterator rdi(inputPath);
        boost::filesystem::recursive_directory_iterator end_rdi;
                
                
        int prev_size = 0;
        char *buf = nullptr;        
        std::string ext(".key");
        for (; rdi != end_rdi; ++rdi) {
            if (ext.compare((*rdi).path().extension().string()) == 0) {
                try {
                    if ( boost::filesystem::is_regular_file(rdi->status()) ) {                        
                        int size = boost::filesystem::file_size((*rdi).path());
                        if (size > prev_size) {
                            if (buf != nullptr) delete[] buf;
                            buf = new char[size+1];
                            buf[size] = '\0';
                            prev_size = size;
                        } 
                        memset(buf, 0, prev_size);

                        
                        IgniteError pe;
                        boost::filesystem::ifstream ifs((*rdi).path());
                        std::string filename = (*rdi).path().filename().string();
                        int num = std::stoi(filename.substr(filename.find_last_of('_')+1));
                        ifs.read(buf, size);
                        testingCache.Put(num, buf, pe);
                        key_set.insert(num);
                        
//                        printf("Result is %d(%s)\n", pe.GetCode(), pe.GetText());
                        
                        ifs.close();
                    }
                } catch (const std::exception& e) {
                    printf("An error occurred in iteratoring directory: %s\n\n", e.what());
                }
            }
        }
        
        delete[] buf;
        printf("All entries cached on this node:%d\n", testingCache.LocalSize());
        /*
        IgniteError ce;
        testingCache.Clear(ce);
        printf("Clear cache:%s, empty=%d\n", ce.GetText(), testingCache.IsEmpty());
                
        key_set.clear();
        ++count;
        }
        */
//        /*
//         * 方法1：根据键值得到全部键值对
//         *         
        IgniteError te;
        std::map<int32_t, std::string> testingMap;
        testingMap = testingCache.GetAll(key_set, te);
        printf("Total count=%d, %d(%s)\n\n", testingMap.size(), te.GetCode(), te.GetText());
//        */
        /*
         * 方法2：根据键值逐个得到所存值
         * 
        IgniteError se;
        for (int32_t key : key_set) {
            if (testingCache.ContainsKey(key, se)) {
                std::string val = testingCache.Get(key);
                cout << "Current element:" << key << "=" << val.size() << endl;
                
                ofstream ofs(outputPath + "/sift_" + std::to_string(key) + ".key");
                ofs << val;
            
                ofs.close();
            } else {
                printf("Current result is %d(%s)\n\n", se.GetCode(), se.GetText());
            }
        }
        */
        // 方法3：利用ScanQuery获取索引，然后再遍历得到所存值
        IgniteError e;
        QueryCursor<int32_t, std::string> testingCursor = testingCache.Query(ScanQuery(), e);
        printf("Result is %d(%s)\n\n", e.GetCode(), e.GetText());
        
//        /*
//         * 方法3-1
//         * 
        IgniteError ace;
        vector< CacheEntry<int32_t, std::string> > vecEntry;
        testingCursor.GetAll(vecEntry, ace);
        printf("Cursor GetAll is %d(%s)\n\n", ace.GetCode(), ace.GetText());
        for (CacheEntry<int32_t, std::string>& c : vecEntry) {
            ofstream ofs(outputPath + "/sift_" + std::to_string(c.GetKey()) + "_from_cursor.key");
            ofs << c.GetValue();
            
            ofs.close();
        }
//       */
        /*
         * 方法3-2
         * 
        IgniteError ne;
        while (testingCursor.HasNext(ne)) {
            IgniteError ie;
            CacheEntry<int32_t, std::string> testingEntry = testingCursor.GetNext(ie);
            printf("testingCursor::GetNext:%d(%s)\n", ie.GetCode(), ie.GetText());
            
            int key = testingEntry.GetKey();
            std::string val = testingEntry.GetValue();
            
            cout << "Current Entry:" << key << "=" << val.size() << endl << endl;
            
            ofstream ofs(outputPath + "/sift_" + std::to_string(key) + ".key");
            ofs << val;
            
            ofs.close();
        }
        printf("HasNext result is %d(%s)\n\n", ne.GetCode(), ne.GetText());
        */
         
        Ignition::Stop(true);
    } catch (IgniteError& err) {
        printf("An error occurred: %d(%s)\n", err.GetCode(), err.GetText());
    }
}

#endif /* TESTSCANLARGEFILE_HPP */

