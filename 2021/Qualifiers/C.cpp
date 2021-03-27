#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// int analysisFn(vector<int> v, bool debug)
// {
//     if (debug)
//         for (int i = 0; i < v.size(); i++)
//         {
//             cout << v[i] << " ";
//         }
//     int ans = 0;
//     for (int i = 0; i < v.size() - 1; i++)
//     {
//         vector<int>::iterator next = min_element(v.begin() + i, v.end());
//         ans += next - v.begin() - i + 1;
//         reverse((v.begin() + i), next + 1);
//     }
//     if (debug)
//         cout << ": " << ans << "\n";
//     return ans;
// }

// void tester(int l, int r)
// {
//     for (int x = l; x <= r; x++)
//     {
//         vector<int> v(x);
//         int maxResult = 0, minResult = INT_MAX;
//         for (int i = 0; i < v.size(); i++)
//         {
//             v[i] = i + 1;
//         }
//         do
//         {
//             int result = analysisFn(v, true);
//             maxResult = max(result, maxResult);
//             minResult = min(result, minResult);
//         } while (next_permutation(v.begin(), v.end()));
//         // if(minResult != x-1 || maxResult != (x * (x+1))/2 - 1)
//         cout << "For x=" << x << ", Max res: " << maxResult << " Min res: " << minResult << "\n";
//     }
// }

vector<int> solve(int n, int c)
{
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        ans[i] = i + 1;
    }
    c -= n - 1;
    int maxSolo = n - 1;
    while (c > maxSolo)
    {
        c -= maxSolo--;
    }

    //solo
    reverse((ans.begin() + n - 1 - c), ans.end());

    //batch
    for (int i = n - 2 - maxSolo; i >= 0; i--)
    {
        reverse((ans.begin() + i), ans.end());
    }

    return ans;
}

// void testGen(int l, int r)
// {
//     int good = 0, bad = 0;
//     for (int x = l; x <= r; x++)
//     {
//         for (int c = x - 1; c < (x * (x + 1)) / 2; c++)
//         {
//             vector<int> v = solve(x, c);
//             cout << "For x = " << x << ", c = " << c << "\n\tArr: ";
//             for(int i = 0; i < v.size(); i++)
//             {
//                 cout << v[i] << " ";
//             }
//             int realC = analysisFn(v, false);
//             if(realC == c) good++;
//             else bad++;
//             cout << "\n\tReal c: " << realC << "\n";
//         }
//     }
//     cout << "Total good: " << good << " Total bad: " << bad << "\nGG EZ";
// }

int main()
{
    // tester(3, 5);
    // testGen(2, 100);
    int t = 0;
    cin >> t;
    for (int j = 0; j < t; j++)
    {
        int n = 0, c = 0;
        cin >> n >> c;
        cout << "Case #" << j + 1 << ": ";
        if (c < n - 1 || c >= (n * (n + 1)) / 2)
        {
            cout << "IMPOSSIBLE\n";
            continue;
        }
        vector<int> v = solve(n, c);
        for (int i = 0; i < n; i++)
        {
            cout << v[i] << " ";
        }
        cout << "\n";
    }
}