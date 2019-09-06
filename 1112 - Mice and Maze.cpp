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
const int OO = 0x3f3f3f3f3f;
const int N = 1e6 + 5;
const int M = 1e6 + 6;
ll n, m, e, _t;
ll dis[10005];
vector<vector<pair<ll, ll>>> adj;
int main()
{
    Ios;
    //freopen("in.in", "r",stdin);
    //freopen("out.out", "w",stdout);
    ll t, u, v;
    ll c;
    bool ok = 0;
    for(cin >> t; t--;)
    {
        cin >> n >> e >> _t >> m;
        if(ok++)cout << endl;
        memset(dis, OO, sizeof(dis));
        adj = vector<vector<pair<ll, ll>>>(n + 5);
        for(int i = 0; i < m; ++i)
            {
                cin >> u >> v >> c;
                adj[v].pb({u, c});
            }

        priority_queue<pair<ll, ll>> q;
        q.push({0LL, e});
        dis[e] = 0;
        while(q.size())
        {
            ll d;
            tie(d, u) = q.top();
            d *= -1;
            q.pop();
            if(d != dis[u])continue;
            for(auto pi: adj[u])
            {
                ll nd;
                tie(v, nd) = pi;
                nd = dis[u] + nd;
                if(ok)
                    debug(u, v, nd, d, dis[v]);
                if(nd < dis[v])
                {
                    dis[v] = nd;
                    nd *= -1LL;
                    q.push({nd, v});
                }
            }
        }
        ll ans = 0;
        for(int i = 1; i <= n; ++i)
        {
            if(dis[i] <= _t)++ans;
            debug(i, dis[i]);
        }
        cout << ans << endl;

    }
    //system("sleep 5");
    return 0;
}
