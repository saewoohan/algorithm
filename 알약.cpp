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

void Solution()
{
   int dp[61][31][31];
   dp[1][n][0] = 1;
   dp[1][n-1][1] = 1;
   for(int i = 2; i<=2*n; i++){
        dp[i][n-(i-3)][0] = dp[i-1]
   }
}

void Input()
{
   
   while(1){
        cin >> n;
        if(n == 0){
            break;
        }
        Solution();
   }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    
}