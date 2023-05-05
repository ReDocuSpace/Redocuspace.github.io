#include <iostream>
#include <cstring>

using namespace std;

char* charMax(char* a, char* b)
{
	for (int i = 0;i < strlen(a);i++)
	{
		if (a[i] < b[i])
			return b;
		if (a[i] > b[i])
			return a;
	}
	return a;
}

void Subtract(char* a, char* b)
{
	for (int i = 0;i < strlen(b);i++)
	{
		a[i] = a[i] - b[i] + '0';
		if (a[i] < '0')
		{
			a[i] += 10;
			a[i - 1]--;
		}
	}

	for (int i = strlen(b) - 1;i >= 0;i--)
	{
		if (a[i] < '0')
		{
			a[i] += 10;
			a[i - 1]--;
		}
	}
}

void DevideSubtract(char* a, char* b, char* check, int index)
{
	check[index] = '0';

	while (a[index - 1] > '0' || charMax(a + index, b) == a + index) 
	{
		Subtract(a + index, b);

		++check[index];
	}
}

void Devide(char* a, char* b, char* check)
{
	int index = 0;
	int digit = strlen(a) - strlen(b);

	while (index <= digit)
		DevideSubtract(a, b, check, index++);

	check[index] = '\0';
}


int main()
{
	ios::sync_with_stdio(false);

	char a[1001];
	char b[1001];
	char check[1001];

	int aDeleteZero = 0;
	int checkDeleteZero = 0;

	cin >> a >> b;

	Devide(a, b, check);


	while (check[checkDeleteZero] == '0')
		checkDeleteZero++;

	while (a[aDeleteZero] == '0')
		aDeleteZero++;


	if (check[0] == '\0')
	{
		check[0] = '0';
		check[1] = '\0';
	}

	if (a[aDeleteZero] == '\0')
		aDeleteZero--;

	if (check[checkDeleteZero] == '\0')
		checkDeleteZero--;

	cout << check + checkDeleteZero << '\n';
	cout << a + aDeleteZero << '\n';


	
}