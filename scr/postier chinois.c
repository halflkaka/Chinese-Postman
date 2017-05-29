#include <stdio.h>
#include <stdlib.h>
#include "dijkstra.h"
#include "Hungrois.h"
#include "Euler.h"

int sousGraph[N][N];//G' avec tous les sommet d'indice impair
int indice[N] = {0};//sommets d'indice impair
extern int nouveau_couplage[N];//variable globale de Hungrois.h
extern int pre[N];//variable globale de dijkstra.h

void init_sousGraph()//initialisation
{
    int i,j;
    for(i=0;i<N/2;i++){
        for(j=0;j<N/2;j++){
            sousGraph[i][j] = 0;
        }
    }
    return;
}

void init_indice()//initialisation
{
    int i,j,flag,k=0;
    for(i=0;i<N;i++){
        flag = 0;
        for(j=0;j<N;j++){
            flag += Adjacence[i][j];
        }
        if(flag % 2 != 0){//Si le degre est impair, ajouter ce sommet dans indice[N]
            indice[k++] = i;
        }
    }
    for(i=0;i<k;i++){
        printf("%d ",indice[i]);
    }
    printf("\n");
    return;
}

int main()
{
    int i,j;
    init_sousGraph();
    //construire le sousGraph, remplacer les poids des arrets par les poids minimaux entre eux
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            if(i == j){sousGraph[i][j] == INFINI;}
            else{
                sousGraph[i][j] = dijkstra(i,j);
            }
        }
    }
    //trouver le couplage maximal avec du poids minimal
    couplage_poids();
    //Doubler les plus courts chemins de G associ¨¦s au couplage trouv¨¦.
    for(i=0;i<N;i++){
        if(nouveau_couplage[i] != -1){
            nouveau_couplage[nouveau_couplage[i]] = -1;
            doubler(i,nouveau_couplage[i]);
        }
    }
    //trouver le cycle Eulerien
    Euler(0);
    return 0;
}
