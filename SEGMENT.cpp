
/*
CUSTOMIZED SEGMENT TREE

struct dat{
    ll sum, pref, suff, ans;
};

dat combine(dat l,dat r){
    dat res;
    res.sum = l.sum + r.sum;
    res.pref = max(l.pref, l.sum + r.pref);
    res.suff = max(r.suff, r.sum + l.suff);
    res.ans = max(max(l.ans, r.ans), l.suff + r.pref);
    return res;
}

dat make_dat(ll val){
    dat res;
    res.sum = val;
    res.pref = res.suff = res.ans = max(0, val);
    return res;
}

dat t[4*N];

void build(ll a[],ll v,ll tl,ll tr){
    if(tl==tr){
        t[v]=make_dat(a[tl]);
    }else{
        ll tm=(tl+tr)/2;
        build(a,v*2,tl,tm);
        build(a,v*2+1,tm+1,tr);
        t[v]=combine(t[v*2],t[v*2+1]);
    }
}

void update(ll v,ll tl,ll tr,ll pos,ll new_val){
    if(tl==tr){
        t[v]=make_dat(new_val);
    }else{
        ll tm=(tl+tr)/2;
        if(pos<=tm){
            update(v*2,tl,tm,pos,new_val);
        }else{
            update(v*2+1,tm+1,tr,pos,new_val);
        }
        t[v]=combine(t[v*2],t[v*2+1]);
    }
}

dat query(ll v,ll tl,ll tr,ll l,ll r){
    if(l>r){ 
        return make_dat(0);
    }
    if(l==tl&&r==tr){ 
        return t[v];
    }
    ll tm=(tl+tr)/2;
    return combine(query(v*2,tl,tm,l,min(r,tm)),query(v*2+1,tm+1,tr,max(l,tm+1),r));
}

*/

/*
SEGMENT TREE
ll t[4*N];
void build(ll a[],ll v,ll tl,ll tr){
    if(tl==tr){
        t[v]=a[tl];
    }else{
        ll tm=(tl+tr)/2;
        build(a,v*2,tl,tm);
        build(a,v*2+1,tm+1,tr);
        t[v]=t[v*2]+t[v*2+1];
    }
}

ll query(ll v,ll tl,ll tr,ll l,ll r){
    if(l>r){ 
    	return 0;
    }
    if(l==tl&&r==tr){
        return t[v];
    }
    ll tm=(tl+tr)/2;
    return query(v*2,tl,tm,l,min(r,tm))+query(v*2+1,tm+1,tr,max(l,tm+1),r);
}

void update(ll v,ll tl,ll tr,ll pos,ll new_val){
    if(tl==tr){
        t[v]=new_val;
    }else{
        ll tm=(tl+tr)/2;
        if(pos<=tm){
            update(v*2,tl,tm,pos,new_val);
        }else{
            update(v*2+1,tm+1,tr,pos,new_val);
        }
        t[v]=t[v*2]+t[v*2+1];
    }
}
*/

/*
SEGMENT LAYZ :/
ll t[4*N];
void build(ll a[],ll v,ll tl,ll tr){
    if(tl==tr){
        t[v]=a[tl];
    }else{
        ll tm=(tl+tr)/2;
        build(a,v*2,tl,tm);
        build(a,v*2+1,tm+1,tr);
        t[v]=0;
    }
}

void update(ll v,ll tl,ll tr,ll l,ll r,ll add){
    if(l>r){
        return;
    }
    if(l==tl&&r==tr){
        t[v]+=add;
    }else{
        ll tm=(tl+tr)/2;
        update(v*2,tl,tm,l,min(r,tm),add);
        update(v*2+1,tm+1,tr,max(l,tm+1),r,add);
    }
}

ll get(ll v,ll tl,ll tr,ll pos) {
    if(tl==tr){
        return t[v];
    }
    ll tm=(tl+tr)/2;
    if(pos<=tm){
    	return t[v]+get(v*2,tl,tm,pos);
    }else{
        return t[v]+get(v*2+1,tm+1,tr,pos);
    }
}
*/