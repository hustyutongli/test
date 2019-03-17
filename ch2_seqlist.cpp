// Example program
#include <stdio.h>
#include <stdlib.h>

#define maxsize 1000

typedef float datatype;

struct SeqList
{
    datatype data[maxsize];
    int last;
};

SeqList *init_seqlist()
{
    SeqList *L;
    L = (SeqList*)malloc(sizeof(SeqList));
    L->last = -1;
    return L;
}

int insert_seqlist(SeqList *L, int i, datatype e)
{
    int j;

    if (L->last == maxsize - 1)
    {
        printf("list is already full\n");
        return -1;
    }

    if (i<1 || i>L->last+2 )
    {
        printf("wrong position\n");
        return -1;
    }

    for (j=L->last; j>=i-1; --j)
    {
        L->data[j+1] = L->data[j];
    }

    L->data[i-1] = e;
    L->last++;

    return 1;
}

void print_seqlist(SeqList *L)
{
    int i;
    for (i=1; i<L->last; ++i)
    {
        printf("%f -> ", L->data[i-1]);
    }
    printf("%f\n", L->data[L->last]);
}
void dele(SeqList*L,int i)
{
    int j;
    if(i<1||i>L->last+1)
    {
        printf("error");
        return;
    }
    for(j=i-1;j<=L->last-1;j++)
    {
        L->data[j]= L->data[j+1];
    }
    L->last--;
}
int main()
{
    int i = 0;

    SeqList* L = init_seqlist();
    for (i=0; i<10; ++i)
    {
        insert_seqlist(L, i+1, i*i);
    }
    printf("list len = %d\n", L->last+1);

    print_seqlist(L);

    insert_seqlist(L, 5, 222);
    print_seqlist(L);
    dele(L,5);
    print_seqlist(L);

    return 1;
}


