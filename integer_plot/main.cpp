/* 
 * File:   main.cpp
 * Author: khanh
 *
 * Iteration vs Recursion
 */

#include <cstdlib>
#include <stdio.h>
#include <iostream>
using namespace std;
int binarySearchRecursive(int *array, int large, int small, int x);
int binarySearchIterative(int *array, int left, int right, int key);
/*
 * 
 */
int main(int argc, char** argv) {
    int *array= {7,2,4,1,6,5,3,8,6,3,5,1,3,9,8,5,3,2,5,3},size = 20,i = 0,j = 0;
    int size = sizeof(array)/ sizeof(array[0]), int key = 8;
    // recursive search
    for(i = 0; i < k; i++)
        for(j = 0; j < size; j++)
            (binarySearchRecursive(&array,size,j) != i)? cout << "\nERROR": cout << "Solution: " <<array[i];
    
    //iterator search
    
    return 0;
}
/*
 * Recursive binary search function which returns the index of the key in
 * the array or if none is found then -1 is returned.
 */
int binarySearchRecursive(int *array, int left, int right, int key)
{
    int mid = 0;
    if (right >= left)
    {
        mid = (left+right)/2; 
        if(array[mid] == key) return mid;
        if(array[mid] > key) return binarySearchRecursive(array,left,mid-1,key);
        return binarySearchRecursive(array, mid+1, right, key);
    }
    return -1;
}
/*
 * Iterate binary search function which returns the location of the key in
 * the array or if not found then -1 is returned.
 */
int binarySearchIterative(int *array, int left, int right, int key)
{
    int mid = 0;
    while(left <= right)
    {
        mid = left + (right - left)/2;
        if (array[mid == key]) return mid;
        (array[mid] < key)? left = mid + 1: right = mid -1;    
    }
    return -1;
}

