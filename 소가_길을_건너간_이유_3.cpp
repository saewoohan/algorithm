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

int n;
vector<pair<int,int>> vec;

void solution()
{
    sort(vec.begin(),vec.end());
    int nowTime = vec[0].first + vec[0].second;
    for(int i = 1 ; i<vec.size();i++){
        if(vec[i].first <= nowTime){
            nowTime += vec[i].second;
        } else{
            nowTime = vec[i].first;
            nowTime += vec[i].second;
        }
    }
    cout << nowTime;
}

void input()
{
    cin >> n;
    for(int i=  0 ; i<n; i++){
        int a, b;
        cin >> a >> b;
        vec.push_back({a,b});
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