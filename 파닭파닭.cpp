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
long long sum;

void Solution()
{
    long long l = 1; //0일 이유가 없음 ㅋㅋㅋ ㅅㅂ
    long long r = sum;
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

    cout << sum - answer * C << '\n';
}

void Input()
{
    cin >> S >> C;
    for (int i = 0; i < S; i++)
    {
        long long temp;
        cin >> temp;
        vec.push_back(temp);
        sum += temp;
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