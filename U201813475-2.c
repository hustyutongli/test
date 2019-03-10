#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define N 4

void main()
{
    float a,b,x=0,y=0,n;
    int i,j;
    float Sn=0;
    printf("please input a b n\n");
    scanf("%f %f %f",&a,&b,&n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=i;j++)
        {
           x+=a*pow(10,j);
           y+=b*pow(10,j);
        }
        Sn+=x/(y/pow(10,i));
    }
    printf("%f",Sn);
}
