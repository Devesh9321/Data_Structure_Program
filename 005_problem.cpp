#include <iostream>
#include <random>
using namespace std;

/* * * * Longest Common Sequence * * * */
string findlcs(const string X, const string Y)
{
    int sizex = X.size() + 1, sizey = Y.size() + 1;
    int dp[sizex][sizey];

    for (int i = 0; i < sizex; i++)
        dp[i][0] = 0;

    for (int j = 0; j < sizey; j++)
        dp[0][j] = 0;

    for (int i = 1; i < sizex; i++)
    {
        for (int j = 1; j < sizey; j++)
        {
            if (X[i - 1] == Y[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // print the dp array
    // for (int i = 0; i < sizex; i++)
    // {
    //     for (int j = 0; j < sizey; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << "Longest String will be : " << dp[sizex - 1][sizey - 1] << endl;

    // Using the backtracking to get the string.
    int i = sizex - 1, j = sizey - 1;
    string lcs;
    while (i > 0 && j > 0)
    {
        if (X[i - 1] == Y[j - 1])
        {
            lcs = X[i - 1] + lcs;
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }

    return lcs;
}

main()
{
    string X = "CGATAATTGAGA", Y = "GTTCCTAATA";
    string lcs = findlcs(X, Y);
    cout << "The Longest string will be : " << lcs;
    return 0;
}