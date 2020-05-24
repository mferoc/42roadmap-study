/*
*	printf("conteudo", argumentos);
*	O printf recebe um numero variavel de argumentos (consultar funcoes variadicas)
*	O % tem o seguinte formato:
*	%[flag][width].[precision][specifier]
*	***********************************************************
*	-FLAGS-
*	-
*	+
*	space
*	0
*	WIDTH
*	specifies the minimum number of chars to display
*	PRECISION
*	specifies the number of digits to display after decimal point
*	SPECIFIERS
*	%s -> print strings -> o %s indica que iremos receber uma string como
*	argumento
*	%d %i -> print integers -> %d %i indica que vamos receber um numero inteiro ou tipo int como argumento
*	%f -> ṕrint float -> o %f indica que vamos receber um ponto flutuante ou tipo float como argumento
*	%c -> print char -> indica que vamos receber um caracter como argumento, ou char type
*/
#include <stdio.h>

int main()
{
	char grade = 'B';		 //literal de caracter - ASCII char
	char name[] = "MRrobot"; //string literal
	char sport[] = "killsCapitalism";
	int age = 10000;
	double feet = 5.41;

	printf("%s plays %s\n", name, sport);
	printf("%d years old %s plays %c grade %s\n", age, name, grade, sport);
	/*
	*	in %lf .2 is the precision
	*	%.2lf print only 2 decimal caracters
	*/
	printf("Feet for %s are %lf\n", name, feet);
	printf("Feet for %s are %.2lf\n", name, feet);
	/*
	*	WIDTH is a spacer (ident) to format how output is displayed
	*	%WidthSpecifier
	*	10 is the minimum width but in my tests this is variable (look the second printf below)
		//// Width minimum is the greater then specifier ////
	*/
	printf("%10s has %10.1lf feet\n", name, feet);
	printf("%9s has %4.1lf feet\n", name, feet);
	printf("%10d\n", 42);
	printf("%9d\n", 42);
	printf("%8d\n", 42);
	printf("%7d\n", 42);
	/*
		FLAGS
		the flags works in accord of your functions, see below
		the flag has preference and overlaps others
	*/
	printf("%-10dX\n", 42);
	printf("%09dX\n", 42);
	printf("%08dX\n", 42);
	printf("%07dX\n", 42);
	return (0);
}
