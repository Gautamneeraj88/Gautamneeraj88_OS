#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
void accept(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
}
void display(int a[], int n)
{
    int i;
    printf("\n\n");
    for (i = 0; i < n; i++)
    {
        printf("\t%d", a[i]);
    }
}
void sort(int a[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}
void revsort(int a[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1; j++)
        {
            if (a[j] < a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void first_fit(int psize[], int np, int msize[], int nm)
{
    int i, j, in_fr, ex_fr, flag[30] = {0};
    in_fr = ex_fr = 0;
    for (i = 0; i < np; i++)
    {
        for (j = 0; j < nm; j++)
        {
            if (flag[j] == 0 && msize[j] >= psize[i])
            {
                flag[j] = 1;
                in_fr = in_fr + msize[j] - psize[i];
                break;
            }
            if (j == nm)
                printf("\n\nThere is no space for process %d", i);
        }
    }
    for (i = 0; i < nm; i++)
    {
        if (flag[i] == 0)
            ex_fr = ex_fr + msize[i];
    }
    printf("\n\nProcesses: ");
    display(psize, np);
    printf("\n\nMemory Holes: ");
    display(msize, nm);
    printf("\n\nTotal sum of internal fragmentation = %d", in_fr);
    printf("\n\nTotal sum of external fragmentation = %d", ex_fr);
}

void best_fit(int psize[], int np, int msize[], int nm)
{
    int i, j, in_fr, ex_fr, temp[30], flag[30] = {0};
    in_fr = ex_fr = 0;
    for (i = 0; i < nm; i++)
        temp[i] = msize[i];
    sort(temp, nm);
    for (i = 0; i < nm; i++)
    {
        for (j = 0; j, nm; j++)
        {
            if (flag[j] == 0 && temp[j] >= psize[i])
            {
                flag[j] = 1;
                in_fr = in_fr + temp[j] - psize[i];
                break;
            }
            if (j == nm)
                printf("\n\nThere is no space for process %d", i);
        }
    }
    for (i = 0; i < nm; j++)
    {
        if (flag[i] == 0)
            ex_fr = ex_fr + temp[i];
    }
    printf("\n\nProcesses: ");
    display(psize, np);
    printf("\n\nMemory Holes: ");
    display(temp, nm);
    printf("\n\nTotal sum of internal fragmentation = %d", in_fr);
    printf("\n\nTotal sum of external fragmentation = %d", ex_fr);
}

void worst_fit(int psize[], int np, int msize[], int nm)
{
    int i, j, in_fr, ex_fr, temp[30], flag[30] = {0};
    in_fr = ex_fr = 0;
    revsort(temp, nm);
    for (i = 0; i < np; i++)
    {
        for (j = 0; j < nm; j++)
        {
            if (flag[j] == 0 && temp[j] >= psize[i])
            {
                flag[j] = 1;
                in_fr = in_fr + temp[j] - psize[i];
                break;
            }
            if (j == nm)
                printf("\n\nThere is no space for prcess %d", i);
        }
    }
    for (i = 0; i < nm; i++)
    {
        if (flag[i] == 0)
            ex_fr = ex_fr + temp[i];
    }
    printf("\n\nProcesses:");
    display(psize, np);
    printf("\n\nMemory HOles:");
    display(temp, nm);
    printf("\n\nTotal sum of internal fragmentation = %d", in_fr);
    printf("\n\nTotal sum of external fragmentation = %d", ex_fr);
}

int main()
{
    int ch, np, nm, psize[30], msize[30];
    printf("\nEnter no. of processes: ");
    scanf("%d", &np);
    printf("\n\nEnter sizes of processes:");
    accept(psize, np);
    printf("\nEnter no. memory holes:");
    scanf("%d", &nm);
    printf("\n\nEnter sizes of memory holes:");
    accept(msize, nm);
    while (1)
    {
        printf("\n\n\t\t**MAIN MENU**");
        printf("\n\n\t\t\tMEMORY MANAGEMENT");
        printf("\n\n\t\t\t1. FIRST FIT");
        printf("\n\n\t\t\t2. BEST FIT");
        printf("\n\n\t\t\t3. WORST FIT");
        printf("\n\n\t\t\t4. OUIT");
        printf("\n\nEnter your choice::");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\n\nFIRST FIT::\n");
            first_fit(psize, np, msize, nm);
            break;
        case 2:
            printf("\n\n\tBEST FIT::\n");
            best_fit(psize, np, msize, nm);
            break;
        case 3:
            printf("\n\n\tWORST FIT::\n");
            worst_fit(psize, np, msize, nm);
            break;
        case 4:
            exit(0);
        default:
            printf("\n\nPlease enter correct choice!!");
        }
    }
}