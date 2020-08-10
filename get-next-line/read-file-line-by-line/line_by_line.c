/*
**
** Usando as funções fgets
** para ler um arquivo linha a linha
** em linguagem C
**
*/ 
/*
** compilar com: 
** gcc -Wall -Wextra -Werror -pedantic -std=c17 line_by_line.c
*/ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char chunk[128];
    FILE    *fp = fopen("lorem.txt", "r");

    if (fp == NULL)
    {
        perror("Impossível abrir o arquivo!");
        exit(-1);
    }
    // Salvando os pedaços de texto em um chunk na variavel linhas
    size_t len = sizeof(chunk);
    char *line = malloc(len);
    if(line == NULL)
    {
        perror("Impossível alocar espaço para o chunk de linha!");
        exit(-1);
    }
    line[0] = '\0'; 
    while(fgets(chunk, sizeof(chunk), fp) != NULL)
    {
        // Recalculando o tamanho do chunk de uma linha se necessário
        if(len - strlen(line) < sizeof(chunk))
        {
            len *= 2;
            if((line = realloc(line, len)) == NULL)
            {
                perror("Impossível realocar memória para uma nova linha!");
                free(line);
                exit(-1);
            }
        }
        // Concatenando o pedaço de texto com o fim do chunk de uma linha
        strcat(line, chunk);
        // Testando se uma linha tem um '\n', se sim processar a linha de texto
        if(line[strlen(line) - 1] == '\n')
        {
            // Imprimindo as linhas do arquivo
            //fputs(line, stdout);
            //fputs("|*\n", stdout);
            // imprimindo o tamanho de uma linha
            printf("Tamanho da linha: %zd\n", strlen(line));
            line[0] = '\0';
        }
    }
    fclose(fp);
    free(line);
    // imprimindo o tamanho máximo de linhas
    printf("\n\nTamanho máximo de linhas: %zd\n", len);
    return 0;
}
