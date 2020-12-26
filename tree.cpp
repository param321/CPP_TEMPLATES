//DFS
ll sub[N];

void dfs(ll x,ll y){
	sub[x]=1;
	for(auto u:adj[x]){
		if(u==y) continue;
		dfs(u,x);
		sub[x]+=sub[u];
	}
}

//Euler Tour
vector<ll> euler_tour;
vector<ll> height;

void dfs(ll v,ll p,ll h) {
    first_visit[v]=euler_tour.size();
    euler_tour.push_back(v);
    height[v]=h;
    for(ll u:adj[v]){
        if(u==p) continue;
        dfs(u,v,h+1);
        euler_tour.push_back(v);
    }
}

//in tiem and out time
void dfs(ll x,ll y){
    tin[x]=t++;
    for(auto it:adj[x]){
        if(it==y){
            continue;
        }
        dfs(it,x);
    }
    tout[x]=t++;
}

