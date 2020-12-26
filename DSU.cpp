/*
DSU

ll parent[N];
ll siz[N];
set <ll> st;
void make(ll v) {
    parent[v] = v;
    siz[v] = 1;
    st.insert(v);
}

ll findset(ll v) {
    if (v == parent[v])
        return v;
    return parent[v] = findset(parent[v]);
}

void merge(ll a, ll b){
    a = findset(a);
    b = findset(b);
    if (a != b) {
        if (siz[a] < siz[b])
            swap(a, b);
        parent[b] = a;
        siz[a] += siz[b];
    }
}

void merge2(ll x,ll y){
    auto it=st.ub(x);
    while(it!=st.end()&&*it<=y)
    {
        merge(x,*it);
        ll value=*it;
        st.erase(it);
        it=st.ub(value);
    }
}
*/