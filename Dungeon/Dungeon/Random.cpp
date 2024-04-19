#include"Random.h"
int randomNum(int a, int b)
{
	int n = rand() % 100;
	if (n < a)return 0;
	return 1;
}
int randomNum(int a, int b, int c)
{
	int n = rand() % 100;
	if (n < a)return 0;
	else if (n < a + b)return 1;
	return 2;
}
int randomNum(int a, int b, int c, int d)
{
	int n = rand() % 100;
	if (n < a)return 0;
	else if (n < a + b)return 1;
	else if (n < a + b + c)return 2;
	return 3;
}
int randomNum(int a, int b, int c, int d, int e)
{
	int n = rand() % 100;
	if (n < a)return 0;
	else if (n < a + b)return 1;
	else if (n < a + b + c)return 2;
	else if (n < a + b + c + d)return 3;
	return 4;
}