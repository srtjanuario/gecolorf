#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

void print(int i)
{
	cout << i << endl;
}

void print(char c, int color, int size)
{
	switch (color)
	{
	case 1:
		cout << setw(size) << one << c << deff;
		break;
	case 2:
		cout << setw(size) << two << c << deff;
		break;
	case 3:
		cout << setw(size) << three << c << deff;
		break;
	case 4:
		cout << setw(size) << four << c << deff;
		break;
	case 5:
		cout << setw(size) << five << c << deff;
		break;
	case 6:
		cout << setw(size) << six << c << deff;
		break;
	case 7:
		cout << setw(size) << seven << "\e[1m" << c << "\e[0m" << deff;
		break;
	case 8:
		cout << setw(size) << eight << "\e[1m" << c << "\e[0m" << deff;
		break;
	case 9:
		cout << setw(size) << nine << "\e[1m" << c << "\e[0m" << deff;
		break;
	default:
		cout << setw(size) << deff << c << deff;
		break;
	}
}