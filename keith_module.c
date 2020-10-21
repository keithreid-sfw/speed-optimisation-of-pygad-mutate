#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// MODEL

double get_mutation(int min_mutation, int max_mutation)
{
// secondary declaration and definition
int gap = max_mutation - min_mutation;

double mutation;
    {
    mutation = min_mutation + gap*(double)rand()/RAND_MAX;
    }
    return mutation;
}

double *keith_mutate(double *p, int min_mutation, int max_mutation, int length_flat_population, int number_of_mutations)
{

    // log incoming args

    printf("\n");
    printf("%f\t",*p);
    printf("%d\t",min_mutation);
    printf("%d\t",max_mutation);
    printf("%d\t",length_flat_population);
    printf("%d\t",number_of_mutations);
    printf("\n");

    // primary declarations
    int    i;
    int    random_index;
    double candidate_gene;
    double mutation;

    // secondary declarations
    int mutation_index_stack[number_of_mutations];
    int gap = max_mutation - min_mutation;

    // initialise seed here not inside loops
    srand(time(NULL));

    // make a stack of random indexes
    for (i = 0; i < number_of_mutations; ++i)
    {
        random_index = length_flat_population * (double)rand()/RAND_MAX;
        mutation_index_stack[i] = random_index;
    }

    printf("\n\nPopulation in keith_mutate before\n");
    for(i = 0; i < length_flat_population; i++)
        {
        printf("%5f ", *(p+i));
        }
    // use the pointer and each index to reference and then change genes in memory
    for(i = 0; i < number_of_mutations; i++)
        {
        candidate_gene = *(p + mutation_index_stack[i]);
        mutation = get_mutation(min_mutation, max_mutation);
        candidate_gene += mutation;
        *(p + mutation_index_stack[i]) = candidate_gene;
    }

    printf("\n\nPopulation in keith mutate after\n");
    for(i = 0; i < length_flat_population; i++)
        {
        printf("%5f ", *(p+i));
        }
    printf("\nif that was blank it didnt work");
    return p;
}

// VIEW

void tell_population(double *p, int length_flat_population)
{
int i;
    printf("\n\nPopulation\n");
    for(i = 0; i < length_flat_population; i++)
        {
        printf("%5f ", *(p+i));
        }
}

// CONTROL

int main()
{
    // this module has duplications
    // they are subsidiary functions that I would have written in C as clean code
    // which are not called seperately but rather included in keith_mutate scope
    // the calling lines have been changed and or commented
    // I have retained parts of them so that this can be re written cleanly in C
    // because I want all the dependencies to port across when we import keith_mutate

    // primary declarations
    int i;
    int length_flat_population;
    int max_mutation;
    int min_mutation;
    int number_of_mutations;
    double *p;

    // primary definitions
    length_flat_population =  10;
    number_of_mutations    =  5;
    min_mutation           = -1;
    max_mutation           =  1;

    // secondary declarations
    double flat_population[length_flat_population];

    // Build a fake flat population in main
    for(i = 0; i < length_flat_population; i++)
        {
        flat_population[i] = get_mutation(min_mutation, max_mutation);
        }

    // assign a pointer to be passed to keith_mutate
    p = flat_population;
    //tell_population(p, length_flat_population);
    keith_mutate(p, min_mutation, max_mutation, length_flat_population, number_of_mutations); // acts in memory using pointer so is void return
    //tell_population(p, length_flat_population);
    return 0;
}