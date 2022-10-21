#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <deque>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    
    deque<string> D;
    
    for(string& s : cities)
    {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
    }
    
    for(int i = 0; i < cities.size(); i++)
    {
        // 덱에 있는지 확인
        // 있으면 제거한후 푸쉬
        // 없으면 pop_front 후 push
        
        // 푸쉬하고 나서 사이즈보다 크면 pop_front
        auto it = find(D.begin(), D.end(), cities[i]);
        if(it != D.end())
        {
            // 있는경우 (cache hit)
            D.erase(it);
            D.push_back(cities[i]);
            answer += 1;
        }
        else
        {
            // 없는경우 (cache miss)
            D.push_back(cities[i]);
            answer += 5;
        }
        
        if(D.size() > cacheSize)
            D.pop_front();
    }
    return answer;
}