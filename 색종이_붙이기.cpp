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

int arr[10][10];
int number[5] = {5, 5, 5, 5, 5};
int answer = INT_MAX;
int total;
bool first = false;

// 5x5 확인
bool check5_5Arr(int y, int x)
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            int py = y + i;
            int px = x + j;
            if (py < 0 ||px < 0 || py >= 10 || px >= 10)
            {
                return false;
            }
            if (arr[py][px] == 0 )
            {
                return false;
            }
        }
    }
    return true;
}

// 4x4 확인
bool check4_4Arr(int y, int x)
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            int py = y + i;
            int px = x + j;
            if (py < 0 || px < 0 || py >= 10 || px >= 10)
            {
                return false;
            }
            if (arr[py][px] == 0 )
            {
                return false;
            }
        }
    }

    return true;
}

// 3x3 확인
bool check3_3Arr(int y, int x)
{

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int py = y + i;
            int px = x + j;
            if (py < 0 || px < 0 ||py >= 10 || px >= 10)
            {
                return false;
            }
            if (arr[py][px] == 0)
            {
                return false;
            }
        }
    }

    return true;
}

// 2x2 확인
bool check2_2Arr(int y, int x)
{

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            int py = y + i;
            int px = x + j;
            if (py < 0 || px < 0 || py >= 10 || px >= 10)
            {
                return false;
            }
            if (arr[py][px] == 0)
            {
                return false;
            }
        }
    }
    return true;
}

// 1x1 확인
bool checkArr(int y, int x)
{
    int py = y;
    int px = x;
    if (py < 0 || px < 0 || py >= 10 || px >= 10)
    {
        return false;
    }
    return true;
}

void dfs(int y, int x, int sum, int depth)
{
     while (arr[y][x] == 0)
	{
		x++;
		if (x >= 10)
		{
			y++;
			if (y >= 10)
			{
				answer = min(answer, sum);
				return;
			}
		    x = 0;
		}
	}
    cout << y << " " << x << '\n';
    if (sum >= answer)
    {
        return;
    }

   
        bool possible = false;

        // 5x5 가능
        if (check5_5Arr(y, x) && number[4] > 0)
        {
            possible = true;
            number[4]--;
            for (int k = 0; k < 5; k++)
            {
                for (int p = 0; p < 5; p++)
                {
                    arr[y + k][x + p] = 0;
                }
            }
            dfs(y, x, sum + 1, depth + 25);
            for (int k = 0; k < 5; k++)
            {
                for (int p = 0; p < 5; p++)
                {
                    arr[y + k][x + p] = 1;
                }
            }
            number[4]++;
        }

        // 4x4 가능
        if (check4_4Arr(y, x) && number[3] > 0)
        {
            possible = true;
            number[3]--;
            for (int k = 0; k < 4; k++)
            {
                for (int p = 0; p < 4; p++)
                {
                    arr[y + k][x + p] = 0;
                }
            }
            dfs(y, x, sum + 1, depth + 16);
            for (int k = 0; k < 4; k++)
            {
                for (int p = 0; p < 4; p++)
                {
                    arr[y + k][x + p] = 1;
                }
            }
            number[3]++;
        }

        // 3x3 가능
        if (check3_3Arr(y, x) && number[2] > 0)
        {
            possible = true;
            number[2]--;
            for (int k = 0; k < 3; k++)
            {
                for (int p = 0; p < 3; p++)
                {
                    arr[y + k][x + p] = 0;
                }
            }
            dfs(y, x, sum + 1, depth + 9);
            for (int k = 0; k < 3; k++)
            {
                for (int p = 0; p < 3; p++)
                {
                    arr[y + k][x + p] = 1;
                }
            }
            number[2]++;
        }

        // 2x2 가능
        if (check2_2Arr(y, x) && number[1] > 0)
        {
            possible = true;
            number[1]--;
            for (int k = 0; k < 2; k++)
            {
                for (int p = 0; p < 2; p++)
                {
                    arr[y + k][x + p] = 0;
                }
            }
            dfs(y, x, sum + 1, depth + 4);
            for (int k = 0; k < 2; k++)
            {
                for (int p = 0; p < 2; p++)
                {
                    arr[y + k][x + p] = 1;
                }
            }
            number[1]++;
        }

        // 1x1 가능
        if (checkArr(y, x) && number[0] > 0)
        {
            possible = true;
            number[0]--;
            arr[y][x] = 0;
            dfs(y, x, sum + 1, depth + 1);
            arr[y][x] = 1;
            number[0]++;
        }

    
}

void Solution()
{

    dfs(0, 0, 0, 0);
    if (answer == INT_MAX)
    {
        cout << -1 << '\n';
        return;
    }
    cout << answer << '\n';
}

void Input()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 1)
            {
                total++;
            }
        }
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