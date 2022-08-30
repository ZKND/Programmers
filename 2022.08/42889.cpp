#include <string>
#include <vector>
#include <algorithm>


using namespace std;

bool cmp(pair<int, double> a, pair<int, double> b)
{
    if(a.second == b.second)
        return a.first < b.first;
    else
        return a.second > b.second;    
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<double> stop(N+1, 0);
    vector<pair<int, double>> percent;
    
    int players = stages.size();
    
    sort(stages.begin(), stages.end());
    
    int tmp = 0;
    for(int i = 1; i <= N; i++)
    {
        for(int j = tmp; j < players; j++)
        {
            if(stages[j] == i)
                stop[i]++;
            else
            {
                tmp = j;
                break;                
            }
        }
    }
    
    double tmp2 = players;
    
    for(int i = 1; i <= N; i++)
    {
        tmp2 -= stop[i-1];
        if(tmp2 == 0)
        {
            percent.push_back({i,0});
        }
        else
            percent.push_back({i, stop[i]/tmp2});
    }
    
    sort(percent.begin(), percent.end(), cmp);
    
    for(int i = 0; i < N; i++)
    {
        answer.push_back(percent[i].first);
    }
    
    return answer;
}