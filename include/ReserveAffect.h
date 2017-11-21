/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ReserveAffect.h
 * Author: root
 *
 * Created on 2017年11月20日, 上午11:03
 */

#ifndef RESERVEAFFECT_H
#define RESERVEAFFECT_H
#include "share.h"

void TestReserveAffect() {
    vector<int> a;
    cout << a.size() << " " << a.capacity() << endl;
    a.reserve(20);
    cout << a.size() << " " << a.capacity() << endl;
}

#endif /* RESERVEAFFECT_H */

