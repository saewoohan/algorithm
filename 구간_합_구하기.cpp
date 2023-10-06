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

long long N, M, K;
long long arr[1000001];
vector<pair<long long, pair<long long, long long>>> change;
long long segTree[10000001];

long long init(long long node, long long st, long long end)
{
    // st   : init 함수가 관심두는 arr의 시작 인덱스
    // end  : init 함수가 관심두는 arr의 끝 인덱스
    // node : segTree의 노드
    // -> node번째 노드가 st ~ end의 합을 저장한다.
    if (st == end)
        return segTree[node] = arr[st];
    long long mid = (st + end) / 2;

    // 재귀로 반씩 나눠서 초기화
    return segTree[node] = init(node * 2, st, mid) + init(node * 2 + 1, mid + 1, end);
}

void update(long long n, long long st, long long end, long long t, long long diff)
{
    // st   : 시작 인덱스
    // end  : 끝 인덱스
    // idx  : 수정할 원소의 인덱스
    // diff  : 수정할 값

    // 범위 안에 있을 경우
    if (st <= t && t <= end)
        segTree[n] += diff;

    // 범위 밖에 있을 경우
    else
        return;
    if (st == end)
        return;
    long long mid = (st + end) / 2;
    update(n * 2, st, mid, t, diff);
    update(n * 2 + 1, mid + 1, end, t, diff);
}

long long sum(long long l, long long r, long long node, long long st, long long end)
{
    // st   : 시작 인덱스
    // end  : 끝 인덱스
    // l~r  : 구하고자 하는 구간 합의 범위
    // [l, r]이 [st, end]를 완전히 포함하는 경우
    if (l <= st && end <= r)
        return segTree[node];

    // [l, r]와 [st, end]가 겹치지 않는 경우
    if (r < st || end < l)
        return 0;

    // 나머지 경우 (일부분 겹칠때)
    long long m = (st + end) / 2;
    return sum(l, r, node * 2, st, m) + sum(l, r, node * 2 + 1, m + 1, end);
}

void Solution()
{
    init(1, 1, N);
    for (long long i = 0; i < change.size(); i++)
    {
        long long type = change[i].first;
        for(long long j = 1; j<= N; j++){
        
        }
        if (type == 1)
        {
            long long diff = change[i].second.second - sum(change[i].second.first, change[i].second.first, 1, 1, N);
            update(1, 1, N, change[i].second.first, diff);
        }
        else
        {
            cout << sum(change[i].second.first, change[i].second.second, 1, 1, N) << '\n';
        }
    }
}

void Input()
{
    cin >> N >> M >> K;
    for (long long i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }
    for (long long i = 0; i < M + K; i++)
    {
        long long a, b, c;
        cin >> a >> b >> c;
        change.push_back({a, {b, c}});
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