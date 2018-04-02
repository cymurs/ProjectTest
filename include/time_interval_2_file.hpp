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

#ifdef GCC
#include <sys/time.h>
#else
#include <ctime>
#endif // GCC

#include <fstream>
#include <mutex>
using std::ofstream;
using std::string;
using std::mutex;
using std::lock_guard<mutex>;

class TimeInterval2File
{
    TimeInterval2File(ofstream&& rhs, const string& d) : outfile(rhs), detail(d)
    {
        init();
    }

    TimeInterval2File(ofstream&& rhs)
    {
        init();
    }
    
    ~TimeInterval2File()
    {
        outfile.close();
    }

    TimeInterval2File& operator()(const string& d) 
    {
        detail.assign(d);
    }
    
    void begin() {
#ifdef GCC
        gettimeofday(&begin, NULL);
#else
        begin = clock();
#endif // GCC
    }
    
    void end() {
        lock_guard<mutex> lck(mtx);
#ifdef GCC
        gettimeofday(&end, NULL);
        outfile << detail 
            << 1000 * (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000 
            << " ms" << endl;
#else
        end = clock();
        outfile << detail 
            << (double)(end - begin) << " ms" << std::endl;
#endif // GCC        
    }
    
protected:
    void init() {
        
    }
private:
    string detail;
    ofstream outfile;
    mutex mtx;
#ifdef GCC
    timeval begin, end;
#else
    clock_t begin, end;
#endif // GCC
};

#endif /* TIME_INTERVAL_2_FILE_HPP */

