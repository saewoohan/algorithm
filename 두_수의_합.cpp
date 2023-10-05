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

int n,x;
vector<int> vec;

void solution()
{
    sort(vec.begin(), vec.end());

    int start = 0;
    int end = vec.size()-1;
    int answer = 0;

    while(start < end){
        if(vec[start] + vec[end] > x){
            end--;
        }
        else if(vec[start] + vec[end] < x){
            start++;
        }
        else{
            answer++;
            start++;
        }
    }
    cout << answer << '\n';
  
}

void input()
{
   cin >> n;
   for(int i = 0 ; i<n; i++){
        int a;
        cin >> a;
        vec.push_back(a);
   }
   cin >> x;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    solution();
}