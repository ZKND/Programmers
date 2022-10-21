#include <string>
#include <vector>
#include <deque>
#include <stack>

using namespace std;

template <typename T>
bool check(T deque)
{
    stack<char> S;
    
    for(char c : deque)
    {
        if(S.empty())
            S.push(c);
        else if(S.top() == c - 1 || S.top() == c - 2)
            S.pop();
        else
            S.push(c);
    }    
    return S.empty() ? true : false;
}

int solution(string s) {
    int answer = 0;
    deque<char> D;
    
    for(char c : s)
        D.push_back(c);
    
    for(int i = 0; i < D.size(); i++)
    {
        if(check(D))
            answer++;
        char tmp = D.front();
        D.pop_front();
        D.push_back(tmp);
    }
    
    return answer;
}