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

int x;
int n, m;
vector<int> vec1;
vector<int> vec2;

unordered_map<int, int> m_a;
unordered_map<int, int> m_b;
int answer = 0;

void Solution()
{

    for (int i = 0; i < vec1.size(); i++)
    {
        int psum = 0;
        int index = i;
        for (int j = 0; j < n - 1; j++)
        {
            if (j + i >= n)
            {
                psum += vec1[j + i - n];
            }
            else
            {
                psum += vec1[j + i];
            }

            m_a[psum]++;
        }
    }
    int psum = 0;
    for (int i = 0; i < vec1.size(); i++)
    {
        psum += vec1[i];
    }
    m_a[psum]++;
    m_a[0]++;

    for (int i = 0; i < vec2.size(); i++)
    {
        int psum = 0;
        int index = i;
        for (int j = 0; j < m - 1; j++)
        {
            if (j + i >= m)
            {
                psum += vec2[j + i - m];
            }
            else
            {
                psum += vec2[j + i];
            }

            m_b[psum]++;
        }
    }
    psum = 0;
    for (int i = 0; i < vec2.size(); i++)
    {
        psum += vec2[i];
    }
    m_b[psum]++;
    m_b[0]++;

    for (auto iter = m_a.begin(); iter != m_a.end(); iter++)
    {
        int temp = x - iter->first;
        auto item = m_b.find(temp);
        if (item != m_b.end())
        {

            answer += (item->second * iter->second);
        }
    }

    cout << answer << '\n';
}

void Input()
{
    cin >> x;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        vec1.push_back(a);
    }
    for (int i = 0; i < m; i++)
    {
        int a;
        cin >> a;
        vec2.push_back(a);
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