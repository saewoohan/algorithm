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

struct Lecture
{
    int index;
    int startTime;
    int endTime;
    Lecture(int index, int startTime, int endTime)
    {
        this->index = index;
        this->startTime = startTime;
        this->endTime = endTime;
    }
};

int N;
vector<Lecture> vec;

bool compare(Lecture a, Lecture b)
{
    if (a.startTime == b.startTime)
    {
        return a.endTime > b.endTime;
    }
    return a.startTime < b.startTime;
}

void Solution()
{
    sort(vec.begin(), vec.end(), compare);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int answer = 1;
    pq.push({vec[0].endTime, vec[0].startTime});
    for (int i = 1; i < N; i++)
    {

        int nextTime = vec[i].startTime;
        int nowTime = pq.top().first;
        // cout << nowTime << " " << nextTime << " " << answer <<'\n';
        if (pq.size() == 0)
        {
            pq.push({vec[i].endTime, nextTime});
        }
        else
        {
            if (nextTime < nowTime)
            {
                answer++;
                pq.push({vec[i].endTime, nextTime});
            }
            else
            {

                pq.pop();

                pq.push({vec[i].endTime, nextTime});
            }
        }
    }
    cout << answer << '\n';
}

void Input()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        Lecture lecture = Lecture(a, b, c);

        vec.push_back(lecture);
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