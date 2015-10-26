#include <iostream> 
using namespace std;
int delwp(int* ar, int k, int size)
{
	int temp;
	for (int i = k; i < size; i++)
	{
		temp = ar[i];
		ar[i] = ar[i + 1];
		ar[i + 1] = temp;
	}
	size--;
}
int min(int a, int b)
{
	if (a < b)
		return a;
	else
		return b;
}
int max(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}
int babyDontHurtMe(char* str)
{
	int j;
	int temp = 0;
	int a[100];
	for (int i = 0; i<strlen(str); i++)
	{
		if (isdigit(str[i]))
		{
			a[temp] = str[i] - '0';
			temp++;
		}
		if (str[i] == 'i') 
		{
			a[temp] = 10;
			temp++;
		}
		if (str[i] == 'a')
		{
			a[temp] = 11;
			temp++;
		}
	}
	j = temp - 2;
	while (temp != 1 && j >= 1)
	{
		if (a[j] >= 10)
		{
			if (a[j] == 10)
				a[j] = min(a[j + 1], a[j + 2]);
			else
				a[j] = max(a[j + 1], a[j + 2]);
			delwp(a, j + 2, temp);
			delwp(a, j + 1, temp);
		}
		j--;
	}
	return a[0];
}

int main()
{
	return 0;
}