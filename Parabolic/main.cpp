/* 
 * File:   main.cpp
 * Author: khanh
 *
 * Problem 2:
 * We know three points on a curve: ( x 1 , y 1 ), ( x 2 , y 2 ), ( x 3 , y 3 ). 
 * You have to create a program that for any value x 1  x  x 3 computes the 
 * corresponding value y assuming that the segment of curve can be approximated 
 * with the parabola y = ax^2 + bx + c . Write a function that can be called as
 * y(x1,y1,x2,y2,x3,y3,x) and a main program that reads x1,y1,x2,y2,x3,y3 and 
 * then displays y(x1,y1,x2,y2,x3,y3,x) in n=40 equidistant x points between x1 
 * and x3.
 * 
 */

#include <cstdlib>
#include <iostream>
using namespace std;
int cal_determinant(int a, int b, int c, int d, int e, int f, int g, int h, int i);
void user_inputs(int x1, int y1, int x2, int y2, int x3, int y3);
void cal_coeffi_cramers(int x1, int y1, int x2, int y2, int x3, int y3);
void cal_coeffi_lagrange(int x1, int y1, int x2, int y2, int x3, int y3);

/*
 * 
 */
int main() {
    //Test points
    int x1 = 1, x2 = 3, x3 = 5, y1 = 2, y2 = 9, y3 = 25;
    // int x1 = 0, x2 = 0, x3 = 0, y1 = 0, y2 = 0, y3 = 0;
    cout << "Please enter x and y values to test: ";
    
    while(true)
    {
        cout << "Please enter x and y values to test: ";
    }
    return 0;
}

void void user_inputs(int &x1, int &y1, int &x2, int &y2, int &x3, int &y3)
{
    string inputs = "";
    while(true)
    {
        cout << "Please enter x and y values to test:(2 3 => x1 y1) ";
        getline(cin, inputs);
        if(inputs.length() > 1)
        {
            
        }
    }
}

int cal_determinant(int a, int b, int c, int d, int e, int f, int g, int h, int i)
{
    return a*(e * i - f * h) - b*(d * i - f * g) + c*(d * h - e * g);
}
void cal_coeffi_cramers(int x1, int y1, int x2, int y2, int x3, int y3)
{
    int determ = cal_determinant(x1 * x1, x1, 1, x2 * x2, x2, 1, x3 * x3, x3, 1); 
    int a = -1, b = -1, c = -1; 
    if(determ != 0)
    {
        cout << "Determinant of Coefficient Matrix Is Zero!";
    }else
    {
        //calculating coefficients of y = ax^2 + bx + c 
        a = cal_determinant( y1, x1, 1, y2, x2, 1, y3, x3, 1); 
    }
        
    
}
void cal_coeffi_lagrange(int x1, int y1, int x2, int y2, int x3, int y3);