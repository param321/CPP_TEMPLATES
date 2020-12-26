/*
DIJKSTRA

ll d[x+1],pa[x+1];
    bool vis[x+1];
    fore(i,1,x){
        pa[i]=0;
        d[i]=INF;
        vis[i]=false;
    }
    d[1]=0;
    forz(i,y){
        cin>>p>>q>>r;
        adj[p].pb({q,r});
        adj[q].pb({p,r});
    }
    priority_queue <pair<ll,ll>> qu;
    qu.push({0,1});
    while(!qu.empty()){
        ll a = qu.top().second; 
        qu.pop();
        pa[1]=-1;
        if(!vis[a]){
            vis[a] = true;
            for(auto u:adj[a]){
                ll b=u.first,w=u.second;
                if(d[a]+w<d[b]){
                    d[b]=d[a]+w;
                    qu.push({-d[b],b});
                    pa[b]=a;
                }
            }
        }
    }
*/