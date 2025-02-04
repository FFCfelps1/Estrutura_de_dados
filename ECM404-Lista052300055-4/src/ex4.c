/* 
 * Enunciado: 
 * Desenvolva um programa capaz de ler uma string digitada pelo usuário e, 
 * a seguir, implemente a estratégia de criptografia ZENIT - POLAR.
 * A estratégia em questão consiste em substituir os caracteres da string 
 * da seguinte maneira:
 *
 *            Z <-> P 
 *            E <-> O
 *            N <-> L
 *            I <-> A
 *            T <-> R
 *
 * O programa deve desconsiderar a diferença entre letras maíusculas e
 * letras minúsculas.
 *
 * Exemplos:
 *
 *   Digite uma string: polar
 *   zenit
 *
 *   Digite uma string: zenit
 *   polar
 *
 *   Digite uma string: ZeNit
 *   polar
 *   
 *   Digite uma string: seu ou, e ratataci!
 *   sou eu, o tiririca!
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100 // Valor máximo para o tamanho do array. Não modifique.

// Protótipo da função lerString
char* lerString(char str[]);

// Função para aplicar a criptografia ZENIT - POLAR
void criptografar(char str[]);

int main() {
    char str[MAX];

    // Chama a função lerString para ler a string do usuário
    lerString(str);

    // Aplica a criptografia ZENIT - POLAR
    criptografar(str);

    // Imprime a string criptografada
    printf("%s\n", str);

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

// Define a função para aplicar a criptografia ZENIT - POLAR
void criptografar(char str[]) {
    int i;

    // Percorre a string e substitui os caracteres de acordo com as regras
    for (i = 0; str[i] != '\0'; i++) {
        // Converte o caractere para minúscula
        char c = tolower(str[i]);

        // Aplica as substituições de acordo com as regras
        switch (c) {
            case 'z':
                str[i] = 'p';
                break;
            case 'e':
                str[i] = 'o';
                break;
            case 'n':
                str[i] = 'l';
                break;
            case 'i':
                str[i] = 'a';
                break;
            case 't':
                str[i] = 'r';
                break;
            case 'p':
                str[i] = 'z';
                break;
            case 'o':
                str[i] = 'e';
                break;
            case 'l':
                str[i] = 'n';
                break;
            case 'a':
                str[i] = 'i';
                break;
            case 'r':
                str[i] = 't';
                break;
        }
    }
}
