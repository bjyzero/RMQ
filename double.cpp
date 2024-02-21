#include <bits/stdc++.h>
using namespace std;

// RQM  时间复杂度 O(log n)
// 用倍增来求 多次区间最小值查询 问题
// 询问 q 次，左边界 l，有边界 r
#define maxn 110000
#define ll long long

int n, a[maxn], f[maxn][40]; // f 数组的第二维度的值 x 要确保 2^x大于等于maxn

int query(int l, int r)
{
    int k = (int)(log((r - l + 1) * 1.0) / log(2.0));
    return min(f[l][k], f[r - (1 << k) + 1][k]);
}

int main(void)
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        f[i][0] = a[i]; // 预处理
    }

    // 预处理 -> 只需要推 log(2n) 次
    // 如果不清楚 C++ 中log 是以 2 还是 10 为底可以 -> log(n * 1.0) / log(2.0)
    for (int j = 1; j <= (int)(log(n * 1.0) / log(2.0)); ++j)
    {
        // 此时枚举的 i 是左边界，j 又确定，那么右边界也可以确定，而右边界一定要小于等于 n
        for (int i = 1; i + (1 << j) - 1 <= n; ++i)
        {
            f[i][j] = min(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
        }
    }

    // 预处理完就可以回答多次询问
    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << query(l, r) << '\n';
    }
    return 0;
}