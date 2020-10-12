#include<stdio.h>
#include<stdlib.h>
#include<time.h>

float get_small_float()
{
float small_float;
    {
    small_float = (float)rand()/RAND_MAX;
    }
    return small_float;
}

/* generate and return random ints*/
int * get_rand_ints()
{
    static int arr[8];
    int i;

    /* set the seed */
    srand ((unsigned)time(NULL));
    for (i=0; i<8; ++i)
    {
        arr[i] = rand();
    }
    return arr;
}

/* generate and return random floats*/
float * get_rand_floats()
{
    static float arr[8];
    int i;

    /* set the seed */
    srand ((unsigned)time(NULL));
    for (i=0; i<8; ++i)
    {
        arr[i] = 100000000.0/rand();
    }
    return arr;
}


/* generate and return zeroes except one*/
int * get_zeroes_except_one()
{
    static int arr[8];
    int i;

    /* set the seed */
    /*srand ((unsigned)time(NULL));*/
    for (i=0; i<8; ++i)
    {
        if (i == 3) {
            arr[i] = 1;
        }
        else {
            arr[i] = 0;
        }
    }

    return arr;
}

int main()

{
    float mat1[8][4], mat2[8][4], mat3[8][4];

    int i, j;

    /* arrays that might be useful */
    int   *pointer_arr_ints;
    float *pointer_arr_floats;
    int   *pointer_arr_zeros_except_one;

    pointer_arr_ints             = get_rand_ints();
    pointer_arr_floats           = get_rand_floats();
    pointer_arr_zeros_except_one = get_zeroes_except_one();

    for (i=0; i<10; i++)
    {
         printf("\n%5d", *(pointer_arr_ints + i));
         printf("\n%5f", *(pointer_arr_floats + i));
         printf("\n%5d", *(pointer_arr_zeros_except_one + i));
    }

    printf("Built a random matrix to mock up a population");
    for(i = 0; i < 8; i++)
    {
        for(j = 0; j < 4; j++)
        {
            mat1[i][j] = get_small_float();
        }
    }

    printf("\n");
    for(i = 0; i < 8; i++)
    {
        for(j = 0; j < 4; j++)
        {
            printf("%5f ", mat1[i][j]);
        }
        printf("\n");
    }

    printf("\nEnter a second matrix and throw a mutation in manually every so often: \n\n");
    for(i = 0; i < 8; i++)
    {
        for(j = 0; j < 4; j++)
        {
            printf("Enter a[%d][%d]: ", i, j);
            scanf("%f", &mat2[i][j]);
        }
    }

    printf("\n");
    for(i = 0; i < 8; i++)
    {
        for(j = 0; j < 4; j++)
        {
            printf("%5f ", mat2[i][j]);
        }
        printf("\n");
    }


    printf("\n");
    // add mat1 and mat2
    for(i = 0; i < 8; i++)
    {
        for(j = 0; j < 4; j++)
        {
            mat3[i][j] = mat1[i][j] + mat2[i][j];
        }
    }

    printf("\nResultant array: \n\n");
    // print resultant array
    for(i = 0; i < 8; i++)
    {
        for(j = 0; j < 4; j++)
        {
            printf("%5f ", mat3[i][j]);
        }
        printf("\n");
    }

    // signal to operating system program ran fine
    return 0;
}

