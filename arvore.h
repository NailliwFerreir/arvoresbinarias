#ifndef ARVORE_H_INCLUDED
#define ARVORE_H_INCLUDED
#include <stdio.h>
#include<stdlib.h>

typedef struct NoArvore
{
 int info;
 struct NoArvore *esq, *dir;
}NoArv;

typedef struct Arvore
{
    NoArv *raiz;
}Arv;

Arv *CriaArv (){
    Arv* aux;
    aux = (Arv*)malloc(sizeof(Arv));
    aux->raiz = NULL;
    return aux;
}

int ArvVazia(Arv *base){
    if(base->raiz==NULL){
        return 1;
    }
    return 0;
}

Arv *InsereArv (Arv *aux, int num){
    NoArv *Pai;
    NoArv *novo = (NoArv *)malloc(sizeof(NoArv));
    novo->esq = NULL;
    novo->dir = NULL;
    novo->info = num;
    if(aux==NULL){
        return novo;
    }
    else{
        Pai = aux;
        int flag=0;
        while(flag==0){
            if(num>Pai->info){
                if(Pai->dir==NULL){
                    Pai->dir=novo;
                    flag=1;
                }
                else{
                    Pai = Pai->dir;
                }
            }
            if(num<Pai->info){
                if(Pai->esq==NULL){
                    Pai->esq=novo;
                    flag=1;
                }
                else{
                    Pai = Pai->esq;
                }
            }
        }
    }
    return aux;
}

void insere (Arv *Arvore, int num)
{
    Arvore->raiz=InsereArv(Arvore->raiz,num);
}

void PreOrder (NoArv *aux)
{
    printf("- %d -", aux->info);
    if(aux->dir!=NULL)
    {
        PreOrder(aux->dir);
    }
    if(aux->esq!=NULL)
    {
        PreOrder(aux->esq);
    }
}
void PosOrder (NoArv *aux)
{
    
    if(aux->dir!=NULL)
    {
        PosOrder(aux->dir);
    }
    if(aux->esq!=NULL)
    {
        PosOrder(aux->esq);
    }
    printf("- %d -", aux->info);
}
void InOrder (NoArv *aux)
{
   
    if(aux->dir!=NULL)
    {
        InOrder(aux->dir);
    } 
    printf("- %d -", aux->info);
    if(aux->esq!=NULL)
    {
        InOrder(aux->esq);
    }
}

void SomeArv (NoArv *aux, int *soma)
{

    *soma+=aux->info;
    if(aux->dir!=NULL)
    {
        SomeArv(aux->dir, soma);
    }

    if(aux->esq!=NULL)
    {
        SomeArv(aux->esq, soma);
    }     
}

void ContaPArv (NoArv *aux, int *cp)
{
    if((aux->info%2)==0)
    {
        *cp+=1;
    }
    if(aux->dir!=NULL)
    {
        ContaPArv(aux->dir,cp);
    }
    if(aux->esq!=NULL)
    {
        ContaPArv(aux->esq,cp);
    }
}


int noNivel (NoArv *Pai, int num)
{
    int nivel=-1;
    int flag =1;
    while(flag==1)
    {
        nivel=nivel+1;
        if(Pai->info==num)
        {
            flag=0;
        }else{
            if (num>Pai->info)
            {
                if(Pai->dir!=NULL)
                {
                    Pai=Pai->dir;
                }else{
                    flag=-1;
                    nivel=-1;
                }
            }else{
                if(Pai->esq!=NULL)
                {
                    Pai=Pai->esq;
                }else{
                    flag=-1;
                    nivel=-1;
                }
            }
        }
    }
    return nivel;
}

int NoINterno(NoArv *Pai)//tem pelo menos um filho
{
    int cont=0;
    if((Pai->dir!=NULL)||(Pai->esq!=NULL))
    {
        cont+=1;
    }
    if(Pai->dir!=NULL)
    {
        cont+=NoINterno(Pai->dir);
    }
    if(Pai->esq!=NULL)
    {
        cont+=NoINterno(Pai->esq);
    }
    return cont;
}// na programa principal se deve decrementar um 

int NoFolha(NoArv *Pai)//contar nós folhas ou seja nos que nao tem filhos
{
    int cont=0;
    if((Pai->dir==NULL)&&(Pai->esq==NULL)){
        cont+=1;
    }
    if(Pai->dir!=NULL)
    {
        cont+=NoFolha(Pai->dir);
    }
    if(Pai->esq!=NULL)
    {
        cont+=NoFolha(Pai->esq);
    }
    return cont;
} 

int NosDescendentes (NoArv *Pai, int num)
{
    int descendente=-1;
    int flag =1;
    while(flag==1)
    {
        if(Pai->info==num)
        {
            if (num>Pai->info)
            {
                if(Pai->dir!=NULL)
                {        
                    descendente+=1;
                    Pai=Pai->dir;
                }else if(Pai->esq!=NULL)
                {
                    descendente+=1;
                    Pai=Pai->esq;
                }
                flag=0;
            }   
        }else{
            if (num>Pai->info)
            {
                if(Pai->dir!=NULL)
                {        
                    Pai=Pai->dir;
                }else if(Pai->esq!=NULL)
                {
                    Pai=Pai->esq;
                }
                flag=0;
            }
        }
    }
    return descendente;
}

int ContaNo(NoArv *Pai)
{    int cont=0;
    if(Pai->dir!=NULL)
    {
        cont+=1+ContaNo(Pai->dir);
    }
    if(Pai->esq!=NULL)
    {
        cont+=1+ContaNo(Pai->esq);
    }
    return cont;
} 

#endif

/*
int funcaoExiste(Arv *aux, int num){
    NoArv *Pai;
    Pai = aux;
    int flag=2;
    if(Pai->info==num){
        flag 1;
    }
    else{
        
        while(flag==2){
            if(num>Pai->info){
                while (Pai!=NULL)
                {
                    if(num==Pai->info)
                    {
                        flag=1;
                    }
                    Pai = Pai->dir;
                }
                
            }
            if(num<Pai->info){
                while (Pai!=NULL)
                {
                    if(num==Pai->info)
                    {
                        flag=1;
                    }
                    Pai = Pai->esq;
                }
            }
            flag=0;
        }
    }
    return flag;
}  

void ExisteNaArv(NoArv *aux,int confere){
    int verify=0;
    verify=funcaoExiste(aux,confere);
    switch(verify)
    {
        case 1:
        printf("\n \nEste numero existe na arvore!");
    break;
    case2:
        printf("\n \nNao existe na arvore."); 
        break; 
    }
}


void ContaNo (NoArv *aux,int *conta)//passa o parametro iniciado com zero
{
    *conta+=1;
    if(aux->dir!=NULL)
    {
        ContaNo(aux->dir,conta);
    }
    if(aux->esq!=NULL)
    {
        ContaNo(aux->esq,conta);
    }
}

int ContaNos (NoArv *aux)
{
    int cont=1;
    if(aux->dir!=NULL)
    {
        cont= cont+ContaNos(aux->dir,conta);
    }
    if(aux->esq!=NULL)
    {
        cont=cont+ContaNos(aux->esq,conta);
    }
    return cont;
}



*/