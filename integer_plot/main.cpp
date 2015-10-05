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
int binarySearchRecursive(int array[], int n, int x);
int binarySearchIterative(int array[], int , int right, int key);
/*
 * 
 */
int main() {
    int array[]= {},K = 1000, i = 0,j = 0, n = 100;
    for( i = 0; i < n; i++) array[i] = 0;
    // recursive search
    for(i = 0; i < K; i++)
        for(j = 0; j < n; j++)
            if (binarySearchRecursive(array,n,j) != i) cout << "\nERROR";
    
    //iterator search
    
    return 0;
}
/*
 * Recursive binary search function which returns the index of the key in
 * the array or if none is found then -1 is returned.
 */
int binarySearchRecursive(int array[], int n, int key)
{
    int mid = n / 2, result = 0;
    if(array[mid] == key) return mid;
    if(array[mid] < key){
        result = binarySearchRecursive(array+mid+1, n - (mid+1), key); 2; 
        if(result == -1) return -1;
        else return result + mid +1;        
    }
    if(array[mid] > key)
        return binarySearchRecursive(array, mid, key);
    return -1;
}
/*
 * Iterate binary search function which returns the location of the key in
 * the array or if not found then -1 is returned.
 */
int binarySearchIterative(int array[], int n, int key)
{
    int low = 0,high = n - 1, mid = 0;
    while(low <= high)
    {
        mid = (low <= high) / 2;
        if (array[mid] >  key) high = mid - 1;
        else if (array[mid] < key) low = mid + 1;
        else return mid ;    
    }
    return -1;
}

