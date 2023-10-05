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
vector<long long> vec;
vector<long long> lis;
vector<long long> indexs;
int idx;

void Solution()
{
    //LIS (이분 탐색을 사용한 LIS는 길이만 구할 수 있음)
    lis.push_back(vec[0]);
    indexs.push_back(1);
    for (int i = 1; i < N; i++)
    {
        if (lis.back() < vec[i])
        {
            lis.push_back(vec[i]);
            indexs.push_back(lis.size());
        }

        else
        {
            int index = lower_bound(lis.begin(), lis.end(), vec[i]) - lis.begin();
            lis[index] = vec[i];
            indexs.push_back(index+1);
        }
      
    }
    int maxLength = lis.size();
    //실제 LIS구하기
    vector<long long> answer;
    for (int i = N; i >= 0; i--)
    {
        if (answer.size() == lis.size())
        {
            break;
        }
        if (indexs[i] == maxLength)
        {
            answer.push_back(vec[i]);
            maxLength--;
        }
    }
    reverse(answer.begin(), answer.end());
    cout << answer.size() << '\n';
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << " ";
    }
}

void Input()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        vec.push_back(a);
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