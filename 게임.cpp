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

int N, M;
string s;
int arr[51][51];

void Solution()
{
}

void Input()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> s;
        for (int j = 0; j < s.length(); j++)
        {
            arr[i][j] = s[j] - 48;
        }
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