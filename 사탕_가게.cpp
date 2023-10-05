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
double M;
vector<pair<int, int>> vec;
vector<int> dp(100001, 0);

void Solution()
{
    int target = (int)(M * 100 + 0.5);
    sort(vec.begin(), vec.end());
    for (int i = 1; i <= target; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int c = vec[j].second;
            int p = vec[j].first;

            if (i < p)
            {
                continue;
            }
            dp[i] = max(dp[i], dp[i - p] + c);
        }
    }
    // for(int i =1 ; i<=target; i++){
    //     cout << dp[i] << " ";
    // }
    cout << dp[target] << '\n';
}

void Input()
{
    while (1)
    {
        cin >> N >> M;
        fill(dp.begin(),dp.end(),0);
        vec.clear();
        if (N == 0 && M == 0.00)
        {
            break;
        }
        for (int i = 0; i < N; i++)
        {
            int a;
            double b;
            cin >> a >> b;
            vec.push_back({(int)(b * 100 + 0.5), a});
        }
        Solution();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    // Solution();
}