/* 
 * File:   main.cpp
 * Author: khanh
 *
 * Problem 4:
 * Write a program BigInt(n) that displays an arbitrary positive integer n
 * using big characters of size 7X7, as in BigInt(170)
 * 
 */

#include <cstdlib>
#include <stdio.h>
#include <iostream>
using namespace std;

#define DIMENSION 7
void BigInt(int digits);
void get_Digit_Matrix(int digits, char matrix[][]);
void assign_Matrix(char assign_Matrix[][], char matrix[][]);
void append_Matrix(char assign_Matrix[][], char matrix[][], int count);
void print_Matrix(char matrix[][], int size);
/*
 * 
 */
int main() 
{
    int input;
    cout << "Please enter any integer value: ", cin >> input;
    while(cin.fail()) 
    {
      cout << "Error!, please enter integer value only!: "; 
      cin.clear(),cin.ignore(256,'\n'), cin >> input;
    }
    BigInt(input);    
    return 0;
}

void BigInt(int value)
{
    int size = 0, n = value, digits[4], integer_count = 0, i = 0, cal_Size = 0;
    while(n) n /= 10, digits[size] = value%10, size++;
    cal_Size = size*(DIMENSION +1);
    char display_Matrix[DIMENSION][cal_Size];
    char matrix[DIMENSION][DIMENSION];
    for(i = 0; i < size; i++)
    {
        get_Digit_Matrix(digits[i], matrix);
        append_Matrix(display_Matrix, matrix, integer_count);
        integer_count += (DIMENSION + 1);
    }
    print_Matrix(display_Matrix, size);
}

void print_Matrix(char matrix[][], int size)
{
    int i = 0, j = 0;
    for(i = 0; i < DIMENSION; i++){
          for(j = 0; j < size*(DIMENSION+1); j++)
          {
              cout <<matrix[i][j];
          }
          cout << "\n";
    }
}

void append_Matrix(char display_Matrix[][], char matrix[][], int count)
{
    int row = 0, addCol = 0, col = 0, appendCol = 0;
    for(row = 0; row < DIMENSION; row++)
    {
        addCol = count;
        for(col = count, appendCol = 0; col < (DIMENSION + count); ++col, ++appendCol )
            display_Matrix[row][appendCol] = matrix[row][col], addCol++;
    }
    display_Matrix[row][addCol] = ' ';
}

