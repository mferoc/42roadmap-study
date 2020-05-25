#include <stdio.h>

void test(void) {
	printf("HACKERCODE\n");
}

int test2(int n) {
	return (n * 2);
}

int main(int argc, char const *argv[])
{
	/* utilizando ponteiro de função */
	/* tipo_da_funcao (*ponteiro) (parametro) = &funcao */
	void (*ptrFunction) (void) = &test;
	int (*ptrFunc2) (int) = &test2;
	int a = 0;

	ptrFunction();
	a = ptrFunc2(45);

	printf("%d\n", a);
	return (0);
}
