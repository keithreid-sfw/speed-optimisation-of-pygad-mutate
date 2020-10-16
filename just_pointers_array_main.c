#include <stdio.h>
#include <stdlib.h>

void main()
{
    int i, j; // iterator and jiterator
    double algo[10][2] = {{0.1,  1.2,  2.3,  3.4,  4.5,  5.6,  6.7,  7.8,  8.9,  9.0},
                        { 10.1, 11.2, 12.3, 13.4, 14.5, 15.6, 16.7, 17.8, 18.9, 19.0}}; // genetic algorithm
    int *p; // gene pointer p declared as an int of pointer type needing memory later as in * we will refer to this

    p = &algo[0][0]; // assign q the numerical value of the starting point with & "... AAaaaannnndd it starts here"

    for (i=0; i<2; ++i)
    {   printf("\niterator:\t%d", i);
        for (j=0; j<10; ++j)
        printf("\njiterator:\t%d", j);
        {
            printf("\n%5f\n", *p);      // the literal value got by referring to the pointer
        }
    }


    return 0;
}
