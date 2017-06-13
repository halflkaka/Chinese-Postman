struct stack
{
    int top;
    int sommet[N];
}s;

extern int Chemin[N*N];
extern int longueur;

void dfs(int depart)//DFS pour parcourir tous les arrets possibles
{
    s.top ++;
    s.sommet[s.top] = depart;//push
    int i;
    for(i=0;i<N;i++)
    {
        if(Adjacence[i][depart])
        {
            Adjacence[i][depart]--;
            Adjacence[depart][i]--;//Car on a double le chemin
            dfs(i);
            break;
        }
    }
    return;
}

void Euler(int depart)
{
    //push le premier sommet dans s
    s.top = 0;
    s.sommet[s.top] = depart;
    printf("[ ");
    //Si s n'est pas vide
    while(s.top >= 0)
    {
        int flag = 0;
        int i;
        for(i=0;i<N;i++)
        {
            if(Adjacence[i][s.sommet[s.top]])//S'il y a encore d'autre arret part depuis ce sommet
            {
                flag = 1;
                break;
            }
        }
        if(!flag){//Si tous les arrets sont parcourus
            printf("%d ",s.sommet[s.top]);
            Chemin[longueur++] = s.sommet[s.top];
            s.top --;//pop
        }
        else{
            dfs(s.sommet[s.top--]);
        }
    }
    printf("]\n");
}
