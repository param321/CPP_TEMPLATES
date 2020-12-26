
/*
SEGMENT TREE
ll t[4*N];
void build(ll a[], ll v, ll tl, ll tr) {
    if(tl==tr){
        t[v]=a[tl];
    }else{
        ll tm=(tl+tr)/2;
        build(a,v*2,tl,tm);
        build(a,v*2+1,tm+1,tr);
        t[v]=t[v*2]+t[v*2+1];
    }
}

ll sum(ll v, ll tl, ll tr, ll l, ll r) {
    if(l>r){ 
    	return 0;
    }
    if(l==tl&&r==tr){
        return t[v];
    }
    ll tm=(tl+tr)/2;
    return sum(v*2,tl,tm,l,min(r,tm))+sum(v*2+1,tm+1,tr,max(l,tm+1),r);
}

void update(ll v, ll tl, ll tr, ll pos, ll new_val){
    if(tl==tr){
        t[v]=new_val;
    }else{
        ll tm=(tl+tr)/2;
        if(pos<=tm)
            update(v*2,tl,tm,pos,new_val);
        else
            update(v*2+1,tm+1,tr,pos,new_val);
        t[v]=t[v*2]+t[v*2+1];
    }
}
*/

/*
SEGMENT LAYZ :/
ll t[4*N];
void build(ll a[], ll v, ll tl, ll tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        ll tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = 0;
    }
}

void update(ll v, ll tl, ll tr, ll l, ll r, ll add) {
    if (l > r)
        return;
    if (l == tl && r == tr) {
        t[v] += add;
    } else {
        ll tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), add);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, add);
    }
}

ll get(ll v,ll tl,ll tr,ll pos) {
    if (tl == tr)
        return t[v];
    ll tm=(tl+tr)/2;
    if(pos<=tm)
    	return t[v]+get(v*2,tl,tm,pos);
    else
        return t[v]+get(v*2+1,tm+1,tr,pos);
}
*/