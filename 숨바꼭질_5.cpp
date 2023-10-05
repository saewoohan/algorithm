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

int N, K;
int visited[1000001];
int answer = -1;

void bfs()
{
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>> q;
    q.push({0, {N, K}});
    visited[N] = 1;

    while (!q.empty())
    {
        int nextPos = q.top().second.first;
        int time = q.top().first;
        int tempK = q.top().second.second;
       

        q.pop();

        if (nextPos > 500000 || nextPos < 0)
        {
            continue;
        }
        cout << time << '\n';
        //  cout << nextPos << '\n';
        if (nextPos == tempK)
        {
            if (nextPos <= 500000)
            {

                answer = time;
            }

            break;
        }

        if (visited[nextPos + 1] == 0)
        {
            visited[nextPos + 1] = 1;
            q.push({time+1, {nextPos + 1, tempK + time + 1}});
        }
        if (visited[nextPos - 1] == 0)
        {
            visited[nextPos - 1] = 1;
            q.push({time+1, {nextPos-1 ,tempK + time + 1}});
        }
        if (visited[nextPos * 2] == 0)
        {
            visited[nextPos * 2] = 1;
            q.push({time+1, {nextPos*2, tempK + time + 1}});
        }
    }
}

void Solution()
{
    bfs();
    cout << answer << '\n';
}

void Input()
{
    cin >> N >> K;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    Solution();
}