#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <io.h>
#include <fcntl.h>
#define N 4
struct hfm
{
  int weight;
  int parent,lchild,rchild;
};
int n;
char*a;
struct hfm*hp;
char**hc;
void init()
{
    int i,j,k;
    printf("please input the number of letter\n");
    scanf("%d",&n);
    a=(char*)malloc((n+1)*sizeof(char));
    hp=(struct hfm*)malloc((2*n)*sizeof(struct hfm));
    scanf("%s",a);
    for(i=1;i<=n;i++)
    {
       scanf("%d",&hp[i].weight);
    }
    for(i=n+1;i<2*n;i++)
    {
        hp[i].weight=0;
    }
    for(i=1;i<2*n;i++)
    {
        hp[i].parent=hp[i].rchild=hp[i].lchild=0;
    }
    for(i=n+1;i<2*n;++i)
    {
        int s1=-1,s2=-1;
        for(j=1;j<=i-1;j++)
        {
            if(hp[j].parent!=0)
            {
                continue;
            }
            if(s1==-1||s2==-1)
            {
                if(s1==-1)
                {
                    s1=j;
                }
                else
                {
                    s2=j;
                }
            }
            else
            {
                if(hp[j].weight<hp[s1].weight||hp[j].weight<hp[s2].weight)
                {
                    if(hp[s1].weight<hp[s2].weight)
                    {
                        s2=j;
                    }
                    else
                    {
                        s1=j;
                    }
                }
            }
        }
        hp[s1].parent=hp[s2].parent=i;
        hp[i].lchild=s1;hp[i].rchild=s2;
        hp[i].weight=hp[s1].weight+hp[s2].weight;
    }
    hc=(char**)malloc((n+1)*sizeof(char*));
    char*cd=(char*)malloc(n*sizeof(char));
    cd[n-1]='\0';
    for(i=1;i<=n;i++)
    {
         int start=n-1,c,f;
         for(c=i,f=hp[i].parent;f!=0;c=f,f=hp[f].parent)
         {
             if(hp[f].lchild==c)
             {
                 cd[--start]='0';
             }
             else
             {
                 cd[--start]='1';
             }
         }
         hc[i]=(char*)malloc((n-start)*sizeof(char));
         strcpy(hc[i],&cd[start]);
    }
    free(cd);
}
void enco()
{
    int i,j,k;
    char y[100];
   printf("please input the content \n");
   scanf("%s",y);
   for(i=0;i<=strlen(y)-1;i++)
   {
       for(j=0;j<=n-1;j++)
       {
           if(a[j]==y[i])
           {
               printf("%s\t",hc[j+1]);
               break;
           }
       }
       if(j>n-1)
       {
           printf("error\n");
           return;
       }
   }
   printf("\n");
}
void deco()
{
    int i,j,k,h=0,m=0;
    printf("please input the code");
    char w[100];
    scanf("%s",w);
  while(h<=strlen(w)-1)
  {
      m=h;
     for(i=1;i<=n;i++)
     {
        k=strlen(hc[i]);
        for(j=0;j<=k-1;j++,h++)
        {
            if(hc[i][j]==w[h])
            {
               continue;
            }
            else
            {
                break;
            }
        }
        if(j>k-1)
        {
            printf("%c",a[i-1]);
            break;
        }
        else
        {
            h=m;
        }
    }
    if(h==m)
    {
       printf("can not translate\n");
       return;
    }
  }
}
void treep()
{
    int i;
    for(i=1;i<2*n;i++)
    {
        if(hp[i].parent==0&&hp[i].weight!=0)
        {
            digui(hp[i],i,0);
        }
    }

}
void digui(struct hfm z,int o,int v)
{
    int i;
    for(i=1;i<=v;i++)
    {
        printf(" ");
    }
    if(o>n)
        {
            printf("#\n");
        }
        else
        {
            printf("%c\n",a[o-1]);
        }
    if(z.lchild==0&&z.rchild==0)
    {
        return;
    }
    else if(z.lchild==0)
    {
        digui(hp[z.rchild],z.rchild,v+1);
    }
    else if(z.rchild==0)
    {
        digui(hp[z.lchild],z.lchild,v+1);
    }
    else
    {
       digui(hp[z.lchild],z.lchild,v+1);
       digui(hp[z.rchild],z.rchild,v+1);
    }
}
void main()
{
   while(1)
   {
       char s;
       printf("please input from I E D P T Q\n");
       scanf("%c",&s);
       switch(s)
       {
           case'I':init();break;
           case'E':enco();break;
           case'D':deco();break;
           case'T':treep();break;
           case'Q': free(a);free(hp);free(hc);return;
       }
   }
}
