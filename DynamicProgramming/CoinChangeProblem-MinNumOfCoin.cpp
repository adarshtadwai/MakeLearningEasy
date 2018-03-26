/*
---------- Coin change problem - minimum number of coins -----------
My friend SSS is a talented and beautiful girl. She loves Ice cream. One day, she
went to the shop and bought an Ice cream. She gave 20 takas (currency of Bangladesh)
to the shopkeeper. After keeping the price of the Ice cream, the shopkeeper
exchanged 13 takas using 6 coins where 5 coins of 2 takas and 1 coin of 3 takas.
SSS is a talented girl and she also knows dynamic programming. She doesn't want to
increase the weight of her purse by taking more coins. In the shopkeeper, only 3 types
of coins are available. The denominations of those coins are 2, 3, and 5. SSS calculated
the minimum number of coins to make 13 takas and took those coins.

Find out the minimum number of coins that SSS calculated and also those coins.
*/

#include <iostream>
#include <climits>

void print_used_coins(int usedCoins[], int value)
{
    while (value > 0)
    {
        std::cout << usedCoins[value] << " ";
        value -= usedCoins[value];
    }
    std::cout << std::endl;
}

int find_min_coins(int coins[], int value, int numOfCoins, int minNumCoins[], int usedCoin[])
{
    minNumCoins[0] = 0;        // set base case when value is 0

    for (int i=1; i<=value; i++)
        minNumCoins[i] = INT_MAX;

    for (int i=1; i<=value; i++)
    {
        for (int j=0; j<numOfCoins; j++)
        {
            if (coins[j] <= i)
            {
                int sub_res = minNumCoins[i-coins[j]];
                if (sub_res != INT_MAX && sub_res + 1 < minNumCoins[i])
                {
                    minNumCoins[i] = sub_res + 1;
                    usedCoin[i] = coins[j];
                }
            }
        }
    }

    return minNumCoins[value];
}

int main()
{
    int value = 13;
    int coins[] = {2, 3, 5};
    int numOfCoins = sizeof(coins)/sizeof(coins[0]);

    int minNumCoins[value+1];
    int usedCoin[value+1];

    std::cout << "Minimum number of coins required: "
            << find_min_coins(coins, value, numOfCoins, minNumCoins, usedCoin) << std::endl;

    std::cout << "Used coins are: ";
    print_used_coins(usedCoin, value) ;

    return 0;
}
