#include <iostream>
#include <vector>
#include <string>
using namespace std;

int comp(vector<int> v, int x, int y, int z)
{
    if((v[x] < v[y] && v[x] > v[z]) || (v[x] > v[y] && v[x] < v[z]))
        return x;
    if((v[y] < v[x] && v[y] > v[z]) || (v[y] > v[x] && v[y] < v[z]))
        return y;
    return z;
}

int main()
{
    int T = 1, N = 50, Q = 300;
    cout << T << " " << N << " " << Q << endl;
    while(T--)
    {
        vector<int> ans(N);
        for(int i = 0; i < N; i++)
        {
            ans[i] = i + 1;
        }
        string req;
        while(Q--)
        {
            getline(cin, req);
            int spaceCount = 0;
            int x = req[0] - '0', y = req[2] - '0', z = req[4] - '0';
            int old = 0;
            for(int j = 0; j < req.length(); j++)
            {
                if(req[j] == ' ')
                    spaceCount++;
                    if(spaceCount == 1)
                        x = stoi(req.substr(0, j-1));
                    if(spaceCount == 2)
                    {
                        y = stoi(req.substr(old, j-old-1));
                        z = stoi(req.substr(j+1, req.length() - j - 1));
                    }
                    old = j + 1;
            }
            if(spaceCount > 2) break;
            cerr << "new request, " << x << " " << y << " " << z << endl;
            int median = comp(ans, x, y, z);
            cout << median << endl;
        }
        bool match = true;
        for(int i = 0; i < N; i++)
        {
            if(req[i * 2] - '0' != ans[i])
            {
                match = false;
            }
        }
        cout << ((match) ? 1 : -1) << endl;
        if(!match) break;
    }
}