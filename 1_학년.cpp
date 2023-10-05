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
vector<int> vec;
long long dp[101][21];
long long answer;

void Solution()
{
    if (vec[0] + vec[1] <= 20 && vec[0] + vec[1] >= 0)
    {
        dp[1][vec[0] + vec[1]]++;
    }
    if (vec[0] - vec[1] <= 20 && vec[0] - vec[1] >= 0)
    {
        dp[1][vec[0] - vec[1]]++;
    }
    for (int i = 2; i < N; i++)
    {
        for (int j = 0; j <= 20; j++)
        {
            if (i == N - 1)
            {
                
                if (dp[i-1][j] > 0 && j == vec[i])
                {
                    answer += dp[i-1][j];
                }
                continue;
            }
            if (dp[i - 1][j] > 0)
            {
                if (j + vec[i] >= 0 && j + vec[i] <= 20)
                {
                    dp[i][j + vec[i]] += dp[i - 1][j];
                }
                if (j - vec[i] >= 0 && j - vec[i] <= 20)
                {
                    dp[i][j - vec[i]] += dp[i - 1][j];
                }
            }
        }
    }

    cout << answer << '\n';
}

void Input()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        vec.push_back(a);
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