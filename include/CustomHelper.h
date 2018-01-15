/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CustomHelper.h
 * Author: root
 *
 * Created on 2018年1月12日, 下午1:33
 */

#ifndef CUSTOMHELPER_H
#define CUSTOMHELPER_H

namespace native {

class CustomHelper {
public:
    CustomHelper();
    CustomHelper(const CustomHelper& orig);
    virtual ~CustomHelper();
    
    static void QueryCpuNum(size_t& cnum);
private:

};

}
#endif /* CUSTOMHELPER_H */

