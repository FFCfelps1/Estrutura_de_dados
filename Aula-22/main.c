#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sqlite3.h"

#define MAX_Q 1000
#define MAX 100

int Menu();
void lerString(char s[]);
void imprimeCabecalho(sqlite3_stmt *stmt);
void imprimeTabela(sqlite3_stmt *stmt);
void imprimeLinha(sqlite3_stmt *stmt);



int main()
{

    char str[MAX_Q];
    char nome [MAX];
    sqlite3 *db = NULL;
    int conexao;
    sqlite3_stmt *stmt = NULL; //statement

    printf("Conectando com o db\n");
    sqlite3_open("pokemonCenter.db", &db);

    if (conexao =! SQLITE_OK){
        printf("Erro de Conexão");
        exit(-1);
    }
    printf("Sucesso\n");

    //aqui dentro que o db sera modificado:

    op = Menu();

    switch(op){

        case 1:
            sprintf(str, "SELECT * from vendas")
            sqlite3_prepare(db, str, -1, &stmt, NULL);
            imprimeCabecalho(stmt);
            imprimeTabela(stmt);
            break;

        case 2:
            printf("ID:");
            scanf("%i", int id);
            print("Valor:");
            scanf("%.2f", float valor);
            printf("Quantidade:");
            scanf("%i", int quant);
            printf("Nome:")
            lerString(nome);

            sprintf(str, "Insert into vendas(id, valor, quant, nome) values(%i, %.2f, %i, %s)", id, valor, quant, nome);
            sqlite3_prepare(db, str, -1, &stmt, NULL);
            sqlite3_step(stmt);
            break;

        case 3:
            printf("ID do produto:")
            scanf("%i", int id);

            sprintf(str, "select valor*quant from vendas where id = %i", id);
            sqlite3_prepare(db, str, -1, &stmt, NULL);
            imprimeLinha(stmt);

    }while op != -1



return 0;
}

    sqlite3_close(db);

    return 0;
}

void imprimeCabecalho(sqlite3_stmt *stmt){

    //printa o cabeçalho
    for (i = 0; i < sqlite3_column_count(stmt); i++)
        printf("%s\t", sqlite3_column_name(stmt, 0));
        printf("\n"); // termina a exibição do cabeçalho
}

void imprimeTabela(sqlite3_stmt *stmt){

    //imprime os valores da tabela
    while (sqlite3_step(stmt) != SQLITE_DONE){
        // para cada coluna
        for (int i = 0; i < sqlite3_column_count(stmt); i++)
            printf("%s\t", sqlite3_column_text(stmt, i));
            printf("\n"); // termina a exibição de uma linha
    }
    sqlite3_finalize(stmt);
    sqlite3_close(db);
}

void imprimeLinha(sqlite3_stmt *stmt){

    //imprime os valores da tabela
    if (sqlite3_step(stmt) == SQLITE_ROW){
        // para cada coluna
        for (int i = 0; i < sqlite3_column_count(stmt); i++)
            printf("%s\t", sqlite3_column_text(stmt, i));
            printf("\n"); // termina a exibição de uma linha
    }
    sqlite3_finalize(stmt);
    sqlite3_close(db);
}


int Menu(){

    int i;

    printf("Digite a opção desejada:");
    printf("1) Consultar tabela");
    printf("2) Inserir linha");
    printf("2) Consultar uma linha");
    printf("-1) Sair");
    scanf("Opção:%i", i);

    return i;
}

void lerString(char s[]){

    setbuf(stdin,0);
    fgets(s, MAX, stdin);
    if(s[strlen(s) - 1] == '\n'){
        s[strlen(s) - 1] = '\0';
    }
}

// https://dontpad.com/sqlonlinesexta
