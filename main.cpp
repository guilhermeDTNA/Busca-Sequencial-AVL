#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>

using namespace std;

#define TAM_cem 100
#define TAM_mil 1000
#define TAM_dez_mil 10000
#define TAM_cem_mil 100000
#define TAM_meio_milhao 500000
#define TAM_um_milhao 1000000

typedef struct TipoRegistro {

    int Chave;
    long int dados1;
    char dados2;

} TipoRegistro;

typedef struct TipoNo *TipoApontador;

typedef struct TipoNo {

    TipoRegistro Reg;
    TipoApontador Esq, Dir;
    int alturaDir, alturaEsq, balanceador;

} TipoNo;

void ordena100();
void ordena1000();
void ordena10000();
void ordena100000();
void ordena1000000();
void desordena100();
void desordena1000();
void desordena10000();
void desordena100000();
void desordena1000000();
void Inicializa(TipoApontador *Dicionario);
void Insere(TipoRegistro x, TipoApontador *p);
void Pesquisa(TipoRegistro *x, TipoApontador *p, int i);
void rotacionaDir(TipoApontador *p);
void rotacionaEsq(TipoApontador *p);
void balancear(TipoApontador *p);
int AlturaAVL(TipoApontador *p);
bool VerificaBalanceamento(TipoApontador *p);
void InsereAVL(TipoRegistro x, TipoApontador *p);
bool acesso_sequencial();
bool arvore_binaria();
bool arvore_AVL();
void FuncGerador(int tam);
void InsereComparacoes(int i);

void ordena100() {

    int i = 0, vet[TAM_cem], chave;
    long int k[TAM_cem], dados1;
    char c[TAM_cem] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    char dados2;

    ofstream arq;
    arq.open("100-ordenada.txt");

    cout << "Gerando arquivo...\n";

    for (i = 0; i < TAM_cem; i++) {

        c[i] = 'a' + (char) (rand() % 26);
        vet[i] = i + 1;
        k[i] = vet[i] + 1;
        arq << vet[i] << "   " << k[i] << "   " << c[i] << endl;

    }

    arq.close();
    cout << "Arquivo gerado com sucesso !!\n\n";

    bool opcao;

    cout << "Digite 1 para ver o arquivo ou 0 para voltar:\n";
    cin>>opcao;

    if (opcao == 1) {

        ifstream arq1;
        arq1.open("100-ordenada.txt");

        for (i = 0; i < TAM_cem; i++) {

            arq1 >> chave >> dados1>>dados2;
            cout << "Chave: " << chave << " Dados 1: " << dados1 << " Dados 2: " << dados2 << endl << endl;

        }

        arq1.close();

    }

    else {

        exit;

    }

}

void ordena1000() {

    int i = 0, vet[TAM_mil], chave;
    long int k[TAM_mil], dados1;
    char c[TAM_mil] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    char dados2;

    ofstream arq;
    arq.open("1000-ordenada.txt");

    cout << "Gerando arquivo...\n";

    for (i = 0; i < TAM_mil; i++) {

        c[i] = 'a' + (char) (rand() % 26);
        vet[i] = i + 1;
        k[i] = vet[i] + 1;
        arq << vet[i] << "   " << k[i] << "   " << c[i] << endl;

    }

    arq.close();
    cout << "Arquivo gerado com sucesso !!\n\n";

    bool opcao;

    cout << "Digite 1 para ver o arquivo ou 0 para voltar:\n";
    cin>>opcao;

    if (opcao == 1) {

        ifstream arq1;
        arq1.open("1000-ordenada.txt");

        for (i = 0; i < TAM_mil; i++) {

            arq1 >> chave >> dados1>>dados2;
            cout << "Chave: " << chave << " Dados 1: " << dados1 << " Dados 2: " << dados2 << endl << endl;

        }

        arq1.close();

    }

    else {

        exit;

    }

}

void ordena10000() {

    int i = 0, vet[TAM_dez_mil], chave;
    long int k[TAM_dez_mil], dados1;
    char c[TAM_dez_mil] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    char dados2;

    ofstream arq;
    arq.open("10000-ordenada.txt");

    cout << "Gerando arquivo...\n";

    for (i = 0; i < TAM_dez_mil; i++) {

        c[i] = 'a' + (char) (rand() % 26);
        vet[i] = i + 1;
        k[i] = vet[i] + 1;
        arq << vet[i] << "   " << k[i] << "   " << c[i] << endl;

    }

    arq.close();
    cout << "Arquivo gerado com sucesso !!\n\n";

    bool opcao;
    cout << "Digite 1 para ver o arquivo ou 0 para voltar:\n";
    cin>>opcao;

    if (opcao == 1) {

        ifstream arq1;
        arq1.open("10000-ordenada.txt");

        for (i = 0; i < TAM_dez_mil; i++) {

            arq1 >> chave >> dados1>>dados2;
            cout << "Chave: " << chave << " Dados 1: " << dados1 << " Dados 2: " << dados2 << endl << endl;

        }

        arq1.close();

    }

    else {

        exit;

    }

}

void ordena100000() {

    int i, vet[TAM_cem_mil], chave;
    long int k[TAM_cem_mil], dados1;
    char c[TAM_cem_mil] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    char dados2;

    ofstream arq;
    arq.open("100000-ordenada.txt");

    cout << "Gerando arquivo...\n";

    for (i = 0; i < TAM_cem_mil; i++) {

        c[i] = 'a' + (char) (rand() % 26);
        vet[i] = i + 1;
        k[i] = vet[i] + 1;
        arq << vet[i] << "   " << k[i] << "   " << c[i] << endl;

    }

    arq.close();
    cout << "Arquivo gerado com sucesso !!\n\n";

    bool opcao;

    cout << "Digite 1 para ver o arquivo ou 0 para voltar:\n";
    cin>>opcao;

    if (opcao == 1) {

        ifstream arq1;
        arq1.open("100000-ordenada.txt");

        for (i = 0; i < TAM_cem_mil; i++) {

            arq1 >> chave >> dados1>>dados2;
            cout << "Chave: " << chave << " Dados 1: " << dados1 << " Dados 2: " << dados2 << endl << endl;

        }

        arq1.close();

    }

    else {

        exit;

    }

}

void ordena1000000() {

    int i, vet[TAM_meio_milhao], chave;
    long int k[TAM_meio_milhao], dados1;
    char c[TAM_meio_milhao] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    char dados2;

    ofstream arq;
    arq.open("1000000-ordenada.txt");

    cout << "Gerando arquivo...\n";

    for (i = 0; i < TAM_meio_milhao; i++) {

        c[i] = 'a' + (char) (rand() % 26);
        vet[i] = i + 1;
        k[i] = vet[i] + 1;
        arq << vet[i] << "   " << k[i] << "   " << c[i] << endl;

    }

    arq.close();

    ofstream arq1;
    arq1.open("1000000-ordenada.txt", ofstream::app);

    for (i = 0; i < TAM_meio_milhao; i++) {

        c[i] = 'a' + (char) (rand() % 26);
        vet[i] = i + 1;
        k[i] = vet[i] + 1;
        arq1 << vet[i] + 500000 << "   " << k[i] + 500000 << "   " << c[i] << endl;

    }

    arq1.close();
    cout << "Arquivo gerado com sucesso !!\n\n";

    bool opcao;

    cout << "Digite 1 para ver o arquivo ou 0 para voltar:\n";
    cin>>opcao;

    if (opcao == 1) {

        ifstream arq1;
        arq1.open("1000000-ordenada.txt");

        for (i = 0; i < TAM_um_milhao; i++) {

            arq1 >> chave >> dados1>>dados2;
            cout << "Chave: " << chave << " Dados 1: " << dados1 << " Dados 2: " << dados2 << endl << endl;

        }

        arq1.close();

    }

    else {

        exit;

    }

}

void desordena100() {

    int i, vet[TAM_cem], chave;
    long int k[TAM_cem], dados1;
    char c[TAM_cem] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    char dados2;

    ofstream arq;
    arq.open("100-desordenada.txt");

    cout << "Gerando arquivo...\n";

    for (i = 0; i < TAM_cem; i++) {

        for (i = 0; i < TAM_cem; i++) {

            c[i] = 'a' + (rand() % 26);
            k[i] = 0 + (rand() % 100);
            vet[i] = (rand() % TAM_cem) + 1;

            for (int j = 0; j < i; j++) {

                if (vet[j] == vet[i]) {

                    vet[i] = (rand() % TAM_cem) + 1;
                    j = 0;

                }

            }

            arq << "  " << vet[i] << "  " << k[i] << "  " << c[i] << endl;

        }

    }

    cout << "Arquivo gerado com sucesso !!\n\n";

    bool opcao;

    cout << "Digite 1 para ver o arquivo ou 0 para voltar:\n";
    cin>>opcao;

    if (opcao == 1) {

        ifstream arq1;
        arq1.open("100-desordenada.txt");

        for (i = 0; i < TAM_cem; i++) {

            arq1 >> chave >> dados1>>dados2;
            cout << "Chave: " << chave << " Dados 1: " << dados1 << " Dados 2: " << dados2 << endl << endl;

        }

        arq1.close();

    }

    else {

        exit;

    }

}

