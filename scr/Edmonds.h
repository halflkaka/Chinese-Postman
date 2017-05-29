#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include "postier.h"
#include "mystack.h"
//#define N 6

// Definie une pile pour enregistrer le couplage

//Definie des etiquettes pour tous les sommets
typedef struct etiquette
{
    int origine;
    int paire;
    int pre;
}etiquette;
/*int Adjacence[N][N] = {
    {0,1,1,0,0,1},
    {1,0,0,1,1,1},
    {1,0,0,1,0,0},
    {0,1,1,0,1,0},
    {0,1,0,1,0,0},
    {1,1,0,0,0,0}};*/
pile Couplage;//couplage
int couplage[N][1] = {0};//marque de couplage
int marque_arret[N][N];
etiquette etique[N];//etiquette des sommets
void init_etique()
{
    int i;
    for(i=0;i<N;i++){
        etique[i].origine = 0;
        etique[i].paire = 0;
        etique[i].pre = 0;
    }
    return;
};
void init_marque()
{
    int i,j;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            marque_arret[i][j] = 0;
        }
    }
    return;
};
int dans_Couplage(int point)
{
    int i;
    if(couplage[point][0] != 0){return 1;}
    for(i = 0;i < N;i++){
        if(couplage[i][0] == point + 1){
            return 1;
        }
    }
    return 0;
}
void renouveler_Couplage(int s)
{
    while(Couplage.length != 0){
        int x = topx(&Couplage);
        int y = topy(&Couplage);
        couplage[x][0] = 0;
        couplage[y][0] = 0;
        pop(&Couplage);
    }
    //push(x,y,&Couplage);
    int n = N;
    int i;
    while(n-- > 0){
        for(i=0;i<N;i++){
            if(etique[i].pre == s + 1 && etique[i].paire == 1){
                push(i+1,s+1,&Couplage);
                couplage[i][0] = s + 1;
                couplage[s][0] = i + 1;
                printf("{%d,%d}\n",i+1,s+1);
                s = i;
                break;
            }
            else if(etique[i].pre == s + 1 && etique[i].paire == 0){
                s = i;
                break;
            }
        }
    }

}
void etape2(int x,int s)
{
    int y;
    for(y = 0;y < N;y++){
        if(Adjacence[x][y] == 1 && marque_arret[x][y] == 0 && etique[x].origine == s + 1 && etique[x].paire == 0){
            if(etique[y].origine == 0 && !dans_Couplage(y)){
                couplage[x][0] = y + 1;//{x,y} x+1=x, y+1=y
                //push(x+1,y+1,&Couplage);
                //couplage[y][0] = x + 1;
                //printf("couplage{%d,%d}\n",x+1,y+1);
                etique[y].origine = s + 1;
                etique[y].paire = 1;
                etique[y].pre = x + 1;
                printf("couplage de %d a %d\n",s+1,y+1);
                return;
            }
            else if(etique[y].origine == 0 && dans_Couplage(y)){
                couplage[x][0] = y + 1;
                int z = couplage[y][0] - 1;//position of z
                etique[y].origine = s + 1;
                etique[y].paire = 1;
                etique[y].pre = x + 1;
                etique[z].origine = s + 1;
                etique[z].paire = 0;
                etique[z].pre = y + 1;
                int i;
                for(i = 0;i < N;i++){
                    marque_arret[i][y] = 1;
                    marque_arret[y][i] = 1;
                }
                etape2(z,s);
                return;
            }
            else if(etique[y].origine != 0 && etique[y].paire == 0 && etique[y].origine != s + 1){
                int u = etique[y].origine;
                printf("couplage de %d a %d\n",s+1,u+1);
                return;
            }
        }
    }
    return;
}
