#include <bits/stdc++.h>
using namespace std;

class DSU{
    
    unordered_map<int,int> par;
    
    public:
    
    void makeSet(vector<int>& u){
        for(auto it:u) par[it]=it;
        
    }
    
    int Find(int x){
        if(par[x]==x) return x;
        
        else return par[x] = Find(par[x]);
    }
    
    bool Union(int x,int y){
        int parx = Find(x);
        int pary = Find(y);
        
        if(parx==pary) return false;
        
        par[pary] = parx;
        
        return true;
    }
};



int main() {
    
    
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        
        vector<pair<int,int>> cord(n);
        
        vector<vector<int>> edges;
        
        
        for(int i=0;i<n;i++){
            int x,y;
            cin>>x>>y;
            
            cord[i] = {x,y};
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++){
                
                int x1  = cord[i].first;
                int y1  = cord[i].second;
                int x2  = cord[i].first;
                int y2  = cord[j].second;
                
                int dis = pow(x1-x2,2)+pow(y1-y2,2);

                vector<int> tp = {dis,i,j};
                
                edges.push_back(tp);
                
                
            }
        }
        
        
    sort(edges.begin(),edges.end());
    
    vector<int> u(n);
    
    for(int i=0;i<n;i++) u[i]=i;
    
    DSU dsu;
    
    dsu.makeSet(u);
 
    
    for(auto& it:edges){
      
      int b = it[1];
      int c = it[2];
  
      if(dsu.Union(b,c)) cout<<b+1<<" "<<c+1<<endl;
    }
    
        
    }
    
    return 0;
    
    
    
}