void desordena1000() {

    int i, vet[TAM_mil], chave;
    long int k[TAM_mil], dados1;
    char c[TAM_mil] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    char dados2;

    ofstream arq;
    arq.open("1000-desordenada.txt");

    cout << "Gerando arquivo...\n";

    for (i = 0; i < TAM_mil; i++) {

        for (i = 0; i < TAM_mil; i++) {

            c[i] = 'a' + (rand() % 26);
            k[i] = 0 + (rand() % 1000);
            vet[i] = (rand() % TAM_mil) + 1;

            for (int j = 0; j < i; j++) {

                if (vet[j] == vet[i]) {

                    vet[i] = (rand() % TAM_mil) + 1;
                    j = 0;

                }

            }

            arq << "  " << vet[i] << "  " << k[i] << "  " << c[i] << endl;

        }

    }

    bool opcao;

    cout << "Arquivo gerado com sucesso !!\n\n";

    cout << "Digite 1 para ver o arquivo ou 0 para voltar:\n";
    cin>>opcao;

    if (opcao == 1) {

        ifstream arq1;
        arq1.open("1000-desordenada.txt");

        for (i = 0; i < TAM_mil; i++) {

            arq1 >> chave >> dados1>>dados2;
            cout << "Chave: " << chave << " Dados 1: " << dados1 << " Dados 2: " << dados2 << endl << endl;

        }

        arq1.close();

    }

    else {

        exit;

    }

}

void desordena10000() {

    int i, vet[TAM_dez_mil], chave;
    long int k[TAM_dez_mil], dados1;
    char c[TAM_dez_mil] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    char dados2;

    ofstream arq;
    arq.open("10000-desordenada.txt");

    cout << "Gerando arquivo...\n";

    for (i = 0; i < TAM_dez_mil; i++) {

        for (i = 0; i < TAM_dez_mil; i++) {

            c[i] = 'a' + (rand() % 26);
            k[i] = 0 + (rand() % 1000);
            vet[i] = (rand() % TAM_dez_mil) + 1;

            for (int j = 0; j < i; j++) {

                if (vet[j] == vet[i]) {

                    vet[i] = (rand() % TAM_dez_mil) + 1;
                    j = 0;

                }

            }

            arq << "  " << vet[i] << "  " << k[i] << "  " << c[i] << endl;

        }

    }

    bool opcao;

    cout << "Arquivo gerado com sucesso !!\n\n";

    cout << "Digite 1 para ver o arquivo ou 0 para voltar:\n";
    cin>>opcao;

    if (opcao == 1) {

        ifstream arq1;
        arq1.open("10000-desordenada.txt");

        for (i = 0; i < TAM_dez_mil; i++) {

            arq1 >> chave >> dados1>>dados2;
            cout << "Chave: " << chave << " Dados 1: " << dados1 << " Dados 2: " << dados2 << endl << endl;

        }

        arq1.close();

    }

    else {

        exit;

    }

}

void desordena100000() {

    int i, vet[TAM_cem_mil], chave;
    long int k[TAM_cem_mil], dados1;
    char c[TAM_cem_mil] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    char dados2;

    ofstream arq;
    arq.open("100000-desordenada.txt");

    cout << "Gerando arquivo...\n";

    for (i = 0; i < TAM_cem_mil; i++) {

        for (i = 0; i < TAM_cem_mil; i++) {

            c[i] = 'a' + (rand() % 26);
            k[i] = 0 + (rand() % 1000);
            vet[i] = (rand() % TAM_cem_mil) + 1;

            for (int j = 0; j < i; j++) {

                if (vet[j] == vet[i]) {

                    vet[i] = (rand() % TAM_cem_mil) + 1;
                    j = 0;

                }

            }

            arq << "  " << vet[i] << "  " << k[i] << "  " << c[i] << endl;

        }

    }

    bool opcao;

    cout << "Arquivo gerado com sucesso !!\n\n";

    cout << "Digite 1 para ver o arquivo ou 0 para voltar:\n";
    cin>>opcao;

    if (opcao == 1) {

        ifstream arq1;
        arq1.open("100000-desordenada.txt");

        for (i = 0; i < TAM_cem_mil; i++) {

            arq1 >> chave >> dados1>>dados2;
            cout << "Chave: " << chave << " Dados 1: " << dados1 << " Dados 2: " << dados2 << endl << endl;

        }

        arq1.close();

    }
    else {

        exit;

    }

}

