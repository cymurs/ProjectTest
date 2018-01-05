/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   share.h
 * Author: root
 *
 * Created on 2017年9月20日, 上午11:58
 */

#ifndef SHARE_H
#define SHARE_H


#include <map>
#include <set>
#include <string>
#include <iostream>
#include <algorithm>
#include <thread>
#include <boost/any.hpp>
//#include <boost/thread.hpp>
#include <boost/filesystem.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>


#define BOOST_DATE_TIME_SOURCE

using namespace std;
namespace BPT = boost::posix_time;
namespace BPP = boost::property_tree;

typedef map<string, boost::any> any_map;

#endif /* SHARE_H */

