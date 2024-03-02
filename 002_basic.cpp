#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'reverseArray' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY a as parameter.
 */
vector<int> reverseArray(vector<int> a)
{
    int mid = a.size() / 2, tmp = 0, t = mid - 1;
    if (a.size() % 2 == 1)
    {
        for (int j = 1; j <= mid; j++)
        {
            tmp = a[mid - j];
            a[mid - j] = a[mid + j];
            a[mid + j] = tmp;
        }
    }
    else
    {
        for (int j = 1; j <= mid; j++)
        {
            tmp = a[t];
            a[t] = a[mid - 1 + j];
            a[mid - 1 + j] = tmp;
            t--;
        }
    }
    return a;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string arr_count_temp;
    getline(cin, arr_count_temp);

    int arr_count = stoi(ltrim(rtrim(arr_count_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(arr_count);

    for (int i = 0; i < arr_count; i++)
    {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    vector<int> res = reverseArray(arr);

    cout << " Reversed array : ";
    for (size_t i = 0; i < res.size(); i++)
    {
        fout << res[i];

        if (i != res.size() - 1)
        {
            fout << " ";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}

vector<string> split(const string &str)
{
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos)
    {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
