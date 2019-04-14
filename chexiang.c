#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define N 100
struct zhan
{
    int a[N];
    int top;
};
void push(struct zhan *x,int y)
{
    if(x->top==N-1)
    {
        printf("the stack is full");
        return;
    }
    x->a[++x->top]=y;
}
int pop(struct zhan *x)
{
    if(x->top==-1)
    {
        printf("the stack is empty");
        return;
    }
    return(x->a[x->top--]);
}
int isfull(struct zhan x)
{
    if(x.top==N-1)
    {
        return 0;
    }
    return 1;
}
int isempty(struct zhan x)
{
    if(x.top==-1)
    {
        return 0;
    }
    return 1;
}
void railplay(struct zhan x,struct  zhan y,int n,int j)//n为车厢总数，k为入站车厢，x为车站，y为出战
{
    struct zhan b=x,c=x,d=y,e=y;
    int i,k=j;
    if(y.top==n-1)//如果出列已满车箱数则输出
    {
        for(i=0;i<=n-1;i++)
        {
            printf("%d",y.a[i]);
        }
        printf("\n");
    }
    else if(k>n)//若车厢全进入则只出站
    {
        push(&d,pop(&b));
        railplay(b,d,n,k);
    }
    else if(isempty(x))//若站内不为空则有两个分支，入站和出站
    {
        push(&d,pop(&b));
        push(&c,k);
        railplay(b,d,n,k);
        k++;
        railplay(c,e,n,k);
    }
    else if(!isempty(x))//若为空则只有入站操作
    {
        push(&c,k);
        k++;
        railplay(c,e,n,k);
    }
}
void main()
{
    struct zhan x,y;
    int i,n,k=1;
    y.top=-1;
    x.top=-1;
    printf("please input n\n");
    scanf("%d",&n);
    railplay(x,y,n,k);
}
