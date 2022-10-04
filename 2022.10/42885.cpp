#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0, sub, tmp;

    int idx = 0;
    sort(people.begin(), people.end());

    while (true)
    {
        //tmp = -1;
        sub = limit - people.back();
        people.pop_back();
        answer++;

        //      if(tmp != -1)
        //            people.erase(people.begin() + tmp);

        if (sub >= people[idx])
            idx++;

        //if(people.empty())
        if (idx >= people.size())
            return answer;
    }
}