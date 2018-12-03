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
#define rep(i,a,b) for (int i = (a), _b = (b); i < _b; i++)
#define repr(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define lp(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define lpr(i,n) for (int i = (n) - 1; ~i; i--)
#define foreach(it, ar) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )
//-------------------------------------------------------------------------------------//

#define clr(ar, val) memset(ar, val, sizeof(ar))
//----------------------------------------------//

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
#define inn freopen("in.in","r",stdin)
#define outt freopen("out.out","w",stdout)

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

#define N (int)1e5 + 5
template<class T>
T _f_pow(T a, T b)
{
    T res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
//vector<vi> adj;
unordered_map<char, ii> dir;
char cmd[105], d;
bool vis[505][505];
int r, c, x, y;
bool flag = 0;
void dfs(char cm)
{
    if(cm=='R')
    {
        if(d=='E')
            d = 'S';
        else if(d=='S')
            d = 'W';
        else if(d == 'W')
            d = 'N';
        else if(d=='N')
            d = 'E';
    }
    else if(cm=='L')
    {
        if(d=='E')
            d = 'N';
        else if(d=='S')
            d = 'E';
        else if(d == 'W')
            d = 'S';
        else if(d=='N')
            d = 'W';
    }

    else if(cm=='F')
    {
        //debug(x, y, vis[x][y],d, flag,cm);
        if(d == 'N')
        {
            if(y==r)
            {
                if(vis[x][y])
                    return;
                else
                {
                    printf("%d %d N LOST\n", x, y);
                    flag = 1;
                    vis[x][y] = 1;
                    return;
                }
            }
        }
        if(d == 'S')
        {
            if(y==0)
            {
                if(vis[x][y])
                    return;
                else
                {
                    printf("%d %d S LOST\n", x, y);
                    flag = 1;
                    vis[x][y] = 1;
                    return;
                }
            }
        }
        if(d == 'E')
        {
            if(x==c)
            {
                if(vis[x][y])
                    return;
                else
                {
                    printf("%d %d E LOST\n", x, y);
                    flag = 1;
                    vis[x][y] = 1;
                    return;
                }
            }
        }
        if(d == 'W')
        {
            if(x==0)
            {
                if(vis[x][y])
                    return;
                else
                {
                    printf("%d %d W LOST\n", x, y);
                    flag = 1;
                    vis[x][y] = 1;
                    return;
                }
            }
        }
        x += dir[d].first;
        y += dir[d].second;
        //vis[x][y] = 1;
    }

}
int main()
{
    Ios;
    //inn;outt;
    dir['S'] = {0, -1};
    dir['E'] = {1, 0};
    dir['N'] = {0, 1};
    dir['W'] = {-1, 0};
    scanf("%d %d", &c, &r);
    while(scanf("%d %d %c", &x, &y, &d)!=EOF)
    {
        //clr(vis, 0);
        flag = 0;
        scanf("%s", cmd);
        lp(i, strlen(cmd))
        if(!flag)
            dfs(cmd[i]);
        else
            break;
        if(!flag)
            printf("%d %d %c\n", x, y,d);
    }
    return 0;
}
