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
#define iter(x) for(int i = 0; i < (int)x; ++i)
int OO = 0x3f3f3f3f;
const int N = 1e6 + 5;
const int M = 1e6 + 6;
int n, m, s, d, t, p;
int dist[N], rdist[N];
vector<vector<pair<int, int>>> adj, radj;
void dijkstra(const vector<vector<pair<int, int>>>& g, int dis[N],const int& src)
{
    dis[src] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({0, src});
    while(pq.size())
    {
        int len, u;
        tie(len, u) = pq.top();
        len *= -1;
        pq.pop();
        if(dis[u] != len)continue;
        for(auto ch: g[u])
        {
            int c, v;
            tie(v, c) = ch;
            if(dis[v] > dis[u] + c)
            {
                dis[v] = dis[u] + c;
                pq.push({-dis[v], v});
            }
        }
    }
    //return dis[stop];
}
int main()
{
    Ios;
    //freopen("in.in", "r",stdin);
    //freopen("out.out", "w",stdout);
    cin >> t;
    while(t--)
    {
        cin >> n >> m >> s >> d >> p;
        memset(dist, OO, sizeof(dist));
        memset(rdist, OO, sizeof(rdist));
        adj = vector<vector<pair<int, int>>>(n + 5);
        radj = vector<vector<pair<int, int>>>(n + 5);
        iter(m)
        {
            int u, v, c;
            cin >> u >> v >> c;
            adj[u].pb({v, c});
            radj[v].pb({u, c});
        }
        dijkstra(adj, dist, s);
        dijkstra(radj, rdist, d);
        int cst = dist[d];
        if(cst > p)
            cout << "-1";
        else
        {
            int mx = 0;
            for(int i = 1; i <= n; ++i)
            {
                for(auto v: adj[i])
                {
                    if(dist[i] + v.second + rdist[v.first] <= p)
                    {
                        mx = max(mx, v.second);
                    }
                }
            }
            cout << mx;
        }
        cout << endl;

    }
    //cout << (n * )
    //system("sleep 5");
    return 0;
}
