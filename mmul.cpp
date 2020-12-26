struct matrix{
    vector <vector<ll>> m;
};

void msi(matrix &m,ll a,ll b){
    m.m.resize(a);
    forz(i,a){
       m.m[i].resize(b);
    }
}

void minit(matrix &m,ll x){
    forz(i,m.m.size()){
        forz(j,m.m[0].size()){
            m.m[i][j]=x;
        }
    }
}

matrix mul(matrix m1,matrix m2){
    matrix m3;
    msi(m3,m1.m.size(),m2.m[0].size());
    forz(i,m3.m.size()){
        forz(j,m3.m[0].size()){
            m3.m[i][j]=0;
            forz(k,m1.m[0].size()){
                m3.m[i][j]=(m3.m[i][j]+((m1.m[i][k]*m2.m[k][j])%mod))%mod;
            }
        }
    }
    return m3;
}
matrix mexp(matrix &mx,ll p){
    matrix res;
    msi(res,mx.m.size(),mx.m.size());
    minit(res,0);
    forz(i,mx.m.size()){
        res.m[i][i]=1;
    }
    while(p>0){
        if(p&1){
            res=mul(res,mx); 
        }
        mx=mul(mx,mx);
        p=p>>1;
    }
    return res;
}
//CODE FOR FIBO
int main()
{
    kira;
    lli n;
    cin>>n;
    matrix ans;
    msi(ans,3,3);
    minit(ans,0);
    ans.m[0][0]=1;
    ans.m[0][1]=1;
    ans.m[0][2]=1;
    for(int i=1;i<3;i++)
    {
        ans.m[i][i-1]=1;
    }
    ans=mexp(ans,n);
    lli res=ans.m[0][0];
    cout<<res;
    return 0;
}