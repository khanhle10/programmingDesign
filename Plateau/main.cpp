/* 
 * File:   main.cpp
 * Author: khanh
 *
 * 
 */

#include <cstdlib>
#include <iostream>
using namespace std;
int max_len(int array[], int size);
/*
 * 
 */
int main() 
{
    int array[14] = {1,1,1,2,3,3,5,6,6,6,6,6,7,9}, size = 13;
    cout << max_len(array, size) << endl;
    return 0;
}

int max_len(int array[], int size)
{
   int previous = array[0], count = 1, i = 0;
   for (i = 1; i < size; i++)
      (array[i] == previous)? count++: previous = array[i], count = 1;
   return count;
}
