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
vector<double> vec;


void Solution()
{
    double m = INT_MIN;
   for(int i = 0 ; i<N; i++){
    double temp = vec[i];
    m = max(m,temp);
    for(int j = i+1 ; j<N; j++){
        temp *= vec[j];
        m = max(m,temp);
    }
   }
}

void Input()
{
    cin >> N;
    for(int i = 0 ; i<N; i++){
        double d;
        cin >> d;
        vec.push_back(d);
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