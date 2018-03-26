#include <iostream>
#include <cstring>

int count( int coins[], int num_of_coins, int value )
{
    int table[value + 1];

    memset(table, 0, sizeof(table));
    table[0] = 1;

    for(int i=0; i<num_of_coins; i++)
        for(int j=coins[i]; j<=value; j++)
            table[j] += table[j-coins[i]];

    return table[value];
}


int main()
{
    int value = 7;
    int coins[] = {1, 2, 3};
    int num_of_coins = sizeof(coins)/sizeof(coins[0]);

    std::cout << "Number of Ways: " << count(coins, num_of_coins, value) << std::endl;
    return 0;
}