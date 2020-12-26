//zero based indexing

struct FenwickTree2D{
    vector<vector<ll>> bit;
    ll n, m;

    ll sum(ll x, ll y) {
        ll ret = 0;
        for (ll i = x; i >= 0; i = (i & (i + 1)) - 1){
            for (ll j = y; j >= 0; j = (j & (j + 1)) - 1){
                ret += bit[i][j];
            }
        }
        return ret;
    }

    void add(ll x, ll y, ll delta) {
        for (ll i = x; i < n; i = i | (i + 1)){
            for (ll j = y; j < m; j = j | (j + 1)){
                bit[i][j] += delta;
            }
        }
    }
};