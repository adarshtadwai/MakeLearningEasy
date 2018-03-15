/*
----------- Longest Common Subsequence -----------
Given two sequences, find the length of longest subsequence present in both of them.
*/

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>


int lcs(char *X, char *Y, int m, int n)
{
	std::vector< std::vector<int> > L(m+1, std::vector<int>(n+1));   // int L[m+1][n+1]

    for(int i=0; i<=m; i++)
    {
        for(int j=0; j<=n; j++)
        {
            if(i==0 || j==0)
                L[i][j] = 0;
            else if(X[i-1] == Y[j-1])
                L[i][j] = L[i-1][j-1] + 1;
            else
                L[i][j] = std::max(L[i-1][j], L[i][j-1]);
        }
    }

    return L[m][n];
}


int main()
{
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";

    int m = strlen(X);
    int n = strlen(Y);

    std::cout << "Length of lcs is: " << lcs(X, Y, m, n) << std::endl;

    return 0;
}

