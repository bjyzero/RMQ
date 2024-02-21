#include <bits/stdc++.h>
using namespace std;

// RQM  ʱ�临�Ӷ� O(log n)
// �ñ������� ���������Сֵ��ѯ ����
// ѯ�� q �Σ���߽� l���б߽� r
#define maxn 110000
#define ll long long

int n, a[maxn], f[maxn][40]; // f ����ĵڶ�ά�ȵ�ֵ x Ҫȷ�� 2^x���ڵ���maxn

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
        f[i][0] = a[i]; // Ԥ����
    }

    // Ԥ���� -> ֻ��Ҫ�� log(2n) ��
    // �������� C++ ��log ���� 2 ���� 10 Ϊ�׿��� -> log(n * 1.0) / log(2.0)
    for (int j = 1; j <= (int)(log(n * 1.0) / log(2.0)); ++j)
    {
        // ��ʱö�ٵ� i ����߽磬j ��ȷ������ô�ұ߽�Ҳ����ȷ�������ұ߽�һ��ҪС�ڵ��� n
        for (int i = 1; i + (1 << j) - 1 <= n; ++i)
        {
            f[i][j] = min(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
        }
    }

    // Ԥ������Ϳ��Իش���ѯ��
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