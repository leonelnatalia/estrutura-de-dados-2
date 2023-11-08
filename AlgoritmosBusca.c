#include <stdio.h>
#define TAM 25

int buscaExaustiva(int chave, int vetDesorganizado[])
{
    int i = 0;
    while (vetDesorganizado[i]!=chave && i<TAM)
    {
        i++;
    }
    printf("\nIteracoes necessarias: %d", i+1);
    if(i<TAM && vetDesorganizado[i] == chave)
    {
        return i;
    }
    else
    {
        return -1;
    }
}

int buscaSequencial(int chave, int vetOrganizado[])
{
    int i = 0;
    while (chave > vetOrganizado[i] && i<TAM)
    {
        i++;
    }
    printf("\nIteracoes necessarias: %d", i+1);
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
        else {
            inicio = meio + 1;
        }
        i++;
    }

    printf("\nIteracoes necessarias: %d", i+1);
        return -1;


}

void main()
{
    int vetOrganizado[TAM];
    int vetDesorganizado[TAM]= {22,14,23,17,21,0,12,11,16,13,3,8,19,5,10,1,24,15,20,6,7,18,4,2,9};
    int chave, pos;

    for(int i = 0; i<TAM; i++)
    {
        vetOrganizado[i] = i;
    }

    printf("\nInsira a chave de pesquisa: ");
    scanf("%d", &chave);
    int op = 1;
    while(op!=0)
    {
        printf("\n\n---------------------------------");
        printf("\nBusca Exaustiva.................1");
        printf("\nBusca Sequencial................2");
        printf("\nBusca Binária...................3");
        printf("\nSair............................0");
        printf("\n---------------------------------\n");
        printf("\nOpcao: ");
        scanf("%d", &op);

        switch(op)
        {
        case 0:


            break;

        case 1:
            pos = buscaExaustiva(chave, vetDesorganizado);
            if(pos != -1)
            {
                printf("\nElemento encontrado na posicao %d", pos);
            }
            else
            {
                printf("\nElemento nao encontrado!");
            }

            break;

        case 2:
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

        case 3:
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
