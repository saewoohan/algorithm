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

struct RoomInfo
{
    long long t;
    long long a;
    long long h;
    RoomInfo(long long t, long long a, long long h)
    {
        this->h = h;
        this->t = t;
        this->a = a;
    }
};

long long N, H;
vector<RoomInfo> roomsInfo;
long long answer = LLONG_MAX - 1;

void Solution()
{
    long long l = 1;
    long long r = LLONG_MAX - 1;
    long long maxHP;

    while (l <= r)
    {
        bool possible = true;
        maxHP = (l + r) / 2;
        long long curHP = maxHP;
        long long curH = H;
        // cout << curHP << '\n';

        for (int i = 0; i < roomsInfo.size(); i++)
        {

            long long type = roomsInfo[i].t;
            if (type == 1)
            {
                long long a = roomsInfo[i].a;
                long long h = roomsInfo[i].h;
                long long temp = h / curH;
                long long remain = h % curH;
                if (remain != 0)
                {
                    temp++;
                }

                long long temp2 = curHP / a;
                remain = curHP % a;
                if (remain != 0)
                {
                    temp2++;
                }
                if (temp > temp2)
                {
                    possible = false;
                    break;
                }
                else
                {
                    curHP -= (temp - 1) * a;
                }
            }
            else
            {
                long long a = roomsInfo[i].a;
                long long h = roomsInfo[i].h;

                curH += a;
                curHP += h;
                if (curHP > maxHP)
                {
                    curHP = maxHP;
                }
            }
        }

        if (!possible)
        {
            l = maxHP + 1;
        }
        else
        {
            answer = min(maxHP, answer);
            r = maxHP - 1;
        }
    }

    cout << answer;
}

void Input()
{
    cin >> N >> H;
    for (int i = 0; i < N; i++)
    {
        long long t, a, h;
        cin >> t >> a >> h;
        RoomInfo roomInfo = RoomInfo(t, a, h);
        roomsInfo.push_back(roomInfo);
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