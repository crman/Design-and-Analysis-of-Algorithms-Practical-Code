#include<stdio.h>

int Partition(int A[],int LOW,int HIGH)
{
    int pivot,temp=0;
    pivot=A[HIGH];

    /*
    int i=LOW+1;

    for(int j=i;j<=HIGH;j++)
    {
        if(A[j] < pivot)
        {
            temp=A[i];
            A[i]=A[j];
            A[j]=temp;

            i++;
        }
    }

    temp=A[LOW];
    A[LOW]=A[i-1];
    A[i-1]=temp;

    return i-1;

    */


    int i=LOW;
    int j=HIGH-1;

    for(i=LOW,j=HIGH-1;i<=j;i++,j--)
    {
        while(A[i]<pivot)
        {
            i++;
        }
        while(A[j]>pivot)
        {
            j--;
        }
        if(i<j)
        {
            temp=A[i];
            A[i]=A[j];
            A[j]=temp;
        }
    }
    i--;

    temp=A[i];
    A[i]=A[HIGH];
    A[HIGH]=temp;

    return i;

}

void QuickSort(int A[],int LOW,int HIGH)
{
    if(LOW<HIGH)
    {
        int pi = Partition(A,LOW,HIGH);
        QuickSort(A,LOW,pi-1);
        QuickSort(A,pi+1,HIGH);
    }
}

void main()
{
    int n;
    time_t t1,t2,t3,t4,t5,t6;
    printf("Enter the number of elements : ");
    scanf("%d",&n);
    int A[n],B[n],C[n];

    //worst case
    for(int j=0;j<n;j++)
    {
        A[j] = n-j;
    }

    //best case
    for(int j=0;j<n;j++)
    {
        B[j] = j;
    }

    //avg case
    for(int j=0;j<n;j++)
    {
        C[j] = rand();
    }

    time(&t1);
    QuickSort(A,0,n-1);
    time(&t2);
    t2=t2-t1;

    time(&t3);
    QuickSort(B,0,n-1);
    time(&t4);
    t4=t4-t3;

    time(&t5);
    QuickSort(C,0,n-1);
    time(&t6);
    t6=t6-t5;

   /*
    for(int i=0;i<n;i++)
    {
        printf("\n%d",A[i]);
    }
*/
    printf("\nTime Worst %d\n", t2*1000000);
    printf("\nTime Best %d\n", t4*1000000);
    printf("\nTime Average %d\n", t6*1000000);
}
