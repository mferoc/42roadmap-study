/* ************************************************************************** */
/*                                                                            */
/*                                                        ::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathferr <mathferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 02:12:09 by mathferr          #+#    #+#             */
/*   Updated: 2020/03/03 02:12:10 by mathferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 4096

static void ft_putchar_fd(int fd, char *str)
{
	/*	Escreve caracteres num determinado fd	*/
	write(fd, str, strlen(str));
}

static void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}	
}

int main(void)
{
	/*	File descriptor -> representa um arquivo aberto ou criado	*/
	int fd;
	/*	Representa o retorno de um arquivo lido por read()	*/
	int ret;
	/*	Char para armazenar o que foi lido do arquivo, pode ser static, sera inicializado com malloc	*/
	char buf[BUF_SIZE + 1];

	/*  Abrindo um arquivo/criando chamado 42 e com permissão de escrita		*/
	/*	fd = open("42", O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR); 	*/
	/*	Abrindo um arquivo chamdo 42 com permissão apenas de leitura -> para usar read()	*/
	fd = open("42", O_RDONLY);

	if(fd == -1)
	{
		printf("open() ERROR\n");
		return (1);
	}
	printf("%d\n", fd);

	/*	Read() -> Lendo conteudo de um arquivo	*/
	/*	Lendo 4096 bytes do arquivo chamado 42	e salvando em buf	*/
	ret = read(fd, buf, BUF_SIZE);
	/*	Finalizando a string buf com \0		*/
	buf[ret] = '\0';
	/*	Imprimindo o numero de caracteres lido do arquivo	*/
	printf("%d\n", ret);
	/*	Imprimindo conteudo lido do arquivo		*/
	ft_putstr(buf);	

	/*	Escrevendo conteudo dentro do arquivo	*/
	ft_putchar_fd(fd, "Hello World !");

	/*	Fechando (encerrando um arquivo)	*/
	int cls = close(fd);

	if(cls == -1)
	{
		printf("close() ERROR\n");
		return (1);
	}
	printf("\n%d\n", cls);

	return (0);
}
