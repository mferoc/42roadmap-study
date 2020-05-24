#include <stdio.h>
#include <stdarg.h>

void	dumb_printf(const char *format, ...) {
	va_list	ap;

	va_start(ap, format);
	while (*format) {
		if (*format == 'd' || *format == 'i') {
			int nat;
			nat = va_arg(ap, int);
			printf("%d\t", nat);

		}
		else if (*format == 'c') {
			int chr;
			chr = va_arg(ap, int);
			printf("%c\t", chr);

		}
		else if (*format == 'f') {
			double d;
			d = va_arg(ap, double);
			printf("%f\t", d);
		}
		/* implement to *format == 's' */
		++format;
	}
	va_end(ap);
}

int		main(void) {
	dumb_printf("dicf", 666, 42, 'X', 3.14159265359);
	printf("\n");
	return (0);
}
