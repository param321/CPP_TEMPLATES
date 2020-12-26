void prefix_function(ll pi[],string s) {
    ll n=s.len;
    pi[0]=0;
    for(ll i=1;i<n;i++){
        ll j=pi[i-1];
        while(j>0&&s[i]!=s[j]){
            j=pi[j-1];
        }
        if(s[i]==s[j]){
            j++;
        }
        pi[i]=j;
    }
    return ;
}


void z_function(ll z[],string s){
    ll n=s.length(),l=0,r=0;
    z[0]=0;
    for(ll i=1;i<n;++i){
        if(i<=r){
            z[i]=min(r-i+1,z[i-l]);
        }
        while((i+z[i]<n)&&(s[z[i]]==s[i+z[i]]){
            ++z[i];
        }
        if((i+z[i]-1)>r){
            l=i,r=i+z[i]-1;
        }
    }
}