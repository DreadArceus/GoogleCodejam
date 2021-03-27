#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int t = 0;
    cin >> t;
    for (int j = 0; j < t; j++)
    {
        int x = 0, y = 0;
        string s;
        cin >> x >> y >> s;
        int ans = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] != '?' && i != s.length() - 1)
            {
                if (s[i] == 'C' && s[i + 1] == 'J')
                    ans += x;
                if (s[i] == 'J' && s[i + 1] == 'C')
                    ans += y;
                continue;
            }
            if (i == 0 && s[i + 1] == '?')
            {
                if (x < 0 || y < 0)
                {
                    if (x < y)
                    {
                        s[i] = 'C';
                    }
                    else
                    {
                        s[i] = 'J';
                    }
                }
                else
                {
                    char c = 'x';
                    for (int x = 0; x < s.length(); x++)
                    {
                        if (s[x] != '?')
                        {
                            c = s[x];
                            break;
                        }
                    }
                    if (c == 'x' || c == 'C')
                    {
                        s[i] = 'C';
                    }
                    else
                    {
                        s[i] = 'J';
                    }
                }
                continue;
            }
            int potC = 0, potJ = 0;
            if (i != 0 && s[i - 1] != '?')
            {
                if (s[i - 1] == 'C')
                {
                    potJ += x;
                }
                else
                {
                    potC += y;
                }
            }
            if (i != s.length() - 1 && s[i + 1] != '?')
            {
                if (s[i + 1] == 'C')
                {
                    potJ += y;
                }
                else
                {
                    potC += x;
                }
            }
            if (potJ < potC)
            {
                s[i] = 'J';
                ans += potJ;
            }
            else
            {
                s[i] = 'C';
                ans += potC;
            }
        }
        cout << "Case #" << j + 1 << ": " << ans << "\n";
    }
}