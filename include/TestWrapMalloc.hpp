/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TestWrapMalloc.hpp
 * Author: root
 *
 * Created on 2018年1月25日, 下午1:17
 */

#ifndef TESTWRAPMALLOC_HPP
#define TESTWRAPMALLOC_HPP

int g_malloc(0);
int g_free(0);

#ifdef __cplusplus
extern "C" {
#endif

void * __real_malloc(size_t c);
void * __wrap_malloc(int size)
{
    g_malloc++;
    printf("Execute malloc once.\n");
    return __real_malloc(size);
}

void __real_free(void *ptr);
void __wrap_free(void *ptr)
{
    g_free++;
    printf("Execute free once.\n");
    __real_free(ptr);
}

#ifdef __cplusplus
}
#endif

void TestWrapMalloc(int cnt) {
    for (int n=0; n<cnt; ++n) {
        char* t = (char *)malloc(cnt * sizeof(char));
        printf("Already malloc [%d]\n", cnt);
        free(t);
    }
    
    if (g_malloc != g_free) printf("Memory leak\n");
}

#endif /* TESTWRAPMALLOC_HPP */

