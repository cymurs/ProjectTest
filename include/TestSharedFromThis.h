/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TestSharedFromThis.h
 * Author: root
 *
 * Created on 2017年11月23日, 下午5:51
 */

#ifndef TESTSHAREDFROMTHIS_H
#define TESTSHAREDFROMTHIS_H
#include <memory>

class test_sft : public std::enable_shared_from_this<test_sft> {
public:
    ~test_sft() {
        std::cout << "destruct test_shared_from_this.\n";
    }
    
    std::shared_ptr<test_sft> get_ptr() {
        return shared_from_this();
    }
    
};

#endif /* TESTSHAREDFROMTHIS_H */

