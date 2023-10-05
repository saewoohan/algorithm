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
int L[21];
int dp[101];
int J[21];

void Solution()
{

    int answer = INT_MIN;
    for (int i = 0; i < N; i++)
    {
        for (int j = 100; j >= 1; j--)
        {
            if (L[i] < j)
            { // 넣을 수 있다면?
                dp[j] = max(dp[j], dp[j - L[i]] + J[i]);
                // 그 물건을 넣었을 때와 넣지 않았을 때 중 더 큰 값으로 초기화
            }
        }
    }

    cout << dp[100] << '\n';
}

void Input()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> L[i];
    }
    for (int i = 0; i < N; i++)
    {
        cin >> J[i];
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