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
int n, m;
int grid[1000][1000], dis[1000][1000];
int main()
{
    Ios;
    //freopen("in.in", "r",stdin);
    //freopen("out.out", "w",stdout);
    int t;
    int xd[] = {-1,0,1,0};
    int yd[] = {0,1,0,-1};
    for(cin >> t; t--;)
    {
        cin >> n >> m;
        memset(dis, OO, sizeof(dis));
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                cin >> grid[i][j];
            auto ok = [](int x, int y)
            {
                return (x < n && x >= 0 && y < m && y >= 0);
            };
            priority_queue<pair<int, pair<int, int>>> q;
            q.push({-grid[0][0], {0, 0}});
            dis[0][0] = grid[0][0];
            while(q.size())
            {
                int x, y, d;
                d = q.top().first * -1;
                tie(x, y) = q.top().second;
                q.pop();
                if(d != dis[x][y])continue;
                int nx, ny;
                for(int i = 0; i < 4; ++i)
                {
                    nx = x + xd[i];
                    ny = y + yd[i];
                    if(ok(nx, ny) && d + grid[nx][ny] < dis[nx][ny])
                    {
                        dis[nx][ny] = d + grid[nx][ny];
                        q.push({-dis[nx][ny], {nx, ny}});
                    }
                }
            }
            cout << dis[n - 1][m - 1] << endl;

    }
    //system("sleep 5");
    return 0;
}
