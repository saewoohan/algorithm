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
int answer = INT_MAX;
vector<vector<int>> permutations;
int visited[61][61][61];

void bfs()
{
    queue<pair<vector<int>, int>> q;
    q.push({vec, 0});

    while (!q.empty())
    {
        vector<int> SCVs = q.front().first;
        int depth = q.front().second;

        q.pop();
        if (SCVs[0] <= 0 && SCVs[1] <= 0 && SCVs[2] <= 0)
        {
            cout << depth << '\n';
            break;
        }

        for (int i = 0; i < permutations.size(); i++)
        {
            vector<int> tempScvs = SCVs;
            for (int j = 0; j < 3; j++)
            {

                if (j == 0)
                {
                    tempScvs[permutations[i][j]] -= 9;
                }
                else if (j == 1)
                {

                    tempScvs[permutations[i][j]] -= 3;
                }
                else
                {
                    tempScvs[permutations[i][j]] -= 1;
                }
            }
            for (int i = 0; i < 3; i++)
            {
                if (tempScvs[i] < 0)
                {
                    tempScvs[i] = 0;
                }
            }
            if (visited[tempScvs[0]][tempScvs[1]][tempScvs[2]] == 0)
            {
                visited[tempScvs[0]][tempScvs[1]][tempScvs[2]] = 1;
                q.push({tempScvs, depth + 1});
            }
        }
    }
}

void Solution()
{
    vector<int> tempArr;
    for (int i = 0; i < vec.size(); i++)
    {
        tempArr.push_back(i);
    }
    do
    {
        vector<int> temp;
        for (int i = 0; i < tempArr.size(); i++)
        {
            temp.push_back(tempArr[i]);
        }
        permutations.push_back(temp);
    } while (next_permutation(tempArr.begin(), tempArr.end()));
    bfs();
}

void Input()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        vec.push_back(temp);
    }
    while (vec.size() < 3)
    {
        vec.push_back(0);
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