#include<stdio.h>

void Merge(int A[],int P,int Q,int R)
{
    int i,j,k;
    int n1 = (Q-P)+1;
    int n2 = R-Q;

    int l[n1];
    int r[n2];


    for(i=0;i<n1;i++)
    {
        l[i]=A[P+i];
    }
    for(j=0;j<n2;j++)
    {
        r[j]=A[Q+1+j];
    }

    l[i] = 999999;
    r[j] = 999999;

    i=0;
    j=0;
    k=P;

 //   printf(" P value %d\n",P);
    for(k=P;k<=R;k++)
    {
        if(l[i]<=r[j])
        {
            A[k] = l[i];
            i++;
        }
        else
        {
            A[k] = r[j];
            j++;
        }
    }


    /*
    while(i < n1 && j < n2)
    {
        if (l[i] <= r[j])
        {
            A[k] = l[i];
            i++;
        }
        else
        {
            A[k] = r[j];
            j++;
        }
        k++;
    }
    while(i < n1)
    {
        A[k] = l[i];
        i++;
        k++;
    }

    while(j < n2)
    {
        A[k] = r[j];
        j++;
        k++;
    }
*/
}

void MergeSort(int A[],int P,int R)
{
    if(P<R)
    {
        int Q = (P+R)/2;
        MergeSort(A,P,Q);
        MergeSort(A,Q+1,R);
        Merge(A,P,Q,R);
    }
}

void main()
{
    int n;
    time_t t1,t2;
    printf("Enter the number of elements : ");
    scanf("%d",&n);

    int A[n];

    for(int j=0;j<n;j++)
    {
        A[j] = n-j;
    }


    time(&t1);
  //  t1=t1*1000000;

    MergeSort(A,0,n-1);
    time(&t2);
   // t2=t2*1000000;

    t2=t2-t1;


    for(int i=0;i<n;i++)
    {
        printf("\n %d",A[i]);
    }

    printf("\nT %d\n", t2*1000000);
}
