#pragma once
#include <fstream>
#include <stdio.h>
#include <conio.h>
#include <iostream>

using namespace std;

struct Vector;

Vector sum(Vector a, Vector b);
double Scalar_Multiplication(Vector a, Vector b);
double norm(Vector a);
Vector Multiplication_by_scalar(Vector a, double b);
void Output_console(Vector a);
void Input_Bin(Vector* a);
long long Binom_coef(int n, int k);
void Task_1();
int StrToInt(char* s, int& i);
void Task_3();
void Task_2();
void Task_4();

int main();
int menu();