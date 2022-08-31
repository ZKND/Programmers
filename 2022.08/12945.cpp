#include <string>
#include <vector>

using namespace std;
#define DIV 1234567

long long solution(int n) {
    long long answer = 0;    
    vector<long long> dp(n+1,0);
    dp[0] = 0;
    dp[1] = 1;
    
    for(int i = 2; i <= n; i++)
    {
        dp[i] = dp[i-1] % DIV + dp[i-2] % DIV;
    }
    
    return dp[n] % DIV;
}