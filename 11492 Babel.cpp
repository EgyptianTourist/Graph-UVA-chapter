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
int main()
{
    Ios;
    //freopen("in.in", "r",stdin);
    //freopen("out.out", "w",stdout);
    int n;
    while(cin >> n && n)
    {
        vector<vector<pair<int, string>>> adj;
        vector<int> dist(N, OO);
        unordered_map<string, int> id;
        int _id = 2;
        string x, y, z;
        cin >> x >> y;
        id[x] = 0;
        id[y] = 1;
        adj.pb(vector<pair<int, string>>());
        adj.pb(vector<pair<int, string>>());
        for(int i = 0; i  < n; ++i)
        {
            int u, v;
            cin >> x >> y >> z;
            if(id.count(x))
                u = id[x];
            else
            {
                u = _id++, id[x] = u;
                adj.pb(vector<pair<int, string>>());
            }
            if(id.count(y))
                v = id[y];
            else
            {
                v = _id++, id[y] = v;
                adj.pb(vector<pair<int, string>>());
            }
            adj[u].pb({v, z});
            adj[v].pb({u, z});
            //debug(x, id[x], y, id[y], z);
        }
        priority_queue<pair<int, pair<int, char>>, vector<pair<int, pair<int, char>>>,
                       function<bool(pair<int, pair<int, char>>,
                                     pair<int, pair<int, char>>)>> q
                       ([](pair<int, pair<int, char>>a, pair<int, pair<int, char>>b)
        {
            return a.first > b.first;
        });
        dist[1] = 0;
        q.push({0, {1, '*'}});
        while(q.size())
        {
            int u, c;
            char ok;
            c = q.top().first;
            tie(u, ok) = q.top().second;
            q.pop();
            if(c != dist[u])continue;
            for(auto p: adj[u])
            {
                int nc, v;
                string z;
                tie(v, z) = p;
                nc = (int)sz(z);
                if(dist[u] + nc < dist[v] && ok != z[0])
                {
                    dist[v] = dist[u] + nc;
                    q.push({dist[v],{v, z[0]}});
                }
            }
        }
        //debug(dist[k]);
        if(dist[0] >= OO)
            cout << "impossivel" << endl;
        else
            cout << dist[0] << endl;
    }
    //system("sleep 5");
    return 0;
}
