#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include "Header.h"

using namespace std;

struct Vector { double x, y; };

Vector sum(Vector a, Vector b)
{
	Vector c;
	c.x = a.x + b.x;
	c.y = a.y + b.y;
	return c;
}

double Scalar_Multiplication(Vector a, Vector b) {
	return a.x * b.x + a.y * b.y;
}

double norm(Vector a)
{
	return sqrt(pow(a.x, 2) + pow(a.y, 2));
}

Vector Multiplication_by_scalar(Vector a, double b)
{
	Vector c;
	c.x = b * a.x;
	c.y = b * a.y;
	return c;
}

void Output_console(Vector a)
{
	cout << "Here is Vector:\n";
	cout << '(' << a.x << ", " << a.y << ')';
	cout << "\n\n";
}

void Output_Bin(Vector* a)
{
	ofstream out("Vector.bin");
	out.write((char*)&a, sizeof(Vector));
	out.close();
}

void Input_Bin(Vector* a)
{
	ifstream input("Vector.bin");
	input.read((char*)&a, sizeof(Vector));
	input.close();
}

void Task_2()
{
	Vector a, b;
	double k;
	cout << "Enter 2 Vectors (coordinates):\n";
	cout << "Enter your first vector: ";
	cin >> a.x >> a.y;
	cout << "Enter your second vector: ";
	cin >> b.x >> b.y;
	cout << "Enter scalar: ";
	cin >> k;
	Output_console(a);
	Output_console(b);
	cout << "Sum: ";
	cout << '(' << sum(a, b).x << ", " << sum(a, b).y << ')' << endl;
	cout << "Their scalar multiplication: " << Scalar_Multiplication(a, b) << endl;
	cout << "Norm of first: " << norm(a) << endl;
	cout << "Norm of second: " << norm(b) << endl;
	cout << "Multiplication by scalar (first): " << '(' << Multiplication_by_scalar(a, k).x << ", " << Multiplication_by_scalar(a, k).y << ')' << endl;
	cout << "Multiplication by scalar (second): " << '(' << Multiplication_by_scalar(b, k).x << ", " << Multiplication_by_scalar(b, k).y << ')' << endl;
	Vector m[2];
	m[0] = a;
	m[1] = b;
	Output_Bin(m);
	cout << "Would you like to do another task?\n";
	cout << "If yes, press a space button.";
	char tmp;
	tmp = _getch();
	if (tmp == 32)main();
	else return;
}

long long Binom_coef(int n, int k)
{
	if (k > n) return -1;
	if (n == k || k == 0) return 1;
	else
	{
		return Binom_coef(n - 1, k - 1) + Binom_coef(n - 1, k);
	}
}

void Task_4()
{
	int n, k;
	cout << "There is a binominal coefficient C of n to k.\nEnter n and k: ";
	cin >> n >> k;
	cout << "Here is your binominal coefficient: " << Binom_coef(n, k) << endl;
	cout << "Would you like to do another task?\n";
	cout << "If yes, press a space button.";
	char tmp;
	tmp = _getch();
	if (tmp == 32)main();
	else return;
}

void Task_1()
{
	FILE* f = fopen("text_1.txt", "r");
	char text[1000] = { '\0' };
	fread(text, sizeof(char), 1000, f);
	int i = 0;
	bool flag = false;
	while (i <= strlen(text) - 2)
	{
		if (text[i] == '/' && text[i + 1] == '/')
		{
			text[i] = 32;
			text[i + 1] = 32;
			i += 2;
			while (i <= strlen(text) - 1)
			{
				if (text[i] == 32 && text[i+1]==32)
					flag = true;
				if (flag) break;
				if (text[i] == 10)
				{
					cout << endl;
					break;
				}
				
				cout << text[i];
				text[i] = 32;
				i++;
			}
		}
		i++;
	}
	fclose(f);
	f = fopen("text_1.txt", "w");
	fwrite(text, sizeof(char), i, f);
	fclose(f);
	cout << "\nWould you like to do another task?\n";
	cout << "If yes, press a space button.";
	char tmp;
	tmp = _getch();
	if (tmp == 32)main();
	else return;
}



int StrToInt(char* s, int& i)
{
	int temp = 0;
	int sign = 0;
	if (s[i] == '-')
	{
		sign = 1;
		i++;
	}
	while ((int)s[i] >= 48 && (int)s[i] <= 57)
	{
		temp += ((int)s[i] - 48);
		temp *= 10;
		i++;
	}
	temp /= 10;
	if (sign == 1)
		temp = -temp;
	return temp;
}

void Task_3()
{
	ifstream input("text_3.txt");
	char text[1000] = { '\0' };
	input.read(text, sizeof(text));
	input.close();

	int i = 0;
	int n = StrToInt(text, i);

	int* tmp = new int[n * n];
	int** a = new int* [n];

	for (int ix = 0; ix < n; ix++)
	{
		a[ix] = new int[n];
	}

	int j = 0;
	while (j < n * n)
	{
		i++;
		tmp[j] = StrToInt(text, i);
		j++;
	}

	int itr = 0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			a[i][j] = tmp[itr];
			itr++;
		}
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (a[i][j] == a[n - 1 - j][n - 1 - i])
			{
				a[i][j] = 0;
				a[n - 1 - j][n - 1 - i] = 0;
			}
		}
	}

	int countR = 0, countC = 0;
	for (i = 0; i < n; i++)
	{
		countR = 0;
		countC = 0;
		for (j = 0; j < n; j++)
		{
			if (a[i][j] == 0) countR++;
			if (a[j][i] == 0) countC++;
		}
		if (countC == 0) cout << "Null column exist" << endl;
		if (countR == 0) cout << "Null row exist" << endl;
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	cout << "Would you like to do another task?\n";
	cout << "If yes, press a space button.";
	char temp;
	temp = _getch();
	if (temp == 32)main();
	else return;
}