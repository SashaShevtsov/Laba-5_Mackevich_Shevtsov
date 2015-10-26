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
void assert(char* string, int answer)
{
	int firstanswer = babyDontHurtMe(string);
	if (firstanswer == answer)
		cout << "OK" << endl;
	else
		cout << "False" << endl;
}
void tests()
{
	char string1[] = "9";
	char string2[] = "max(5,min(4,2))";
	char string3[] = "max(5,max(min(max(5,8),7),min(6,max(3,max(2,1)))))";
	char string4[] = "min(9,min(8,min(7,max(0,6))))";
	char string5[] = "min(min(max(8,7),max(9,0)),max(min(0,2),min(3,1)))";
	char string6[] = "max(min(max(0,0),8),0)";
	assert(string1, 9);
	assert(string2, 5);
	assert(string3, 7);
	assert(string4, 6);
	assert(string5, 3);
	assert(string6, 0);
}
int main()
{
	tests();
	return 0;
}