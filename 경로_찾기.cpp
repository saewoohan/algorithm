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

int N, M, C;
long long dp[51][51][51][51]; // dp[y][x][c] => y,x좌표에서 c개의 오락실을 지난 경로 개수
long long visited[51][51][51][51];
long long arr[51][51]; // y,x 좌표에서의 오락실 번호 (없으면 0)
int dy[2] = {1, 0};
int dx[2] = {0, 1};

void bfs()
{
    queue<pair<int, pair<int, pair<int, int>>>> q;
    if (arr[0][0] == 0)
    {
        q.push({0, {0, {0, 0}}});
        dp[0][0][0][0] = 1;
        visited[0][0][0][0] = 1;
    }
    else
    {
        q.push({0, {0, {arr[0][0], 1}}});
        dp[0][0][1][arr[0][0]] = 1;
        visited[0][0][1][arr[0][0]] = 1;
    }

    while (!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second.first;
        int lastRoom = q.front().second.second.first;
        int number = q.front().second.second.second;

        q.pop();

        if (y == N - 1 && x == M - 1)
        {

            continue;
        }

        for (int i = 0; i < 2; i++)
        {
            int py = y + dy[i];
            int px = x + dx[i];

            if (py < 0 || px < 0 || py >= N || px >= M)
            {
                continue;
            }
            // 오락실을 만나지 않은 경우
            if (arr[py][px] == 0)
            {

                dp[py][px][number][lastRoom] += ((dp[y][x][number][lastRoom]));
                dp[py][px][number][lastRoom] %= 1000007;
                if (visited[py][px][number][lastRoom] == 0)
                {
                    visited[py][px][number][lastRoom] = 1;
                    q.push({py, {px, {lastRoom, number}}});
                }
            }
            // 오락실을 만난 경우
            else
            {
                // 이전에 방문한 오락실보다 번호가 크다면
                if (lastRoom < arr[py][px] || number == 0)
                {

                    dp[py][px][number + 1][arr[py][px]] += dp[y][x][number][lastRoom];
                    dp[py][px][number + 1][arr[py][px]] %= 1000007;
                    if (visited[py][px][number + 1][arr[py][px]] == 0)
                    {
                        visited[py][px][number + 1][arr[py][px]] = 1;
                        q.push({py, {px, {arr[py][px], number + 1}}});
                    }
                }
            }
        }
    }
}

void Solution()
{

    bfs();

    for (int p = 0; p <= C; p++)
    {
        int temp = 0;
        for (int k = 0; k <= C; k++)
        {

            temp += dp[N - 1][M - 1][p][k];
        }

        cout << temp % 1000007 << " ";
    }
}

void Input()
{
    cin >> N >> M >> C;
    int index = 1;
    for (int i = 0; i < C; i++)
    {
        int a, b;
        cin >> a >> b;
        arr[a - 1][b - 1] = index;
        index++;
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