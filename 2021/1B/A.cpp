#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;
#define int long long
#define pii pair<int, int>

int h = 0, m = 0, s = 0, n = 0;
void update(int x, int y, int z)
{
    int c1 = x / 1e9 / 3600, c2 = y / 1e9 / 60, c3 = z / 1e9, c4 = z % (int)(1e9);
    // if (c1 >= 12 || c2 >= 60 || c3 >= 60)
    //     return;
    h = c1;
    m = c2;
    s = c3;
    n = c4;
    // cout << "xx " << h << " " << m << " " << s << " " << n << endl;
}

void solveCase(int tn)
{
    int t1 = 0, t2 = 0, t3 = 0;
    cin >> t1 >> t2 >> t3;
    h = 0, m = 0, s = 0, n = 0;
    if (t1 % 720 == 0)
    {
        if (t2 % 12 == 0)
        {
            update(t3, t2 / 12, t1 / 720);
        }
        if (t3 % 12 == 0)
        {
            update(t2, t3 / 12, t1 / 720);
        }
    }
    if (t2 % 720 == 0)
    {
        if (t1 % 12 == 0)
        {
            update(t3, t1 / 12, t2 / 720);
        }
        if (t3 % 12 == 0)
        {
            update(t1, t3 / 12, t2 / 720);
        }
    }
    if (t3 % 720 == 0)
    {
        if (t2 % 12 == 0)
        {
            update(t1, t2 / 12, t3 / 720);
        }
        if (t1 % 12 == 0)
        {
            update(t2, t1 / 12, t3 / 720);
        }
    }
    cout << "Case #" << tn << ": " << h << " " << m << " " << s << " " << n << "\n";
}

int32_t main()
{
    int t = 0;
    cin >> t;
    for (int j = 0; j < t; j++)
    {
        solveCase(j + 1);
    }
}