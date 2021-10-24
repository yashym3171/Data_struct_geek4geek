// Given a permutation p[i] of n elements, find for each i the number of j such that j < i and p[j] > p[i].

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

void solve();

void update(ll node, ll l, ll r, ll seg[], ll num)
{
    if (l == r)
    {
        seg[node] = 1;
        return;
    }
    ll mid = (l + r) / 2;
    if (num <= mid)
    {
        update(node * 2, l, mid, seg, num);
    }
    else
    {
        update(node * 2 + 1, mid + 1, r, seg, num);
    }
    seg[node] = seg[node * 2] + seg[node * 2 + 1];
}

ll result(ll node, ll l, ll r, ll seg[], ll num)
{
    if (num == r)
    {
        return 0;
    }
    if (l == r)
    {
        return seg[node];
    }
    ll mid = (l + r) / 2, ans;
    if (num < mid)
    {
        ans = seg[node * 2 + 1];
        ans += result(node * 2, l, mid, seg, num);
    }
    else
    {
        ans = result(node * 2 + 1, mid + 1, r, seg, num);
    }
    return ans;
}

int main()
{
    FASTIO
    ll i, j, n;
    cin >> n;
    ll a[n];
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll l = 1;
    while (n > l)
    {
        l *= 2;
    }
    ll seg[l * 2] = {};
    for (i = 0; i < n; i++)
    {
        update(1, 1, n, seg, a[i]);
        cout << result(1, 1, n, seg, a[i]) << " ";
    }
    return 0;
}
