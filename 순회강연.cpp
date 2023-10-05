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

priority_queue<int, vector<int>, greater<int>> pq;
vector<pair<int,int>> vec;
int n;

void Solution()
{
    sort(vec.begin(),vec.end());
    int sum = 0;
    for(int i  =0  ; i<vec.size(); i++){
       pq.push(vec[i].second);
       sum += vec[i].second;
       if(vec[i].first < pq.size()){
        int top = pq.top();
        sum -= top;
        pq.pop();
       }
    }
    cout << sum << '\n';
    
}

void Input()
{
   cin >> n;
   for(int i = 0 ; i<n; i++){
    int p,d;
    cin >>p>> d;
    vec.push_back({d,p});
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