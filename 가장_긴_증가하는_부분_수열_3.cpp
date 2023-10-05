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

int S, C;
vector<long long> vec;

void Solution()
{
    long long l = 0;
    long long r = (long long)1000000000 * (long long)1000000;
    long long answer = LLONG_MIN;
    while (l <= r)
    {
        long long mid = (l + r) / 2;
        long long temp = 0;
        for (int i = 0; i < S; i++)
        {
            temp += vec[i] / mid;
        }
        if (temp < C)
        {
            r = mid - 1;
        }
     
        else
        {
 answer = max(answer, mid);
            l = mid + 1;
        }
    }
    cout << answer << '\n';
}

void Input()
{
    cin >> S >> C;
    for (int i = 0; i < S; i++)
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