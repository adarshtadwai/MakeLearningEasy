/*
----------------- Subset Sum Problem -------------------
Find subset of elements that are selected from a given set whose sum adds up to a given number K.

This solutions finds all possible solutions by exhaustive search.
*/

#include <iostream>


#define NUM_OF_ITEMS 7
#define TARGET_SUM 35

static int total_solutions = 0;


void print_subset(int subset_items[], int size)
{
	total_solutions++;

    for(int i = 0; i < size; i++){
		std::cout << subset_items[i] << "   ";
	}

	std::cout << std::endl;
}

void find_subsets(int weights[], int w_itr, int subset_items[], int s_pos, int s_sum)
{
    if (TARGET_SUM == s_sum){
        print_subset(subset_items, s_pos);
        find_subsets(weights, w_itr+1, subset_items, s_pos-1, s_sum - subset_items[s_pos-1]);
    }
    else{
        for(w_itr; w_itr < NUM_OF_ITEMS; w_itr++)
        {
            subset_items[s_pos] = weights[w_itr];
            find_subsets(weights, w_itr+1, subset_items, s_pos + 1, s_sum + weights[w_itr]);
        }
    }
}

int main()
{
	int weights[] = {10, 7, 5, 18, 12, 20, 15};
    int subset_items[NUM_OF_ITEMS];

    find_subsets(weights, 0, subset_items, 0, 0);
    std::cout << "Total number of solutions: " << total_solutions << std::endl;

	return 0;
}
