#include<stdio.h>
#include<string.h>

void main()
{
    char T[]="AAABAAABAAA";
    char P[]="AAA";
    int n=strlen(T);
    int m=strlen(P);
    int i,j;

    int limit=n-m;  //limit
    printf("m %d, n %d, limit %d\n",m,n,limit);

    for(i=0;i<=limit;i++)
    {
        for(j=0;j<m;j++)
        {
            if(P[j]!=T[i+j])
            break;
        }
        if(j==m)
        printf("Pattern Found At Position %d \n",i);
    }
}
