/*
------------- Coin change problem - finding out the number of ways to make the value ----------
You are given coins of different denominations and a total amount of money. Find out the
number of ways to make up the money.
*/

#include <iostream>
#include <cstring>

int count( int coins[], int numOfCoins, int value )
{
    int numOfWays[value + 1];

    memset(numOfWays, 0, sizeof(numOfWays));
    numOfWays[0] = 1;

    for(int i=0; i<numOfCoins; i++)
        for(int j=coins[i]; j<=value; j++)
            numOfWays[j] += numOfWays[j-coins[i]];    // Adding number of ways after using the coin

    return numOfWays[value];
}


int main()
{
    int value = 7;
    int coins[] = {1, 3, 2};
    int numOfCoins = sizeof(coins)/sizeof(coins[0]);

    std::cout << "Number of Ways: " << count(coins, numOfCoins, value) << std::endl;
    return 0;
}
