#include<bits/stdc++.h>
 
#define ll long long
 
#define pb push_back
 
#define mod 1000000007
 
#define vi vector<int>
 
#define REP(i, n) for(int i=1; i<=n; i++)
 
using namespace std;
 
int main()
 
{
 
    ios_base::sync_with_stdio(false);
 
    cin.tie(NULL);
 
    cout.tie(NULL);
 
    ll n, q, i, j, x, t1, t2,sum, k;
 
    cin>>n>>q;
 
    priority_queue<ll> maxh;
 
    priority_queue<ll, vector<ll>, greater<ll>> minh;
 
    sum=0;
 
    for(i=0; i<n; i++){
 
        cin>>x;
 
        sum+=x;
 
        maxh.push(x);
 
        minh.push(x);
 
    }   
 
    t1=-1, t2=-1;
 
    ll a[n]={0};
 
    a[0]=sum;
 
    for(i=1; i<n; i++){
 
        t1 = maxh.top(); t2=minh.top();
 
        a[i] = a[i-1]-(t1+t2)+(t1-t2);
 
        maxh.pop(); minh.pop();
 
        maxh.push(t1-t2); minh.push(t1-t2);
 
    }
 
    for(i=0; i<q; i++){
 
        cin>>k;
 
        cout<<a[k]<<'\n';
 
    }
 
    return 0;   
 
}