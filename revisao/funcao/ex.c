#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int elev(int a, int n)
{
	for(int i = 0; i != n; i++)
	{
		a += a;
	}
	return a;
}

int main()
{
	int a = 2, n = 3;
	printf("%d", elev(a,n));
}
