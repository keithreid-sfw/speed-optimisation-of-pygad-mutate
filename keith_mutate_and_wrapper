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

int keith_mutate(double *p, int min_mutation, int max_mutation, int length_flat_population, int number_of_mutations)
{
    // primary declarations
    int    i;
    int    random_index;
    double candidate_gene;
    double mutation;

    // secondary declarations
    int mutation_index_stack[number_of_mutations];

    // initialise seed here not inside loops
    srand(time(NULL));

    // make a stack of random indexes
    for (i = 0; i < number_of_mutations; ++i)
    {
        random_index = length_flat_population * (double)rand()/RAND_MAX;
        mutation_index_stack[i] = random_index;
    }
    // use the pointer and each index to reference and then change genes in memory
    for(i = 0; i < number_of_mutations; i++)
        {
        candidate_gene = *(p + mutation_index_stack[i]);
        mutation = get_mutation(min_mutation, max_mutation);
        candidate_gene += mutation;
        *(p + mutation_index_stack[i]) = candidate_gene;
    }
    return 0;
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
    tell_population(p, length_flat_population);
    keith_mutate(p, min_mutation, max_mutation, length_flat_population, number_of_mutations); // acts in memory using pointer so is void return
    tell_population(p, length_flat_population);
    return 0;
}
