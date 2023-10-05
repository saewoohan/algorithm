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
#define MAX_SIZE 51
using namespace std;

int N;
vector<int> vec[51];
int visited[51];
int root;
int answer;
int K;

void dfs(int start)
{
    if (start == K)
    {
        return;
    }
    bool possible = false;
    for (int i = 0; i < vec[start].size(); i++)
    {
        int next = vec[start][i];
        if (visited[next] == 0 && next != K)
        {
            possible = true;
            visited[next] = 1;
            dfs(next);
        }
    }
    if (!possible)
    {
        answer++;
    }
}

void Solution()
{
    dfs(root);
    cout << answer << '\n';
}

void Input()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        if (a != -1)
        {
            vec[a].push_back(i);
        }
        else
        {
            root = i;
        }
    }
    cin >> K;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    Solution();
}