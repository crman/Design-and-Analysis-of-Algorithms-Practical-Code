#include <stdio.h>

int main()
{
    int obj,max;
    printf("Enter no. of objects:");
    scanf("%d",&obj);
    printf("Enter Capacity of Knapsack:");
    scanf("%d",&max);
    int w[(obj+1)],p[(obj+1)];
    int v[(obj+1)][(max+1)],backi[(obj+1)][(max+1)],backj[(obj+1)][(max+1)];
    w[0]=0,p[0]=0;

    for(int i=1;i<=obj;i++)
    {
        printf("Enter w of object %d:",i);
        scanf("%d",&w[i]);
        printf("Enter p of object %d:",i);
        scanf("%d",&p[i]);
    }

    for(int i=0;i<=obj;i++)
    {
        for(int j=0;j<=max;j++)
        {
            if(i==0 || j==0)
            {
                v[i][j]=0;
                backi[i][j]=0;
                backj[i][j]=0;
            }
            else
            {
                if(j>=w[i])
                {
                    if(v[(i-1)][j]>v[(i-1)][j-w[i]]+p[i])
                        {
                            v[i][j]=v[(i-1)][j];
                            backi[i][j]=i-1;
                            backj[i][j]=j;
                        }
                    else
                        {
                            v[i][j]=v[(i-1)][j-w[i]]+p[i];
                            backi[i][j]=i-1;
                            backj[i][j]=j-w[i];
                        }
                }
                else
                {
                    v[i][j]=v[(i-1)][j];
                    backi[i][j]=i-1;
                    backj[i][j]=j;
                }
            }
        }
    }

    int count=0,count1=obj,count2=max;
    int old1=count1,old2=count2;
    int check=v[obj][max],objects[obj];
    while(count1!=0 || count2!=0)
    {
        if(check==v[count1][count2])
        {
            count1--;
        }
        else
        {
            count1++;
            check=v[count1][count2];
            objects[count]=count1;
            count++;
            old1=count1,old2=count2;
            count1=backi[old1][old2];
            count2=backj[old1][old2];
            check=v[count1][count2];
        }
    }

    printf("Maximum p is:%d",v[obj][max]);
    printf("\nObjects in knapsack:");
    for(int i=(count-1);i>=0;i--)
    {
        printf(" %d",objects[i]);
    }

    return 0;
}
