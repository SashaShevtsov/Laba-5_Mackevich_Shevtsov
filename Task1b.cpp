#include <iostream>
using namespace std;
struct Node
{
	char bracket;
	Node* next;
};
Node* first(char bracket)
{
	Node* pkey = new Node;
	pkey->bracket = bracket;
	pkey->next = 0;
	return pkey;
}
void push(Node** top, char bracket)
{
	Node* pkey = new Node;
	pkey->bracket = bracket;
	pkey->next = *top;
	*top = pkey;
}
void pop(Node** top)
{
	Node* pv = *top;
	*top = (*top)->next;
	delete pv;
}
char peek(Node* const top)
{
	if (top != 0)
		return top->bracket;
	else
		return '.';
}
bool isRight(char* string)
{
	int i = 0;
	while (string[i] != '(' && string[i] != ')' && string[i] != '{' && string[i] != '}' && string[i] != '[' && string[i] != ']' && i<strlen(string))
		i++;
	if (i == strlen(string))
		return true;
	Node* top = first(string[i]);
	for (i += 1; i < strlen(string); i++)
	{
		if (string[i] == '(' || string[i] == ')' || string[i] == '{' || string[i] == '}' || string[i] == '[' || string[i] == ']')
		{
			if ((peek(top) == '(' && string[i] == ')') || (peek(top) == '[' && string[i] == ']') || (peek(top) == '{' && string[i] == '}'))
				pop(&top);
			else
                push(&top, string[i]);
		}
	}
	if (top == 0)
		return true;
	else
		return false;
}
void test(char*a, bool ans)
{
	if (isRight(a) == ans)
		cout << "kokokok" << endl;
	else
		cout << "smutachak" << endl;

}
int main()
{
	char a1[40] = "(1+4+8+8)*(2+2+8)=[1}={1}";
	test(a1, false);
	char a2[40] = "(a)+{[z]+a}+z";
	test(a2, true);
	char a3[10] = " ";
	test(a3, true);
	char a4[40] = "((({{{[[[]]]}}})))";
	test(a4, true);
	char a5[15] = "(2+2}*2=6";
	test(a5, false);
	char a6[40] = "(2+2)*2=8";
	test(a6, true);
	return 0;
}