void desordena1000000() {

    int i, vet[TAM_cem_mil], chave, l = 1;
    long int k[TAM_cem_mil], dados1;
    char c[TAM_cem_mil] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    char dados2;

    if (l == 1) {

        ofstream arq;
        arq.open("1000000-desordenada.txt");

        cout << "Gerando arquivo...\n";

        for (i = 0; i < TAM_cem_mil; i++) {

            for (i = 0; i < TAM_cem_mil; i++) {

                c[i] = 'a' + (rand() % 26);
                k[i] = 0 + (rand() % 10000);
                vet[i] = (rand() % TAM_cem_mil) + 1;

                for (int j = 0; j < i; j++) {

                    if (vet[j] == vet[i]) {

                        vet[i] = (rand() % TAM_cem_mil) + 1;
                        j = 0;

                    }

                }

                arq << "  " << vet[i] << "  " << k[i] << "  " << c[i] << endl;

            }

        }


        cout << "100 mil números inseridos pela " << l << "ª vez\n";
        l++;

    }

    if (l == 2) {

        ofstream arq1;
        arq1.open("1000000-desordenada.txt", ofstream::app);

        cout << "Gerando arquivo...\n";

        for (i = 0; i < TAM_cem_mil; i++) {

            for (i = 0; i < TAM_cem_mil; i++) {

                c[i] = 'a' + (rand() % 26);
                k[i] = ((l - 1)*100000) + (rand() % 100000);
                vet[i] = (rand() % TAM_cem_mil) + ((l - 1)*100000);

                for (int j = 0; j < i; j++) {

                    if (vet[j] == vet[i]) {

                        vet[i] = (rand() % TAM_cem_mil) + ((l - 1)*100000) + 1;
                        j = 0;

                    }

                }

                arq1 << "  " << vet[i] << "  " << k[i] << "  " << c[i] << endl;

            }

        }

        cout << "100 mil números inseridos pela " << l << "ª vez\n";
        l++;

    }

    if (l == 3) {

        ofstream arq1;
        arq1.open("1000000-desordenada.txt", ofstream::app);

        cout << "Gerando arquivo...\n";

        for (i = 0; i < TAM_cem_mil; i++) {

            for (i = 0; i < TAM_cem_mil; i++) {

                c[i] = 'a' + (rand() % 26);
                k[i] = ((l - 1)*100000) + (rand() % 100000);
                vet[i] = (rand() % TAM_cem_mil) + ((l - 1)*100000);

                for (int j = 0; j < i; j++) {

                    if (vet[j] == vet[i]) {

                        vet[i] = (rand() % TAM_cem_mil) + ((l - 1)*100000) + 1;
                        j = 0;

                    }

                }

                arq1 << "  " << vet[i] << "  " << k[i] << "  " << c[i] << endl;

            }

        }

        cout << "100 mil números inseridos pela " << l << "ª vez\n";
        l++;

    }

    if (l == 4) {

        ofstream arq1;
        arq1.open("1000000-desordenada.txt", ofstream::app);

        cout << "Gerando arquivo...\n";

        for (i = 0; i < TAM_cem_mil; i++) {

            for (i = 0; i < TAM_cem_mil; i++) {

                c[i] = 'a' + (rand() % 26);
                k[i] = ((l - 1)*100000) + (rand() % 100000);
                vet[i] = (rand() % TAM_cem_mil) + ((l - 1)*100000);

                for (int j = 0; j < i; j++) {

                    if (vet[j] == vet[i]) {

                        vet[i] = (rand() % TAM_cem_mil) + ((l - 1)*100000) + 1;
                        j = 0;

                    }

                }

                arq1 << "  " << vet[i] << "  " << k[i] << "  " << c[i] << endl;

            }

        }

        cout << "100 mil números inseridos pela " << l << "ª vez\n";
        l++;

    }

    if (l == 5) {

        ofstream arq1;
        arq1.open("1000000-desordenada.txt", ofstream::app);

        cout << "Gerando arquivo...\n";

        for (i = 0; i < TAM_cem_mil; i++) {

            for (i = 0; i < TAM_cem_mil; i++) {

                c[i] = 'a' + (rand() % 26);
                k[i] = ((l - 1)*100000) + (rand() % 100000);
                vet[i] = (rand() % TAM_cem_mil) + ((l - 1)*100000);

                for (int j = 0; j < i; j++) {

                    if (vet[j] == vet[i]) {

                        vet[i] = (rand() % TAM_cem_mil) + ((l - 1)*100000) + 1;
                        j = 0;

                    }

                }

                arq1 << "  " << vet[i] << "  " << k[i] << "  " << c[i] << endl;

            }

        }

        cout << "100 mil números inseridos pela " << l << "ª vez\n";
        l++;

    }

    if (l == 6) {

        ofstream arq1;
        arq1.open("1000000-desordenada.txt", ofstream::app);

        cout << "Gerando arquivo...\n";

        for (i = 0; i < TAM_cem_mil; i++) {

            for (i = 0; i < TAM_cem_mil; i++) {

                c[i] = 'a' + (rand() % 26);
                k[i] = ((l - 1)*100000) + (rand() % 100000);
                vet[i] = (rand() % TAM_cem_mil) + ((l - 1)*100000);

                for (int j = 0; j < i; j++) {

                    if (vet[j] == vet[i]) {

                        vet[i] = (rand() % TAM_cem_mil) + ((l - 1)*100000) + 1;
                        j = 0;

                    }

                }

                arq1 << "  " << vet[i] << "  " << k[i] << "  " << c[i] << endl;

            }

        }

        cout << "100 mil números inseridos pela " << l << "ª vez\n";
        l++;

    }

    if (l == 7) {

        ofstream arq1;
        arq1.open("1000000-desordenada.txt", ofstream::app);

        cout << "Gerando arquivo...\n";

        for (i = 0; i < TAM_cem_mil; i++) {

            for (i = 0; i < TAM_cem_mil; i++) {

                c[i] = 'a' + (rand() % 26);
                k[i] = ((l - 1)*100000) + (rand() % 100000);
                vet[i] = (rand() % TAM_cem_mil) + ((l - 1)*100000);

                for (int j = 0; j < i; j++) {

                    if (vet[j] == vet[i]) {

                        vet[i] = (rand() % TAM_cem_mil) + ((l - 1)*100000) + 1;
                        j = 0;

                    }

                }

                arq1 << "  " << vet[i] << "  " << k[i] << "  " << c[i] << endl;

            }

        }

        cout << "100 mil números inseridos pela " << l << "ª vez\n";
        l++;

    }

    if (l == 8) {

        ofstream arq1;
        arq1.open("1000000-desordenada.txt", ofstream::app);

        cout << "Gerando arquivo...\n";

        for (i = 0; i < TAM_cem_mil; i++) {

            for (i = 0; i < TAM_cem_mil; i++) {

                c[i] = 'a' + (rand() % 26);
                k[i] = ((l - 1)*100000) + (rand() % 100000);
                vet[i] = (rand() % TAM_cem_mil) + ((l - 1)*100000);

                for (int j = 0; j < i; j++) {

                    if (vet[j] == vet[i]) {

                        vet[i] = (rand() % TAM_cem_mil) + ((l - 1)*100000) + 1;
                        j = 0;

                    }

                }

                arq1 << "  " << vet[i] << "  " << k[i] << "  " << c[i] << endl;
            }

        }

        cout << "100 mil números inseridos pela " << l << "ª vez\n";
        l++;

    }

    if (l == 9) {

        ofstream arq1;
        arq1.open("1000000-desordenada.txt", ofstream::app);

        cout << "Gerando arquivo...\n";

        for (i = 0; i < TAM_cem_mil; i++) {

            for (i = 0; i < TAM_cem_mil; i++) {

                c[i] = 'a' + (rand() % 26);
                k[i] = ((l - 1)*100000) + (rand() % 100000);
                vet[i] = (rand() % TAM_cem_mil) + ((l - 1)*100000);

                for (int j = 0; j < i; j++) {

                    if (vet[j] == vet[i]) {

                        vet[i] = (rand() % TAM_cem_mil) + ((l - 1)*100000) + 1;
                        j = 0;

                    }

                }

                arq1 << "  " << vet[i] << "  " << k[i] << "  " << c[i] << endl;

            }

        }

        cout << "100 mil números inseridos pela " << l << "ª vez\n";
        l++;

    }

    if (l == 10) {

        ofstream arq1;
        arq1.open("1000000-desordenada.txt", ofstream::app);

        cout << "Gerando arquivo...\n";

        for (i = 0; i < TAM_cem_mil; i++) {

            for (i = 0; i < TAM_cem_mil; i++) {

                c[i] = 'a' + (rand() % 26);
                k[i] = ((l - 1)*100000) + (rand() % 100000);
                vet[i] = (rand() % TAM_cem_mil) + ((l - 1)*100000);

                for (int j = 0; j < i; j++) {

                    if (vet[j] == vet[i]) {

                        vet[i] = (rand() % TAM_cem_mil) + ((l - 1)*100000) + 1;
                        j = 0;

                    }

                }

                arq1 << "  " << vet[i] << "  " << k[i] << "  " << c[i] << endl;

            }

        }

        cout << "100 mil números inseridos pela " << l << "ª vez\n";
        l++;

    }

    bool opcao;
    cout << "Digite 1 para ver o arquivo ou 0 para voltar:\n";
    cin>>opcao;

    if (opcao == 1) {

        ifstream arq1;
        arq1.open("1000000-desordenada.txt");

        for (i = 0; i < TAM_um_milhao; i++) {

            arq1 >> chave >> dados1>>dados2;
            cout << "Chave: " << chave << " Dados 1: " << dados1 << " Dados 2: " << dados2 << endl << endl;
       
        }

        arq1.close();

    }
    
    else {

        exit;

    }

}

void InsereComparacoes(int i) {

    ofstream arq;
    arq.open("comparacoes.txt", ofstream::app);
    arq << i << endl;
    arq.close();

}

void Inicializa(TipoApontador *Dicionario) {

    *Dicionario = NULL;

}

void Insere(TipoRegistro x, TipoApontador *p) {

    if (*p == NULL) {

        *p = (TipoApontador) malloc(sizeof (TipoNo));
        (*p)->Reg = x;
        (*p)->Esq = NULL;
        (*p)->Dir = NULL;

        return;

    }

    if (x.Chave < (*p)->Reg.Chave) {

        Insere(x, &(*p)->Esq);
        return;

    }

    if (x.Chave > (*p)->Reg.Chave) {

        Insere(x, &(*p)->Dir);

    }
    
    else {

        cout << "Registro " << x.Chave << " já está presente na árvore!\n";

    }

}

void Pesquisa(TipoRegistro *x, TipoApontador *p, int i) {

    if (*p == NULL) {

        cout << "Chave não encontrada! \n\n";
        cout << "Número de comparações: " << i << endl;
        InsereComparacoes(i);
        return;

    }

    if (x->Chave < (*p)->Reg.Chave) {

        i++;
        Pesquisa(x, &(*p)->Esq, i);

        return;

    }

    if (x->Chave > (*p)->Reg.Chave) {

        i++;
        Pesquisa(x, &(*p)->Dir, i);

    }
    
    else {

        *x = (*p)->Reg;
        cout << "Chave encontrada! \n";
        cout << "Chave:" << " " << x->Chave << " Dado 1:" << " " << x->dados1 << " Dado 2:" << " " << x->dados2 << " Número de comparações: " << i << endl << endl;
        InsereComparacoes(i);

    }

}

void rotacionaDir(TipoApontador *p) {

    TipoApontador *aux = (TipoApontador *) malloc(sizeof (TipoNo));
    (*aux) = (*p)->Esq;
    (*p)->Esq = (*aux)->Dir;
    (*aux)->Dir = (*p);
    (*p) = (*aux);

}

void rotacionaEsq(TipoApontador *p) {

    TipoApontador *aux = (TipoApontador *) malloc(sizeof (TipoNo));
    (*aux) = (*p)->Dir;
    (*p)->Dir = (*aux)->Esq;
    (*aux)->Esq = (*p);
    (*p) = (*aux);

}

void balancear(TipoApontador *p) {

    (*p)->alturaEsq = (AlturaAVL(&(*p) -> Esq));
    (*p)->alturaDir = (AlturaAVL(&(*p) -> Dir));
    (*p)->balanceador = (*p)->alturaDir - (*p)->alturaEsq;

    if ((*p)->balanceador == 2) {

        if ((*p)->Dir != NULL) {

            int filho = ((*p)->Dir->alturaDir - (*p)->Dir->alturaEsq);

            if (filho == 1 || filho == 0) {

                rotacionaEsq(&(*p));

            }
            
            else if (filho == -1) {

                rotacionaDir(&(*p)->Dir);
                rotacionaEsq(&(*p));

            }

        }

    }
    
    else if ((*p)->balanceador == -2) {

        if ((*p)->Esq != NULL) {

            int filho = ((*p)->Esq->alturaDir - (*p)->Esq->alturaEsq);

            if (filho == -1 || filho == 0) {

                rotacionaDir(&(*p));

            }
            
            else if (filho == 1) {

                rotacionaEsq(&(*p)->Esq);
                rotacionaDir(&(*p));

            }

        }

    }

}

