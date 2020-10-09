#include<stdio.h>
#include<stdlib.h>
#define ROW 2
#define COL 3

float get_small_float()
{
float small_float;
    {
    small_float = (float)rand()/RAND_MAX;
    }
    return small_float;
}

int main()
{
    float mat1[ROW][COL], mat2[ROW][COL], mat3[ROW][COL];
    int i, j;

    printf("Built a random matrix to mock up a population");
    for(i = 0; i < ROW; i++)
    {
        for(j = 0; j < COL; j++)
        {
            mat1[i][j] = get_small_float();
        }
    }

    printf("\n");
    for(i = 0; i < ROW; i++)
    {
        for(j = 0; j < COL; j++)
        {
            printf("%5f ", mat1[i][j]);
        }
        printf("\n");
    }


    printf("\nEnter a second matriux and htrow a mutation in manually every so often: \n\n");

    for(i = 0; i < ROW; i++)
    {
        for(j = 0; j < COL; j++)
        {
            printf("Enter a[%d][%d]: ", i, j);
            scanf("%f", &mat2[i][j]);
        }
    }


    {
    printf("\n");
    }
    for(i = 0; i < ROW; i++)
    {
        for(j = 0; j < COL; j++)
        {
            printf("%5f ", mat2[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    // add mat1 and mat2

    for(i = 0; i < ROW; i++)
    {
        for(j = 0; j < COL; j++)
        {
            mat3[i][j] = mat1[i][j] + mat2[i][j] ;
        }
    }

    printf("\nResultant array: \n\n");

    // print resultant array

    for(i = 0; i < ROW; i++)
    {
        for(j = 0; j < COL; j++)
        {
            printf("%5f ", mat3[i][j]);
        }
        printf("\n");
    }

    // signal to operating system program ran fine
    return 0;
}
