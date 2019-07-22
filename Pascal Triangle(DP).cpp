#pragma GCC optimize("03")
/*
name:       Cursed_Angel
MSG:        Hello World I am a Cursed Angel
*/

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//-------------------------------------------------------//
#define rep(i,a,b) for (ll i = (a), _b = (b); i <= _b; i++)
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
//------------------------------------------------------------//
#define mod (int)(1e9 + 7)
#define N (int)1e5 + 5
#define M (int)2e6 + 5
#define OO 0x3f3f3f3f
//----------------------------------//
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
//---------------------------------//
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
template<class T>
T gcd(T a, T b)
{
    while(a && b)
        if(a > b)
            (a%=b);
        else(b%=a);

    return a + b;
}
template<class T>
T lcm(T a, T b)
{
    return (a * b) / gcd(a, b);
}
ll dp[1000][1000];
ll solve(ll n, ll k)
{
    if(k <= 1 && n <= 1)
        return 1;
    ll&ret = dp[n][k];
    if(~ret)return ret;
    ret = 0;
    if(n - 1 >= 0 && k - 1 >= 0)
    {
        ret += solve(n - 1, k - 1);
    }
    if(n - 1 >= 0 && n - 1 >= k)
        ret += solve(n - 1, k);
    return ret;
}
int main()
{
    Ios;
    //inn;
    //outt;
    //auto tt = clock();
    ll n, k;
    clr(dp, -1);
    //Pascal's triangle using DP
    rep(i, 0, 15)
    {
        bool first = true;
        for(ll j = i; ~j; j--)
        {
            printf("%lld ", solve(i*1LL, j));
            first = false;
        }
        puts("");
    }
    //cout << (double(clock() - tt)/CLOCKS_PER_SEC * 1.00) << endl;
    //system("sleep 50");
    return 0;
}