int AlturaAVL(TipoApontador *p) {

    int esq = AlturaAVL(&(*p) -> Esq) + 1;
    int dir = AlturaAVL(&(*p) -> Dir) + 1;

    if ((*p) == NULL) {

        return 0;

    }

    if (esq > dir) {

        return esq++;

    }

    return dir++;

}

bool VerificaBalanceamento(TipoApontador *p) {

    if ((*p) == NULL) {

        return true;

    }
    
    else
        if ((*p) -> Esq == NULL && (*p) -> Dir == NULL) {

        return true;

    }
    
    else
        if ((*p) -> Esq != NULL && (*p) -> Dir != NULL) {

        return VerificaBalanceamento(&(*p) -> Esq) && VerificaBalanceamento(&(*p) -> Dir);

    }
    
    else
        if ((*p) -> Esq != NULL) {

        return (AlturaAVL(&(*p) -> Esq) == 1);

    }

    else {

        return (AlturaAVL(&(*p) -> Dir) == 1);

    }

}

void InsereAVL(TipoRegistro x, TipoApontador *p) {

    if (*p == NULL) {

        *p = (TipoApontador) malloc(sizeof (TipoNo));
        
        (*p)->Reg = x;
        (*p)->Esq = NULL;
        (*p)->Dir = NULL;
        (*p)->balanceador = 0;
        (*p)->alturaDir = 0;
        (*p)->alturaEsq = 0;

        return;

    }

    if (x.Chave < (*p)->Reg.Chave) {

        InsereAVL(x, &(*p)->Esq);

        balancear(&(*p));

        return;

    }

    if (x.Chave > (*p)->Reg.Chave) {

        InsereAVL(x, &(*p)->Dir);

        balancear(&(*p));

    }
    
    else {

        cout << "Registro " << x.Chave << " já está presente na árvore!\n";

    }

}

