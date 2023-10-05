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
int N, M;
unordered_set<int> notebook_1;
vector<int> notebook_2;

void Solution()
{
    for(int i = 0 ; i<M; i++){
        auto item = notebook_1.find(notebook_2[i]);
        if(item != notebook_1.end()){
            cout << 1 << '\n';
        }
        else{
            cout << 0 << '\n';
        }
    }
}

void Input()
{
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        notebook_1.clear();
        notebook_2.clear();
        cin >> N;
        for (int j = 0; j < N; j++)
        {
            int a;
            cin >> a;
            notebook_1.insert(a);
        }
        cin >> M;
        for (int j = 0; j < M; j++)
        {
            int a;
            cin >> a;
            notebook_2.push_back(a);
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