/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CreateListOfFileInDir.hpp
 * Author: root
 *
 * Created on 2017年10月18日, 上午9:16
 */

#ifndef CREATELISTOFFILEINDIR_HPP
#define CREATELISTOFFILEINDIR_HPP
#include <fstream>

#include "share.h"

void CreateListOfFile(const string& dir) {
    boost::filesystem::path p(dir);
    set<string> file_set;
    if (boost::filesystem::exists(p)) {
        bool bIsDirectory = boost::filesystem::is_directory(p); //判断file_path是否为目录  
        boost::filesystem::recursive_directory_iterator beg_iter(p);  
        boost::filesystem::recursive_directory_iterator end_iter;  
        for (; beg_iter != end_iter; ++beg_iter)  
        {  
            if (boost::filesystem::is_directory(*beg_iter))  
            {  
                continue;  
            }  
            else  
            {     
                std::string strPath = beg_iter->path().string();  //遍历出来的文件名  
                file_set.insert(strPath);  
            }  
        }  
    }
    
    ofstream out(dir + "/list.txt");
    ofstream out_app(dir + "/listf1.txt");
    if (!file_set.empty()) {
        for (auto iter = file_set.begin(); iter != file_set.end(); ++iter) {
            out << *iter << "\n";
            out_app << *iter << " 0 1387.09677" << "\n";
        }
    }
    out.close();
    out_app.close();
}

#endif /* CREATELISTOFFILEINDIR_HPP */

