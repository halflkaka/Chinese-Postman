
typedef struct stack
{
    int arret[N][2];
    int length;
}pile;
void init(pile *q)
{
    q->length = 0;
};
void push(int x,int y,pile *q)
{
    if(q->length == N) exit(1);
    q->arret[q->length][0] = x;
    q->arret[q->length++][1] = y;
};
void pop(pile* q)
{
    if(q->length == 0) exit(2);
    q->length--;
}
int topx(pile* q)
{
    if(q->length == 0) exit(3);
    return q->arret[q->length-1][0];
}
int topy(pile* q)
{
    if(q->length == 0) exit(4);
    return q->arret[q->length-1][1];
}
