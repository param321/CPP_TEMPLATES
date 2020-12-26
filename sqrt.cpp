vector<ll> a(n);
ll len=sqrt(n)+1; 
vector<ll> b(len);
for(ll i=0;i<n;++i){
    b[i/len]+=a[i];
}

//queries
for(;;){
    ll l,r;
    ll sum=0;
    for(ll i=l;i<=r;){
        if(i%len==0&&i+len-1<=r){
            sum+=b[i/len];
            i+=len;
        }else{
            sum+=a[i];
            ++i;
        }
    }
}