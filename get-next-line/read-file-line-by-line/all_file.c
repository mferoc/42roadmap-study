/*
**
** Usando as funções fgets e getline
** para ler um arquivo em linguagem C
**
*/ 
/*
** compilar com: 
** gcc -Wall -Wextra -Werror -pedantic -std=c17 all_file.c
*/ 
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // Abrindo um arquivo como um ponteiro do tipo FILE
    FILE    *fp = fopen("lorem.txt", "r");
    // Variavel que ira guardar as partes de texto lidas de um arqiuvo
    char chunk[128];
    
    // Testando se a abertura do arquivo funcionou
    if (fp == NULL)
    {
        perror("Impossível abrir o arquivo!");
        exit(-1);
    }
    // Lendo todo o arquivo e imprimindo na saida padrao
    while(fgets(chunk, sizeof(chunk), fp) != NULL)
    {
        fputs(chunk, stdout);
        fputs("|*\n", stdout);
    }
    // Fechando o arquivo
    fclose(fp);
    return 0;
}
