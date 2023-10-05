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

int T;
int A, B;
vector<int> vecA;
vector<int> vecB;

void Solution()
{
    int answer = 0;
    sort(vecA.begin(),vecA.end());
    for(int i = 0 ;i<vecB.size(); i++){
       int temp = upper_bound(vecA.begin(),vecA.end(),vecB[i]) - vecA.begin();
       

       answer +=  vecA.size() - temp;

    }
    cout << answer << '\n';

}

void Input()
{
    cin >> T;
    for (int k = 0; k < T; k++)
    {
        cin >> A >> B;
        vecA.clear();
        vecB.clear();
        for (int i = 0; i < A; i++)
        {
            int temp;
            cin >> temp;
            vecA.push_back(temp);
        }
        for (int i = 0; i < B; i++)
        {
            int temp;
            cin >> temp;
            vecB.push_back(temp);
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