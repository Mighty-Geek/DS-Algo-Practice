#include <iostream>
#include <string.h>
using namespace std;

#define d 256

void search(char pat[], char txt[], int q)
{
    int m = strlen(pat);
    int n = strlen(txt);

    int i, j;
    int p = 0;
    int t = 0;
    int h = 1;

    for (i = 0; i < m - 1; i++)
    {
        h = (h * d) % q;
    }

    for (i = 0; i < m; i++)
    {
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }

    for (i = 0; i <= n - m; i++)
    {
        if (p == t)
        {
            for (j = 0; j < m; j++)
            {
                if (txt[i + j] != pat[j])
                    break;
            }
            if (j == m)
                cout << "Pattern found at index " << i << "\n";
        }

        if (i < n - m)
        {
            t = (d * (t - txt[i] * h) + txt[i + m]) % q;

            if (t < 0)
            {
                t += q;
            }
        }
    }
}

int main()
{
    char text[] = "GEEKS FOR GEEKS";
    char pattern[] = "GEEK";
    int q = 101;

    search(pattern, text, q);
    return 0;
}