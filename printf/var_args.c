/*
** conceitos matematicos -> aridade, operandos, funcoes variadicas (variadics)
** operando -> é um dos argumentos de um operador
** aridadde -> quatidade de operandos presente em um operador ou funcao
** va_args tem aridade variavel, ou indefinida
*/
/*
**
** sao funcoes que recebem um numero VARIAVEL DE ARGUMENTOS
** a declaracao de funcoes variaveis utiliza reticencias como parametro
** int printf (const char *format, ...);
** ***********************************************************
** para ter acesso as funcoes e argumentos variadicos em C, incluimos o header stdarg.h
** Definicoes de stdarg.h
** va_start -> enables access to variadic function arguments
** va_arg -> accesses the next variadic function argument
** va_copy -> makes a copy of the variadic function arguments
** va_end -> ends traversal of the variadic function arguments
** va_list -> holds the information needed by va_start, va_arg, va_end, and va_copy
*/
#include <stdio.h>
#include <stdarg.h>

/* para fazer uma soma, precisamos passar os operandos explicitamente para a funcao, MASS, e se quisermos fazer somas sem limitar o numero de operandos??? */
int	sum(a,b,c) {
	return (a + b + c);
}

/* podemos usar um numero variavel de argumentos para a soma, bastando indicar quantos argumentos queremos usar */
int variable_sum(const int count, ...) {
	va_list	args; /* va_list eh um tipo, damos um nome aos args da lista */
	int		i;
	int		sum;

	sum = 0;
	i = 0;
	/*  void va_start(va_list ap, last); */
	va_start(args, count); /* inicializamos a lista, tendo a lista e a qtd_args */
	while (i++ < count)
		/* type va_arg(va_list ap, type); */
		sum += va_arg(args, int); /* percorre a lista, passamos a lista e o tipo do arg */
	/* void va_end(va_list ap); */
	va_end(args); /* encerra o acesso a lista de argumentos, passamos a lista */
	return (sum);
}

int main(void) {
	printf("%d\n", variable_sum(3, 7, 7, -1)); /* 13 */
	printf("%d\n", variable_sum(10, 4, 4, 10, 2, 1 , 1, 5, 5, 6, 4)); /* 42 */
	return (0);
}
