/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   configuration.h
 * Author: root
 *
 * Created on 2017年9月20日, 下午4:14
 */

#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include "share.h"

struct configuration {
    ostream& operator<<(ostream& os, const configuration& cfg ) {
        os << cfg.name << "=";
        if (!cfg.value.empty()) {
            if (typeid(int) == cfg.value.type()) {
                os << boost::any_cast<int>(cfg.value);
            } else if (typeid(float) == cfg.value.type()) {
                os << boost::any_cast<float>(cfg.value);
            } else {
                os << boost::any_cast<string>(cfg.value);
            }
        }
        return os;
    }
    
    configuration(const string& key, boost::any& value)
            : name(key), value(value) {}
    
    string name;
    boost::any value;
};

#endif /* CONFIGURATION_H */

