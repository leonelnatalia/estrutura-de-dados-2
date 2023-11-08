#include <stdio.h>
#define TAM 15

void bubleSort(int vetOrganizado[], int vetDesorganizado[])
{
    int aux, cont =0;
    for(int i=0; i<TAM; i++)
    {
        vetOrganizado[i]=vetDesorganizado[i];
    }
    for (int j = TAM -1; j>0; j--)
    {
        for(int i=0; i<j; i++)
        {
            cont++;
            if(vetOrganizado[i]>vetOrganizado[i+1])
            {
                aux = vetOrganizado[i];
                vetOrganizado[i] = vetOrganizado[i+1];
                vetOrganizado[i+1] = aux;
            }
        }
    }
    printf("\nIteracoes necessarias: %d \n", cont);

}

void selectSort(int vetOrganizado[], int vetDesorganizado[])
{
    int aux, cont = 0;
    for(int i=0; i<TAM; i++)
    {
        vetOrganizado[i]=vetDesorganizado[i];
    }
    for (int j = 0; j<TAM-1; j++)
    {
        for(int i=j+1; i<TAM; i++)
        {
            cont++;
            if(vetOrganizado[j]>vetOrganizado[i])
            {
                aux = vetOrganizado[i];
                vetOrganizado[i] = vetOrganizado[j];
                vetOrganizado[j] = aux;
            }
        }
    }
    printf("\nIteracoes necessarias: %d \n", cont);

}


int buscaSequencial(int chave, int vetOrganizado[])
{
    int i = 0;
    while (chave > vetOrganizado[i] && i<TAM)
    {
        i++;
    }
    printf("\nIteracoes necessarias: %d ", i+1);
    if(i<TAM && vetOrganizado[i] == chave)
    {
        return i;
    }
    else
    {
        return -1;
    }

}

int buscaBinaria(int chave, int vetOrganizado[])
{
    int i = 0;
    int inicio = 0;
    int fim = TAM-1;
    int meio;
    while (inicio<=fim)
    {
        meio = (inicio+fim)/2;
        if(chave == vetOrganizado[meio])
        {
            printf("\nIteracoes necessarias: %d", i+1);
            return meio;
        }
        if(chave < vetOrganizado[meio])
        {
            fim = meio -1;
        }
        else
        {
            inicio = meio + 1;
        }
        i++;
    }

    printf("\nIteracoes necessarias: %d", i+1);
    return -1;
}
void ler(int vetor[])
{
    printf("\nInsira os elementos do vetor: ");
    for(int i=0; i<TAM; i++)
    {
        scanf("%d", &vetor[i]);
    }
}

void main()
{
    int vetOrganizado[TAM];
    int vetDesorganizado[TAM];
    int chave, pos;

    int op = 1;
    while(op!=0)
    {
        printf("\n\n---------------------------------");
        printf("\nLer Vetor.......................1");
        printf("\nOrdenar por Buble-Sort..........2");
        printf("\nOrdenar por Select-Sort.........3");
        printf("\nBusca Sequencial................4");
        printf("\nBusca Binária...................5");
        printf("\nSair............................0");
        printf("\n---------------------------------\n");
        printf("\nOpcao: ");
        scanf("%d", &op);

        switch(op)
        {
        case 0:


            break;

        case 1:
            ler(vetDesorganizado);

            break;

        case 2:
            bubleSort(vetOrganizado, vetDesorganizado);
            for(int i=0; i<TAM; i++)
            {
                printf("| %d ", vetOrganizado[i]);
            }
            break;

        case 3:
            selectSort(vetOrganizado, vetDesorganizado);
            for(int i=0; i<TAM; i++)
            {
                printf("| %d ", vetOrganizado[i]);
            }
            break;


        case 4:
            printf("\nInsira a chave de pesquisa: ");
            scanf("%d", &chave);
            pos = buscaSequencial(chave, vetOrganizado);
            if(pos != -1)
            {
                printf("\nElemento encontrado na posicao %d", pos);
            }
            else
            {
                printf("\nElemento nao encontrado!");
            }

            break;

        case 5:
            printf("\nInsira a chave de pesquisa: ");
            scanf("%d", &chave);
            pos = buscaBinaria(chave, vetOrganizado);
            if(pos != -1)
            {
                printf("\nElemento encontrado na posicao %d", pos);
            }
            else
            {
                printf("\nElemento nao encontrado!");
            }


            break;


        }

    }

}
