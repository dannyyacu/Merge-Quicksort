/*
 * Name:
 * Date Submitted:
 * Lab Section:
 * Assignment Name:
 */

#pragma once

#include <vector>

template <class T>
std::vector<T> merge(std::vector<T> left, std::vector<T> right){
    std::vector<T> result(left.size() + right.size());
    int leftPointer = 0;
    int rightPointer = 0;
    int resultPointer = 0;
    while(leftPointer < left.size() || rightPointer < right.size()){
        if(leftPointer < left.size() && rightPointer < right.size()){
            if(left[leftPointer] <= right[rightPointer]){
                result[resultPointer++] = left[leftPointer++];
            }
            else{
                result[resultPointer++] = right[rightPointer++]; 
            }
        }
        else if(leftPointer < left.size()){
            result[resultPointer++] = left[leftPointer++];
        }
        else if(rightPointer < right.size()){
            result[resultPointer++] = right[rightPointer++];
        }
    }
    return result;
}


template <class T>
std::vector<T> mergeSort(std::vector<T> lst){
    if(lst.size() <= 1){
        return lst;
    }
    int middle = (lst.size())/2;
    std::vector<T> leftVector(middle);
    std::vector<T> rightVector;
    int rightSize = rightVector.size();

    if(lst.size()%2 == 0){
        rightSize = middle;
        rightVector.resize(rightSize);
    }
    else{
        rightSize = middle + 1;
        rightVector.resize(rightSize);
    }
    for(int i = 0; i < middle; i++){
        leftVector[i] = lst[i];
    }
    for(int j = 0; j < rightVector.size(); j++){
        rightVector[j] = lst[middle+j];
    }
    std::vector<T> result(lst.size());
    leftVector = mergeSort(leftVector);
    rightVector = mergeSort(rightVector);
    result = merge(leftVector, rightVector);
    return result;
}

template <class T>
void swap(std::vector<T> &lst, int a, int b)
{
    T t = lst[a];
    lst[a] = lst[b];
    lst[b] = t;
}

template <class T>
int partition(std::vector<T> &lst, int low, int high){
    int pivotIndex = rand()%(high-low + 1) + low;
    T pivot = lst[pivotIndex];
    swap(lst, pivotIndex, low);
    pivotIndex = low;
    for(int j = low + 1; j <= high; j++){
        if(lst[j] < pivot){
            pivotIndex++;
            swap(lst, pivotIndex, j);
        }
    }
    swap(lst, low, pivotIndex);
    return pivotIndex;
}


template <class T>
void quickSort(std::vector<T> &lst, int low, int high){
    if(low < high){
        int partitionIndex = partition(lst, low, high);
        quickSort(lst, low, partitionIndex - 1);
        quickSort(lst, partitionIndex + 1, high);
    }
}

template <class T>
std::vector<T> quickSort(std::vector<T> lst){
    int low = 0;
    int high = lst.size() - 1;
    if(low < high){
        int partitionIndex = partition(lst, low, high);
        quickSort(lst, low, partitionIndex - 1);
        quickSort(lst, partitionIndex + 1, high);
    }
    return lst;
}

