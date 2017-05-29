#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
//#include <limits.h>
//#define INFINI INT_MAX
//#define N 6
//#include "Edmonds.h"//Edmonds est pour trouver le couplage maximal, mais ici je n'ai pas l'utilise en fait

/*int Kilometres[N][N] = {
    {INFINI,1,3,2,1,2},
    {1,INFINI,3,1,2,3},
    {3,3,INFINI,5,3,2},
    {2,1,5,INFINI,2,3},
    {1,2,3,2,INFINI,1},
    {2,3,2,3,1,INFINI}};*///un exemple du cours, le poids minimal de couplage maximal est bien 4!(peut etre verifier)

extern int impaire[N];
extern int sousGraph[N][N];

int copy_couplage[N];//enregistrer le couplage

int pi = 100000;//poids minimal

int poids = 0;//le poids minimal de couplage maximal

int Arret[N][N];//enregistrer les arrets qui sont lies

int etiquer[N] = {0};//Si le sommet a ete etique

int copy_etique[N] = {0};//enregistrer l'etique

int nouveau_couplage[N];//Si le sommet est dans le couplage



void copyEtique()//copy etiquer to copy_etique
{
    int i;
    for(i=0;i<N;i++){
        copy_etique[i] = etiquer[i];
    }
    return;
};

void copytoEtique()//copy copy_etique to etiquer
{
    int i;
    for(i=0;i<N;i++){
        etiquer[i] = copy_etique[i];
    }
    return;
};

void Arret_lier()//lier les arrets
{
    int i,j;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            Arret[i][j] = -1;
        }
    }
    for(i=0;i<N;i++){
        int k = 0;
        for(j=0;j<N;j++){
            if(sousGraph[i][j] != INFINI){
                Arret[i][k++] = j;
            }
        }
    }
    return;
};

void refreshEtique()//renouveler l'etique apres chaque tour de cherche
{
    int i;
    for(i=0;i<N;i++){
        if(nouveau_couplage[i] != -1){
            etiquer[i] = 1;
        }
        else{
            etiquer[i] = 0;
        }
    }
    return;
};

void init_nouvcouplage()//initialisation de couplage
{
    int i;
    for(i=0;i<N;i++){
        nouveau_couplage[i] = -1;
    }
    return;
};

void init_copyCouplage()//initialisation de copy_couplage
{
    int i;
    for(i=0;i<N;i++){
        copy_couplage[i] = -1;
    }
    return;
};

void copyCouplage()//copy nouveau_couplage to copy_couplage
{
    int i;
    for(i=0;i<N;i++){
        copy_couplage[i] = nouveau_couplage[i];
    }
    return;
};

void copyNouveauCouplage()//copy copy_couplage to nouveau_couplage
{
    int i;
    for(i=0;i<N;i++){
        nouveau_couplage[i] = copy_couplage[i];
    }
    return;
};

void print_Arret()//c'est juste pour trouver les bugs
{
    int i,j;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            if(Arret[i][j] != -1){
                printf("point adjacent of %d:%d\n",i,Arret[i][j]);
            }
        }
    }
    return;
};

int DFS(int depart,int start)//depth first search pour trouver un chemin augmentant de tous les sommets
{
    int i;
    etiquer[depart] = 1;
    for(i=start;i<N;i++){
        if(Arret[depart][i] != -1){
            int arrive = Arret[depart][i];
            if(etiquer[arrive] == 0){
                etiquer[arrive] = 1;
                //print_couplage();
                //printf("couplage of %d is %d\n",arrive,nouveau_couplage[arrive]);
                if(nouveau_couplage[arrive] == -1 || DFS(nouveau_couplage[arrive],0)){
                    nouveau_couplage[arrive] = depart;
                    nouveau_couplage[depart] = arrive;
                    //printf("newcouplage{%d,%d} of dfs(%d,%d),sum is %d\n",depart,nouveau_couplage[depart],depart,start,sum_couplage());
                    return 1;
                }
            }
        }
    }
    return 0;
};

int sum_couplage()//calculer le poids du couplage
{
    int i,sum = 0;
    for(i=0;i<N;i++){
        if(nouveau_couplage[i] != -1){
            sum += sousGraph[i][nouveau_couplage[i]];
        }
    }
    return (sum / 2);
};

void init_etiquer()//initialisation de l'etique
{
    int i;
    for(i=0;i<N;i++){
        etiquer[i] = 0;
    }
    return;
};

void print_couplage()//pour verifier
{
    int i;
    for(i=0;i<N;i++){
        if(nouveau_couplage[i] != -1){
            printf("{%d,%d}\n",i,nouveau_couplage[i]);
        }
    }
    return;
};

void print_etique()//pour verifier
{
    int i;
    for(i=0;i<N;i++){
        if(etiquer[i] != 0){
            printf("%d is etique\n",i);
        }
    }
    return;
};

int couplage_poids()
{
    int i,j,k,flag = 0;
    //initialisation
    Arret_lier();
    init_copyCouplage();
    init_nouvcouplage();

    //trouver tous les chemins augmentants partir de chaque sommet

    for(k=0;k<N;k++){//Trouver le poids minimal
        for(i=0;i<N;i++){
            if(etiquer[i] == 0){
                for(j=0;j<N;j++){
                    init_etiquer();
                    if(DFS(i,j) == 1){//Si le chemin augmentant existe
                        poids = sum_couplage();
                        if(poids < pi){pi = poids;}//modifier le poids minimal
                        copyNouveauCouplage();//important! Le couplage doit etre enregistre, sinon DFS aura le probleme
                    }
                    refreshEtique();
                }
            }
        }

        if(pi == 10000){break;}//Si il n'y a pas de chemin augmentant, c'est termine!

        for(i=0;i<N;i++){//Rechercher le poids minimal pour renouveler le couplage
            if(etiquer[i] == 0){
                init_etiquer();
                for(j=0;j<N;j++){
                    if(DFS(i,j) == 1){
                        poids = sum_couplage();

                        if(poids == pi){//On l'a trouver!
                            pi = 10000;
                            flag = 1;
                            copyCouplage();//nouveau couplage
                            copyEtique();//nouvelle etique
                            refreshEtique();
                            break;
                        }
                        else{
                            copyNouveauCouplage();
                            init_etiquer();
                        }
                    }
                }
                if(flag != 0){flag = 0;break;}
            }
        }
    }
    //print_couplage();
    //printf("%d\n",poids);
    return poids;
}
