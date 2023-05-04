#include <stdio.h>

#define MAX_SIZE 100

int main()
{
    int x[MAX_SIZE];
    int y[MAX_SIZE];
    int z, i, j, count;

    printf("Dizinin boyutunu girin: ");
    scanf("%d", &z);

    printf("Dizi elemanlarýný girin:\n");
    for(i=0; i<z; i++)
    {
        scanf("%d", &x[i]);
        y[i] = -1;
    }

    for(i=0; i<z; i++)
    {
        count = 1;
        for(j=i+1; j<z; j++)
        {
            if(x[i] == x[j])
            {
                count++;
                y[j] = 0;
            }
        }
        if(y[i] != 0)
        {
            y[i] = count;
        }
    }

    printf("\nTüm elemanlar ve frekanslarý:\n");
    for(i=0; i<z; i++)
    {
        if(y[i] != 0)
        {
            printf("Dizinin Boyutu %d Frekansý %d \n", x[i], y[i]);
        }
    }

    return 0;
}