bool acesso_sequencial() {

    int opcao, chavebuscaseq, i, j = 0, a = 0;
    double to, tf;

    cout << "Escolha um arquivo:\n";
    cout << "0 - Voltar ao menu \n"
            "1 - Arquivo com 100 (cem) números  ordenados \n"
            "2 - Arquivo com 1000 (mil) números  ordenados \n"
            "3 - Arquivo com 10000 (dez mil) números  ordenados \n"
            "4 - Arquivo com 100000 (cem mil) números  ordenados \n"
            "5 - Arquivo com 100000 (um milhão) números  ordenados \n"
            "6 - Arquivo com 100 (cem) números  desordenados \n"
            "7 - Arquivo com 1000 (mil) números  desordenados \n"
            "8 - Arquivo com 10000 (dez mil) números  desordenados \n"
            "9 - Arquivo com 100000 (cem mil) números  desordenados \n"
            "10 - Arquivo com 100000 (um milhão) números  desordenados \n";
    cin>>opcao;

    if (opcao == 0) {

        return 1;

    }

menu:

    cout << "Digite a chave a ser buscada:\n";
    cin>>chavebuscaseq;

    if (chavebuscaseq == 98765) {

        return 1;

    }

    if (opcao == 1) {

        int *chave = new int[TAM_cem];
        long int *dados1 = new long int[TAM_cem];
        char *dados2 = new char[TAM_cem];

        ifstream arq;
        arq.open("100-ordenada.txt");

        for (i = 0; i < TAM_cem; i++) {

            arq >> chave[i] >> dados1[i] >> dados2[i];

        }

        to = clock();
        j = 0;

        for (i = 0; i < TAM_cem; i++) {

            if (chavebuscaseq == chave[i]) {

                cout << "Chave encontrada! \n";
                cout << "Chave:" << " " << chave[i] << " Dado 1:" << " " << dados1[i] << " Dado 2:" << " " << dados2[i] << endl << endl;
                tf = clock();
                ofstream saidas("Encontradas.txt", ios::app);
                saidas << chavebuscaseq << "    " << (tf - to) / CLOCKS_PER_SEC * 1000 << endl;
                saidas.close();
                cout << "Tempo gasto: " << (tf - to) / CLOCKS_PER_SEC * 1000 << " seg" << "  Números de comparações: " << j << " \n\n";
                InsereComparacoes(j);
                goto menu;

            }

            if (chavebuscaseq != chave[i]) {

                j++;

            }

            if (j == TAM_cem) {

                cout << "Chave não encontrada! \n\n";
                ofstream saidas("Nao_Encontradas.txt", ios::app);
                tf = clock();
                saidas << chavebuscaseq << "    " << (tf - to) / CLOCKS_PER_SEC * 1000 << endl;
                saidas.close();
                cout << "Tempo gasto: " << (tf - to) / CLOCKS_PER_SEC * 1000 << " seg" << "  Números de comparações: " << j << " \n\n";
                InsereComparacoes(j);
                goto menu;

            }

        }

        cout << "Tempo gasto: " << (tf - to) / CLOCKS_PER_SEC * 1000 << " seg" << "  Números de comparações: " << j << " \n\n";

        arq.close();

        delete chave;
        delete dados1;
        delete dados2;

    }

    if (opcao == 2) {

        int *chave = new int[TAM_mil];
        long int *dados1 = new long int[TAM_mil];
        char *dados2 = new char[TAM_mil];


        ifstream arq;
        arq.open("1000-ordenada.txt");

        for (i = 0; i < TAM_mil; i++) {

            arq >> chave[i] >> dados1[i] >> dados2[i];

        }

        to = clock();
        j = 0;

        for (i = 0; i < TAM_mil; i++) {

            if (chavebuscaseq == chave[i]) {

                cout << "Chave encontrada! \n";
                cout << "Chave:" << " " << chave[i] << " Dado 1:" << " " << dados1[i] << " Dado 2:" << " " << dados2[i] << endl << endl;
                tf = clock();
                ofstream saidas("Encontradas.txt", ios::app);
                saidas << chavebuscaseq << "    " << (tf - to) / CLOCKS_PER_SEC * 1000 << endl;
                saidas.close();
                cout << "Tempo gasto: " << (tf - to) / CLOCKS_PER_SEC * 1000 << " seg" << "  Números de comparações: " << j << " \n\n";
                InsereComparacoes(j);
                goto menu;

            }

            if (chavebuscaseq != chave[i]) {

                j++;

            }

            if (j == TAM_mil) {

                cout << "Chave não encontrada! \n\n";
                ofstream saidas("Nao_Encontradas.txt", ios::app);
                tf = clock();
                saidas << chavebuscaseq << "    " << (tf - to) / CLOCKS_PER_SEC * 1000 << endl;
                saidas.close();
                cout << "Tempo gasto: " << (tf - to) / CLOCKS_PER_SEC * 1000 << " seg" << "  Números de comparações: " << j << " \n\n";
                InsereComparacoes(j);
                goto menu;

            }

        }

        arq.close();

        delete chave;
        delete dados1;
        delete dados2;

    }

    if (opcao == 3) {

        int *chave = new int[TAM_dez_mil];
        long int *dados1 = new long int[TAM_dez_mil];
        char *dados2 = new char[TAM_dez_mil];

        ifstream arq;
        arq.open("10000-ordenada.txt");

        for (i = 0; i < TAM_dez_mil; i++) {

            arq >> chave[i] >> dados1[i] >> dados2[i];

        }

        to = clock();
        j = 0;

        for (i = 0; i < TAM_dez_mil; i++) {

            if (chavebuscaseq == chave[i]) {

                cout << "Chave encontrada! \n";
                cout << "Chave:" << " " << chave[i] << " Dado 1:" << " " << dados1[i] << " Dado 2:" << " " << dados2[i] << endl << endl;
                tf = clock();
                ofstream saidas("Encontradas.txt", ios::app);
                saidas << chavebuscaseq << "    " << (tf - to) / CLOCKS_PER_SEC * 1000 << endl;
                saidas.close();
                cout << "Tempo gasto: " << (tf - to) / CLOCKS_PER_SEC * 1000 << " seg" << "  Números de comparações: " << j << " \n\n";
                InsereComparacoes(j);
                goto menu;

            }

            if (chavebuscaseq != chave[i]) {

                j++;

            }

            if (j == TAM_dez_mil) {

                cout << "Chave não encontrada! \n\n";
                ofstream saidas("Nao_Encontradas.txt", ios::app);
                tf = clock();
                saidas << chavebuscaseq << "    " << (tf - to) / CLOCKS_PER_SEC * 1000 << endl;
                saidas.close();
                cout << "Tempo gasto: " << (tf - to) / CLOCKS_PER_SEC * 1000 << " seg" << "  Números de comparações: " << j << " \n\n";
                InsereComparacoes(j);
                goto menu;

            }

        }

        cout << "Tempo gasto: " << (tf - to) / CLOCKS_PER_SEC * 1000 << " seg" << "  Números de comparações: " << j << " \n\n";

        arq.close();

        delete chave;
        delete dados1;
        delete dados2;

    }

    if (opcao == 4) {

        int *chave = new int[TAM_cem_mil];
        long int *dados1 = new long int[TAM_cem_mil];
        char *dados2 = new char[TAM_cem_mil];

        ifstream arq;
        arq.open("100000-ordenada.txt");

        for (i = 0; i < TAM_cem_mil; i++) {

            arq >> chave[i] >> dados1[i] >> dados2[i];

        }

        to = clock();
        j = 0;

        for (i = 0; i < TAM_cem_mil; i++) {

            if (chavebuscaseq == chave[i]) {

                cout << "Chave encontrada! \n";
                cout << "Chave:" << " " << chave[i] << " Dado 1:" << " " << dados1[i] << " Dado 2:" << " " << dados2[i] << endl << endl;
                tf = clock();
                ofstream saidas("Encontradas.txt", ios::app);
                saidas << chavebuscaseq << "    " << (tf - to) / CLOCKS_PER_SEC * 1000 << endl;
                saidas.close();
                cout << "Tempo gasto: " << ((tf - to) / CLOCKS_PER_SEC * 1000) << " seg" << "  Números de comparações: " << j << " \n\n";
                InsereComparacoes(j);
                goto menu;

            }

            if (chavebuscaseq != chave[i]) {

                j++;

            }

            if (j == TAM_cem_mil) {

                cout << "Chave não encontrada! \n\n";
                ofstream saidas("Nao_Encontradas.txt", ios::app);
                tf = clock();
                saidas << chavebuscaseq << "    " << (tf - to) / CLOCKS_PER_SEC * 1000 << endl;
                saidas.close();
                cout << "Tempo gasto: " << (tf - to) / CLOCKS_PER_SEC * 1000 << " seg" << "  Números de comparações: " << j << " \n\n";
                InsereComparacoes(j);
                goto menu;

            }

        }

        cout << "Tempo gasto: " << (tf - to) / CLOCKS_PER_SEC * 1000 << " seg" << "  Números de comparações: " << j << " \n\n";

        arq.close();

        delete chave;
        delete dados1;
        delete dados2;

    }

    if (opcao == 5) {

        int *chave = new int[TAM_um_milhao];
        long int *dados1 = new long int[TAM_um_milhao];
        char *dados2 = new char[TAM_um_milhao];

        ifstream arq;
        arq.open("1000000-ordenada.txt");

        for (i = 0; i < TAM_um_milhao; i++) {

            arq >> chave[i] >> dados1[i] >> dados2[i];

        }

        to = clock();
        j = 0;

        for (i = 0; i < TAM_um_milhao; i++) {

            if (chavebuscaseq == chave[i]) {

                cout << "Chave encontrada! \n";
                cout << "Chave:" << " " << chave[i] << " Dado 1:" << " " << dados1[i] << " Dado 2:" << " " << dados2[i] << endl << endl;
                tf = clock();
                ofstream saidas("Encontradas.txt", ios::app);
                saidas << chavebuscaseq << "    " << (tf - to) / CLOCKS_PER_SEC * 1000 << endl;
                saidas.close();
                cout << "Tempo gasto: " << (tf - to) / CLOCKS_PER_SEC * 1000 << " seg" << "  Números de comparações: " << j << " \n\n";
                InsereComparacoes(j);
                goto menu;

            }

            if (chavebuscaseq != chave[i]) {

                j++;

            }

            if (j == TAM_um_milhao) {

                cout << "Chave não encontrada! \n\n";
                ofstream saidas("Nao_Encontradas.txt", ios::app);
                tf = clock();
                saidas << chavebuscaseq << "    " << (tf - to) / CLOCKS_PER_SEC * 1000 << endl;
                saidas.close();
                cout << "Tempo gasto: " << (tf - to) / CLOCKS_PER_SEC * 1000 << " seg" << "  Números de comparações: " << j << " \n\n";
                InsereComparacoes(j);
                goto menu;

            }

        }

        cout << "Tempo gasto: " << (tf - to) / CLOCKS_PER_SEC * 1000 << " seg" << "  Números de comparações: " << j << " \n\n";

        arq.close();

        delete chave;
        delete dados1;
        delete dados2;

    }

    if (opcao == 6) {

        int *chave = new int[TAM_cem];
        long int *dados1 = new long int[TAM_cem];
        char *dados2 = new char[TAM_cem];

        ifstream arq;
        arq.open("100-desordenada.txt");

        for (i = 0; i < TAM_cem; i++) {

            arq >> chave[i] >> dados1[i] >> dados2[i];

        }

        to = clock();
        j = 0;

        for (i = 0; i < TAM_cem; i++) {

            if (chavebuscaseq == chave[i]) {

                cout << "Chave encontrada! \n";
                cout << "Chave:" << " " << chave[i] << " Dado 1:" << " " << dados1[i] << " Dado 2:" << " " << dados2[i] << endl << endl;
                tf = clock();
                ofstream saidas("Encontradas.txt", ios::app);
                saidas << chavebuscaseq << "    " << (tf - to) / CLOCKS_PER_SEC * 1000 << endl;
                saidas.close();
                cout << "Tempo gasto: " << (tf - to) / CLOCKS_PER_SEC * 1000 << " seg" << "  Números de comparações: " << j << " \n\n";
                InsereComparacoes(j);
                goto menu;

            }

            if (chavebuscaseq != chave[i]) {

                j++;

            }

            if (j == TAM_cem) {

                cout << "Chave não encontrada! \n\n";
                ofstream saidas("Nao_Encontradas.txt", ios::app);
                tf = clock();
                saidas << chavebuscaseq << "    " << (tf - to) / CLOCKS_PER_SEC * 1000 << endl;
                saidas.close();
                cout << "Tempo gasto: " << (tf - to) / CLOCKS_PER_SEC * 1000 << " seg" << "  Números de comparações: " << j << " \n\n";
                InsereComparacoes(j);
                goto menu;

            }

        }

        cout << "Tempo gasto: " << (tf - to) / CLOCKS_PER_SEC * 1000 << " seg" << "  Números de comparações: " << j << " \n\n";

        arq.close();

        delete chave;
        delete dados1;
        delete dados2;

    }

    if (opcao == 7) {

        int *chave = new int[TAM_mil];
        long int *dados1 = new long int[TAM_mil];
        char *dados2 = new char[TAM_mil];

        ifstream arq;
        arq.open("1000-desordenada.txt");

        for (i = 0; i < TAM_mil; i++) {

            arq >> chave[i] >> dados1[i] >> dados2[i];

        }

        to = clock();
        j = 0;

        for (i = 0; i < TAM_mil; i++) {

            if (chavebuscaseq == chave[i]) {

                cout << "Chave encontrada! \n";
                cout << "Chave:" << " " << chave[i] << " Dado 1:" << " " << dados1[i] << " Dado 2:" << " " << dados2[i] << endl << endl;
                tf = clock();
                ofstream saidas("Encontradas.txt", ios::app);
                saidas << chavebuscaseq << "    " << (tf - to) / CLOCKS_PER_SEC * 1000 << endl;
                saidas.close();
                cout << "Tempo gasto: " << (tf - to) / CLOCKS_PER_SEC * 1000 << " seg" << "  Números de comparações: " << j << " \n\n";
                InsereComparacoes(j);
                goto menu;

            }

            if (chavebuscaseq != chave[i]) {

                j++;

            }

            if (j == TAM_mil) {

                cout << "Chave não encontrada! \n\n";
                ofstream saidas("Nao_Encontradas.txt", ios::app);
                tf = clock();
                saidas << chavebuscaseq << "    " << (tf - to) / CLOCKS_PER_SEC * 1000 << endl;
                saidas.close();
                cout << "Tempo gasto: " << (tf - to) / CLOCKS_PER_SEC * 1000 << " seg" << "  Números de comparações: " << j << " \n\n";
                InsereComparacoes(j);
                goto menu;

            }

        }

        cout << "Tempo gasto: " << (tf - to) / CLOCKS_PER_SEC * 1000 << " seg" << "  Números de comparações: " << j << " \n\n";

        arq.close();

        delete chave;
        delete dados1;
        delete dados2;

    }

    if (opcao == 8) {

        int *chave = new int[TAM_dez_mil];
        long int *dados1 = new long int[TAM_dez_mil];
        char *dados2 = new char[TAM_dez_mil];

        ifstream arq;
        arq.open("10000-desordenada.txt");

        for (i = 0; i < TAM_dez_mil; i++) {

            arq >> chave[i] >> dados1[i] >> dados2[i];

        }

        to = clock();
        j = 0;

        for (i = 0; i < TAM_dez_mil; i++) {

            if (chavebuscaseq == chave[i]) {

                cout << "Chave encontrada! \n";
                cout << "Chave:" << " " << chave[i] << " Dado 1:" << " " << dados1[i] << " Dado 2:" << " " << dados2[i] << endl << endl;
                tf = clock();
                ofstream saidas("Encontradas.txt", ios::app);
                saidas << chavebuscaseq << "    " << (tf - to) / CLOCKS_PER_SEC * 1000 << endl;
                saidas.close();
                cout << "Tempo gasto: " << (tf - to) / CLOCKS_PER_SEC * 1000 << " seg" << "  Números de comparações: " << j << " \n\n";
                InsereComparacoes(j);
                goto menu;

            }

            if (chavebuscaseq != chave[i]) {

                j++;

            }

            if (j == TAM_dez_mil) {

                cout << "Chave não encontrada! \n\n";
                ofstream saidas("Nao_Encontradas.txt", ios::app);
                tf = clock();
                saidas << chavebuscaseq << "    " << (tf - to) / CLOCKS_PER_SEC * 1000 << endl;
                saidas.close();
                cout << "Tempo gasto: " << (tf - to) / CLOCKS_PER_SEC * 1000 << " seg" << "  Números de comparações: " << j << " \n\n";
                InsereComparacoes(j);
                goto menu;

            }

        }

        cout << "Tempo gasto: " << (tf - to) / CLOCKS_PER_SEC * 1000 << " seg" << "  Números de comparações: " << j << " \n\n";

        arq.close();

        delete chave;
        delete dados1;
        delete dados2;

    }

    if (opcao == 9) {

        int *chave = new int[TAM_cem_mil];
        long int *dados1 = new long int[TAM_cem_mil];
        char *dados2 = new char[TAM_cem_mil];

        ifstream arq;
        arq.open("100000-desordenada.txt");

        for (i = 0; i < TAM_cem_mil; i++) {

            arq >> chave[i] >> dados1[i] >> dados2[i];

        }

        to = clock();
        j = 0;

        for (i = 0; i < TAM_cem_mil; i++) {

            if (chavebuscaseq == chave[i]) {

                cout << "Chave encontrada! \n";
                cout << "Chave:" << " " << chave[i] << " Dado 1:" << " " << dados1[i] << " Dado 2:" << " " << dados2[i] << endl << endl;
                tf = clock();
                ofstream saidas("Encontradas.txt", ios::app);
                saidas << chavebuscaseq << "    " << (tf - to) / CLOCKS_PER_SEC * 1000 << endl;
                saidas.close();
                cout << "Tempo gasto: " << (tf - to) / CLOCKS_PER_SEC * 1000 << " seg" << "  Números de comparações: " << j << " \n\n";
                InsereComparacoes(j);
                goto menu;

            }

            if (chavebuscaseq != chave[i]) {

                j++;

            }

            if (j == TAM_cem_mil) {

                cout << "Chave não encontrada! \n\n";
                ofstream saidas("Nao_Encontradas.txt", ios::app);
                tf = clock();
                saidas << chavebuscaseq << "    " << (tf - to) / CLOCKS_PER_SEC * 1000 << endl;
                saidas.close();
                cout << "Tempo gasto: " << (tf - to) / CLOCKS_PER_SEC * 1000 << " seg" << "  Números de comparações: " << j << " \n\n";
                InsereComparacoes(j);
                goto menu;

            }

        }

        cout << "Tempo gasto: " << (tf - to) / CLOCKS_PER_SEC * 1000 << " seg" << "  Números de comparações: " << j << " \n\n";

        arq.close();

        delete chave;
        delete dados1;
        delete dados2;

    }

    if (opcao == 10) {

        int *chave = new int[TAM_um_milhao];
        long int *dados1 = new long int[TAM_um_milhao];
        char *dados2 = new char[TAM_um_milhao];

        ifstream arq;
        arq.open("1000000-desordenada.txt");

        for (i = 0; i < TAM_um_milhao; i++) {

            arq >> chave[i] >> dados1[i] >> dados2[i];

        }

        to = clock();
        j = 0;

        for (i = 0; i < TAM_um_milhao; i++) {

            if (chavebuscaseq == chave[i]) {

                cout << "Chave encontrada! \n";
                cout << "Chave:" << " " << chave[i] << " Dado 1:" << " " << dados1[i] << " Dado 2:" << " " << dados2[i] << endl << endl;
                tf = clock();
                ofstream saidas("Encontradas.txt", ios::app);
                saidas << chavebuscaseq << "    " << (tf - to) / CLOCKS_PER_SEC * 1000 << endl;
                saidas.close();
                cout << "Tempo gasto: " << (tf - to) / CLOCKS_PER_SEC * 1000 << " seg" << "  Números de comparações: " << j << " \n\n";
                InsereComparacoes(j);
                goto menu;

            }

            if (chavebuscaseq != chave[i]) {

                j++;

            }

            if (j == TAM_um_milhao) {

                cout << "Chave não encontrada! \n\n";
                ofstream saidas("Nao_Encontradas.txt", ios::app);
                tf = clock();
                saidas << chavebuscaseq << "    " << (tf - to) / CLOCKS_PER_SEC * 1000 << endl;
                saidas.close();
                cout << "Tempo gasto: " << (tf - to) / CLOCKS_PER_SEC * 1000 << " seg" << "  Números de comparações: " << j << " \n\n";
                InsereComparacoes(j);
                goto menu;

            }

        }

        cout << "Tempo gasto: " << (tf - to) / CLOCKS_PER_SEC * 1000 << " seg" << "  Números de comparações: " << j << " \n\n";

        arq.close();


        delete chave;
        delete dados1;
        delete dados2;

    }

    if (opcao == 0) {

        return 1;

    }

}

