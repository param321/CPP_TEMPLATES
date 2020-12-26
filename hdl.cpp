vector <vector<pair<ll,ll>>> adj(N);
const ll MAX = 25;
ll parent[N][MAX];

void HLD(int v, int par) {
    int heavyChild = -1, heavySize = 0,heavyEdgeWeight = -1;
    chain[v] = chainId;
    position[v] = pos++;
    for(auto p : adj[v]) {
        if(p.F!=par) {
            if(subtree_size[p.F] > heavySize) {
                heavySize = subtree_size[p.F];
                heavyChild = p.F;
                heavyEdgeWeight = p.S;
            }
        }
    }
    if(heavyChild!=-1) {
        arr[pos] = heavyEdgeWeight;
        HLD(heavyChild, v);
    }
    for(auto p : adj[v]) {
        if(p.F != par && p.F != heavyChild) {
            chainId++;
            chainHead[chainId] = p.F;
            arr[pos] = p.S;
            HLD(p.F, v);
        }
    }
}

void dfs(int v, int par, int l) {
    parent[v][0] = par;
    for(int i=1;i<=MAX;++i) {
        if(parent[v][i-1]!=0) {
            parent[v][i] = parent[parent[v][i-1]][i-1];
        }
    }
    subtree_size[v] += 1;
    level[v] = l;
    for(auto p : adj[v]) {
        if(p.F!=par) {
            dfs(p.F, v, l+1);
            subtree_size[v]+=subtree_size[p.F];
        }
    }
}
