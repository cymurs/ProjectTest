/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TestZlib.hpp
 * Author: root
 *
 * Created on 2018年4月10日, 上午9:31
 */

#ifndef TESTZLIB_HPP
#define TESTZLIB_HPP

#include "zlib/zlib.h"



void TestZlib() {
    unsigned char szSrc[] = "The source code of these utility functions can be modified if you need special options.";
    ulong srcLen = strlen((const char *)szSrc);
    unsigned char *szDest = new unsigned char[128]();
    ulong destLen = 128;
    unsigned char *szSrcEx = new unsigned char[128]();
    ulong srcExLen = 128;
    
    int ret = compress2(szDest, &destLen, szSrc, srcLen, 0);
    if (Z_OK == ret)
        ret = uncompress2(szSrcEx, &srcExLen, szDest, &destLen);
    printf("0: src=%s, src_len=%d, result=%d\n", szSrcEx, srcExLen, ret);
    memset(szDest, '\0', 128);
    destLen = 128;
    memset(szSrcEx, '\0', 128);
    srcExLen = 128;
    
    
    ret = compress2(szDest, &destLen, szSrc, srcLen, 1);   
    if (Z_OK == ret)
        ret = uncompress2(szSrcEx, &srcExLen, szDest, &destLen);
    printf("1 (best speed): src=%s, src_len=%d, dest=%d, result=%d\n", szSrcEx, srcExLen, destLen, ret);
    memset(szDest, '\0', 128);
    destLen = 128;
    memset(szSrcEx, '\0', 128);
    srcExLen = 128;
    
    ret = compress2(szDest, &destLen, szSrc, srcLen, 9);
    if (Z_OK == ret)
        ret = uncompress2(szSrcEx, &srcExLen, szDest, &destLen);
    printf("9 (best compression): src=%s, src_len=%d, dest=%d, result=%d\n", szSrcEx, srcExLen, destLen, ret);
    
    
    delete[] szDest;
}

#endif /* TESTZLIB_HPP */