bool arvore_binaria() {

    int i, opcao, a = 0;
    double to, tf;
    TipoApontador p;
    TipoRegistro x, chavebusca;

    cout << "Selecione um dos arquivos abaixo para pesquisar:" << endl;
    cout << "0 - Voltar ao menu \n"
            "1 - Arquivo com 100 (cem) números  ordenados \n"
            "2 - Arquivo com 1000 (mil) números  ordenados \n"
            "3 - Arquivo com 10000 (dez mil) números  ordenados \n"
            "4 - Arquivo com 100000 (cem mil) números  ordenados \n"
            "5 - Arquivo com 100000 (um milhão) números  ordenados \n"
            "6 - Arquivo com 100 (cem) números  desordenados \n"
            "7 - Arquivo com 1000 (mil) números  desordenados \n"
            "8 - Arquivo com 10000 (dez mil) números  desordenados \n"
            "9 - Arquivo com 100000 (cem mil) números  desordenados \n"
            "10 - Arquivo com 100000 (um milhão) números  desordenados \n";
    cin>>opcao;

    if (opcao == 0) {

        return 1;

    }

    if (opcao == 9) {

        ifstream arq;
        arq.open("100000-desordenada.txt");


        Inicializa(&(p));
        cout << "Criando árvore...\n";


        for (i = 0; i < 100000; i++) {

            arq >> x.Chave >> x.dados1 >> x.dados2;
            InsereAVL(x, &(p));
            VerificaBalanceamento(&(p));
            cout << i + 1 << "º número inserido\n";

        }

        arq.close();

    }

    if (opcao == 4) {

        ifstream arq;
        arq.open("100000-ordenada.txt");


        Inicializa(&(p));
        cout << "Criando árvore...\n";


        for (i = 0; i < 100000; i++) {

            arq >> x.Chave >> x.dados1 >> x.dados2;
            InsereAVL(x, &(p));
            VerificaBalanceamento(&(p));
            cout << i + 1 << "º número inserido\n";

        }

        arq.close();

    }

    if (opcao == 5) {

        ifstream arq;
        arq.open("1000000-ordenada.txt");


        Inicializa(&(p));
        cout << "Criando árvore...\n";


        for (i = 0; i < 1000000; i++) {

            arq >> x.Chave >> x.dados1 >> x.dados2;
            InsereAVL(x, &(p));
            VerificaBalanceamento(&(p));
            cout << i + 1 << "º número inserido\n";

        }

        arq.close();

    }

    if (opcao == 10) {

        ifstream arq;
        arq.open("1000000-desordenada.txt");


        Inicializa(&(p));
        cout << "Criando árvore...\n";


        for (i = 0; i < 1000000; i++) {

            arq >> x.Chave >> x.dados1 >> x.dados2;
            InsereAVL(x, &(p));
            VerificaBalanceamento(&(p));
            cout << i + 1 << "º número inserido\n";

        }

        arq.close();

    }

menu:

    cout << "Digite a chave a ser buscada:\n";
    cin >> chavebusca.Chave;

    if (chavebusca.Chave == 98765) {

        return 1;

    }

    if (opcao == 1) {

        ifstream arq;
        arq.open("100-ordenada.txt");


        Inicializa(&(p));
        cout << "Criando árvore...\n";


        for (i = 0; i < 100; i++) {

            arq >> x.Chave >> x.dados1 >> x.dados2;
            Insere(x, &(p));

        }

        cout << "Pesquisando...\n";

        to = clock();
        Pesquisa(&(chavebusca), &(p), a);
        tf = clock();

        arq.close();

        cout << "Tempo gasto: " << (tf - to) / CLOCKS_PER_SEC * 1000 << " seg\n\n";

        ofstream saidas("Chaves.txt", ios::app);
        saidas << chavebusca.Chave << "    " << (tf - to) / CLOCKS_PER_SEC * 1000 << endl;

        goto menu;

    }

    if (opcao == 2) {

        ifstream arq;
        arq.open("1000-ordenada.txt");


        Inicializa(&(p));
        cout << "Criando árvore...\n";


        for (i = 0; i < 1000; i++) {

            arq >> x.Chave >> x.dados1 >> x.dados2;
            Insere(x, &(p));

        }

        cout << "Pesquisando...\n";

        to = clock();
        Pesquisa(&(chavebusca), &(p), a);
        tf = clock();

        arq.close();

        cout << "Tempo gasto: " << (tf - to) / CLOCKS_PER_SEC * 1000 << " seg\n\n";

        ofstream saidas("Chaves.txt", ios::app);
        saidas << chavebusca.Chave << "    " << (tf - to) / CLOCKS_PER_SEC * 1000 << endl;

        goto menu;

    }

    if (opcao == 3) {

        ifstream arq;
        arq.open("10000-ordenada.txt");


        Inicializa(&(p));
        cout << "Criando árvore...\n";


        for (i = 0; i < 10000; i++) {

            arq >> x.Chave >> x.dados1 >> x.dados2;
            Insere(x, &(p));

        }

        cout << "Pesquisando...\n";

        to = clock();
        Pesquisa(&(chavebusca), &(p), a);
        tf = clock();

        arq.close();

        cout << "Tempo gasto: " << (tf - to) / CLOCKS_PER_SEC * 1000 << " seg\n\n";

        ofstream saidas("Chaves.txt", ios::app);
        saidas << chavebusca.Chave << "    " << (tf - to) / CLOCKS_PER_SEC * 1000 << endl;

        goto menu;

    }

    if (opcao == 4) {

        cout << "Pesquisando...\n";

        to = clock();
        Pesquisa(&(chavebusca), &(p), a);
        tf = clock();

        cout << "Tempo gasto: " << (tf - to) / CLOCKS_PER_SEC * 1000 << " seg\n\n";

        ofstream saidas("Chaves.txt", ios::app);
        saidas << chavebusca.Chave << "    " << (tf - to) / CLOCKS_PER_SEC * 1000 << endl;

        goto menu;

    }

    if (opcao == 5) {

        cout << "Pesquisando...\n";

        to = clock();
        Pesquisa(&(chavebusca), &(p), a);
        tf = clock();

        cout << "Tempo gasto: " << (tf - to) / CLOCKS_PER_SEC * 1000 << " seg\n\n";

        ofstream saidas("Chaves.txt", ios::app);
        saidas << chavebusca.Chave << "    " << (tf - to) / CLOCKS_PER_SEC * 1000 << endl;

        goto menu;

    }

    if (opcao == 6) {

        ifstream arq;
        arq.open("100-desordenada.txt");


        Inicializa(&(p));
        cout << "Criando árvore...\n";


        for (i = 0; i < 100; i++) {

            arq >> x.Chave >> x.dados1 >> x.dados2;
            Insere(x, &(p));

        }

        cout << "Pesquisando...\n";

        to = clock();
        Pesquisa(&(chavebusca), &(p), a);
        tf = clock();

        arq.close();

        cout << "Tempo gasto: " << (tf - to) / CLOCKS_PER_SEC * 1000 << " seg\n\n";

        ofstream saidas("Chaves.txt", ios::app);
        saidas << chavebusca.Chave << "    " << (tf - to) / CLOCKS_PER_SEC * 1000 << endl;

        goto menu;

    }

    if (opcao == 7) {

        ifstream arq;
        arq.open("1000-desordenada.txt");


        Inicializa(&(p));
        cout << "Criando árvore...\n";


        for (i = 0; i < 1000; i++) {

            arq >> x.Chave >> x.dados1 >> x.dados2;
            Insere(x, &(p));

        }

        cout << "Pesquisando...\n";

        to = clock();
        Pesquisa(&(chavebusca), &(p), a);
        tf = clock();

        arq.close();

        cout << "Tempo gasto: " << (tf - to) / CLOCKS_PER_SEC * 1000 << " seg\n\n";

        ofstream saidas("Chaves.txt", ios::app);
        saidas << chavebusca.Chave << "    " << (tf - to) / CLOCKS_PER_SEC * 1000 << endl;

        goto menu;

    }

    if (opcao == 8) {

        ifstream arq;
        arq.open("10000-desordenada.txt");


        Inicializa(&(p));
        cout << "Criando árvore...\n";


        for (i = 0; i < 10000; i++) {

            arq >> x.Chave >> x.dados1 >> x.dados2;
            Insere(x, &(p));

        }

        cout << "Pesquisando...\n";

        to = clock();
        Pesquisa(&(chavebusca), &(p), a);
        tf = clock();

        arq.close();

        cout << "Tempo gasto: " << (tf - to) / CLOCKS_PER_SEC * 1000 << " seg\n\n";

        ofstream saidas("Chaves.txt", ios::app);
        saidas << chavebusca.Chave << "    " << (tf - to) / CLOCKS_PER_SEC * 1000 << endl;

        goto menu;

    }

    if (opcao == 9) {

        cout << "Pesquisando...\n";

        to = clock();
        Pesquisa(&(chavebusca), &(p), a);
        tf = clock();

        cout << "Tempo gasto: " << (tf - to) / CLOCKS_PER_SEC * 1000 << " seg\n\n";

        ofstream saidas("Chaves.txt", ios::app);
        saidas << chavebusca.Chave << "    " << (tf - to) / CLOCKS_PER_SEC * 1000 << endl;

        goto menu;

    }

    if (opcao == 10) {

        cout << "Pesquisando...\n";

        to = clock();
        Pesquisa(&(chavebusca), &(p), a);
        tf = clock();

        cout << "Tempo gasto: " << (tf - to) / CLOCKS_PER_SEC * 1000 << " seg\n\n";

        ofstream saidas("Chaves.txt", ios::app);
        saidas << chavebusca.Chave << "    " << (tf - to) / CLOCKS_PER_SEC * 1000 << endl;

        goto menu;

    }

}

