#include <stdio.h>
#include <stdlib.h>
#include "dijkstra.h"
#include "Hungrois.h"
#include "Euler.h"

int sousGraph[N][N];//G' avec tous les sommet d'indice impair
int indice[N];//sommets d'indice impair
extern int nouveau_couplage[N];//variable globale de Hungrois.h
extern int pre[N];//variable globale de dijkstra.h
int Chemin[N*N];
int ans = 0;
int longueur = 0;

void init_chemin()
{
    int i;
    for(i=0;i<N*N;i++){
        Chemin[i] = -1;
    }
    return;
}

void init_sousGraph()//initialisation
{
    int i,j;
    for(i=0;i<N/2;i++){
        for(j=0;j<N/2;j++){
            sousGraph[i][j] = INFINI;
        }
    }
    return;
}

void init_indice()//initialisation
{
    int i,j,flag,k=0;
    for(i=0;i<N;i++){
        indice[i] = -1;
    }
    for(i=0;i<N;i++){
        flag = 0;
        for(j=0;j<N;j++){
            flag += Adjacence[i][j];
        }
        if(flag % 2 != 0){//Si le degre est impair, ajouter ce sommet dans indice[N]
            indice[k++] = i;
        }
    }
    printf("Sommets d'indice impaire sont:\n");
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
    init_indice();
    init_chemin();
    //construire le sousGraph, remplacer les poids des arrets par les poids minimaux entre eux
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            if(indice[i] != -1 && indice[j] != -1){
                if(i == j){sousGraph[i][j] == INFINI;}
                else{
                    sousGraph[i][j] = dijkstra(indice[i],indice[j]);
                }
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
    printf("le chemin eulerien:\n");
    Euler(0);
    for(i=0;i<longueur-1;i++){
        if(Chemin[i] != -1 && Chemin[i+1] != -1){
            ans += Kilometres[Chemin[i]][Chemin[i+1]];
        }
    }
    printf("poids total: %d\n",ans);
    return 0;
}
