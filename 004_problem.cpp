#include <iostream>
#include <string>
#include <cmath>
#include <time.h>

using namespace std;

void print(const auto str, string end = "\n") { cout << str << end; }

/* * * Multiplication of Two number using Karatsuba algorithm * * *
    X = number
    Y = number
    a = Xl * Yl
    d = Xr * Yr
    e = (( Xl + Xr) * (Yl + Yr)) - a - d
    XY = r^n * a + r^n/1 * r + d
*/

void s_eql(string &n1, string &n2)
{
    if (n1.size() != n2.size())
    {
        if (n1.size() > n2.size())
        {
            int a0 = n1.size() - n2.size();
            for (int i = 0; i < a0; i++)
                n2.insert(0, "0");
        }
        else
        {
            int a0 = n2.size() - n1.size();
            for (int i = 0; i < a0; i++)
                n1.insert(0, "0");
        }
    }
}

string Multipli(const string &n1, const string &n2)
{
    int n = n1.size();
    if (n == 1)
        return to_string((n1[0] - '0') * (n2[0] - '0'));

    int halfn = n / 2;
    string Xl = n1.substr(0, halfn),
           Xr = n1.substr(halfn),
           Yl = n2.substr(0, halfn),
           Yr = n2.substr(halfn);

    string a = Multipli(Xl, Yl);
    string d = Multipli(Xr, Yr);
    string sumX = to_string(stoi(Xl) + stoi(Xr));
    string sumY = to_string(stoi(Yl) + stoi(Yr));
    string e = Multipli(sumX, sumY);
    int mid_ele = stoi(e) - stoi(a) - stoi(d);

    string result = a;
    for (int i = 0; i < n; i++)
        result += "0";
    for (int i = 0; i < halfn; i++)
        mid_ele *= 10;
    result = to_string(stoi(result) + mid_ele);
    result = to_string(stoi(result) + stoi(d));

    return result;
    // return to_string(stoi(a) * pow(10,n) + stoi(d) + stoi(e) * pow(10,n));
}

main()
{
    string n1 = "1234";
    string n2 = "4321";

    clock_t start_m = clock();
    // Start Code which time should be calculated
    s_eql(n1, n2);
    string result = Multipli(n1, n2);
    // End Code which time should be calculated
    clock_t end_m = clock();
    long double time_required_m = (long double)(end_m - start_m);
    cout << "\n| Multiplication  \t| " << time_required_m << " \t| " << result;

    return 0;
}
