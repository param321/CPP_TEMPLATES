vector<ll> parent, depth, heavy, head, pos;
ll cur_pos;

ll dfs(ll v) {
    ll size = 1;
    ll max_c_size = 0;
    for (ll c : adj[v]) {
        if (c != parent[v]) {
            parent[c] = v, depth[c] = depth[v] + 1;
            ll c_size = dfs(c);
            size += c_size;
            if (c_size > max_c_size){
                max_c_size = c_size;
                heavy[v] = c;
            }
        }
    }
    return size;
}

ll decompose(ll v,ll h){
    head[v]=h;
    pos[v] = cur_pos++;
    if(heavy[v]!=-1){
        decompose(heavy[v],h);
    }
    for(ll c:adj[v]){
        if(c!=parent[v]&&c!=heavy[v]){
            decompose(c,c);
        }
    }
}

void init() {
    parent = vector<ll>(N);
    depth = vector<ll>(N);
    heavy = vector<ll>(N, -1);
    head = vector<ll>(N);
    pos = vector<ll>(N);
    cur_pos = 0;

    dfs(0);
    decompose(0, 0);
}

ll query(ll a, ll b) {
    ll res = 0;
    for(;head[a]!=head[b];b=parent[head[b]]){
        if(depth[head[a]]>depth[head[b]]){
            swap(a,b);
        }
        ll cur_heavy_path_max = segment_tree_query(pos[head[b]], pos[b]);
        res = max(res, cur_heavy_path_max);
    }
    if (depth[a] > depth[b]){
        swap(a, b);
    }
    ll last_heavy_path_max = segment_tree_query(pos[a], pos[b]);
    res = max(res, last_heavy_path_max);
    return res;
}

void update(ll i,ll w) { 
   segtree_tree_update(pos[i] , w);
}
