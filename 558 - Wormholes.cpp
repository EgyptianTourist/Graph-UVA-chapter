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
int from[M], to[M], cst[M], dist[M];
int n, m;
int bellman(int src)
{
    dist[src] = 0;
    int x = n;
    while(x--)
    {
        for(int e = 0; e < m; ++e)
        {
            int d = dist[from[e]] + cst[e];
            if(dist[to[e]] > d)
            {
                dist[to[e]] = d;
                if(!x)return 0;
            }
        }
    }
    return 1;
}
int main()
{
    Ios;
    //freopen("in.in", "r",stdin);
    //freopen("out.out", "w",stdout);
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        memset(dist, OO, sizeof(dist));
        for(int i = 0; i < m; ++i)
        {
            cin >> from[i] >> to[i] >> cst[i];
        }
        for(int i = 0; i < n; ++i)
        {
            from[m] = n;
            to[m] = i;
            cst[m] = 0;
            ++m;
        }
        puts(bellman(n++) ? "not possible" : "possible");
    }
    //system("sleep 5");
    return 0;
}
