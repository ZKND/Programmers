#include <string>
#include <vector>
#include <algorithm>
#include <functional>


using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer(2);
    int tmp = brown + yellow;
    answer[0] = 3;

    while (true)
    {
        if (tmp % answer[0] == 0)
        {
            answer[1] = tmp / answer[0];
            if ((answer[0] - 2) * (answer[1] - 2) == yellow)
                break;
        }
        answer[0]++;
    }
    sort(answer.begin(), answer.end(), greater<int>());
    return answer;
}