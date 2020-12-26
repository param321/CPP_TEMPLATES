/*
BFS
ll s; // source vertex

queue<ll> qu;
vector<bool> used(N);
vector<ll> d(N), pa(N);
acc(used);
acc(d);
acc(pa);
qu.push(s);
used[s]=true;
pa[s]=-1;
while(!qu.empty()){
    ll v=qu.front();
    qu.pop();
    for(ll u:adj[v]){
        if(!used[u]){
            used[u]=true;
            qu.push(u);
            d[u]=d[v]+1;
            pa[u]=v;
        }
    }
}
*/

/*
DFS
vector<bool> vis;

void dfs(ll v){
    vis[v]=true;
    for(ll u:adj[v]){
        if(!vis[u]){
            dfs(u);
        }
    }
}
*/