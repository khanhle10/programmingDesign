/* 
 * File:   main.cpp
 * Author: khanh
 *
 * Created on October 3, 2015, 2:56 PM
 */

#include <cstdlib>
#define CHAR_BIT 8;
using namespace std;
void reduce(int *array, int *n);
void sort(int *value, int *value2, int *value3);
void print(int *array, int *n);
void min(int *value, int *value2, int *value3);
/*
 * 
 */
int main() {
    int *array = {9,1,1,6,7,1,2,3,3,5,6,6,6,6,7,9}, *size = 16;
    reduce(&array, &size);
    print(&array, &size);
    return 0;
}
// 911/6
void reduce(int *array, int *size)
{
  int *max_value = *array,*max_value2 = *array[1],*max_value3 = *array[2],i = 0;
  sort(&array, *size);
  for(i = 3; i < *size; i++)
    (*max_value < *array[i])? *max_value = *array[i], i++:i++ ;
    
}
// 1 2 3 / 2 3 1 
void min(int *value, int *value2, int *value3)
{
   int temp = 0;
   if((value < value2) && (value < value3))
   {
       cout << "Nothing Change" << endl;
   }else if(value2 > value3) 
   {
       temp = value3, value = value3, value3 = temp;
   }else
       temp = value3, value3 = value, value = temp;   
}