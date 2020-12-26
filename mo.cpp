const ll block_size = 500;
ll ar[200001];
ll freq[1000001];
ll an=0;
 
bool cmp(pair<pair<ll,ll>,ll> p1,pair<pair<ll,ll>,ll> p2){
    if(p1.F.F/block_size == p2.F.F/block_size){
        return p1.F.S<p2.F.S;
    }else{
        return p1.F.F<p2.F.F;
    }
}
 
void add(ll x){
    an=an-(freq[ar[x]]*freq[ar[x]]*ar[x]);
    freq[ar[x]]++;
    an=an+(freq[ar[x]]*freq[ar[x]]*ar[x]);
}
 
void remove(ll x){
    an=an-(freq[ar[x]]*freq[ar[x]]*ar[x]);
    freq[ar[x]]--;
    an=an+(freq[ar[x]]*freq[ar[x]]*ar[x]);
}

vector <pair<pair<ll,ll>,ll>> qu;
    forz(i,y){
        cin>>p>>r;
        p--;
        r--;
        qu.pb({{p,r},i});
    }
    sort(all(qu),cmp);
    ll ans[y];
    ll cur_l = 0;
    ll cur_r = -1;
    for(auto q : qu) {
        while (cur_l > q.F.F) {
            cur_l--;
            add(cur_l);
        }
        while (cur_r < q.F.S) {
            cur_r++;
            add(cur_r);
        }
        while (cur_l < q.F.F) {
            remove(cur_l);
            cur_l++;
        }
        while (cur_r > q.F.S) {
            remove(cur_r);
            cur_r--;
        }
        ans[q.S] = an;
    }