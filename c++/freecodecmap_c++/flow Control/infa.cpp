
#include <bits/stdc++.h>

// 300 300 600 600 880
// 667 667 117 110 110
// 2,3   a3b2a1  &&  ||

// a300b500a300b7a280b110

using namespace std;

void vectorIntPrint(vector<int> &vector)
{
    if (!vector.size())
        return;
    for (int element : vector)
        cout << element << " ";
    cout << endl;
}

string odwrotString(string a)
{
    string b = "";
    for (int i = 0; i < a.size(); i++)
    {
        b += a[a.size() - i - 1];
    }
    // vectorIntPrint(a);
    // vectorIntPrint(b);
    return b;
}

int zamiana(string a) // zamienia  1234 na 2143   ||  123456 na 213465
{
    a = odwrotString(a);
    int zamieniona = 0;
    vector<int> cyfry;
    for (int i = 0; i < a.length(); i++)
    {
        int tmp;
        switch (a[i])
        {
        case '0':
            tmp = 0;
            break;
        case '1':
            tmp = 1;
            break;
        case '2':
            tmp = 2;
            break;
        case '3':
            tmp = 3;
            break;
        case '4':
            tmp = 4;
            break;
        case '5':
            tmp = 5;
            break;
        case '6':
            tmp = 6;
            break;
        case '7':
            tmp = 7;
            break;
        case '8':
            tmp = 8;
            break;
        case '9':
            tmp = 9;
            break;
        }
        cyfry.push_back(tmp);
    }
    for (int i = 0; i < cyfry.size(); i++)
    {
        zamieniona = zamieniona + cyfry[i] * pow(10, i);
        // cout << zamieniona << endl;
    }
    return zamieniona;
}

int main()
{
    string s;
    cin >> s;
    vector<int> A;
    vector<int> B;
    for (int i = 0; i < s.length(); i++)
    {
        string tmp = "";
        if (s[i] == 'a' || s[i] == 'b')
        {
            int j;
            for (j = i + 1; j < s.length(); j++)
            {
                if (s[j] == 'a' || s[j] == 'b')
                    break;
                tmp = tmp + s[j];
                // cout << tmp << '\n';
            }
            if (s[i] == 'a')
            {
                A.push_back(zamiana(tmp));
            }
            if (s[i] == 'b')
            {
                B.push_back(zamiana(tmp));
            }
            // i = j;
        }
    }
    // vectorIntPrint(A);
    // vectorIntPrint(B);

    vector<int> prefA(A.size());
    vector<int> prefB(B.size());

    prefA[0] = A[0];
    for (int i = 1; i < A.size(); i++)
    {
        prefA[i] = prefA[i - 1] + A[i];
    }
    prefB[B.size() - 1] = B[B.size() - 1];
    for (int i = B.size() - 2; i >= 0; i--)
    {
        prefB[i] = prefB[i + 1] + B[i];
    }

    vector<int> odp(prefA.size());
    for (int i = 0; i < prefA.size(); i++)
    {
        odp[i] = prefA[i] + prefB[i];
    }
    int mini = odp[0];
    for (int i = 1; i < prefA.size(); i++)
    {
        if (odp[i] > mini)
            mini = odp[i];
    }
    // vectorIntPrint(odp);
    cout << mini;

    return 0;
}