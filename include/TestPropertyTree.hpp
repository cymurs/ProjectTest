/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TestPropertyTree.hpp
 * Author: root
 *
 * Created on 2018年1月5日, 上午8:45
 */

#ifndef TESTPROPERTYTREE_HPP
#define TESTPROPERTYTREE_HPP

#include "share.h"

void TestRWJson() {
    BPP::ptree root, child, exchild;
    child.put("key", std::string("value"));
//    root.put("a.b.c", std::string("empty"));
    exchild.put_value(std::string("empty"));
    root.push_back(std::make_pair(std::string("192.168.1.1"), exchild));
    
//    root.add_child(std::string("127\.0\.0\.1").c_str(), child);    
    root.push_back(std::make_pair("127.0.0.1", child));    
    
    BPP::write_json(std::cout, root);
}

#endif /* TESTPROPERTYTREE_HPP */

