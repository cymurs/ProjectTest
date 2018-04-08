/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   time_interval_2_file.hpp
 * Author: root
 *
 * Created on 2018年3月30日, 下午5:23
 */

#ifndef TIME_INTERVAL_2_FILE_HPP
#define TIME_INTERVAL_2_FILE_HPP


#ifndef WIN32
//#include <sys/time.h>
#include <chrono>
#else
#include <ctime>
#endif // GCC

#include <fstream>
#include <mutex>
using std::ofstream;
using std::string;
using std::mutex;
using std::lock_guard;
using std::ios;
using namespace chrono;

class TimeInterval2File
{
public:
    TimeInterval2File(const string& f, const string& d) : outfile(f, ios::out | ios::app), detail(d), suspend(duration<int>(0))
    {
        init();
    }    
    
    TimeInterval2File(const string& f) : outfile(f), suspend(duration<int>(0))
    {
        init();
    }
    
    TimeInterval2File(TimeInterval2File& obj) = delete;
    TimeInterval2File& operator=(TimeInterval2File& obj) = delete;    
    
    ~TimeInterval2File()
    {
        if (outfile.is_open())
            outfile.close();
    }

    TimeInterval2File& operator()(const string& d) 
    {
        detail.assign(d);
    }
    
    void start() {
#ifndef WIN32
//        gettimeofday(&begin, NULL);
//        begin = {begin.tv_sec - suspend.tv_sec, begin.tv_usec - suspend.tv_usec);
        begin = system_clock::now();
        begin -= suspend;
#else
        begin = clock();
        begin -= suspend;
#endif // GCC                
    }
    
    void stop() {
        lock_guard<mutex> lck(mtx);
#ifndef WIN32
//        gettimeofday(&end, NULL);
//        outfile << detail 
//            << 1000 * (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000 
//            << " ms" << endl;
        end = system_clock::now();
        outfile << detail
                << duration_cast<milliseconds>(end - begin).count() << " ms" << endl;                
#else
        end = clock();
        outfile << detail 
            << (double)(end - begin) << " ms" << std::endl;
#endif // GCC        
    }
    
    void pause() {
#ifndef WIN32
//        gettimeofday(&suspend, NULL);
        system_clock::time_point temp = system_clock::now();        
#else
        suspend = clock();
#endif // GCC              
        suspend = temp - begin;
    }
    
    void reset() {
        suspend = duration<int>(0);
    }
    
protected:
    void init() {
        
    }
private:
    string detail;
    ofstream outfile;
    mutex mtx;
#ifndef WIN32
//    timeval begin, end, suspend;
    system_clock::time_point begin, end;
    system_clock::duration suspend;
#else
    clock_t begin, end, suspend;
#endif // GCC
};

#endif /* TIME_INTERVAL_2_FILE_HPP */

