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

int N, M, H;
vector<pair<int, int>> vec;
int visited[11][31];
int arr[11][11][31];
int answer = INT_MAX;
bool possible = true;

bool ladderMove()
{
    for (int i = 1; i < N; i++)
    {
        int start = i;

        for (int j = 1; j <= H; j++)
        {
       
            if (arr[start][start-1][j] == 1)
            {
                start = start - 1;
            }
            else if (arr[start][start + 1][j] == 1)
            {
                start = start + 1;
            }
        }

        if (i != start)
        {
            return false;
        }
    }
    return true;
}

void dfs(int depth, int r, int c)
{
    if (ladderMove())
    {
        answer = min(answer, depth);
        return;
    }

    if (depth == 3)
    {
        return;
    }

    for (int i = r; i < N; i++)
    {
        for (int j = 1; j <= H; j++)
        {
            if (visited[i][j] == 0 && visited[i - 1][j] == 0 && visited[i + 1][j] == 0)
            {
                visited[i][j] = 1;
                arr[i][i + 1][j] = 1;
                arr[i + 1][i][j] = 1;
                dfs(depth + 1, i, j+1);
                arr[i + 1][i][j] = 0;
                arr[i][i + 1][j] = 0;
                visited[i][j] = 0;
            }
        }
    }
}

void Solution()
{
    dfs(0, 1, 1);
    if (answer == INT_MAX)
    {
        cout << -1 << '\n';
        return;
    }
    cout << answer << '\n';
}

void Input()
{
    cin >> N >> M >> H;
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        arr[b][b + 1][a] = 1;
        arr[b + 1][b][a] = 1;
        visited[b][a] = 1;
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