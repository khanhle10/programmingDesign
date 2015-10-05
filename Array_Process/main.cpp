/* 
 * File:   main.cpp
 * Author: khanh
 *Problem 3:
 * The array of a(1..n) contains arbitrary integers. Write a function
 * reduce(a, n) that reduces the array a(1..n) by eliminating it all
 * values that are equal to three largest different integers. For example,
 * if a = (9,1,1,6,7,1,2,3,3,5,6,6,6,6,7,9) then largest different integers are
 * 6,7,9 and after reduction the reduced array will be a=(1,1,1,2,3,3,5), n=7.
 * The solution should have time complexity O(n). 
 */

#include <cstdlib>
#include <iostream>

using namespace std;

int* reduce(int *array, int size, int large, int mid, int small, int count);
void print(int array[], int n);
void findLargeValues(int &large, int &mid, int &small, int value, int &count);
/*  take the array and find the three largest values by calling findLargeValues
 *  
 * 
 */
int main() {
    int array[16] = {9,1,1,6,7,1,2,3,3,5,6,6,6,6,7,9};
    int large = 0, mid = 0, small = 0, size = 16, count = 0;
    int i = 0, *newArray;
    for(i = 1; i < size; i++)
      findLargeValues(large, mid, small, array[i], count);
    cout << "The Three Largest Values: "<< large << " " <<
            mid << " " << small << endl;
    newArray = reduce(array, count, large, mid, small, size);
     
    for(i = 0; i < count; i++)
        cout << newArray[i] << " ";
    return 0;
}
/*
 Pass: Array of data type int, along with three large variables, and size of array
 * with new size of array.
 * Return: the new array. 
 */
int* reduce(int *array, int count, int large, int mid, int small, int size)
{
    int *tempArray = new int[count], i = 0, tempCount = 0;
    while( i < size )
    {
      if((array[i] != large) && (array[i] != mid) && (array[i] != small))
      {
          tempArray[tempCount] = array[i],tempCount++;
      }
      i++;
    }
    return tempArray;
    
}

/* Pass in large, medium, small variables of data type int
   Program: compare passed in variable with the three suggested values.
 * the returned variables 
 */
void findLargeValues(int &large, int &mid, int &small, int value, int &count)
{
    if(value > large)
    { 
        small = mid, mid = large, large = value, count++;
    }else if ((value > mid) && (value < large))
    {
        small = mid, mid = value, count++;  
    }else if ((value < mid) && (value > small))
    { 
        small = value, count++;
    }
}
/* Outputs:
 The Three Largest Values: 9 7 6
1 1 1 2 3 3 5 
RUN FINISHED; exit value 0; real time: 0ms; user: 0ms; system: 0ms
 */