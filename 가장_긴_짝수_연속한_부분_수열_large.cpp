#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<deque>
#include<string>
#include<climits>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdio> 

using namespace std;

int n;
double m;

// 4781

int main() {
  while(1) {
    // 비교하기 편하게 int로 다 변환
    int dp[10005];
    vector<pair<int,int>> vec;

    memset(dp, 0, sizeof(dp));

    scanf("%d %lf", &n, &m);
    int money = (double)m * (double)100;

    if(n == 0 && money == 0) return 0;

    for(int i = 0; i < n; i++){
      int c; 
      double p; 
      scanf("%d %lf", &c, &p);

      int price = (double)p * (double)100;

      vec.push_back({price, c});
    }

    sort(vec.begin(), vec.end());  

    for(int i = 1; i <= money; i++) {
      for(int j = 0; j < n; j++) {
        if(i < vec[j].first) break;
        dp[i] = max(dp[i], dp[i - vec[j].first] + vec[j].second);
      }
    }

    printf("%d\n", dp[money]);
  }
}

/*
  
*/