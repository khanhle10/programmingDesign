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
void generatePoints(float x[], float y[], int n, int x1, int 3);
void calculate(int x1, int x2, int x3, int y1, int y2, int y3, int n);
void cal_coeffi_cramers(int x1, int y1, int x2, int y2, int x3, int y3);
void cal_coeffi_lagrange(int x1, int y1, int x2, int y2, int x3, int y3);

/*
 * 
 */
int main() {
    //Test points
    int x1 = 1, x2 = 3, x3 = 5, y1 = 2, y2 = 9, y3 = 25, n = 40;
    float x[n], y[n];
    // int x1 = 0, x2 = 0, x3 = 0, y1 = 0, y2 = 0, y3 = 0;
    generatePoints(x,y,n, x1,x3);
    calculate(x1, x2, x3, y1, y2, y3, n);
    
    return 0;
}

void generatePoints(float x[], float y[], int n, int x1, int x3)
{
    int i = 0;
    double value = (4 * 3.145) / (n - 1), begin_x = x1;
    for(i = 0; i < n; i++,  begin_x += value)
    {
        x[i] = begin_x;
        y[i] = sin(2 * begin_x) / begin_x;
        
    }
}

void calculate(int x1, int x2, int x3, int y1, int y2, int y3, int n)
{
    if((x1 != x2) && (x1 != x3) && (x2 != x3))
    {
        cal_coeffi_cramers( x1, y1, x2, y2, x3, y3);
        cal_coeffi_lagrange( x1, y1, x2, y2, x3, y3);
    }else
    {
        cout << "Error! All values Must Be Unique." << endl;
    }
}

int cal_determinant(int a, int b, int c, int d, int e, int f, int g, int h, int i)
{
    return a*(e * i - f * h) - b*(d * i - f * g) + c*(d * h - e * g);
}
void cal_coeffi_cramers(int x1, int y1, int x2, int y2, int x3, int y3)
{
    cout << "Cramer's Coefficients" << endl;
    int determ = cal_determinant(x1 * x1, x1, 1, x2 * x2, x2, 1, x3 * x3, x3, 1); 
    int a = -1, b = -1, c = -1; 
    if(determ == 0)
    {
        cout << "Determinant of Coefficient Matrix Is Zero!";
    }else
    {
        //calculating coefficients of y = ax^2 + bx + c 
        a = cal_determinant( y1, x1, 1, y2, x2, 1, y3, x3, 1) / determ;
        b = cal_determinant( x1 * x1, y1, 1, x2 * x2, y2, 1, x3 * x3, y3, 1) / determ;
        c = cal_determinant( x1 * x1, x1, y1, x2 * x2, x2, y2, x3 * x3, x3, y3) / determ;
    }
    cout << a << " " << b << " " << c << endl;
    
}
void cal_coeffi_lagrange(int x1, int y1, int x2, int y2, int x3, int y3)
{
    cout << "Lagrange's Coefficients" <<endl;
    float denom, denom2, denom3, a, b, c;
    denom = (x1 - x2) * (x1 - x3);
    denom2 = (x2 - x1) * (x2 - x3);
    denom3 = (x3 - x1) * (x3 - x2);
    a = ((y1 / denom) + (y2 / denom2) + (y3 / denom3));
    b = -(((y1 * (x2 + x3)) / denom) + ((y2 * (x1 + x3)) / denom2) + 
                                               ((y3 * (x1 + x2)) / denom3));
    c = (((y1 * x2 * x3) / denom) + ((y2 * x1 * x3) / denom2) + 
                                               ((y3 * x1 *x2) / denom3));
    cout << a << " " << b << " " << c << endl;
}
/* Outputs:
 Cramer's Coefficients
1 -1 1
Lagrange's Coefficients
1.125 -1 1.875

RUN FINISHED; exit value 0; real time: 0ms; user: 0ms; system: 0ms

 
 
 */