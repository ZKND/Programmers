#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    vector<bool> chk(201, false);
    
    for(int i = 0; i < numbers.size(); i++)
    {
        for(int j = i+1; j < numbers.size(); j++)
        {
            chk[numbers[i]+numbers[j]] = true;
        }
    }
    
    for(int i = 0; i < 201; i++)
    {
        if(chk[i])
            answer.push_back(i);
    }
    return answer;
}