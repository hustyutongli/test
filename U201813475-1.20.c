#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
struct mat
{
    int a;
    struct mat* next;
};//����ṹ��
struct mat* create(int n);//��������
void input(struct mat*head);//��������
void caculate(struct mat*head,int n);//����x�����м��㲢������
void dele(struct mat*head);//��������
void main()
{
    struct mat* head;int n;
    printf("please input n\n");
    scanf("%d",&n);
    head=create(n);
    printf("please input a  as i from big to small in order\n");
    input(head);
    printf("please input x\n");
    caculate(head,n);
    dele(head);
}
struct mat*create(int n)//���������Ӷ�O(n)
{
    struct mat*head=NULL;
    struct mat*p,*q; int i=0;
    while(i<=n)
    {
        p=(struct mat*)malloc(sizeof(struct mat));
        if(p==NULL)
        {
            printf("error");
            return;
        }
        if(head==NULL)
        {
            head=p;
            q=p;
        }
        else
        {
            q->next=p;
            q=p;
        }
        i++;
    }
    q->next=NULL;
    return head;
}
void input(struct mat*head)//���������Ӷ�O(n);
{
    struct mat*p=head;
    while(p!=NULL)
    {
        scanf("%d",&p->a);
        p=p->next;
    }
}
void caculate(struct mat*head,int n)//���������Ӷ�ΪO(n)
{
    float x,y=0;
    int i;
    struct mat*p=head;
    scanf("%f",&x);
    for(i=0;i<=n;i++)
    {
        y=p->a+x*y;
        p=p->next;
    }
    printf("the result is %f",y);
}
void dele(struct mat*head)
{
    struct mat*p,*q=head->next;
    for(p=head;p!=NULL;p=q,q=p->next)
    {
        free(p);
    }
}//���������Ӷ�ΪO(n)
//���ϱ��㷨���Ӷ�ΪO(n)
