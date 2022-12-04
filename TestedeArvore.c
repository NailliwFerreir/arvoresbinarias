#include<stdio.h>
#include<stdlib.h>
#include "arvore.h"

int main ()
{
    system("cls");
    int contp=0,soma=0,nivel=0;
    Arv *arvore = NULL;
    arvore = CriaArv();

    if(ArvVazia(arvore))
    {
        printf("\n \nIniciando com a arvore vazia OK\n \n");
    }
    insere(arvore,50);
    insere(arvore,10);
    insere(arvore,80);
    insere(arvore,90);
    insere(arvore,70);
    insere(arvore,25);
    insere(arvore,5);
    insere(arvore,6);
    insere(arvore,2);


    printf("\n \nImprimindo com PreOrder! \n");
    PreOrder(arvore->raiz); 

    printf("\n \nImprimindo com InOrder! \n");
    InOrder(arvore->raiz);

    printf("\n \nImprimindo com PosOrder! \n");
    PosOrder(arvore->raiz);

    printf("\n \nSomando dos valores da Arvore eh:");
    SomeArv (arvore->raiz,&soma);    
    printf(" %d.",soma);

    printf("\n \nContando os valores pares da Arvore e sao:");
    ContaPArv (arvore->raiz,&contp);    
    printf(" %d.",contp);

    printf("\n \nO nivel da arvore eh :%d\n",noNivel(arvore->raiz,2));

    printf("\n \nContando NOS internos de uma arvore:%d\n",NoINterno(arvore->raiz));//tem q tirar um 

    printf("\n \nQuantos NOS folha tem uma arvore:%d\n",NoFolha(arvore->raiz));
    //ExisteNaArv(arvore->raiz,34);
    printf("\n \nContando NOS de uma arvore:%d\n",ContaNo(arvore->raiz));//tem q tirar um 


    printf("\n \n \n");
    return 0;
}