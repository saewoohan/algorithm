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

struct Rotate
{
    pair<int, int> topLeft;
    pair<int, int> bottomRight;
};

int N, M, K;
int arr[51][51];
vector<Rotate> vec;
int sum = 0;
int visited[10001];

void dfs(int depth, int index, int temp[51][51])
{

    for (int i = index; i < vec.size(); i++)
    {
        if (visited[i] == 0)
        {
            visited[i] = 1;
            if (depth == vec.size())
            {
                return;
            }
            int temp[51][51];
            for (int i = 0; i < 51; i++)
            {
                for (int j = 0; j < 51; j++)
                {
                    temp[i][j] = arr[i][j];
                }
            }
            
            dfs(depth + 1, index + 1, temp);
            visited[i] = 0;
        }
    }
}


void solution()
{
    dfs(0, 0);
}

void input()
{
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < K; i++)
    {
        int r, c, s;
        cin >> r >> c >> s;
        Rotate rotate = Rotate();
        rotate.topLeft = {r - s, c - s};
        rotate.bottomRight = {r + s, c + s};
        vec.push_back(rotate);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    solution();
}