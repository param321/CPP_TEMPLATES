                                           //         PAR_YUMMM            //
                                           //           CPP                //
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ll int
#define ld long double
ll const N=1e6+5;

#define pb push_back
#define popb pop_back()
#define pf push_front
#define popf pop_front()
#define si size()
#define be begin()
#define en end()
#define all(v) v.be, v.en
#define len length()
#define umap unordered_map
#define uset unordered_set
#define acc(v) accumulate(all(v), 0)
#define F first
#define S second
 
#define forz(i, n) for (ll i = 0; i < n; i++)
#define fore(i, m, n) for (ll i = m; i <= n; i++)
#define rforz(i, n) for (ll i = n - 1; i >= 0; i--)
#define rfore(i, m, n) for (ll i = n; i >= m; i--)
#define deci(n) fixed << setprecision(n)
#define high(n) __builtin_popcount(n)
#define highll(n) __builtin_popcountll(n)
#define parity(n) __builtin_parity(n)
#define ctz(n) __builtin_ctz(n)
#define lb lower_bound
#define ub upper_bound
#define er equal_range
#define maxe *max_element
#define mine *min_element
#define mod 1000000007
#define mod2 998244353
#define gcd __gcd
#define sexy ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
 
#define endl "\n"
#define p0(a) cout << a << " "
#define p1(a) cout << a << endl
#define p2(a, b) cout << a << " " << b << endl
#define p3(a, b, c) cout << a << " " << b << " " << c << endl
#define p4(a, b, c, d) cout << a << " " << b << " " << c << " " << d << endl
 
#define oset tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define osetll tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
//member functions :
//1. order_of_key(k) : number of elements strictly lesser than k
//2. find_by_order(k) : k-th element in the set
#define ofk order_of_key
#define fbo find_by_order

ll po(ll a,ll b,ll m){
    ll res=1;
    while(b>0){
        if(b&1){
            res=((res%m)*(a%m))%m;
        }
        a=((a%m)*(a%m))%m;
        b>>=1;
    }
    return res;
}

ll modi(ll a,ll m){
    return po(a,m-2,m);
}

ll lcm(ll a,ll b){ 
    return (a*b)/(gcd(a, b));
}

ll max(ll a,ll b){
    if(a>b){
        return a;
    }else{
        return b;
    }
}

ll min(ll a,ll b){
    if(a<b){
        return a;
    }else{
        return b;
    }
}

ll bins(ll ar[],ll l,ll r,ll x){ 
    if(r>=l){ 
        ll m=l+((r-l)/2); 
        if(ar[m]==x){
            return m; 
        }else if(ar[m]>x){ 
            return bins(ar,l,m-1,x);
        }else{
            return bins(ar,m+1,r,x); 
        }
    } 
    return -1; 
} 

ll nCr(ll n,ll k){ 
    ll C[n + 1][k + 1]; 
    ll i, j; 
    for(i=0;i<=n;i++){ 
        for(j=0;j<=min(i,k);j++){
            if(j==0||j==i){
                C[i][j]=1;  
            }else{
                C[i][j]=C[i-1][j-1]+C[i-1][j]; 
            }
        } 
    }
    return C[n][k]; 
} 

//vector<vector<ll>> adj(N); 

void count_sort(vector <ll> &p,vector <ll> &c){
    ll x=p.si;
    vector <ll> cnt(x),pos(x);
    forz(i,x){
        cnt[i]=0;
        pos[i]=0;
    }
    for(auto it:c){
        cnt[it]++;
    }
    pos[0]=0;
    fore(i,1,x-1){
        pos[i]=pos[i-1]+cnt[i-1];
    }
    vector <ll> pnew(x);
    for(auto it:p){
        ll i=c[it];
        pnew[pos[i]]=it;
        pos[i]++;
    }
    p=pnew;
}

string subst(string s,ll i,ll j){
    string a="";
    ll x=s.len;
    fore(k,i,j-1){
        a+=s[k%x];
    }
    return a;
}

int main(){
    sexy;
    ll T,x,y,z,q,r;
    string s,a,b;
    cin>>s;
    s+='$';
    x=s.len;
    vector <ll> p(x),c(x);
    vector <pair<char,ll>> ve;
    forz(i,x){
        ve.pb({s[i],i});
    }
    sort(all(ve));
    forz(i,x){
        p[i]=ve[i].S;
    }
    c[p[0]]=0;
    fore(i,1,x-1){
        if(ve[i].F==ve[i-1].F){
            c[p[i]]=c[p[i-1]];
        }else{
            c[p[i]]=c[p[i-1]]+1;
        }
    }
    ll k=0;
    while((1<<k)<x){
        forz(i,x){
            p[i]=(p[i]-(1<<k)+x)%x;
        }
        count_sort(p,c);
        vector <ll> c_new(x);
        c_new[p[0]]=0;
        fore(i,1,x-1){
            pair <ll,ll> prev={c[p[i-1]],c[(p[i-1]+(1<<k))%x]};
            pair <ll,ll> now={c[p[i]],c[(p[i]+(1<<k))%x]};
            if(prev==now){
                c_new[p[i]]=c_new[p[i-1]];
            }else{
                c_new[p[i]]=c_new[p[i-1]]+1;
            }
        }
        c=c_new;
        k++;
    }
    cin>>y;
    forz(i,y){
        cin>>a;
        z=a.len;
        ll lr=0,rr=x-1;
        ll ans=-1;
        while(lr<=rr){
            ll mid=lr+((rr-lr)/2);
            if(subst(s,p[mid],p[mid]+z)<a){
                lr=mid+1;
            }else if(subst(s,p[mid],p[mid]+z)>a){
                rr=mid-1;
            }else{
                ans=1;
                break;
            }
        }
        if(ans==1){
            p1("Yes");
        }else{
            p1("No");
        }
    }
    return 0;
}
