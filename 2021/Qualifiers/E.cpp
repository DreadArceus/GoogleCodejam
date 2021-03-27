#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
double maxProb = 0.99753;
double avgProb = 0.5;
double minProb = 0.00247;

// bool comp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b)
// {
//     return double(a.first.first) / a.first.second > double(b.first.first) / b.first.second;
// }

// int solve(vector<pair<pair<int, int>, int> > score)
// {
//     sort(score.begin(), score.end(), comp);
//     return score[0].second;
// }

int deepAnalysis(vector<pair<pair<int, int>, int> > score, vector<pair<int, int> > &freq, vector<string> v)
{
    sort(freq.begin(), freq.end());
    double maxSus = 0, ans = -1;
    for(int i = 0; i < v.size(); i++)
    {
        double localSus = 0;
        for(int j = 0; j < freq.size(); j++)
        {
            if(v[i][freq[j].second] == '1')
                localSus += (10000 - freq[j].first);
            else
                localSus += (freq[j].first);
        }
        localSus += double(score[i].first.first) / (score[i].first.second + 1);
        if(localSus > maxSus)
        {
            maxSus = localSus;
            ans = i;
        }
    }
    return ans;
}

int main()
{
    freopen("./inpE.txt", "r", stdin);
    int t = 0, p = 0;
    cin >> t >> p;
    for (int i = 0; i < t; i++)
    {
        vector<string> v(100);
        vector<pair<pair<int, int>, int> > score(100);
        vector<pair<int, int> > freq(10000);
        for(int i = 0; i < freq.size(); i++)
        {
            freq[i] = make_pair(0, i);
        }
        for (int j = 0; j < 100; j++)
        {
            cin >> v[j];
            int correct = 0, incorrect = 0;
            for(int k = 0; k < v[j].length(); k++)
            {
                if(v[j][k] == '1')
                {
                    correct++;
                    freq[k].first++;
                }
                else
                    incorrect++;
            }
            score[j] = make_pair(make_pair(correct, incorrect), j);
        }
        // int answer = solve(score);
        int answer = deepAnalysis(score, freq, v);
        cout << "Case #" << i + 1 << ": " << answer + 1 << "\n";
    }
}