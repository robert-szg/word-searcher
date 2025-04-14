#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define FALSE 0
#define TRUE 1

#define INDEFINIDO -1
#define ESQUERDO 0
#define DIREITO 1



void numLinhas(char *argv1) {
    int nLinhas = 0;
    char linha[100];
    char arquivo[20];
    FILE * file;

    strcpy(arquivo, argv1);
    file = fopen("text.txt", "r");

    if(file == NULL) {
        printf("Erro\n");
    }
    while(fgets(linha, 100, file) != NULL) {
        nLinhas++;
    }
    printf("Numero de linhas no arquivo: %d\n", nLinhas);
}

void tipoIndice(char *argv2) {
    char indice[10];
    char arvore[7] = {'a','r','v','o','r','e','\0'};
    char lista[6] = "lista";
    int rArv, rLis;

    strcpy(indice, argv2);

    rArv = strcmp(indice, arvore);
    rLis = strcmp(indice, lista); 

    if(rArv == 0 || rLis == 0) {
        printf("Tipo de indice: '%s'\n", indice);
    }
    if(rArv != 0 && rLis != 0) {
        printf("Erro no indice\n");
    }
}



int main(int argc, char *argv[]) {

    clock_t tempo, tempo1, tempo2;
    tempo = clock();
    tempo1 = clock();
    tempo2 = clock();

    char lista[6] = {'l','i','s','t','a','\0'};
    char arvore[7] = {'a','r','v','o','r','e','\0'};

    tipoIndice(argv[2]);

    printf("Arquivo texto: '%s'\n", argv[1]);

    numLinhas(argv[1]);

    int x, y, i, z = 0, nLinhas = 0, contaPalavra = 0, ocorrencia = 0;
    char linha[100];
    char guardaLinhas[20][100];
    char auxGL[20][100];
    char auxL[20][100];
    char guardaPalavra[1000][20];
    char *palavra;
    char busca[20];
    char modo[10];
    char buscar[6] = {'b','u','s','c','a','\0'};
    char fim[4] = {'f','i','m','\0'};
    char aux1[20];
    char auxB[20];

    FILE * file;
    file = fopen(argv[1], "r");

    if(strcmp(argv[2], lista) == 0) {

        for(i = 0; fgets(linha, 100, file) != NULL; nLinhas++, i++) {
            strcpy(guardaLinhas[i], linha);
            strcpy(auxL[i], linha);
            strcpy(auxGL[i], guardaLinhas[i]);
            strlwr(auxGL[i]);
        }

        for(y = 0; y < nLinhas; y++) {
            palavra = strtok(guardaLinhas[y], " !.,-/");
        
            while(palavra != NULL) {
                strcpy(guardaPalavra[z], palavra);
                contaPalavra++;
                z++;
                palavra = strtok( NULL, " !,.-/");
            }

            contaPalavra = 0;
        }

        tempo = clock() - tempo;
        printf("Tempo para carregar o arquivo e construir o indice: %f ms\n", ((float)tempo)/CLOCKS_PER_SEC);

        printf("\n> ");

        scanf("%s", &modo);
        if(strcmp(modo, fim) == 0) {
            printf("Busca finalizada");
            return 1;
        }

        scanf("%s", &busca);
        if(strcmp(modo, buscar) != 0) {
            while(strcmp(modo, buscar) != 0) {
                printf("Opcao invalida\n> ");
                scanf("%s %s", &modo, &busca);
            }
        }


        while(strcmp(modo, buscar) == 0) {
        
            tempo1 = clock();

            for(i = 0; i <= z; i++) {
                strlwr(guardaPalavra[i]);
                strcpy(aux1, guardaPalavra[i]);
        
                strcpy(auxB, busca);
                strlwr(auxB);

                if(strcmp(aux1, auxB) == 0) {
                    ocorrencia++;
                }
            }
            
            if(ocorrencia == 0) {
                printf("Palavra nao encontrada");
            }
            else {
                for(x = 0; x <= nLinhas; x++) {
                    if(strstr(auxGL[x], auxB) != NULL) {
                        printf("\n Achei '%s' na linha: %d \n Linha %d: %s", auxB, x+1, x+1, auxL[x]);
                    }
                }

                printf(" \n A palavra '%s' foi encontrada %d vez(es)", busca, ocorrencia);
                ocorrencia = 0;
            }
            
            tempo1 = clock() - tempo1;
            printf("\nTempo de busca: %f ms\n", ((float)tempo1)/CLOCKS_PER_SEC);

            printf("\n\n> ");

            scanf("%s", &modo);
            if(strcmp(modo, fim) == 0) {
                printf("Busca finalizada");
                break;
                return 1;
            }

            scanf("%s", &busca);
            if(strcmp(modo, buscar) != 0) {
                printf("Opcao invalida\n> ");
                scanf("%s %s", &modo, &busca);
            }
        }
    }

    if(strcmp(argv[2], arvore) == 0) {
        typedef char Elemento;
        typedef int Boolean;

        typedef struct _no_arvore_ {

	        Elemento valor[100];
	        struct _no_arvore_ * esq;
	        struct _no_arvore_ * dir;

        } No;

        typedef struct {

	        No * raiz;

        } Arvore;

        Arvore * cria_arvore() {
            Arvore * arvore = (Arvore *) malloc (sizeof(Arvore));
	        arvore->raiz = NULL;	
	        return arvore;
        }

        for(i = 0; fgets(linha, 100, file) != NULL; nLinhas++, i++) {
            strcpy(guardaLinhas[i], linha);
            strcpy(auxL[i], linha);
            strcpy(auxGL[i], guardaLinhas[i]);
            strlwr(auxGL[i]);
        }

        for(y = 0; y < nLinhas; y++) {
            palavra = strtok(guardaLinhas[y], " !.,-/");
        
            while(palavra != NULL) {
                strcpy(guardaPalavra[z], palavra);
                contaPalavra++;
                z++;
                palavra = strtok(NULL, " !,.-/");
            }
            contaPalavra = 0;
        }

        tempo = clock() - tempo;
        printf("Tempo para carregar o arquivo e construir o indice: %f ms\n", ((float)tempo)/CLOCKS_PER_SEC);

        printf("\n> ");

        scanf("%s", &modo);
        if(strcmp(modo, fim) == 0) {
            printf("Busca finalizada");
            return 1;
        }

        scanf("%s", &busca);
        if(strcmp(modo, buscar) != 0) {
            while(strcmp(modo, buscar) != 0) {
                printf("Opcao invalida\n> ");
                scanf("%s %s", &modo, &busca);
            }
        }


        while(strcmp(modo, buscar) == 0) {
        
            tempo1 = clock();

            for(i = 0; i <= z; i++) {
                strlwr(guardaPalavra[i]);
                strcpy(aux1, guardaPalavra[i]);
        
                strcpy(auxB, busca);
                strlwr(auxB);

                if(strcmp(aux1, auxB) == 0) {
                    ocorrencia++;
                }

            }
            if(ocorrencia == 0) {
                printf("Palavra nao encontrada");
            }
            else {
                for(x = 0; x <= nLinhas; x++) {
                    if(strstr(auxGL[x], auxB) != NULL) {
                        printf("\n Achei '%s' na linha: %d \n Linha %d: %s", auxB, x+1, x+1, auxL[x]);
                    }
                }
                printf(" \n A palavra '%s' foi encontrada %d vez(es)", busca, ocorrencia);
                ocorrencia = 0;
            }

            tempo1 = clock() - tempo1;
            printf("\nTempo de busca: %f ms\n", ((float)tempo1)/CLOCKS_PER_SEC);

            printf("\n\n> ");

            scanf("%s", &modo);
            if(strcmp(modo, fim) == 0) {
                printf("Busca finalizada");
                break;
                return 1;
            }

            scanf("%s", &busca);
            if(strcmp(modo, buscar) != 0) {
                printf("Opcao invalida\n> ");
                scanf("%s %s", &modo, &busca);
            }
        }
    }
    return 0;
}




