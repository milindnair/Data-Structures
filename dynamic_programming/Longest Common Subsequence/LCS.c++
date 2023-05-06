#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

void LCS_algo(string s1, string s2)
{
    int size1 = s1.length();
    int size2 = s2.length();
    //table for memoization
    //⬇️
    int table[size1 + 1][size2 + 1];
    for (int i = 0; i <= size1; i++)
    {
        for (int j = 0; j <= size2; j++)
        {
            //if any of the string is empty then the value is 0
            //⬇️
            if (i == 0 || j == 0)
                table[i][j] = 0;
            //if characters match then add 1 to the diagonal value
            //⬇️
            else if (s1[i - 1] == s2[j - 1])
                table[i][j] = table[i - 1][j - 1] + 1;
            //else take the max of the top and left value
            //⬇️
            else
                table[i][j] = max(table[i - 1][j], table[i][j - 1]);
        }
    }
    // Printing the matrix
    cout << " ";
    for (int i = 0; i < s2.length(); i++)
    {
        cout << " " << s2[i];
    }
    cout << endl;
    for (int i = 0; i <= size1; i++)
    {
        if (i != 0)
        {
            cout << s1[i - 1] << " ";
        }
        else
        {
            cout << " ";
        }
        for (int j = 0; j <= size2; j++)
        {
            cout << table[i][j] << " ";
        }
        cout << endl;
    }
    int index = table[size1][size2];
    int index1 = size1;
    int index2 = size2;
    char res[index + 1];
    res[index] = '\0';
    while (index1 != 0 && index2 != 0)
    {
        if (s1[index1 - 1] != s2[index2 - 1])
        {
            if (index == table[index1 - 1][index2])
            {
                index1--;
            }
            else
            {
                index2--;
            }
        }
        else
        {
            res[index - 1] = s1[index1 - 1];
            index--;
            index1--;
            index2--;
        }
    }
    cout << endl
         << "LCS: ";
    for (int i = 0; i < strlen(res); i++)
    {
        cout << res[i];
    }
}

int main()
{
    string s1, s2;
    cout << "Enter sequence 1: ";
    cin >> s1;
    cout << "Enter sequence 2: ";
    cin >> s2;
    LCS_algo(s1, s2);
    return 0;
}
