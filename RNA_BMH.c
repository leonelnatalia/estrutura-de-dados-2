#include <stdio.h>
#include <string.h>

#define TAMANHO_MAXIMO 100

// Função para construir a tabela de salto com base no padrão
void construirTabelaSalto(char *padrao, int tamanhoPadrao, int tabelaSalto[256]) {
    for (int i = 0; i < 256; i++) {
        tabelaSalto[i] = tamanhoPadrao; // atribui para todos o tamanho do padrao (3)
    }
    for (int i = 0; i < tamanhoPadrao - 1; i++) {
        tabelaSalto[(unsigned char)padrao[i]] = tamanhoPadrao - 1 - i;// atribui para todas as letras o tamanho -1 -i exceto para o ultimo
    }
}

// Função para encontrar o codon de inicio e retornar sua posição
int encontrarCodonInicio(char *sequencia, char *padraoInicio) {
    int tamanhoSequencia = strlen(sequencia);
    int tamanhoPadrao = strlen(padraoInicio);
    int tabelaSalto[256];

    construirTabelaSalto(padraoInicio, tamanhoPadrao, tabelaSalto); // constroi tabela de salto

    int i = 0;
    while (i < tamanhoSequencia - tamanhoPadrao + 1) { // enquanto o i tiver antes da 3º ultimo caractere do textox
        int j = tamanhoPadrao - 1; // j começa com 2

        while (j >= 0 && sequencia[i + j] == padraoInicio[j]) { // se a posicao j do texto for igual a posicao j do padrao

            j--; // j decrementa para comparar a letra q vem antes
        }

        if (j == -1) { // se j for -1 é pq ele passou 3 vezes pelo whille ent encontrou
            return i; // Retorna a posição do codon de inicio
        }
        i += tabelaSalto[(unsigned char)sequencia[i + j]]; // se nao ele consulta a tabela de salto e vai pra proxima comparação
        //tabela de salto na posicao do unsigned char (asc) da sequencia na posicao j + i
    }

    return -1; // Retorna -1 se o codon de inicio não for encontrado
}

// Função para encontrar o codon de parada após a posição do codon de inicio
int encontrarCodonParada(char *sequencia, int posicaoInicio, char *padraoParada) {
    int tamanhoSequencia = strlen(sequencia);
    int tamanhoPadrao = strlen(padraoParada);
    int tabelaSalto[256];

    construirTabelaSalto(padraoParada, tamanhoPadrao, tabelaSalto); // constroi tabela de salto

    int i = posicaoInicio + tamanhoPadrao; // Começa a busca após o codon de inicio posicao do primeiro
    while (i < tamanhoSequencia - tamanhoPadrao + 1) {
        int j = tamanhoPadrao - 1;

        while (j >= 0 && sequencia[i + j] == padraoParada[j]) {
            j--;
        }

        if (j == -1) {
            return i; // Retorna a posição do codon de parada
        }

        i += tabelaSalto[(unsigned char)sequencia[i + j]];
    }

    return -1; // Retorna -1 se o codon de parada não for encontrado
}

int main() {
    char sequencia[TAMANHO_MAXIMO];

    printf("Digite a sequencia de RNA: ");
    scanf("%s", sequencia);

    char padraoInicio[] = "AUG";
    char padraoParada1[] = "UAA";
    char padraoParada2[] = "UAG";
    char padraoParada3[] = "UGA";

    int posicaoInicio = encontrarCodonInicio(sequencia, padraoInicio);

    if (posicaoInicio != -1) {
        int posicaoParada = -1; // Inicializa com valor inválido

        if ((posicaoParada = encontrarCodonParada(sequencia, posicaoInicio, padraoParada1)) != -1) {
            printf("Codon de inicio AUG encontrado na posicao %d.\n", posicaoInicio);
            printf("Codon de parada UAA encontrado na posicao %d.\n", posicaoParada);
        } else if ((posicaoParada = encontrarCodonParada(sequencia, posicaoInicio, padraoParada2)) != -1) {
            printf("Codon de inicio AUG encontrado na posicao %d.\n", posicaoInicio);
            printf("Codon de parada UAG encontrado na posicao %d.\n", posicaoParada);
        } else if ((posicaoParada = encontrarCodonParada(sequencia, posicaoInicio, padraoParada3)) != -1) {
            printf("Codon de inicio AUG encontrado na posicao %d.\n", posicaoInicio);
            printf("Codon de parada UGA encontrado na posicao %d.\n", posicaoParada);
        }

        if (posicaoParada != -1) {
            // Imprime a sequencia entre o codon de inicio e o codon de parada
            printf("Sequencia entre os codons de inicio e parada: ");
            for (int i = posicaoInicio + strlen(padraoInicio); i < posicaoParada; i++) {
                printf("%c", sequencia[i]);
            }
            printf("\n");
        } else {
            printf("Codon de inicio AUG encontrado na posicao %d, mas o codon de parada nao foi encontrado.\n", posicaoInicio);
        }
    } else {
        printf("Codon de inicio AUG nao encontrado na sequencia.\n");
    }

    return 0;
}
