#include <stdio.h>
int tim = 0;
int main()
{
    int n, b[20], i, j, w[20], tw = 0, taround[20], tt = 0;
    float avw, avt;
    printf("\nEnter the number of process: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        printf("Enter the Burst Time of process %d:", i);
        scanf("%d", &b[i]);
    }

    for (i = 1; j <= n; i++)
    {
        w[i] = tim;
        for (j = 1; j <= b[i]; j++)
        {
            tim++;
            if (j == b[i])
            {
                taround[i] = tim;
            }
        }
    }

    for (i = 1; i <= n; i++)
    {
        tw = tw + w[i];
    }

    avw = (float)tw / n;

    for (i = 1; i <= n; i++)
    {
        tt = tt + taround[i];
    }
    avt = (float)tt / n;
    printf("\nWating times and trun around times of the processes");
 printf("\n*************************************************************************************************************");
 for(i=1; i<=n; i++)
 {
        printf("\nProcess: %d wating time: %d", i, w[i]);
        printf("\nProcess: %d trun around time: %d", i, taround[i]);
 }
 printf("\n\nAverage waiting time: %f", avw);
 printf("\nAverage trun around time: %f\n", avt);
 return 0;
}