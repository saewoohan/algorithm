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

int T, W;
vector<int> vec;
int dp[1001][31][3];

void Solution()
{
    //초기 설정 
    if (vec[0] == 1)
    {
        dp[1][0][1] = 1;
        dp[1][1][1] = 0;
    }
    else
    {
        dp[1][0][2] = 0;
        dp[1][1][2] = 1;
    }

    for (int i = 1; i < vec.size(); i++)
    {
        int tree = vec[i];
        for (int j = 0; j <= i; j++)
        {
            // i초에 움직일 수 있는 횟수는 i번
            if (tree == 1)
            {
                //전혀 움직이지 않은 경우
                if(j == 0){
                    dp[i+1][j][1] = dp[i][j][1] + 1;
                    dp[i+1][j][2] = dp[i][j][2];
                    continue;
                }
                //한번이라도 움직인 경우에는 이전의 움직인 반대편 트리와 움직이지 않은 현재 트리 중 max를 사용
                dp[i + 1][j][1] = max(dp[i][j - 1][2], dp[i][j][1]) + 1;
                //움직일 수 있는 경우에 추가
                if (j + 1 <= W)
                {
                    dp[i + 1][j + 1][1] = dp[i][j][2] + 1;
                }
                dp[i + 1][j][2] = max(dp[i][j - 1][1], dp[i][j][2]);
                if (j + 1 <= W)
                {
                    dp[i + 1][j + 1][2] = dp[i][j][1];
                }
            }
            else
            {
                //전혀 움직이지 않은 경우
                if(j == 0){
                    dp[i+1][j][1] = dp[i][j][1];
                    dp[i+1][j][2] = dp[i][j][2]+1;
                    continue;
                }
                 //한번이라도 움직인 경우에는 이전의 움직인 반대편 트리와 움직이지 않은 현재 트리 중 max를 사용
                dp[i + 1][j][2] = max(dp[i][j - 1][1], dp[i][j][2]) + 1;
                 //움직일 수 있는 경우에 추가
                if (j + 1 <= W)
                {
                    dp[i + 1][j + 1][2] = dp[i][j][1] + 1;
                }
                dp[i + 1][j][1] = max(dp[i][j - 1][1], dp[i][j][1]);
                if (j + 1 <= W)
                {
                    dp[i + 1][j + 1][1] = dp[i][j][2];
                }
            }
        }
    }
    int answer = INT_MIN;
    for (int i = 1; i <= T; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            
            answer = max(answer, max(dp[i][j][1], dp[i][j][2]));
        }
    }
    cout << answer << '\n';
}

void Input()
{
    cin >> T >> W;
    for (int i = 0; i < T; i++)
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