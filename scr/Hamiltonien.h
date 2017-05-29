#include <stdio.h>
#include <stdlib.h>
#include "postier.h"

int label[N] = {0};//etiquer si le sommet a ete parcouru
int chemin[N][1];//enregistrer le sommet prochain de chaque sommet
int chemin_hamiltonien[N] = {0};//enregistrer le resultat: un chemin hamiltonien

void init_chemin()//initialisation du chemin
{
    int i;
    for(i=0;i<N;i++){
        chemin[i][0] = i;
    }
    return;
}

int label_test()//verifier si tous les sommet sont parcourus
{
    int i;
    for(i=0;i<N;i++){
        if(label[i] == 0){return 0;}
    }
    return 1;
}

void chemin_construire(int origine)//une translation de chemin a cycle hamitonien
{
    int i;
    for(i=0;i<N;i++){
        chemin_hamiltonien[i] = origine;
        origine = chemin[origine][0];
    }
    for(i=0;i<N-1;i++){
        printf("%d -> ",chemin_hamiltonien[i]);
    }
    printf("%d\n",chemin_hamiltonien[N-1]);
}

int cycleHamilton(int depart,int origine)//DFS & Back Propagation pour trouver le cycle hamiltonien
{
    int i;
    int arrive = -1;//Si le sommet peut aller a un autre sommet
    for(i=0;i<N;i++){
        if(Adjacence[depart][i] != 0 && label[i] == 0){//si ce sommet est accessible
            arrive = i;
            label[arrive] = 1;//etiquer

            chemin[depart][0] = arrive;//enregistrer
            //printf("depart:%d arrive:%d \n",depart+1,arrive+1);
            if(cycleHamilton(arrive,origine) == 1){return 1;}//Si trouver un cycle hamiltonien, c'est termine!
        }
    }
    if(arrive == -1 && !label_test()){//Si on a un cycle mais pas un cycle hamiltonien
        label[depart] = 0;//On enleve l'etiquette
        //printf("%d pas de chemin\n",depart+1);
        //print_label();
        return 0;
    }
    //else if(arrive == -1 && label_test()){printf("success!\n");print_chemin();flag = 1;return 1;}
    if(label_test() == 1 && Adjacence[depart][origine] != 0){//C'est la condion pour trouver un cycle hamiltonien
        chemin[depart][0] = origine;//Connecter l'origine et l'arrive
        //print_chemin();
        return 1;
    }
    else{
        label[depart] = 0;
        label[arrive] = 0;
        //printf("%d wrong\n",depart+1);
        //print_label();
        return 0;}
}

void hamiltonien(int origine)
{
    label[origine] = 1;
    cycleHamilton(origine,origine);
    chemin_construire(origine);
}
