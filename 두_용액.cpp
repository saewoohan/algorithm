#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits.h>
#include <string>
#include <stack>
#include <list>
#include <unordered_set>
#include <sstream>
#include <deque>
#include <math.h>
#include <map>
#include <set>
using namespace std;

int N;
vector<long long> vec;

void Solution()
{
    sort(vec.begin(), vec.end());
    int left = 0;
    int right = vec.size() - 1;
    pair<long long, long long> answer;
    long long ans = LLONG_MAX;
    while (left < right)
    {
       
        long long temp = vec[left] + vec[right];
        if (abs(temp) < ans)
        {
            ans = abs(temp);
            answer = {vec[left], vec[right]};
        }
        if (vec[left] < 0 && vec[right] < 0)
        {
            left++;
        }
        else if (vec[left] > 0 && vec[right] > 0)
        {
            right--;
        }
        else
        {
            if (temp < 0)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
    }
    cout << answer.first << " " << answer.second << '\n';
}

void Input()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        long long temp;
        cin >> temp;
        vec.push_back(temp);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    Solution();
}