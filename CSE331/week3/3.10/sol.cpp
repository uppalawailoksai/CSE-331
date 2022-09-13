#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a*b / __gcd(a,b)
#define I first
#define II second
#define pb push_back
#define ii pair<int,int>
const int INF = 2 * 1e9;
const int N = 2e5 + 1;
const int MOD = 1e9 + 7;
int n,tt,ans[N];
vector<ii> q[N];
vector<int> g[N];
map<int,int> dfs(int u)
 {
     map<int,int> res;
     int k=g[u].size();
     if (!k) res[1]=1; else
       if (k==1) res=dfs(g[u][0]); else
     {
         for (int v : g[u])
         {
             map<int,int> cur=dfs(v);
             for (auto t : cur)
             {
                 int a=t.I,b=t.II;
                 if (a*k<=1e6) res[a*k]+=b;
             }
         }
     }
     for (auto t : q[u])
     {
         int s=0;
         int i=t.II,w=t.I;
         for (auto v : res)
            if (w%v.I==0) s+=w/v.I * v.II;
         ans[i]=w-s;
     }
     return res;
 }
int main()
{
#define TASKNAME "*"
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (fopen(TASKNAME".inp","r" ))
    {
        freopen(TASKNAME".inp","r",stdin);
        freopen(TASKNAME".out","w",stdout);
    }
    cin>>n;
    for (int i=2;i<=n;i++)
    {
        int p;cin>>p;
        g[p].pb(i);
    }
    cin>>tt;
    for (int i=1;i<=tt;i++)
    {
        int u,w;
        cin>>u>>w;
        q[u].pb({w,i});
    }
    dfs(1);
    for (int i=1;i<=tt;i++) cout<<ans[i]<<'\n';
    return 0;
}
