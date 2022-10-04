#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    int who = 0;
    set<string> Slist;
    bool clear = true;

    Slist.insert(words[0]);

    for (int i = 1; i < words.size(); i++)
    {
        if (Slist.find(words[i]) != Slist.end() || words[i].front() != words[i - 1].back())
        {
            clear = false;
            who = i;
            break;
        }
        Slist.insert(words[i]);
    }

    if (clear)
    {
        answer.assign(2, 0);
        return answer;
    }

    answer.push_back(who % n + 1);
    answer.push_back(who / n + 1);

    return answer;
}