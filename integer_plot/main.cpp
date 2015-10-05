/* 
 * File:   main.cpp
 * Author: khanh
 *
 * Problem 5: Iteration vs Recursion
 * Make a sorted integer array a[i]=i, i=0,...,n-1. Let bs(a,n,x) be a binary 
 * search program that returns the index i of array a[0..n-1] where a[i]=x. 
 * Obviously, bs(a,n,x)=x, and the binary search function can be tested using 
 * the loop for(j=0; j<K; j++) for(i=0; i<n; i++) if(bs(a,n,i) != i) 
 * cout << “\nERROR”; Select the largest n your software can support and 
 * then K so that this loop with an iterative version of bs runs 3 seconds 
 * or more. Then measure and compare this run time and the run time of the loop 
 * that uses a recursive version of bs. Compare these run times using maximum 
 * compiler optimization (release version) and the slowest version (minimum 
 * optimization or the debug version). If you use a laptop, make measurements 
 * using AC power, and then same measurements using only the battery. 
 * What conclusions can you derive from these experiments? Who is faster? Why?
 */

#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <time.h>
#define N 100
using namespace std;
int binarySearchRecursive(int array[], int n, int x);
int binarySearchIterative(int array[], int n, int key);
/*
 * 
 */
int main() {
    int array[]= {},K = 1000, i = 0,j = 0;
    clock_t time_start, time_end;
    float run_time;
    // initialize array to zero's
    for( i = 0; i < N; i++) array[i] = 0;
    
    /*// recursive search
    time_start = clock();
    for(i = 0; i < K; i++)
        for(j = 0; j < N; j++)
            if (binarySearchRecursive(array,N,j) != i) cout << "\nERROR";
    time_end = clock(); 
    // calculate time differences
    run_time = ((float)time_end - (float)time_start);
    cout << "Run Time Recurse: " << run_time << endl; 
    */
    //iterator search
    time_start = clock();
    for(i = 0; i < K; i++)
        for(j = 0; j < N; j++)
            if (binarySearchIterative( array, N, j) != i) cout << "\nERROR";
    time_end = clock(); 
    // calculate time differences
    run_time = ((float)time_end - (float)time_start);
    cout << "Run Time Iterator: " << run_time << endl; 
    return 0;
}
/*
 * Recursive binary search function which returns the index of the key in
 * the array or if none is found then -1 is returned.
 */
int binarySearchRecursive(int array[N], int n, int key)
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
int binarySearchIterative(int array[N], int n, int key)
{
    int low = 0,high = n - 1, mid = 0;
    while(low <= high)
    {
        mid = (low + high) / 2;
        if (array[mid] >  key) high = mid - 1;
        else if (array[mid] < key) low = mid + 1;
        else return mid ;    
    }
    return -1;
}

