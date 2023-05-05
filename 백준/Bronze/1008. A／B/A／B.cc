#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	int num1;
	int num2;

	cin >> num1 >> num2;


	cout.precision(12);
	cout << fixed;
	cout << (double)num1 / num2;

}