/*
 * Name:
 * Date Submitted:
 * Lab Section:
 * Assignment Name:
 */

#pragma once

#include <vector>

template <class T>
int linearSearch(std::vector<T> data, T target){
    int i = 0;
    for(auto x : data){
        if(x == target){
            return i;
        }
        else{
            i++;
        }
    }
        return -1;
}


template <class T>
int binarySearch(std::vector<T> data, T target){
    int left = 0;
    int right = data.size() - 1;
    while(left <= right){
        int middle = (left + right)/2;
        if(data[middle] == target)
            return middle;
        else if(target < data[middle])
            right = middle - 1;
        else
            left = middle + 1;
    }
    return -1;
}
