#pragma GCC optimize("03")
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#ifndef DEBUG
#define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1)
{
    cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args)
{
    const char* comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << " : " << arg1<<" | ";
    __f(comma+1, args...);
}
#else

#define debug(...)
#endif
#define Ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define sz(a) ((int)(a).size())
#define all(n) (n).begin(),(n).end()
#define ll long long
#define pb push_back
#define EPS 1e-9
//const int mod = int(1e9 + 7);
//const int mod = int(1e6 + 3);
int dcmp(const double &a, const double &b)
{
    if (fabs(a - b) < EPS)
        return 0;
    return ((a > b) << 1) - 1;
}
const int OO = 0x3f3f3f3f;
const int N = 1e6 + 5;
const int M = 1e6 + 6;
int n, m, par[N], sz[N], comp, mxcomp;
int from[N], to[N], sorted[N];
ll cst[N];
void init()
{
    iota(par, par + n, 0);
    fill(sz, sz + n, 1);
    ::comp = n;
    mxcomp = 1;
}
int Find(int u)
{
    return u == par[u] ? u : par[u] = Find(par[u]);
}
bool join(int u, int v)
{
    u = Find(u);
    v = Find(v);
    if(u == v)
        return 0;
    if (sz[u] > sz[v])swap(u, v);
    par[u] = v;
    sz[v] += sz[u];
    --comp;
    mxcomp = max(mxcomp, sz[v]);
    return 1;
}
vector<int> bruting;
ll kruskal(bool cool = false)
{
    ll res = 0;
    //puts("LOL");
    sort(sorted, sorted + m, [](int a, int b)
    {
        return cst[a] < cst[b];
    });
    for(int k = 0; k < m; ++k)
    {
        int e = sorted[k];
        if(join(from[e], to[e]))
        {
            if(cool)
                bruting.pb(e);
            res += cst[e];
        }
    }
    return res;
}
int main()
{
    Ios;
    //freopen("in.in", "r",stdin);
    //freopen("out.out", "w",stdout);
    int t,q, ok = 0;
    for(cin >> t; t--;)
    {
        bruting.clear();
        cin >> n >> m;
        init();
        for(int i = 0; i < m; ++i)
        {
            cin >> from[i] >> to[i] >> cst[i];
            sorted[i] = i;
            --from[i], --to[i];
        }
        ll ret;
        ret = kruskal(true);
        ll res = INT_MAX;
        for(const auto &c : bruting)
        {
            int w = cst[c];
            cst[c] = INT_MAX;
            init();
            res = min(res, kruskal());
            cst[c] = w;
        }
        cout << ret << " " << res << endl;
    }
    //system("sleep 5");
    return 0;
}
