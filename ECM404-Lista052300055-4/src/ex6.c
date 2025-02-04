/* 
 * Enunciado: 
 * Desenvolva um programa capaz de ler duas palavras digitadas pelo usuário e,
 * a seguir, deve informá-lo se as palavras formam um anagrama. O programa deve
 * desconsiderar a diferença entre letras maíusculas e letras minúsculas.
 *
 * Exemplos:
 *
 * Digite uma palavra: bored
 * Digite uma palavra: robed
 * bored é anagrama de robed
 *
 * Digite uma palavra: bored
 * Digite uma palavra: robbed
 * bored não é anagrama de robbed
 *
 * Digite uma palavra: ooi
 * Digite uma palavra: oii
 * ooi não é anagrama de oii
 *
 * Digite uma palavra: ooi
 * Digite uma palavra: ioo
 * ooi é anagrama de ioo
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100 // Valor máximo para o tamanho do array. Não modifique.

// Protótipo da função lerString
char* lerString(char str[]);

int main() {
    char str[MAX], str2[MAX];
    int count[26] = {0}; // Inicializa um array de contagem para cada letra do alfabeto
    int tamanho1, tamanho2, i;

    // Chama a função lerString para ler as duas palavras do usuário
    lerString(str);
    lerString(str2);

    // Obtém o tamanho das palavras
    tamanho1 = strlen(str);
    tamanho2 = strlen(str2);

    // Converte todos os caracteres para minúsculas
    for (i = 0; i < tamanho1; i++) {
        str[i] = tolower(str[i]);
    }
    for (i = 0; i < tamanho2; i++) {
        str2[i] = tolower(str2[i]);
    }

    // Verifica se as palavras têm o mesmo tamanho
    if (tamanho1 != tamanho2) {
        printf("As palavras não são anagramas.\n");
        return 0;
    }

    // Conta a frequência de cada letra na primeira palavra
    for (i = 0; i < tamanho1; i++) {
        count[str[i] - 'a']++;
    }

    // Decrementa a frequência de cada letra na segunda palavra
    for (i = 0; i < tamanho2; i++) {
        count[str2[i] - 'a']--;
    }

    // Verifica se todas as frequências são zero
    for (i = 0; i < 26; i++) {
        if (count[i] != 0) {
            printf("As palavras não são anagramas.\n");
            return 0;
        }
    }

    // Se todas as frequências forem zero, as palavras são anagramas
    printf("As palavras são anagramas.\n");

    return 0;
}

// Define a função lerString
char* lerString(char str[]){
    // Solicita que o usuário digite uma string
    printf("Digite uma string: ");
    fgets(str, MAX, stdin);

    // Remove o caractere de nova linha (\n) do final da string, se presente
    int tamanho = strlen(str);
    if (str[tamanho - 1] == '\n') {
        str[tamanho - 1] = '\0';
    }

    // Retorna a string lida
    return str;
}
