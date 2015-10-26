#include <iostream>
using namespace std;
const int numbborder1 = 47;
const int numbborder2 = 58;
struct Stack
{
	double number;
	Stack* next;
};
void pushtoStack(Stack** top, double number)
{
	Stack* pkey = new Stack;
	pkey->number = number;
	pkey->next = *top;
	*top = pkey;
}
double popfromStack(Stack** top)
{
	double temp = (*top)->number;
	Stack* pv = *top;
	*top = (*top)->next;
	delete pv;
	return temp;
}
struct Node
{
	char symbol;
	Node* next;
};
void push(Node** top, char symbol)
{
	Node* pkey = new Node;
	pkey->symbol = symbol;
	pkey->next = *top;
	*top = pkey;
}
char pop(Node** top)
{
	char temp = (*top)->symbol;
	Node* pv = *top;
	*top = (*top)->next;
	delete pv;
	return temp;
}
char peek(Node* const top)
{
	if (top != NULL)
		return top->symbol;
	else
		return 0;
}
char* getstringinRPN(char* string)
{
	char* stringinRPN = new char;
	Node* top = NULL;
	int j = 0;
	for (int i = 0; i < strlen(string); i++)
	{
		if ((int)string[i]>numbborder1 && (int)string[i] < numbborder2)
		{
			while ((int)string[i] > numbborder1 && (int)string[i] < numbborder2)
			{
				stringinRPN[j] = string[i];
				j++;
				i++;
			}
			i--;
			stringinRPN[j] = ' ';
			j++;
		}
		else
		{
            switch (string[i])
			{
		        case '+': 
				{
					while (peek(top) != 0 && peek(top) != '(')	
					{
					   	stringinRPN[j] = pop(&top);
						stringinRPN[j+1] = ' ';
						j+=2;	
				    }		
					push(&top, string[i]);
					break;
				}    
				case '-':
				{
					while (peek(top) != 0 && peek(top) != '(')
					{
						stringinRPN[j] = pop(&top);
						stringinRPN[j + 1] = ' ';
						j += 2;
					}
					push(&top, string[i]);
					break;
				}
				case '(':
				{
					push(&top, string[i]);
					break;
				}
				case '*':
				{
					while (peek(top) == '/')
					{
						stringinRPN[j] = pop(&top);
						stringinRPN[j + 1] = ' ';
						j += 2;
					}
					push(&top, string[i]);
					break;
				}
				case '/':
				{
					while (peek(top) == '*')
					{
						stringinRPN[j] = pop(&top);
						stringinRPN[j + 1] = ' ';
						j += 2;
					}
					push(&top, string[i]);
					break;
				}
				case ')':
				{
					while (peek(top) != '(')
					{
						stringinRPN[j] = pop(&top);
						stringinRPN[j + 1] = ' ';
						j += 2;
					}
					pop(&top);
					break;
				}
			}
		}
	}
	while (top != NULL)
	{
		stringinRPN[j] = pop(&top);
		stringinRPN[j + 1] = ' ';
		j += 2;
	}
	stringinRPN[j] = '\0';
	return stringinRPN;
}
double getanswer(char* string)
{
	char* stringinRPN = getstringinRPN(string);
	Stack* top = NULL;
	for (int i=0; i < strlen(stringinRPN); i++)
	{
		if ((int)stringinRPN[i]>numbborder1 && (int)stringinRPN[i] < numbborder2)
		{
			char* number=new char[10];
			int j = 0;
			while ((int)stringinRPN[i] > numbborder1 && (int)stringinRPN[i] < numbborder2)
			{
				number[j] = stringinRPN[i];
				i++;
				j++;
			}
			double nextnumber=atof(number);
			pushtoStack(&top, nextnumber);
		}
		else
		{
			switch (stringinRPN[i])
			{
			case '+':
			{
				double sum = popfromStack(&top) + popfromStack(&top);
				pushtoStack(&top, sum);
				break;
			}
			case '-':
			{
				double n = popfromStack(&top);
				double m = popfromStack(&top);
				double dif = m - n;
				pushtoStack(&top, dif);
				break;
			}
			case '*':
			{
				double comp = popfromStack(&top) * popfromStack(&top);
				pushtoStack(&top, comp);
				break;
			}
			case '/':
			{
				double n = popfromStack(&top);
				double m = popfromStack(&top);
				double quot = m / n;
				pushtoStack(&top, quot);
				break;
			}
			}
		}
	}
	return popfromStack(&top);
}
void test(char* a, double ans)
{
	if (getanswer(a) == ans)
		cout << "Bravo!" << endl;
	else
		cout << "fuuuuuu" << endl;
}
int main()
{
	char a1[40] = "(1+4+8+8)*(2+2+8)";
	test(a1, 252.);
	char a2[40] = "2+2*2";
	test(a2, 6.);
	char a3[10] = "1";
	test(a3, 1.);
	char a4[40] = "(2+2)*2";
	test(a4, 8.);
	char a5[15] = "(2-1)*2/5*10";
	test(a5, 4.);
	char a6[40] = "(1+2)/2";
	test(a6, 1.5);
}
