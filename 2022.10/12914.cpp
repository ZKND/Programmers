#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<long long> dp(2001);


long long solution(int n) {
    long long answer = 0;
    
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    
    for(int i = 3; i < 2001; i++)
    {
        dp[i] = (dp[i-1] + dp[i-2]) % 1234567;
    }
    
    answer = dp[n];
    return answer;
}