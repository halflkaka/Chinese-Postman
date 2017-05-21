#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#define N 6

/*typedef struct chemin
{
    int sommet[N];
    int longeur;
}chemin
*/

typedef struct etiquette
{
    int origine;
    int paire;
    int pre;
}etiquette;
int Adjacence[N][N] = {
    {0,1,1,0,0,1},
    {1,0,0,1,1,1},
    {1,0,0,1,0,0},
    {0,1,1,0,1,0},
    {0,1,0,1,0,0},
    {1,1,0,0,0,0}};
int couplage[N][1] = {0};
int marque_arret[N][N];
etiquette etique[N];
void init_etique()
{
    int i;
    for(i=0;i<N;i++){
        etique[i].origine = 0;
        etique[i].paire = 0;
        etique[i].pre = 0;
    }
}
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
/*void refresh_Couplage(int s)
{
    int i,j;
    for(i=0;i<N;i++){
        if(dans_Couplage(i)){
            couplage[i][0] = 0;
            //for(j=0;j<N;j++){
              //  if(couplage[j][0] == i){couplage[j][0] = 0;}
            //}
        }
    }
    int n = N;
    while(n-- > 0){
        for(i = 0;i < N;i++){
            if(etique[i].pre == s + 1 && etique[i].paire == 1){
                couplage[i][0] = s + 1;
                s = i;
                break;
            }
            else if(etique[i].pre == s + 1 && etique[i].paire == 0){
                s = i;
                break;
            }
        }
    }
}*/
void etape2(int x,int s)
{
    //int x = s;
    int y;
    for(y = 0;y < N;y++){
        if(Adjacence[x][y] == 1 && marque_arret[x][y] == 0 && etique[x].origine == s + 1 && etique[x].paire == 0){
            if(etique[y].origine == 0 && !dans_Couplage(y)){
                printf("%d not dans couplage\n",y+1);
                couplage[x][0] = y + 1;//{x,y} x+1=x, y+1=y
                //couplage[y][0] = x + 1;
                //printf("couplage{%d,%d}\n",x+1,y+1);
                etique[y].origine = s + 1;
                etique[y].paire = 1;
                etique[y].pre = x + 1;//couplage有问题！如何更新couplage
                printf("couplage de %d a %d\n",s+1,y+1);
                return;
            }
            else if(etique[y].origine == 0 && dans_Couplage(y)){
                int z = couplage[y][0] - 1;//position of z
                printf("y is %d\n",y);
                printf("z is %d\n",z);
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

int main()
{
    int s = 0;
    int n = N;
    while(n-- >= 0){
        //marque_arret[N][2] = {0};
        //etique[N] = {0};
        int i,j;
        for(i = 0;i < N;i++){
            for(j = 0;j < N;j++){
                marque_arret[i][j] = 0;
            }
        }
        init_etique();
        if(!dans_Couplage(s)){
            //printf("%d not dans couplage\n",s+1);
            etique[s].origine = s + 1;
            etique[s].paire = 0;
            etique[s].pre = 0;
            etape2(s,s);
            for(i=0;i<N;i++){
                printf("etique[%d]:[%d,%d,%d]\n",i+1,etique[i].origine,etique[i].paire,etique[i].pre);
            }
            //refresh_Couplage(s);
            s++;
        }
        else{s++;}
        //printf("s = %d\n",s);
    }
	return 0;
}
/* int Poid[5][5]
 * int parcouru[5][5]
 * int pi = 0
 * while(existe chemin augmentant){
 * 		trouver tous les chemins possibles
 * 		while(existe chemin pas regarder encore){
 * 			if(chemin pas parcouru){
 * 				newpi = pi + Poid
 * 			}
 * 			else{
 * 				newpi = pi - Poid
 * 			}
 * 			if(newpi < pi){
 * 				pi = newpi
 * 				update K
 * 			}
 * 		}
 *
*/
