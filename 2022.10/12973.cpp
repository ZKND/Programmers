#include <iostream>
#include <string>
#include <stack>

using namespace std;

int solution(string s)
{
    stack<char> SS;

    for (int i = 0; i < s.length(); i++)
    {
        if (!SS.empty() && SS.top() == s[i])
            SS.pop();
        else
            SS.push(s[i]);
    }
    if (SS.empty())
        return 1;
    else
        return 0;
}