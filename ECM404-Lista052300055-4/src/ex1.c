/* 
 * Enunciado: 
 *  Desenvolva um programa capaz de ler uma string digitada pelo usuário e,
 *  a seguir, exiba essa string invertida.
 *
 *  Exemplo:
 *    Digite uma string: ola
 *    alo
 *
 */

#include <stdio.h>
#include <string.h>

// Protótipo da função lerString
char lerString(char str[]);

int main() {
    char str[100];
    int tamanho, i;

    // Chama a função lerString para ler a string do usuário
    lerString(str);

    // Obtém o tamanho da string
    tamanho = strlen(str);

    // Inverte a string
    for (i = tamanho - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }
    printf("\n");

    return 0;
}

// Define a função lerString
char lerString(char str[]){
    // Solicita que o usuário digite uma string
    printf("Digite uma string: ");
    fgets(str, sizeof(str), stdin);

    // Remove o caractere de nova linha (\n) do final da string
    int tamanho = strlen(str);
    if (str[tamanho - 1] == '\n') {
        str[tamanho - 1] = '\0';
    }

    // Retorna a string lida
    return str;
}
