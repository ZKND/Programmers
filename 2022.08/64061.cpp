#include <string>
#include <iostream>
#include <vector>

using namespace std;

bool merge(vector<int>& reward, int& answer)
{
    bool ret = false;
    for(int i = 1; i <= reward.size(); i++)
    {
        if(reward[i] == reward[i-1])
        {
            reward.erase(reward.begin()+i-1, reward.begin()+i+1);
            i -= 2;
            answer += 2;
            ret = true;
        }
    }
    return ret;
}

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    vector<int> reward;
    
    for(int move : moves)
    {
        for(int i = 0; i < board.size(); i++)
        {
            if(board[i][move-1] != 0)
            {
                reward.push_back(board[i][move-1]);
                board[i][move-1] = 0;
                break;
            }
        }
    }   
    
    while(merge(reward, answer));
    
    return answer;
}