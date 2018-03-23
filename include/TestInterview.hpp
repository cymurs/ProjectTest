/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TestInterview.hpp
 * Author: root
 *
 * Created on 2018年3月23日, 上午9:23
 */

#ifndef TESTINTERVIEW_HPP
#define TESTINTERVIEW_HPP

void TestInterview() {
    int arr[] = {1, 2, 3, 4, 5};
    int *ptr1 = (int *)(&arr + 1);
    int *ptr2 = (int *)((long)arr + 1);
    
    printf("%x,%x\n", ptr1[-2], *ptr2);  // 4,2000000
}

#endif /* TESTINTERVIEW_HPP */

