/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CompareUnordered_mapAndMap.hpp
 * Author: root
 *
 * Created on 2018年3月7日, 上午11:06
 */

#ifndef COMPAREUNORDERED_MAPANDMAP_HPP
#define COMPAREUNORDERED_MAPANDMAP_HPP

#include "share.h"
#include "time_interval.hpp"

/// 返回大于1.5 * num的第一个素数
inline size_t get_hash_table_size(unsigned int num) {
    size_t return_num = 1.5 * num, i, j;
    while (1) {
        /// 素数判断
        j = (size_t)sqrt(return_num++);
        for (i = 2; i < j; ++i) {
            if (return_num % i == 0)
                break;
        }
        if (i == j)
            return return_num;
    }
}

/// 查询、插入和删除都是unordered_map更快
void CompareUnordered_mapAndMap() {
    cout<<"please input map size: "<<endl;
    int map_size;
    cin>>map_size;

    if (map_size <= 0) {
        return;
    }

    set<int> random_nums_set;

    srand(time(0));
    for (int i = 0; i < map_size; ) {
        int random_nums = rand();
        if (0 == random_nums_set.count(random_nums)) {
            random_nums_set.insert(random_nums);
            ++i;
        }
    }

    map<int, int> map_test;
    unordered_map<int, int> unordered_map_test;
    unordered_map_test.rehash(get_hash_table_size(map_size));

    {
        TIME_INTERVAL_SCOPE("map insert: ");
        for (auto it = random_nums_set.begin(); it != random_nums_set.end(); ++it) {
            map_test.insert(std::make_pair(*it, 0));
        }
    }

    {
        TIME_INTERVAL_SCOPE("unordered_map insert: ");
        for (auto it = random_nums_set.begin(); it != random_nums_set.end(); ++it) {
            unordered_map_test.insert(std::make_pair(*it, 0));
            unordered_map_test[*it] = 100;
        }
    }

    {
        TIME_INTERVAL_SCOPE("map iterator: ");
        for (auto it = map_test.begin(); it != map_test.end(); ++it) {
        }
    }

    {
        TIME_INTERVAL_SCOPE("unordered_map iterator: ");
        for (auto it = unordered_map_test.begin(); it != unordered_map_test.end(); ++it) {
        }
    }     

    {
        TIME_INTERVAL_SCOPE("map delete: ");
        for (auto it = random_nums_set.begin(); it != random_nums_set.end(); ++it) {
            map_test.erase(*it);
        }
//        cout << "map.size=" << map_test.size() << endl;
    }

    {
        TIME_INTERVAL_SCOPE("unordered_map delete: ");
        for (auto it = random_nums_set.begin(); it != random_nums_set.end(); ++it) {
            unordered_map_test.erase(*it);
        }
//        cout << "unordered_map.size=" << unordered_map_test.size() << endl;
    }
}

/// 查询 vector更快，插入和删除list更快且无副作用(没有使迭代器、引用、指针失效)
/// 插入和删除时vector有副作用，尤其在重新分配空间的情况下，会使整个vector的迭代器、指针和引用失效
void CompareVectorAndList() {
    cout<<"please input map size: "<<endl;
    int map_size;
    cin>>map_size;

    if (map_size <= 0) {
        return;
    }

    set<int> random_nums_set;

    srand(time(0));
    for (int i = 0; i < map_size; ) {
        int random_nums = rand();
        if (0 == random_nums_set.count(random_nums)) {
            random_nums_set.insert(random_nums);
            ++i;
        }
    }
    
    vector<int> vector_test;
    list<int> list_test;
    vector_test.reserve(map_size);
    
    {
        TIME_INTERVAL_SCOPE("vector insert: ");
        for (auto it = random_nums_set.begin(); it != random_nums_set.end(); ++it) {
            vector_test.insert(vector_test.begin(), *it);            
        }
        cout << "vector.size=" << vector_test.size();
    }

    {
        TIME_INTERVAL_SCOPE("list insert: ");
        for (auto it = random_nums_set.begin(); it != random_nums_set.end(); ++it) {
            list_test.insert(list_test.begin(), *it);            
        }
        cout << "list.size=" << list_test.size();
    }

    {
        TIME_INTERVAL_SCOPE("vector iterator: ");
        for (auto it = vector_test.begin(); it != vector_test.end(); ++it) {
        }
    }

    {
        TIME_INTERVAL_SCOPE("list iterator: ");
        for (auto it = list_test.begin(); it != list_test.end(); ++it) {
        }
    }     

    {
        TIME_INTERVAL_SCOPE("vector delete: ");
        for (auto it = random_nums_set.begin(); it != random_nums_set.end(); ++it) {
            vector_test.erase(vector_test.begin());
        }
        cout << "vector.size=" << vector_test.size() << endl;
    }

    {
        TIME_INTERVAL_SCOPE("list delete: ");
        for (auto it = random_nums_set.begin(); it != random_nums_set.end(); ++it) {
            list_test.erase(list_test.begin());
        }
        cout << "list.size=" << list_test.size() << endl;
    }
}
#endif /* COMPAREUNORDERED_MAPANDMAP_HPP */