bool arvore_AVL() {

    int i, opcao, a = 0;
    double to, tf;
    TipoApontador p;
    TipoRegistro x, chavebusca;

    cout << "Selecione um dos arquivos abaixo para pesquisar:" << endl;
    cout << "0 - Voltar ao menu \n"
            "1 - Arquivo com 100 (cem) números  ordenados \n"
            "2 - Arquivo com 1000 (mil) números  ordenados \n"
            "3 - Arquivo com 10000 (dez mil) números  ordenados \n"
            "4 - Arquivo com 100000 (cem mil) números  ordenados \n"
            "5 - Arquivo com 100000 (um milhão) números  ordenados \n"
            "6 - Arquivo com 100 (cem) números  desordenados \n"
            "7 - Arquivo com 1000 (mil) números  desordenados \n"
            "8 - Arquivo com 10000 (dez mil) números  desordenados \n"
            "9 - Arquivo com 100000 (cem mil) números  desordenados \n"
            "10 - Arquivo com 100000 (um milhão) números  desordenados \n";
    cin>>opcao;

    if (opcao == 0) {

        return 1;

    }

    if (opcao == 9) {

        ifstream arq;
        arq.open("100000-desordenada.txt");


        Inicializa(&(p));
        cout << "Criando árvore...\n";

        for (i = 0; i < 100000; i++) {

            arq >> x.Chave >> x.dados1 >> x.dados2;
            InsereAVL(x, &(p));
            VerificaBalanceamento(&(p));
            cout << i + 1 << "º número inserido\n";

        }

        arq.close();

    }

    if (opcao == 4) {

        ifstream arq;
        arq.open("100000-ordenada.txt");

        Inicializa(&(p));
        cout << "Criando árvore...\n";

        for (i = 0; i < 100000; i++) {

            arq >> x.Chave >> x.dados1 >> x.dados2;
            InsereAVL(x, &(p));
            VerificaBalanceamento(&(p));
            cout << i + 1 << "º número inserido\n";

        }

        arq.close();

    }

    if (opcao == 5) {

        ifstream arq;
        arq.open("1000000-ordenada.txt");


        Inicializa(&(p));
        cout << "Criando árvore...\n";


        for (i = 0; i < 1000000; i++) {

            arq >> x.Chave >> x.dados1 >> x.dados2;
            InsereAVL(x, &(p));
            VerificaBalanceamento(&(p));
            cout << i + 1 << "º número inserido\n";

        }

        arq.close();

    }

    if (opcao == 10) {

        ifstream arq;
        arq.open("1000000-desordenada.txt");


        Inicializa(&(p));
        cout << "Criando árvore...\n";


        for (i = 0; i < 1000000; i++) {

            arq >> x.Chave >> x.dados1 >> x.dados2;
            InsereAVL(x, &(p));
            VerificaBalanceamento(&(p));
            cout << i + 1 << "º número inserido\n";

        }

        arq.close();

    }


menu:

    cout << "Digite a chave a ser buscada:\n";
    cin >> chavebusca.Chave;

    if (chavebusca.Chave == 98765) {

        return 1;

    }

    if (opcao == 1) {

        ifstream arq;
        arq.open("100-ordenada.txt");


        Inicializa(&(p));
        cout << "Criando árvore...\n";


        for (i = 0; i < 100; i++) {

            arq >> x.Chave >> x.dados1 >> x.dados2;
            InsereAVL(x, &(p));
            VerificaBalanceamento(&(p));

        }

        cout << "Pesquisando...\n";

        to = clock();
        Pesquisa(&(chavebusca), &(p), a);
        tf = clock();

        arq.close();

        cout << "Tempo gasto: " << (tf - to) / CLOCKS_PER_SEC * 1000 << " seg\n\n";

        ofstream saidas("Chaves.txt", ios::app);
        saidas << (tf - to) / CLOCKS_PER_SEC * 1000 << endl;

        goto menu;

    }

    if (opcao == 2) {

        ifstream arq;
        arq.open("1000-ordenada.txt");


        Inicializa(&(p));
        cout << "Criando árvore...\n";


        for (i = 0; i < 1000; i++) {

            arq >> x.Chave >> x.dados1 >> x.dados2;
            InsereAVL(x, &(p));
            VerificaBalanceamento(&(p));

        }

        cout << "Pesquisando...\n";

        to = clock();
        Pesquisa(&(chavebusca), &(p), a);
        tf = clock();

        arq.close();

        cout << "Tempo gasto: " << (tf - to) / CLOCKS_PER_SEC * 1000 << " seg\n\n";

        ofstream saidas("Chaves.txt", ios::app);
        saidas << (tf - to) / CLOCKS_PER_SEC * 1000 << endl;

        goto menu;

    }

    if (opcao == 3) {

        ifstream arq;
        arq.open("10000-ordenada.txt");


        Inicializa(&(p));
        cout << "Criando árvore...\n";


        for (i = 0; i < 10000; i++) {

            arq >> x.Chave >> x.dados1 >> x.dados2;
            InsereAVL(x, &(p));
            VerificaBalanceamento(&(p));

        }

        cout << "Pesquisando...\n";

        to = clock();
        Pesquisa(&(chavebusca), &(p), a);
        tf = clock();

        arq.close();

        cout << "Tempo gasto: " << (tf - to) / CLOCKS_PER_SEC * 1000 << " seg" << endl;

        ofstream saidas("Chaves.txt", ios::app);
        saidas << (tf - to) / CLOCKS_PER_SEC * 1000 << endl;

        goto menu;

    }

    if (opcao == 4) {

        cout << "Pesquisando...\n";

        to = clock();
        Pesquisa(&(chavebusca), &(p), a);
        tf = clock();

        cout << "Tempo gasto: " << (tf - to) / CLOCKS_PER_SEC * 1000 << " seg\n\n";

        ofstream saidas("Chaves.txt", ios::app);
        saidas << (tf - to) / CLOCKS_PER_SEC * 1000 << endl;

        goto menu;

    }

    if (opcao == 5) {

        cout << "Pesquisando...\n";

        to = clock();
        Pesquisa(&(chavebusca), &(p), a);
        tf = clock();

        cout << "Tempo gasto: " << (tf - to) / CLOCKS_PER_SEC * 1000 << " seg\n\n";

        ofstream saidas("Chaves.txt", ios::app);
        saidas << (tf - to) / CLOCKS_PER_SEC * 1000 << endl;

        goto menu;

    }

    if (opcao == 6) {

        ifstream arq;
        arq.open("100-desordenada.txt");


        Inicializa(&(p));
        cout << "Criando árvore...\n";


        for (i = 0; i < 100; i++) {

            arq >> x.Chave >> x.dados1 >> x.dados2;
            InsereAVL(x, &(p));
            VerificaBalanceamento(&(p));

        }

        cout << "Pesquisando...\n";

        to = clock();
        Pesquisa(&(chavebusca), &(p), a);
        tf = clock();

        arq.close();

        cout << "Tempo gasto: " << (tf - to) / CLOCKS_PER_SEC * 1000 << " seg\n\n";

        ofstream saidas("Chaves.txt", ios::app);
        saidas << (tf - to) / CLOCKS_PER_SEC * 1000 << endl;

        goto menu;

    }

    if (opcao == 7) {

        ifstream arq;
        arq.open("1000-desordenada.txt");


        Inicializa(&(p));
        cout << "Criando árvore...\n";


        for (i = 0; i < 1000; i++) {

            arq >> x.Chave >> x.dados1 >> x.dados2;
            InsereAVL(x, &(p));
            VerificaBalanceamento(&(p));

        }

        cout << "Pesquisando...\n";

        to = clock();
        Pesquisa(&(chavebusca), &(p), a);
        tf = clock();

        arq.close();

        cout << "Tempo gasto: " << (tf - to) / CLOCKS_PER_SEC * 1000 << " seg\n\n";

        ofstream saidas("Chaves.txt", ios::app);
        saidas << (tf - to) / CLOCKS_PER_SEC * 1000 << endl;

        goto menu;

    }

    if (opcao == 8) {

        ifstream arq;
        arq.open("10000-desordenada.txt");


        Inicializa(&(p));
        cout << "Criando árvore...\n";


        for (i = 0; i < 10000; i++) {

            arq >> x.Chave >> x.dados1 >> x.dados2;
            InsereAVL(x, &(p));
            VerificaBalanceamento(&(p));

        }

        cout << "Pesquisando...\n";

        to = clock();
        Pesquisa(&(chavebusca), &(p), a);
        tf = clock();

        arq.close();

        cout << "Tempo gasto: " << (tf - to) / CLOCKS_PER_SEC * 1000 << " seg\n\n";

        ofstream saidas("Chaves.txt", ios::app);
        saidas << (tf - to) / CLOCKS_PER_SEC * 1000 << endl;

        goto menu;

    }

    if (opcao == 9) {

        cout << "Pesquisando...\n";

        to = clock();
        Pesquisa(&(chavebusca), &(p), a);
        tf = clock();

        cout << "Tempo gasto: " << (tf - to) / CLOCKS_PER_SEC * 1000 << " seg\n\n";

        ofstream saidas("Chaves.txt", ios::app);
        saidas << (tf - to) / CLOCKS_PER_SEC * 1000 << endl;

        goto menu;

    }

    if (opcao == 10) {

        cout << "Pesquisando...\n";

        to = clock();
        Pesquisa(&(chavebusca), &(p), a);
        tf = clock();

        cout << "Tempo gasto: " << (tf - to) / CLOCKS_PER_SEC * 1000 << " seg\n\n";

        ofstream saidas("Chaves.txt", ios::app);
        saidas << (tf - to) / CLOCKS_PER_SEC * 1000 << endl;

        goto menu;

    }

}

