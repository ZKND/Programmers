#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> arr) {
    int answer = 0;
    bool check;

    sort(arr.begin(), arr.end());
    int tmp = arr.back();
    while (true)
    {
        check = true;
        for (int i = 0; i < arr.size() - 1; i++)
        {
            if (arr.back() % arr[i] != 0)
            {
                check = false;
                break;
            }
        }
        if (check)
            return arr.back();

        arr.back() += tmp;
    }
}