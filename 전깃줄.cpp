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
vector<pair<int,int>> vec;
vector<int> lis(1001, INT_MAX);

bool compair(pair<int, int> a, pair<int, int> b)
{
    if (a.first == b.first)
    {
        return a.second > b.second;
    }
    return a.first < b.first;
}

void Solution()
{
    sort(vec.begin(),vec.end(),compair);

    int j = 0;
	lis[0] = vec[0].second;
   
	for(int i = 1 ; i<N; i++){
        int index = upper_bound(lis.begin(),lis.end(),vec[i].second) - lis.begin();
       
        if(lis[index-1] > vec[i].second){
            lis[index-1] = vec[i].second;
        }else{
            lis[index] = vec[i].second;
        }
     
    }

    int maxLength = 0;
    for(int i=  0 ; i<N; i++){
        if(lis[i] == INT_MAX){
            break;
        }
        else{
            maxLength++;
        }
    }
    cout << N-maxLength << '\n';
}

void Input()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int a,b;
        cin>> a >> b;
        vec.push_back({a,b});
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