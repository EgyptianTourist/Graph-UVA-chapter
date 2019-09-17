//#pragma GCC optimize("03")
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
const int mod = int(1e9 + 7);
//const int mod = int(1e6 + 3);
int dcmp(const double &a, const double &b)
{
    if (fabs(a - b) < EPS)
        return 0;
    return ((a > b) << 1) - 1;
}
int OO = 0x3f3f3f3f;
const int N = 1e6 + 5;
const int M = 1e6 + 6;
int n, m;
int cst[N], dist[N];
int vis[N], vid;
vector<vector<int>> adj;
bool dfs(int u, int v)
{
    bool ret = 0;
    if(u == v)
        return 1;
    vis[u] = vid;
    for(auto ch: adj[u])
    {
        if(ch == v)return true;
        if(vis[ch] != vid)
        {
            ret |= dfs(ch, v);
        }
    }
    return ret;
}
int bellman(int src)
{
    dist[src] = 100;
    int x = n - 2;
    while(x--)
    {
        for(int u = 1; u < n; ++u)
        {
            for(auto v : adj[u])
            {
                int d = cst[u] + dist[u];
                if(d > dist[v] && d > 0)
                    dist[v] = d;
            }
        }
    }
    if(dist[n - 1] > 0)return 1;
    for(int u = 1; u < n; ++u)
    {
        for(auto v : adj[u])
        {
            int d = cst[u] + dist[u];
            if(d > dist[v] && d > 0)
                {
                    ++vid;
                    if(dfs(u, n - 1))
                    return 1;
                }
        }
    }
    return 0;
}
int main()
{
    Ios;
    //freopen("in.in", "r",stdin);
    //freopen("out.out", "w",stdout);
    int t;
    while(cin >> n && n > 0)
    {
        adj = vector<vector<int>>(n + 5);
        ++n;
        memset(dist, -OO, sizeof(dist));
        //debug(dist[1]);
        for(int u = 1; u < n; ++u)
        {
            int energy, e;
            cin >> energy >> e;
            cst[u] = energy;
            for(int i = 0; i < e; ++i)
            {
                int v;
                cin >> v;
                adj[u].pb(v);
            }
        }
        puts(bellman(1) ? "winnable" : "hopeless");
    }
    //system("sleep 5");
    return 0;
}
