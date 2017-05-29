#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "postier.h"

int dijkstra(int depart,int arrive)
{
    int pi[N]={0},TN[N]={0},pre[N]={0};
    TN[depart] = 1;
    int i;
    for(i=0;i<N;i++){
        pi[i]=Kilometres[depart][i];
    }
    int fois = 0;
    int m=1000,n=1000;
    for(i=0;i<N;i++){
        if(m > pi[i] && TN[i] != 1){m = pi[i];n = i;}
    }
    pre[n] = depart;
    while(fois ++ < N){
        int Pi = 1000,pt = 1000;
        for(i=0;i<N;i++){
            if(Pi > pi[i] && TN[i] != 1){Pi = pi[i];pt = i;}
        }
        if(pt == 1000){continue;}
        else{
            TN[pt] = 1;
            //pre[pt]=4;
        }
        for(i=0;i<N;i++){
            if(TN[i] != 1){
                if(pi[i] > Pi + Kilometres[pt][i]){
                    pi[i] = Pi + Kilometres[pt][i];
                    pre[i] = pt;
                }
                //else{pre[i] = depart;}
            }
        }
    }
    for(i=0;i<N;i++){
        if(pre[i] == 0){pre[i] = depart;}
    }
    //printf("%d\n",pi[arrive]);
    /*while(arrive != depart){
        printf("pre of %d is %d\n",arrive,pre[arrive]);
        arrive = pre[arrive];
    }*/
    return pi[arrive];
}
void doubler(int depart,int arrive)
{
    int pi[N]={0},TN[N]={0},pre[N]={0};
    TN[depart] = 1;
    int i;
    for(i=0;i<N;i++){
        pi[i]=Kilometres[depart][i];
    }
    int fois = 0;
    int m=1000,n=1000;
    for(i=0;i<N;i++){
        if(m > pi[i] && TN[i] != 1){m = pi[i];n = i;}
    }
    pre[n] = depart;
    while(fois ++ < N){
        int Pi = 1000,pt = 1000;
        for(i=0;i<N;i++){
            if(Pi > pi[i] && TN[i] != 1){Pi = pi[i];pt = i;}
        }
        if(pt == 1000){continue;}
        else{
            TN[pt] = 1;
            //pre[pt]=4;
        }
        for(i=0;i<N;i++){
            if(TN[i] != 1){
                if(pi[i] > Pi + Kilometres[pt][i]){
                    pi[i] = Pi + Kilometres[pt][i];
                    pre[i] = pt;
                }
                //else{pre[i] = depart;}
            }
        }
    }
    for(i=0;i<N;i++){
        if(pre[i] == 0){pre[i] = depart;}
    }
    //printf("arrive:%d -> ",arrive);
    while(arrive != depart){
        Adjacence[pre[arrive]][arrive] ++;
        Adjacence[arrive][pre[arrive]] ++;
        arrive = pre[arrive];
        //printf("%d -> ",arrive);
    }
    //printf("\n");
    return;
}
