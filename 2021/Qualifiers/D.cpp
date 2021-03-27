#include <iostream>
#include <vector>
using namespace std;

// void debug(vector<int> ans, int j)
// {
//     cout << "DEBUG " << j << " element, array : "; 
//     for (int i = 0; i < ans.size(); i++)
//     {
//         cout << ans[i] << " ";
//     }
//     cout << endl;
// }

vector<int> solve(int n, int divi)
{
    vector<int> ans(n);

    vector<int> buf(n);
    for (int i = 0; i < n; i++)
    {
        buf[i] = i + 1 + divi * 10;
    }
    vector<int> middle;
    int x = buf[0], y = buf[1], z = buf[2];
    int current = 2, req = n - 2, iteration = 0;
    while (true)
    {
        while (middle.size() != req)
        {
            int med;
            cout << x << " " << y << " " << z << endl;
            cin >> med;
            if(med == -1) exit(-1);
            if (med == x)
            {
                middle.push_back(med);
                if (middle.size() == req)
                {
                    ans[iteration] = y;
                    ans[n - 1 - iteration] = z;
                }
                else
                {
                    x = buf[++current];
                }
            }
            else if (med == y)
            {
                middle.push_back(med);
                if (middle.size() == req)
                {
                    ans[iteration] = x;
                    ans[n - 1 - iteration] = z;
                }
                else
                {
                    y = buf[++current];
                }
            }
            else
            {
                middle.push_back(med);
                if (middle.size() == req)
                {
                    ans[iteration] = y;
                    ans[n - 1 - iteration] = x;
                }
                else
                {
                    z = buf[++current];
                }
            }
        }
        req -= 2;
        if (req <= 0)
        {
            if (middle.size() == 1)
            {
                ans[n / 2] = middle[0];
            }
            else
            {
                ans[n / 2 - 1] = middle[0];
                ans[n / 2] = middle[1];
            }
            break;
        }
        iteration++;
        buf = middle;
        middle.clear();
        x = buf[0];
        y = buf[1];
        z = buf[2];
        current = 2;
    }

    int currentEdge = 1;
    while (currentEdge < n / 2)
    {
        int med = 0;
        cout << ans[0] << " " << ans[currentEdge] << " "
             << ans[n - 1 - currentEdge] << endl;
        cin >> med;
        if(med == -1) exit(-1);
        if (med == ans[n - 1 - currentEdge])
        {
            ans[n - 1 - currentEdge] = ans[currentEdge];
            ans[currentEdge] = med;
        }
        currentEdge++;
    }

    return ans;
}

pair<int, int> binarySearch(vector<vector<int> > partials, int i, int l, int r, int z)
{
    int x = 0, y = 0;
    while (true)
    {
        if ((l + r) % 2 == 0)
            x = (l + r) / 2 - 1;
        else
            x = (l + r - 1) / 2;
        y = x + 1;
        if(x < 0 || y > partials[0].size() - 1) break;
        cout << partials[0][x] << " " << partials[0][y] << " " << partials[i][z] << endl;
        int med = 0;
        cin >> med;
        if(med == -1) exit(-1);
        if (med == partials[0][x])
        {
            r = x;
        }
        else if (med == partials[0][y])
        {
            l = y + 1;
        }
        else
        {
            break;
        }
    }
    return make_pair(x, y);
}

vector<int> divideAndCombine(int n)
{
    vector<vector<int> > partials(n / 10 + (n % 10 != 0 ? 1 : 0));
    for (int i = 0; i < partials.size(); i++)
    {
        if (i == partials.size() - 1 && n % 10 != 0)
            partials[i] = solve(n % 10, i);
        else
            partials[i] = solve(10, i);
    }

    // vector<vector<int> > partials(3, vector<int>(10, 0));
    // for (int i = 0; i < partials.size(); i++)
    // {
    //     for (int j = 0; j < 10; j++)
    //     {
    //         partials[i][j] = (i) * 10 + j + 1;
    //     }
    // }
    // debug(partials[0], -1);

    for (int i = 1; i < partials.size(); i++)
    {
        pair<int, int> a1 = binarySearch(partials, i, 0, partials[0].size(), 0);
        partials[0].insert(partials[0].begin() + a1.second, partials[i][0]);

        // debug(partials[0], 0);

        pair<int, int> a2 = binarySearch(partials, i, 0, partials[0].size(), 1);
        partials[0].insert(partials[0].begin() + a2.second, partials[i][1]);
        
        // debug(partials[0], 1);
        
        int l = 0, r = partials[0].size(), ordering = -1;
        for (int x = 0; x < partials[0].size(); x++)
        {
            if (partials[0][x] == partials[i][0])
            {
                ordering = 0;
                break;
            }
            if (partials[0][x] == partials[i][1])
            {
                ordering = 1;
                break;
            }
        }
        if(ordering == 0)
        {
            l = a2.first + 2;
        }
        else
        {
            r = a2.first + 1;
        }
        for (int j = 2; j < partials[i].size(); j++)
        {
            pair<int, int> a = binarySearch(partials, i, l, r, j);
            if(a.first < 0 || a.second > partials[0].size() - 1)
            {
                // cout << "EDGE DETECTED" << endl;
                if(a.first < 0)
                    while(j < partials[i].size())
                        partials[0].insert(partials[0].begin(), partials[i][j++]);
                else if(a.second > partials[0].size() - 1)
                    while(j < partials[i].size())
                        partials[0].insert(partials[0].end(), partials[i][j++]);
                // debug(partials[0], -2);
                break;
            }
            else
                partials[0].insert(partials[0].begin() + a.second, partials[i][j]);

            // debug(partials[0], j);

            if(ordering == 0)
            {
                l = a.first + 2;
                r += 1;
            }
            else
            {
                r = a.first + 1;
            }
        }
    }
    return partials[0];
}

int main()
{
    int t = 0, n = 0, q = 0;
    cin >> t >> n >> q;
    for (int i = 0; i < t; i++)
    {
        vector<int> ans;
        if (n <= 10)
        {
            ans = solve(n, 0);
        }
        else
        {
            ans = divideAndCombine(n);
        }
        for (int j = 0; j < n; j++)
        {
            cout << ans[j] << " ";
        }
        cout << endl;
        int result = 0;
        cin >> result;
        if (result == -1)
            break;
    }
}