int main(int argc, char *argv[]) {

    int opcao;

menu:
    cout << "1 - Criar arquivo ordenado de 100 (cem) \n"
            "2 - Criar arquivo ordenado de 1000 (mil) \n"
            "3 - Criar arquivo ordenado de 10000 (dez mil) \n"
            "4 - Criar arquivo ordenado de 100000 (cem mil) \n"
            "5 - Criar arquivo ordenado de 1000000 (um milhão) \n"
            "6 - Criar arquivo desordenado de 100 (cem) \n"
            "7 - Criar arquivo desordenado de 1000 (mil) \n"
            "8 - Criar arquivo desordenado de 10000 (dez mil) \n"
            "9 - Criar arquivo desordenado de 100000 (cem mil)  \n"
            "10 - Criar arquivo desordenado de 1000000 (um milhao) com repetição \n"
            "11 - Buscar chave em algum arquivo por Acesso Sequencial \n"
            "12 - Buscar chave em algum arquivo por Árvore Binária \n"
            "13 - Buscar chave em algum arquivo pela Árvore AVL \n"
            "0 - Sair \n";
    cin>>opcao;

    switch (opcao) {

        case 0:
            cout << "Até mais !" << endl;
            exit;
            break;

        case 1:
            ordena100();
            goto menu;
            break;

        case 2:
            ordena1000();
            goto menu;
            break;

        case 3:
            ordena10000();
            goto menu;
            break;

        case 4:
            ordena100000();
            goto menu;
            break;

        case 5:
            ordena1000000();
            goto menu;
            break;

        case 6:
            desordena100();
            goto menu;
            break;

        case 7:
            desordena1000();
            goto menu;
            break;

        case 8:
            desordena10000();
            goto menu;
            break;

        case 9:
            desordena100000();
            goto menu;
            break;

        case 10:
            desordena1000000();
            goto menu;
            break;

        case 11:
            if (acesso_sequencial() == 1) {

                goto menu;

            }

            break;

        case 12:
            if (arvore_binaria() == 1) {

                goto menu;

            }

            break;

        case 13:
            if (arvore_AVL() == 1) {

                goto menu;

            }

            break;

        default:
            cout << "Opção Inválida!\n";

    }

    return 0;

}