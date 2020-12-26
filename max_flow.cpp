//////O(V(E^2))
ll n;
vector<vector<ll>> capacity;
vector<vector<ll>> adj;

ll bfs(ll s,ll t,vector<ll>& pa){
    fill(pa.begin(),pa.end(),-1);
    pa[s]=-2;
    queue<pair<ll,ll>> qu;
    qu.push({s,INF});
    while(!qu.empty()){
        ll cur=qu.front().first;
        ll flow=qu.front().second;
        qu.pop();
        for(ll next:adj[cur]){
            if(pa[next]==-1&&capacity[cur][next]){
                pa[next]=cur;
                ll new_flow=min(flow,capacity[cur][next]);
                if(next==t){
                    return new_flow;
                }
                qu.push({next,new_flow});
            }
        }
    }
    return 0;
}

ll maxflow(ll s,ll t){
    ll flow=0;
    vector<ll> pa(n);
    ll new_flow;
    while(new_flow=bfs(s, t, pa)){
        flow+=new_flow;
        ll cur=t;
        while(cur!=s){
            ll prev=pa[cur];
            capacity[prev][cur]-=new_flow;
            capacity[cur][prev]+=new_flow;
            cur=prev;
        }
    }
    return flow;
}