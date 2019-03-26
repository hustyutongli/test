#include <stdio.h>
#include <stdlib.h>
struct ysf
{
    int n;
    int m;
    struct ysf*next;
};
struct ysf*create(int k)//创造循环链表 并初始化每人编号
{
   struct ysf*head=NULL,*p,*q;
   int i=1;
   while(i<=k)
   {
       if(head==NULL)
       {
           head=(struct ysf*)malloc(sizeof(struct ysf));
           head->n=i;
           p=head;
       }
       else
       {
           q=p;
           q->next=(struct ysf*)malloc(sizeof (struct ysf));
           p=q->next;
           p->n=i;
       }
       i++;
   }
   p->next=head;
   return head;
}
int game(struct ysf*head,int m0,int k)//删除节点，输出删除的人的编号
{
   int i,j,z,y=m0;
   struct ysf*p=head,*q;
   for(i=1;i<=k-1;i++)
   {
       for(j=1;j<y;j++)
       {
           q=p;
           p=p->next;
       }
       printf("%d\t",p->n);
       y=p->m;
       q->next=p->next;
       free(p);
       p=q->next;
   }
   z=q->n;
   free(q);
   return z;
}
void input(struct ysf*head,int k)//输入每人密码
{
    struct ysf*p=head;
    int i=1;
    while(i<=k)
    {
        scanf("%d",&p->m);
        p=p->next;
        i++;
    }
}
void main()
{
   int k,m0;
   struct ysf*head;
   printf("please input the number of players\n");
    while(1)//对输入人数进行判断
   {
       scanf("%d",&k);
       if(k<1)
       {
           printf("error,you must have one person at least");
           continue;
       }
       else if(k==1)
       {
           printf("the winner is %d",k);
           return;
       }
       else
       {
           break;
       }
   }
   head=create(k);//创造链表
   printf("please input the first code\n");
   scanf("%d",&m0);
   printf("please input every one's code\n");
   input(head,k);//输入密码
   printf("the winner is %d",game(head,m0,k));//输出赢者；
}
