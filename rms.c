#include <stdio.h>
#include <math.h>
int main()
{
    int et[50], tp[50];
    int p[50];
    float n;
    printf("enter the number of processes");
    scanf("%f", &n);
    for (int i = 0; i < n; i++)
    {
        printf("enter the execution time and time period of process  %d ", i);
        scanf("%d %d", &et[i], &tp[i]);
    }
    double u = 0;
    for (int i = 0; i < n; i++)
    {
        u = u + (double)et[i] / (double)tp[i];
    }
    double x = (double)n * ((double)pow(2, (1 / n)) - 1);
    if (u <= x)
    {
        printf("u is %f\n", u);
        printf("x is %f\n", x);
        printf("system is scheduleable\n");
    }
    else
    {
        printf("cannot be executed\n");
    }

    return 0;
}
