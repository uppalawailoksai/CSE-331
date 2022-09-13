#include <bits/stdc++.h>                                                

#define endl            "\n"
#define FASTIO          ios_base::sync_with_stdio(false);cin.tie(NULL);
#define int             long long


using namespace std;

const int MOD = 1e9 + 7;
const int N   = 1e5;

int timer;

void preprocess(){
    return;
}

void dfs(vector<vector<int>> &adj, vector<vector<int>> &t, int crr){
    t[crr][0] = timer++;
    for(auto nbr : adj[crr])
        dfs(adj, t, nbr);
    t[crr][1] = timer++;
}

bool isAnc(vector<vector<int>> &t, int par, int child){
    return t[par][0] < t[child][0] and t[child][1] < t[par][1];
}

void upd(vector<int> &bit, int i, int dv){
    for(++i; i < bit.size(); i += i & -i) bit[i] += dv;
}

int sum(vector<int> &bit, int i){
    int s = 0;
    for(++i; i > 0; i -= i & -i) s += bit[i];
    return s;
}

int sum(vector<int> &bit, int l, int r){
    return sum(bit, r) - sum(bit, l-1);
}

int inline solve(){
    int n, q, i, qt, b, c;
    cin >> n >> q;
    
    vector<vector<int>> adjL(n), adjR(n);
    vector<vector<int>> tL(n, {-1, -1}), tR(n, {-1, -1});
    vector<int> ht(n), tst(n), bitL(2*n+9, 0), bitR(2*n+9, 0);
    
    for(i=0; i<n; ++i)
        cin >> ht[i];
    
    for(i=0; i<n; ++i)
        cin >> tst[i];
    
    stack<int> st;
    
    for(i = 0; i < n; ++i){
        while(!st.empty() and ht[st.top()] < ht[i]){
            adjL[i].push_back(st.top());
            st.pop();
        }
        st.push(i);
    }
    
    while(!st.empty()) st.pop();
    
    for(i = n-1; i >= 0; --i){
        while(!st.empty() and ht[st.top()] < ht[i]){
            adjR[i].push_back(st.top());
            st.pop();
        }
        st.push(i);
    }    
    
    timer = 0;
    for(i = n-1; i >= 0; --i)
        if(tL[i][0] == -1)
            dfs(adjL, tL, i);
    
    timer = 0;
    for(i = 0; i < n; ++i)
        if(tR[i][0] == -1)
            dfs(adjR, tR, i);
    
    for(i = 0; i < n; ++i){
        upd(bitL, tL[i][0], tst[i]);
        upd(bitL, tL[i][1], -tst[i]);
        
        upd(bitR, tR[i][0], tst[i]);
        upd(bitR, tR[i][1], -tst[i]);
    }
    
    while(q --> 0){
        cin >> qt >> b >> c;
        if(qt == 1){ --b;
            upd(bitL, tL[b][0], c - tst[b]);
            upd(bitL, tL[b][1], -c + tst[b]);
            upd(bitR, tR[b][0], c - tst[b]);
            upd(bitR, tR[b][1], -c + tst[b]);
            tst[b] = c;
        }else{ --b; --c;
            if(b == c)
                cout << tst[b] << endl;
            else if(isAnc(tL, b, c))
                cout << sum(bitL, tL[b][0], tL[c][0]) << endl;
            else if(isAnc(tR, b, c))
                cout << sum(bitR, tR[b][0], tR[c][0]) << endl;
            else cout << -1 << endl;
        }
    }
    
    return 0;
}

signed main(){
    FASTIO;
    preprocess();
    int t = 1, i;

    for(i=1; i<=t; ++i){

            solve();

    }
    return 0;
}