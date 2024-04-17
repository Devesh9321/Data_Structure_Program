#include <iostream>
#include <random>
using namespace std;

/* * * * Longest Common Sequence * * * */
main()
{
    string X = "CGATAATTGAGA", Y = "GTTCCTAATA", result = "";
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
    for (int i = 0; i < sizex; i++)
    {
        for (int j = 0; j < sizey; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Longest String will be : " << dp[sizex - 1][sizey - 1] << endl;

    for (int i = sizex - 1; i >= 0; i--)
    {
        for (int j = sizey - 1; j >= 0; j--)
        {
            if (dp[i][j] > dp[i][j - 1])
            {
                // cout << dp[i][j] << " " << i << " " << j << " " << X[i - 1] << " " << Y[j - 1] << endl;
                result.insert(0, 1, Y[i - 1]);
                if (j == 1)
                {
                    goto finalans;
                }
                j = -1;
            }
        }
    }
finalans:
    cout << "The Longest string will be : " << result;
    return 0;
}