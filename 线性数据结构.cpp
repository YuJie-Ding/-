#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable:4996)
#include "LinkedList.h"

int main()
{
	int a[4] = { 5,6,7,8 };
	LinkedList a1(a, 4);
	LinkedList a2;
	a2 = a1;
	a2.Add(3);
	a2.ToLast();
	LinkedList a3 = LinkedList(a2);
	for (int i = 0; i < a3.length; i++) {
		printf("%d", a3.Show());
		a3.ToNext();
	}
	LinkedList* a4 = &a3;
	delete a4;
}

