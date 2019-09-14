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
    int n, k;
    stringstream convertor;
    while(cin >> n >> k)
    {
        //system("sleep 1");
        vector<vector<pair<int, int>>> adj(105);
        vector<int> dist(105, OO);
        int cst_elevator[6];
        for(int i = 0; i  < n; ++i)
        {
            cin >> cst_elevator[i];
            //debug(cst_elevator[i], i);
        }
        string line;
        getline(cin, line);
        for(int i = 0; i  < n; ++i)
        {
            getline(cin, line);
            //cin.ignore();
            convertor.clear();
            convertor << line;
            vector<int> cool;
            int tmp;
            while(convertor >> tmp)
            {
                cool.pb(tmp);
            }
            //debug(cool[sz(cool) - 1], sz(cool), i);
            //cool.pop_back();
            for(int j = 0, u; j < sz(cool); ++j)
                for(int ii = j + 1, v, c; ii < sz(cool); ++ii)
                {
                    u = cool[j];
                    v = cool[ii];
                    c = (v - u) * cst_elevator[i];
                    //debug(u, v, c, i);
                    adj[u].pb({v, c});
                    adj[v].pb({u, c});
                }
                //puts("");
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        dist[0] = 0;
        q.push({0, 0});
        while(q.size())
        {
            int u, c;
            tie(c, u) = q.top();
            q.pop();
            if(c != dist[u])continue;
            for(auto p: adj[u])
            {
                int nc, v;
                tie(v, nc) = p;
                if(dist[u] + nc + 60 < dist[v])
                {
                    dist[v] = dist[u] + nc + 60;
                    q.push({dist[v], v});
                }
            }
        }
        //debug(dist[k]);
        if(dist[k] >= OO)
            cout << "IMPOSSIBLE" << endl;
        else {
            dist[k] -= (60 * (k > 0));
            cout << dist[k] << endl;
        }
    }
    //system("sleep 5");
    return 0;
}
