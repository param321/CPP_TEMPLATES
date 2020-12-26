    vector <vector<ll>> gr;
    vector<bool> used;
    vector<ll> order, component;

    void dfs1(ll v){
        used[v]=true;
        for(auto i:adj[v]){
            if(!used[i]){
                dfs1(i);
            }
        }
        order.push_back(v);
    }

    void dfs2(ll v){
        used[v]=true;
        component.push_back(v);
        for(auto i:gr[v]){
            if(!used[i]){
                dfs2(i);
            }
        }
    }

    int main() {
        ll n;
        ... reading n ...
        for (;;) {
            ll a, b;
            ... reading next edge (a,b) ...
            adj[a].push_back(b);
            gr[b].push_back(a);
        }
        used.assign(n,false);
        for(ll i=1;i<=n;++i){
            if(!used[i]){
                dfs1(i);
            }
        }
        used.assign(n,false);
        for(ll i=0;i<n;++i){
            ll v=order[n-1-i];
            if(!used[v]){
                dfs2(v);
                ... printing next component ...
                component.clear();
            }
        }
    }