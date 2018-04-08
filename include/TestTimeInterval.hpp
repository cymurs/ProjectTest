/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#ifndef TEST_TIME_INTERVAL_H
#define TEST_TIME_INTERVAL_H

#include "time_interval_2_file.hpp"


void TestTimeInterval() {
    printf("Current time is %ld\n", duration<int>(0));
    
    TimeInterval2File timeSpent("/home/testTimeInterval.log", "First run: ");
    for (int idx=0; idx<5; ++idx) {
        timeSpent.start();
        if (idx & 0x1)
            std::this_thread::sleep_for(std::chrono::seconds(5));
        else
            std::this_thread::sleep_for(std::chrono::milliseconds(5000));
        timeSpent.pause();
    }
    timeSpent.start();
    timeSpent.stop();
}

#endif
