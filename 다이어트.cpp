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

struct Nutrition
{
    int p;
    int f;
    int s;
    int v;
    int price;
    Nutrition(int p, int f, int s, int v, int price)
    {
        this->p = p;
        this->f = f;
        this->s = s;
        this->v = v;
        this->price = price;
    }
};

int N;
int mp, mf, ms, mv;
vector<Nutrition> vec;
vector<vector<int>> ans;
int visited[16];
int answer = INT_MAX;

void dfs(int p, int f, int s, int v, int price, vector<int> ansVector, int next)
{
    if (price > answer)
    {
        return;
    }

    if (p >= mp && f >= mf && s >= ms && v >= mv)
    {
        if (answer > price)
        {
            ans.clear();
            answer = price;
            ans.push_back(ansVector);
        }
        else if (answer == price)
        {
            ans.push_back(ansVector);
        }
    }

    for (int i = next; i < vec.size(); i++)
    {
        if (visited[i] == 0)
        {
            ansVector.push_back(i + 1);
            visited[i] = 1;
            dfs(p + vec[i].p, f + vec[i].f, s + vec[i].s, v + vec[i].v, price + vec[i].price, ansVector, i+1);
            visited[i] = 0;
            ansVector.pop_back();
        }
    }
}

void Solution()
{
    vector<int> temp;
    dfs(0, 0, 0, 0, 0, temp, 0 );
    sort(ans.begin(), ans.end());
    if (answer == INT_MAX)
    {
        cout << -1 << '\n';
        return;
    }
    else
    {
        cout << answer << '\n';
        for (int i = 0; i < ans[0].size(); i++)
        {
            cout << ans[0][i] << " ";
        }
        cout << '\n';
    }
}

void Input()
{
    cin >> N;
    cin >> mp >> mf >> ms >> mv;
    for (int i = 0; i < N; i++)
    {
        int p, f, s, v, price;
        cin >> p >> f >> s >> v >> price;
        Nutrition nutrition = Nutrition(p, f, s, v, price);
        vec.push_back(nutrition);
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