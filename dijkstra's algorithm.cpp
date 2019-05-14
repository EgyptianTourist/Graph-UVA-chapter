/*
name:       Egyptian Tourist
PlatForm:   CodeForces/SPOJ...etc
LANG:       C++
DIV:        Training
TIME:       *
RATE:       *
*/

/*
Time Consumed:*
Problem Topics: *
*/

#include <bits/stdc++.h>
#include <iostream>

using namespace std;
//----------------------------------//

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

//-------------------------------------------------------//
#define rep(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define repr(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define lp(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define lpr(i,n) for (int i = (n) - 1; ~i; i--)
#define foreach(it, ar) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )
//-------------------------------------------------------------------------------------//

#define clr(ar, val) memset(ar, val, sizeof(ar))
//----------------------------------------------//

#define inn freopen("in.in","r",stdin)
#define outt freopen("out.out","w",stdout)
#define PI 3.1415926535897932385
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back
#define pob pop_back
#define bit(n) (1<<(n))
#define Last(i) ( (i) & (-i) )
#define all(v) ((v).begin()), ((v).end())
#define sq(x) ((x) * (x))
#define INF INT_MAX
#define Ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

//-------------------------------------------------------------//
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
#define _ist_ cout << "\nSTART OF INPUT DISPLAYING CHECK\n";
#define _iend_ cout << "\nEND OF INPUT DISPLAYING CHECK\n";
//------------------------------------------------------------//
#define mod (int)(1e9 + 7)
template<class T, class T2>
T _f_pow(T a, T2 b)
{
    T res = 1LL;
    //a%=mod;
    while (b > 0)
    {
        if (b & 1)
            res = (res*a);//res = (res * a)%mod;
        a = (a * a);
        //a%=mod;
        b >>= 1;
    }
    return (res);
}
#define N (int)1e3 + 5

int lcm(int a, int b)
{
    return (a * b)/__gcd(a, b);
}
vector<pair<int, int>> adj[N];
int vis[N];
int dis[N];
int n, m;
void sssp(int s)
{
    multiset<pair<int, int>> mn;
    fill(dis, dis + n + 1, INF);
    dis[s] = 0;
    mn.insert({0, s});
    while(mn.size())
    {
        pair<int, int> src = (*mn.begin());
        mn.erase(mn.begin());
        int v = src.second;
        if(vis[v])
            continue;
        vis[v] = true;
        for(auto ch: adj[v])
        {
            int to = ch.first;
            int len = ch.second;
            if(dis[to] > dis[v] + len)
            {
                dis[to] = dis[v] + len;
                mn.insert({dis[to], to});
            }
        }
    }
}
int main()
{
    Ios;
    //inn;outt;
    //auto tt = clock();
    cin >> n >> m;
    rep(i, 1, m)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
       // adj[v].push_back({u, w});
    }
    sssp(1);
    rep(i, 1, n)
    {
        cout << (vis[i] ? dis[i] : -1) << endl;
    }
    //system("sleep 50");
    //cout << (double(clock() - tt)/CLOCKS_PER_SEC * 1.00) << endl;
    return 0;
}
