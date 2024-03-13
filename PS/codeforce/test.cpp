#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    int num[n];
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&num[i]);
    }
    int temp=num[0];
    for(i=1;i<n;i++)
    {
        if(num[i]>num[i-1])
        {
            temp= num[i];
        }
    }
    double sum=0;

    for(i=0;i<n;i++)
    {
        sum = sum+((double)num[i]/temp)*100;
    }

    printf("%f\n",(double)sum/n);

    return 0;
}
