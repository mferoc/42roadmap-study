#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>

/* %s */
void dumb_printf_string(va_list *ap)
{
	char *str = va_arg(*ap, char *);
	write(1, str, strlen(str));
}

/* %c */
void dumb_printf_char(va_list *ap)
{
	char c = va_arg(*ap, int);
	write(1, &c, 1);
}

/* %d %i */
void dumb_printf_int(va_list *ap)
{
	int n = va_arg(*ap, int);
	char buffer[20];
	sprintf(buffer, "%d", n);
	write(1, buffer, strlen(buffer));
}

int findIndex(char *arr, char element) {
	int index = 0;

	for (index = 0; arr[index] != 0; index++) {
		if (arr[index] == element)
			return (index);
	}
	return (-1);
}

/* essa funcao ira se referir a funcao q faz o print de cada specifier */
void dumb_printf(char *str, ...)
{
	va_list ap;

	/* cada um dos specifiers no vetor vai conter um ponteiro pra funcao para a funcao que faz o management do q se quer imprimir */
	char arrIndex[4] = {'s', 'c', 'd', 0};
	/* array com ponteiros para funcao q referenciam as funcoes q serao usadas para fazer a impressao */
	void (*arrFunction[3])(va_list *) = {dumb_printf_string, dumb_printf_char, dumb_printf_int};
	int index = 0;
	int tmpIndex = 0;

	va_start(ap, str);
	for (index = 0; str[index] != 0; index++)
	{
		/* index != 0 para evitar um segmentation fault, verificando se estamos lidando com um specifier */
		if (index != 0 && str[index - 1] == '%')
		{
			/*
			** para evitar diversos ifs, vamos utilizar ponteiro para funcao
			** if(str[index] == 'd' || str[index] == 'i') {
			**	dumb_printf_int(&ap);
			** }
			** if(str[index] == 's') {
			** 	dumb_printf_string(&ap);
			** }
			** if(str[index] == 'c') {
			** 	dumb_printf_char(&ap);
			** }
			*/
			tmpIndex = findIndex(arrIndex, str[index]);
			if (tmpIndex != -1)
				(*arrFunction[tmpIndex]) (&ap);
		}
		else if (str[index] != '%')
		{
			write(1, &str[index], 1);
		}
	}
}

int main(int argc, char const *argv[])
{
	dumb_printf("BLABLABLA %s %d %c\n", "CODER0", 42, 'X');
	return 0;
}
