/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_li.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 11:00:03 by ebresser          #+#    #+#             */
/*   Updated: 2020/06/09 15:56:56 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

/*
 * ***************************************
 * to insert in libftprintf.h
 * ****************************************
 */
struct fields{
    char specifier;
};

/*
 * ***************************************
 * aux functions
 * ****************************************
 */
static void     ft_putchar(char c, int *p)
{
    write(1, &c, 1);
    (*p)++;
}
static void     ft_putstr(char *s, int *p)
{
    if (s)
        while (*s)
            ft_putchar(*s++, p);
}
/*static void		cut(int number)
{
	int		div;
	int		mod;
	char	c;

	div = number / 10;
	mod = number % 10;
	if (div != 0)
		cut(div);
	c = '0' + mod;
	ft_putchar(c);
}

static void     ft_putnbr(int n)
{
	if (n != 0)
	{
		if (n < 0)
		{
			ft_putchar('-');
			if (n == -2147483648)
			{
				n = (-1) * (n / 10);
				cut(n);
				ft_putchar('8');
			}
			else
			{
				n = -n;
				cut(n);
			}
		}
		else
			cut(n);
	}
	else
		ft_putchar('0');
}
*/
static void     ft_specifier_redirect(va_list *p_ap, char sp, int *p)
{
    if(sp == 's')
    {
        char *str;
        str = va_arg(*p_ap, char *);
        ft_putstr(str, p);
    }
    /*
    else if(sp == 'c')
    {
        char c;
        c = (char)var_arg(*p_ap, int);
        ft_putchar(c, p);
    }
    */
}

/*
 * ***************************************
 * PRINTF
 * ****************************************
 */
int             ft_printf(const char *fmt, ...)
{
    int *printed;
    int count;
    va_list ap;
    //struct fields *strformat;
    struct fields strformat;

    if(!fmt)
        return(-1);
    count = 0;
    printed = &count;
    va_start(ap, fmt);
    while (*fmt)
    {
        if(*fmt != '%')
        {
            ft_putchar(*fmt, printed);
            fmt++;
        }
        else
        {
            fmt++;
            if(*fmt == '%')
            {
                ft_putchar(*fmt, printed);
                fmt++;
            }
            else
            {
                strformat.specifier = *fmt;
                //ft_strformat_init(strformat);
                //ft_fieldstorage(fmt,strformat,printed);
                ft_specifier_redirect(&ap, strformat.specifier, printed);
                fmt++;
            }
        }
    }
    va_end(ap);
    return (*printed);
}
/*
 * ***************************************
 * MAIN
 * ****************************************
 */
int            main()
{
    int qtt;

    printf("Dev_Version\n");
    qtt = ft_printf("Ola%s que tal? %s\n", ", Matheus", "Curtiu?");
    printf("%d caracteres impressos\n", qtt);
    printf("Original_Version\n");
    qtt = printf("Ola%s que tal? %s\n", ", Matheus", "Curtiu?");
    printf("%d caracteres impressos\n", qtt);




    return (0);
}

