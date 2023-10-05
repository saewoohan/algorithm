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

int N, M, K;
vector<int> vec;
vector<pair<int, pair<int, int>>> change;

void Solution()
{
    for(int i = 0 ; i<change.size(); i++){
        int type = change[i].first;
        if(type == 1){

        }
        else{
            
        }
    }
}

void Input()
{
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        vec.push_back(temp);
    }
    for (int i = 0; i < M + K; i++)
    {
        int a, b, c;
        change.push_back({a, {b, c}});
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