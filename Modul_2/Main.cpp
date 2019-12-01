#include <fstream>
#include <stdio.h>
#include <iostream>
#include <conio.h>
#include "Header.h"

using namespace std;

int menu();
int main()
{
	int answer = menu();
	switch (answer)
	{
	case 0:Task_1(); break;
	case 1:Task_2(); break;
	case 2:Task_3(); break;
	case 3:Task_4(); break;
		system("pause");
		return 0;
	}
	return 0;
}

int menu() {
	int key = 0;
	int code;
	do {
		system("cls");
		key = (key + 4) % 4;
		if (key == 0) cout << "-> Comments eraser" << endl;
		else  cout << "   Comments eraser" << endl;
		if (key == 1) cout << "-> Vector" << endl;
		else  cout << "   Vector" << endl;
		if (key == 2) cout << "-> Matrix checker" << endl;
		else  cout << "   Matrix checker" << endl;
		if (key == 3) cout << "-> Binominal coefficients" << endl;
		else  cout << "   Binominal coefficients" << endl;
		code = _getch();
		if (code == 224)
		{
			code = _getch();
			if (code == 80) key++;
			if (code == 72) key--;
		}
	} while (code != 13);
	system("cls");
	return key;
}