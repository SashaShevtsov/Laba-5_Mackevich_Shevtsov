#include <iostream> 
using namespace std;

bool isBracketsRight(char* str)
{
	char s[100] = { 0 };
	int j = 0;
	bool b = false;
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] == '[' || str[i] == '(' || str[i] == '{')
		{
			s[j] = str[i];
			j++;
		}
		else
		{
			if (j == 0 && (str[i] == ']' || str[i] == ')' || str[i] == '}'))
			{
				return false;
				break;
			}

			if (str[i] == ']')
			{
				if (s[j - 1] == '[')
					j--;
				else
				{
					return false;
					break;
				}
			}

			if (str[i] == ')')
			{
				if (s[j - 1] == '(')
					j--;
				else
				{
					return false;
					break;
				}
			}

			if (str[i] == '}')
			{
				if (s[j - 1] == '{')
					j--;
				else
				{
					return false;
					break;
				}
			}
		}
	}
	if (b == false)
		if (j != 0)
			return false;
		else return true;
}
void assert(char* string, bool answer)
{
	bool firstanswer = isBracketsRight(string);
	if (firstanswer == answer)
		cout << "OK" << endl;
	else
		cout << "False" << endl;
}
void tests()
{
	char string1[] = "dfdjfhjd(ndfmdnf(ndfmd)dnm)";
	char string2[] = "ddmkssdsd";
	char string3[] = "fh{f}fkd[dsd(dks)dsmk{ds}ds]ds";
	char string4[] = "fjfd{dkmds(sd[ds]dsd)dsds)ds";
	char string5[] = "sdsd{dsd(dsdds[sdds)dssd]dsds}ds";
	char string6[] = "dsd(dsfdj(dskfd{nfm}mf[fdm]fd)fdf{fdf}dfd)";
	assert(string1, true);
	assert(string2, true);
	assert(string3, true);
	assert(string4, false);
	assert(string5, false);
	assert(string6, true);
}

int main()
{
	tests();
	return 0;
}
