#include <iostream> 
using namespace std;

bool whatIsLove(char* str)
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


int main()
{
	return 0;
}
