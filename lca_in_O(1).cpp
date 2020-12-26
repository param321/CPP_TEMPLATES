vector<ll> et;
vector<ll> first_encounter(N);
vector<ll> new_to_old;
vector<ll> lt;
vector<vector<ll>> st;

void findet(ll v,ll p){
    ll new_index=new_to_old.size();
    new_to_old.push_back(v);
    first_encounter[v]=et.size();
    et.push_back(new_index);
    for(ll u:adj[v]){
        if(u==p){
            continue;
        }
        findet(u,v);
        et.push_back(new_index);
    }
}

ll minimum(ll l,ll r) {
    ll log=lt[r-l];
    return min(st[log][l],st[log][r-(1<<log)]);
}

void preprocess(){
    lt.assign(et.size()+1,0);
    for(ll i=2;i<lt.size();i++){ 
        lt[i]=lt[i/2]+1;
    }
    st.assign(lt.back()+1,vector<ll>(et.size()));
    st[0]=et;
    for(ll row=1;row<st.size();row++){
        for(ll i=0;i+(1<<row)<=et.size();i++){
            st[row][i]=min(st[row-1][i],st[row-1][i+(1<<(row-1))]);
        }
    }
}

    findet(1,0);
    preprocess();

    ll u,v;
    cin>>u>>v;
    ll fe1=first_encounter[u];
    ll fe2=first_encounter[v];
    if(fe1>fe2){
        swap(fe1,fe2);
    }
    ll LCA_new_index=rmq.minimum(fe1,fe2+1);
    ll LCA=new_to_old[LCA_new_index];
    p1(LCA);