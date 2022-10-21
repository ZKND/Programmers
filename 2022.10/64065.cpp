#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second > b.second;
}

vector<int> solution(string s) {
    vector<int> answer;
    
    string tmp;
    
    vector<int> numbers;
    vector<pair<int, int>> list;
    
    for(char c : s)
    {
        if(c != '{' && c != '}')
            tmp += c;            
    }
    
    string num;
    for(char c : tmp)
    {
        if(c != ',')
            num += c;
        else
        {
            numbers.push_back(stoi(num));
            num.clear();            
        }
    }
    numbers.push_back(stoi(num));
    
    sort(numbers.begin(), numbers.end());
        
    for(int i = 0; i < numbers.size();)
    {
        int c = 1;
        for(int j = i+1; j < numbers.size(); j++)
        {
            if(numbers[i] == numbers[j])
                c++;
        }
        list.push_back(make_pair(numbers[i], c));
        i += c;        
    }
    
    sort(list.begin(), list.end(), cmp);
    
    for(int i = 0; i < list.size(); i++)
    {
        answer.push_back(list[i].first);
    }
    return answer;
}