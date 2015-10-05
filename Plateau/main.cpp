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
    // initialized array of specific size in sorted ascending order 
    int array[14] = {1,1,1,2,3,3,5,6,6,6,6,6,7,9}, size = 14;
    cout << "Max value count: " << max_len(array, size) << endl;
    return 0;
}
/* Pass in array data type int, and array size of data type int.
 * Program: loop through array and find the maximum count of a value that appear
 */
int max_len(int array[], int size)
{
   int previous = array[0], count = 1, i = 0, maxCount = 1;
   for (i = 1; i < size; i++)
      (array[i] == previous)? count++: (previous = array[i],
              (maxCount < count)? maxCount = count : count = 1);
   return maxCount;
}
/* Outputs:
 Max value count: 5

RUN FINISHED; exit value 0; real time: 0ms; user: 0ms; system: 0ms 
 */

