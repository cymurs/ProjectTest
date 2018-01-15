/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CustomHelper.cpp
 * Author: root
 * 
 * Created on 2018年1月12日, 下午1:33
 */

#include <unistd.h>
#include <istream>
#include <fstream>

#include "CustomHelper.h"

namespace native {

CustomHelper::CustomHelper() {
}

CustomHelper::CustomHelper(const CustomHelper& orig) {
}

CustomHelper::~CustomHelper() {
}

void CustomHelper::QueryCpuNum(size_t& cnum) {
    /*
     * 方法1
     * 
    std::ifstream ifstr("/proc/cpuinfo", std::ifstream::binary);    
    std::filebuf* fbuf = ifstr.rdbuf();
    std::size_t len = fbuf->pubseekoff (0, ifstr.end);
    */
    /*
     * 方法2
     * 
    fbuf->pubseekpos (0, ifstr.in);
    ifstr.seekg(0, ifstr.end);
    int len = ifstr.tellg();
    ifstr.seekg(0, ifstr.beg);
    */
    /*
    char *contents = new char[len];
//    ifstr.read(contents, len);    
    fbuf->sgetn(contents, len);
    
    ifstr.close();
            
    std::string strfind("processor	: ");
    std::string strcont(contents);
    std::size_t found = strcont.rfind(strfind);
    long res = std::stol(strcont.substr(found+strfind.length()));
    cnum = res + 1;
    delete[] contents;
    */
    
    cnum = sysconf(_SC_NPROCESSORS_CONF);
    /*
     * The number of processors currently online (available).
     * 
    int unum = sysconf(_SC_NPROCESSORS_ONLN);
    */
}

}