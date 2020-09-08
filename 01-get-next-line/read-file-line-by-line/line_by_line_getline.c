/*
**
** Usando a função getline
** para ler um arquivo linha a linha
** em linguagem C
**
*/ 
/*
** compilar com:
** gcc -Wall -Wextra -Werror -pedantic -std=gnu17 line_by_line_getline.c
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    FILE    *fp = fopen("lorem.txt", "r");

    if (fp == NULL)
    {
        perror("Impossível abrir o arquivo!");
        exit(-1);
    }

    // Lendo linhas usando a função POSIX getline
    char *line = NULL;
    size_t len = 0;

    while(getline(&line, &len, fp) != -1)
    {
        //fputs(line, stdout);
        //fputs("|*\n", stdout);
        printf("Tamanho da linha: %zd\n", strlen(line));
    }
    fclose(fp);
    // A função getline() aloca memória para uma linha, então é preciso liberar a memória
    free(line);     // getline() ira usar realloc para recalcular o tamanho do input buf se necessário
                    // isso torna necessário usar o free para liberar a memória utilizada

    printf("\n\nTamanho máximo de linhas: %zd\n", len);
    return 0;
}
