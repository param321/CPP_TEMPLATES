//One based Indexing

struct FenwickTree{
    vector<ll> bit; 
    ll n;

    FenwickTree(ll n) {
        this->n = n + 1;
        bit.assign(n + 1, 0);
    }

    FenwickTree(vector<ll> a):FenwickTree(a.size()){
        for(ll i=0;i<a.size();i++){
            add(i, a[i]);
        }
    }

    ll sum(ll idx) {
        ll ret = 0;
        for (++idx;idx>0;idx-=idx&-idx){
            ret+=bit[idx];
        }
        return ret;
    }

    ll sum(ll l, ll r){
        return sum(r)-sum(l-1);
    }

    void add(ll idx,ll delta) {
        for(++idx;idx<n;idx+=idx&-idx){
            bit[idx]+=delta;
        }
    }
};