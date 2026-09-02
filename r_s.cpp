#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    int m, r = 0, n, error = 0;

    cout << "Enter number of data bits (m): ";
    cin >> m;

    while ((1 << r) < (m + r + 1))
    {
        r++;
    }

    n = m + r;

    cout << "Number of parity bits (r): " << r << endl;
    cout << "Total number of bits (n): " << n << endl;

    cout << "Enter received codeword: ";
    cin >> s;

    for (int p = 1; p <= n; p *= 2)
    {
        int parity = 0;

        for (int i = 1; i <= n; i++)
        {
            if (i & p)
                parity ^= (s[n - i] - '0');
        }

        if (parity != 0)
            error += p;
    }

    if (error == 0)
    {
        cout << "\nReceived codeword is correct." << endl;
    }
    else
    {
        cout << "\nReceived codeword is wrong." << endl;
        cout << "Error is at position: " << error << endl;
    }

    return 0;
}