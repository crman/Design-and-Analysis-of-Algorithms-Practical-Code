#include<stdio.h>

void main()
{
    int n,flag=0,sE,sO,j=0,k=0;

    printf("Enter n : ");
    scanf("%d",&n);
    int NQueen[n][n];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            NQueen[i][j]=0;
        }
    }

    if(n%2 == 0)
    {
        sE=n/2;
        sO=n/2;
    }
    else
    {
        sE=n/2;
        sO=(n/2)+1;
    }

    int seqO[sO],seqE[sE];
    for(int i=0; i<sO;i++)
    seqO[i]=0;

    for(int i=0; i<sE;i++)
    seqE[i]=0;

    for(int i=0;i<sE;i++)
    {
        seqE[i]=j+2;
        j++;
        j++;
    }

    for(int i=0;i<sO;i++)
    {
        seqO[i]=k+1;
        k++;
        k++;
    }

    int Eold[sE],Oold[sO];
    for(int i=0;i<sE;i++)
    Eold[i]=seqE[i];

    for(int i=0;i<sO;i++)
    Oold[i]=seqO[i];

    // For Remainder 3 or 9
    if(n%12 == 3 || n%12 == 9)
    {
        flag=1;
        seqE[sE-1]=Eold[0];
        for(int i=0;i<sE-1;i++)
        {
            seqE[i]=Eold[i+1];
        }

        seqO[sO-1]=Oold[1];
        seqO[sO-2]=Oold[0];
        for(int i=0;i<sO-2;i++)
        {
            seqO[i]=Oold[i+2];
        }
    }

    // For Remainder 2
    if(n%12 == 2)
    {
        seqO[sO-1]=Oold[2];
        seqO[0]=Oold[1];
        seqO[1]=Oold[0];
        for(int i=2;i<sO-1;i++)
        {
            seqO[i]=Oold[i+1];
        }
    }

    //For Remainder 8
    if(n%12 == 8)
    {
        for(int i=0;i<sO;i+=2)
        {
            seqO[i]=Oold[i+1];
            seqO[i+1]=Oold[i];
        }
    }

    for(int i=0;i<sE;i++)
    printf("%d ",seqE[i]);

    for(int i=0;i<sO;i++)
    printf("%d ",seqO[i]);

    printf("\n");
    printf("\n");

    if(flag==1)
    {
        //For Printing on Board...
        //For Remainder 9 or 3
        int *p;
        int a=0;
        while(a<sE)
        {
            for(p=&seqE[0];p<=&seqE[sE-1];p++)
            {

                NQueen[*p-1][a]=1;
                a++;
            }
        }
        int *q;
        int b=sO-1;
        while(b<n)
        {
            for(q=&seqO[0];q<=&seqO[sO-1];q++)
            {
                NQueen[*q-1][b]=1;
                b++;
            }
        }
    }
    else
    {
        //Printing...
        //For Other Remainder...
        int *r;
        int a=0;
        while(a<sE)
        {
            for(r=&seqE[0];r<=&seqE[sE-1];r++)
            {

                NQueen[*r-1][a]=1;
                a++;
            }
        }
        int *s;
        int b=sO;
        while(b<n)
        {
            for(s=&seqO[0];s<=&seqO[sO-1];s++)
            {
                NQueen[*s-1][b]=1;
                b++;
            }
        }
    }

    printf("Queens on Board...\n\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf(" %d ",NQueen[i][j]);
        }
        printf("\n");
    }
}
