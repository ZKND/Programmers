#include <string>
#include <vector>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    
    for(int i = citations.size(); i > 0; i--)
    {
        int H = 0;
        for(int j : citations)
        {
            if(j >= i)
                H++;
        }
        
        if(H >= i)
            return i;        
    }
    return answer;
}