void get_Digit_Matrix(int value, char matrix[][] )
{    
    char matrix0[DIMENSION][DIMENSION] = {' ','@','@','@','@','@',' ',
                                          '@','@','@','@','@','@','@',
                                          '@','@',' ',' ',' ','@','@',
                                          '@','@',' ',' ',' ','@','@',
                                          '@','@',' ',' ',' ','@','@',
                                          '@','@','@','@','@','@','@',
                                          ' ','@','@','@','@','@',' ',};
    
    char matrix1[DIMENSION][DIMENSION] = {' ',' ',' ','@','@',' ',' ',
                                          ' ',' ','@','@','@',' ',' ',
                                          ' ',' ',' ','@','@',' ',' ',
                                          ' ',' ',' ','@','@',' ',' ',
                                          ' ',' ',' ','@','@',' ',' ',
                                          ' ',' ',' ','@','@',' ',' ',
                                          ' ','@','@','@','@','@','@',};
    
    char matrix2[DIMENSION][DIMENSION] = {' ','@','@','@','@','@',' ',
                                          '@','@',' ',' ',' ','@','@',
                                          ' ',' ',' ',' ','@','@','@',
                                          ' ',' ',' ','@','@','@',' ',
                                          ' ',' ','@','@',' ',' ',' ',
                                          '@','@','@','@','@','@','@',
                                          '@','@','@','@','@','@','@',};
    
    char matrix3[DIMENSION][DIMENSION] = {' ','@','@','@','@','@',' ',
                                          '@','@',' ',' ',' ','@','@',
                                          ' ',' ',' ',' ',' ','@','@',
                                          ' ',' ',' ','@','@','@',' ',
                                          ' ',' ',' ','@','@','@','@',
                                          '@','@',' ',' ',' ','@','@',
                                          ' ','@','@','@','@','@',' ',};
    
    char matrix4[DIMENSION][DIMENSION] = {' ',' ',' ',' ','@','@',' ',
                                          ' ',' ',' ','@','@','@',' ',
                                          ' ',' ','@',' ','@','@',' ',
                                          ' ','@',' ',' ','@','@',' ',
                                          '@','@','@','@','@','@','@',
                                          ' ',' ',' ',' ','@','@',' ',
                                          ' ',' ',' ','@','@','@','@',};
    
    char matrix5[DIMENSION][DIMENSION] = {'@','@','@','@','@','@','@',
                                          '@','@',' ',' ',' ',' ',' ',
                                          '@','@','@','@','@','@',' ',
                                          ' ',' ',' ',' ',' ','@','@',
                                          ' ',' ',' ',' ',' ','@','@',
                                          '@','@',' ',' ',' ','@','@',
                                          ' ','@','@','@','@','@',' ',};
    
    char matrix6[DIMENSION][DIMENSION] = {'@','@','@','@','@','@','@',
                                          '@','@',' ',' ',' ',' ','@',
                                          '@','@',' ',' ',' ',' ',' ',
                                          '@','@','@','@','@','@',' ',
                                          '@','@',' ',' ',' ','@','@',
                                          '@','@',' ',' ',' ','@','@',
                                          ' ','@','@','@','@','@',' ',};
    
    char matrix7[DIMENSION][DIMENSION] = {' ','@','@','@','@','@','@',
                                          '@','@',' ',' ',' ','@','@',
                                          ' ',' ',' ',' ','@','@',' ',
                                          ' ',' ',' ','@','@',' ',' ',
                                          ' ',' ','@','@',' ',' ',' ',
                                          '@','@','@',' ',' ',' ',' ',
                                          '@','@',' ',' ',' ',' ',' ',};
    
    char matrix8[DIMENSION][DIMENSION] = {' ','@','@','@','@','@',' ',
                                          '@','@',' ',' ',' ','@','@',
                                          '@','@',' ',' ',' ','@','@',
                                          ' ','@','@','@','@','@',' ',
                                          '@','@',' ',' ',' ','@','@',
                                          '@','@',' ',' ',' ','@','@',
                                          ' ','@','@','@','@','@',' ',};
    
    char matrix9[DIMENSION][DIMENSION] = {' ','@','@','@','@','@',' ',
                                          '@','@',' ',' ',' ','@','@',
                                          '@','@',' ',' ',' ','@','@',
                                          ' ','@','@','@','@','@',' ',
                                          ' ',' ',' ',' ',' ','@','@',
                                          '@','@',' ',' ',' ','@','@',
                                          ' ','@','@','@','@','@',' ',};
    switch( value )
    {
      case 1:
            assign_Matrix(matrix, matrix1);
            break;
      case 2:
            assign_Matrix(matrix, matrix2);
            break; 
      case 3:
            assign_Matrix(matrix, matrix3);
            break;
      case 4:
            assign_Matrix(matrix, matrix4);
            break;   
      case 5:
            assign_Matrix(matrix, matrix5);
            break;
      case 6:
            assign_Matrix(matrix, matrix6);
            break; 
      case 7:
            assign_Matrix(matrix, matrix7);
            break;
      case 8:
            assign_Matrix(matrix, matrix8);
            break;  
      case 9:
            assign_Matrix(matrix, matrix9);
            break;  
      case 0:
            assign_Matrix(matrix, matrix0);
            break;  
      default:
            assign_Matrix(matrix, matrix);
            break;  
    }
                                            
    }

void assign_Matrix(char assignMatrix[DIMENSION][DIMENSION], char matrix[DIMENSION][DIMENSION])
{
    int i = 0, j = 0;
    for(i = 0; i < DIMENSION; i++)
        for(j = 0; j < DIMENSION; j++)
            assignMatrix[i][j] = matrix[i][j];
}    