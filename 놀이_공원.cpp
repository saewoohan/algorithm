#include <iostream>
#include <vector>
#include <algorithm> // for __gcd()
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
#include <numeric> //최대 공약수, 최소 공배수 용임
using namespace std; 

long long N , M;
vector<int> vec;

void Solution()
{
    if(N <= M){
        cout << N << '\n';
        return;
    }
    long long l = 0;
    long long r = (long long)2000000000*30;
    long long mid;
    long long sum;
    long long result;
    while(l <= r){
        sum = M;
        long long mid = (l+r)/2;
        for(int i = 0; i<M; i++){
            sum += (mid/vec[i]);
        }
        if(sum < N) l = mid + 1;
        else if(sum > N){
            result = mid;
            r = mid - 1;
        }
        else{
            result = mid;
            r = mid - 1;
        }
    }

    long long person = M;
    for(int i = 0; i<M; i++){
        person += (result-1) / vec[i];
    }
    
    for(int i = 0 ; i< M; i++){
        if(result % vec[i] == 0 ) 
            person ++;
        if(person == N){
            cout << i+1 << '\n';
            break;
        }

    }

    
}

void Input()
{
   cin >> N >> M;
   for(int i = 0 ; i<M; i++){
        int temp;
        cin >> temp;
        vec.push_back(temp);
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