#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t = 0;
    cin >> t;
    for (int j = 0; j < t; j++)
    {
        int n = 0;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        int ans = 0;
        for (int i = 0; i < n - 1; i++)
        {
            vector<int>::iterator next = min_element(v.begin() + i, v.end());
            ans += next - v.begin() - i + 1;
            reverse((v.begin() + i), next + 1);
        }
        cout << "Case #" << j + 1 << ": " << ans << "\n";
    }
}