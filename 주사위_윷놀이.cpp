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
vector<int> vec;
vector<int> visited(11);
vector<int> arr[4];
int answer = INT_MIN;

void dfs(vector<pair<int, int>> pieces, int depth, int sum)
{
    answer = max(answer, sum);
    if (depth == vec.size())
    {

        return;
    }

    for (int i = 0; i < 4; i++)
    {
        vector<pair<int, int>> temp = pieces;

        // 이미 도착한 경우

        if (temp[i].second == 5)
        {
            continue;
        }

        // 주사위 굴리기
        temp[i].first += vec[depth];

        int partSum = 0;
        bool possible = false;

        if (temp[i].first >= arr[temp[i].second].size() - 1)
        {
            temp[i].first = arr[temp[i].second].size() - 1;
            temp[i].second = 5;
        }
        else
        {
            partSum = arr[temp[i].second][temp[i].first];
        }

        // 이동 마치는 칸에 다른 말이 있는 경우

        for (int j = 0; j < 4; j++)
        {
            // 도착에 있다면 괜찮아요!
            if (i == j || temp[j].second == 5 || temp[i].second == 5)
            {
                continue;
            }
            if (arr[temp[i].second][temp[i].first] == arr[temp[j].second][temp[j].first] && arr[temp[j].second][temp[j].first] != 0)
            {
                possible = true;
                // index도 같고, route도 같음
                if (temp[i].second == temp[j].second && temp[i].first == temp[j].first)
                {
                    possible = true;
                }
                if (temp[i].second == 1 && temp[j].second != 1)
                {
                    if (arr[temp[i].second][temp[i].first] == 16)
                    {
                        possible = false;
                    }
                }
                if (temp[j].second == 1 && temp[i].second != 1)
                {
                    if (arr[temp[j].second][temp[j].first] == 16)
                    {
                        possible = false;
                    }
                }
                if (temp[i].second == 2 && temp[j].second != 2)
                {
                    if (arr[temp[i].second][temp[i].first] == 22 || arr[temp[i].second][temp[i].first] == 24)
                    {
                        possible = false;
                    }
                }
                if (temp[j].second == 2 && temp[i].second != 2)
                {
                    if (arr[temp[i].second][temp[i].first] == 22 || arr[temp[i].second][temp[i].first] == 24)
                    {
                        possible = false;
                    }
                }

                if (arr[temp[j].second][temp[j].first] == 28 || arr[temp[j].second][temp[j].first] == 26)
                {
                    if (arr[temp[j].second][temp[j].first - 1] == 27 && arr[temp[i].second][temp[i].first - 1] != 27)
                    {
                        possible = false;
                    }
                    if (arr[temp[i].second][temp[i].first - 1] == 27 && arr[temp[j].second][temp[j].first - 1] != 27)
                    {
                        possible = false;
                    }
                    if (arr[temp[j].second][temp[j].first - 1] == 30 && arr[temp[i].second][temp[i].first - 1] != 30)
                    {
                        possible = false;
                    }
                    if (arr[temp[i].second][temp[i].first - 1] == 27 && arr[temp[j].second][temp[j].first - 1] != 30)
                    {
                        possible = false;
                    }
                }

                if (arr[temp[j].second][temp[j].first] == 30)
                {

                    if (arr[temp[j].second][temp[j].first - 1] == 25 && arr[temp[i].second][temp[i].first - 1] != 25)
                    {
                        possible = false;
                    }
                    if (arr[temp[i].second][temp[i].first - 1] == 25 && arr[temp[j].second][temp[j].first - 1] != 25)
                    {
                        possible = false;
                    }
                }
            }
        }

        // route 변경

        if (temp[i].first == 5 && temp[i].second == 0)
        {
            temp[i].second = 1;
        }
        else if (temp[i].first == 10 && temp[i].second == 0)
        {
            temp[i].second = 2;
        }
        else if (temp[i].first == 15 && temp[i].second == 0)
        {
            temp[i].second = 3;
        }

        if (!possible)
        {
            dfs(temp, depth + 1, sum + partSum);
        }
    }
}

void makeMap()
{
    for (int i = 0; i < 4; i++)
    {
        arr[i].push_back(0);
    }
    for (int i = 1; i <= 20; i++)
    {
        if (i <= 5)
        {
            arr[1].push_back(i * 2);
        }
        if (i <= 10)
        {
            arr[2].push_back(i * 2);
        }
        if (i <= 15)
        {
            arr[3].push_back(i * 2);
        }
        arr[0].push_back(i * 2);
    }
    for (int i = 1; i <= 3; i++)
    {
        arr[1].push_back(10 + i * 3);
    }
    for (int i = 1; i <= 2; i++)
    {
        arr[2].push_back(20 + i * 2);
    }
    for (int i = 1; i <= 3; i++)
    {
        arr[3].push_back(29 - i);
    }
    for (int i = 0; i < 4; i++)
    {
        arr[1].push_back(25 + i * 5);
        arr[2].push_back(25 + i * 5);
        arr[3].push_back(25 + i * 5);
    }
    for (int i = 0; i < 4; i++)
    {
        arr[i].push_back(0);
    }
}

void Solution()
{

    makeMap();

    vector<pair<int, int>> pieces(4, {0, 0});

    dfs(pieces, 0, 0);
    cout << answer << '\n';
}

void Input()
{

    for (int i = 0; i < 10; i++)
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