ll st[n][27];

forz(i,n){
    st[i][0] = f(ar[i]);
}

fore(j,1,k){
    for(ll i=0;i+(1<<j)<= N;i++){
        st[i][j]=f(st[i][j-1],st[i+(1<<(j-1))][j-1]);
    }
}

ll sum=0;
for(ll j=K;j>=0;j--){
    if((1<<j)<=R-L+1){
        sum+=st[L][j];
        L+=1<<j;
    }
}

ll j=log2(R-L+1);
ll minimum=min(st[L][j],st[R-(1<<j)+1][j]);
