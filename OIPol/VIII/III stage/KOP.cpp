#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define pb push_back
#define X first
#define Y second
#define  up_limit 15002
#define maxer 60002
#define INF 1000000007
#define ll long long

typedef int item;
item base_val=0;
item NO_OP=INF;

void modifier_add(item & a, item b, ll len=1)
{
    if(a==NO_OP)a=b;
    else a+=b;
}
item calc(item a , item b)
{
    return max(a,b);
}
template<class T>
struct Seg_tree
{
    ll siz;
    vector<T> data;
    vector<T> ops_add;
    T base_val;
    T (*func)(T obj1, T obj2);
    Seg_tree(vector<T> a,int n, T base_val, T (*func)(T obj1, T obj2)):base_val(base_val)
    {
        this->func=func;
        init(a,n);
    }
    void init(vector<T> a,int n)
    {
        siz=1;
        while(siz<=n)siz*=2;
        data.assign(2*siz,base_val);
        ops_add.assign(2*siz,0);
       // build(a,0,0,siz);
    }
    void build(vector<T> &a, int node,int down,int up )
    {
        if(up-down==1)
        {
            if(down<(int)a.size())data[node]=a[down];
            return;
        }
        int mid = (down+up)/2;
        build(a, 2*node+1, down, mid);
        build(a, 2*node+2, mid, up);
    
        data[node]=func(data[2*node+1], data[2*node+2]);
    }
    void propagate(int node , int down , int up)
    {
        if(up-down==1|| ops_add[node]==NO_OP  )return ;
        int mid=(down+ up)/2;
        if(ops_add[node]!=NO_OP)
        {
            modifier_add(ops_add[2*node+1],ops_add[node],1);
            modifier_add(data[2*node+1],ops_add[node],mid-down);
            modifier_add(ops_add[2*node+2],ops_add[node],1);
            modifier_add(data[2*node+2],ops_add[node],up-mid);
        }
       ops_add[node]=NO_OP;
    }
// this works in range <a,b) 
    T range(int a, int b,int node , int down , int up )
    {
        propagate(node,down,up);
        if(down>=a && up<=b)
            return data[node];
        if(down>=b || a>=up)
            return base_val;
        int mid = (down+ up)/2;
        return func(range( a,b,2*node +1 , down,mid),range(a,b,2*node+2, mid,up));
    }
    // this works  also in range <a,b) 
     void add(int a, int b,int z,int node , int down , int up )
    { 
        propagate(node,down,up);
        if(down>=b || a>=up)return;
        if(down>=a && up<=b)
        { 
            modifier_add(ops_add[node],z);
            modifier_add(data[node],z,(up-down));
            return;
        }
        int mid = (down+ up)/2;
        add( a,b,z,2*node +1 , down,mid);
        add(a,b,z,2*node+2, mid,up);
        data[node]=func(data[2*node+1],data[2*node+2]);
    }

};    



int arr[up_limit]={};
pii queries[up_limit]={};


int s,w,q;

bool comp(tuple<int,int,int>& a, tuple<int,int,int>&  b)
{
    int a0 ,a1,b0, b1, c0, c1;
    tie(a0,b0,c0)=a;
    tie(a1,b1,c1)=b;
    if(b0<b1)
        return 1;
    else if( b1<b0)
        return 0;
    if(c0>c1)
        return 1;
    else if(c1>c0)
        return 0;
    return a0<a1;            
}
int main()
{
    cin.tie(); ios_base::sync_with_stdio(0);
      
    cin>>s>>w>>q;
    vector<tuple<int,int,int>> vec;
    int big=0;
    for(int i=0; i<q;i++)
    {
        int a, b;
        cin>>a>>b;
        a+=30000;b+=30000;
        queries[i]={a,b};
        vec.pb({a,b,1});
        vec.pb({a,b+w,-1});
        big=max(big,b+w);
    }
    sort(vec.begin(),vec.end(),comp);
    vector<item> emp(big);
    Seg_tree<item> seg(emp,maxer,base_val,calc);
    int sol=0;

    for(auto e:vec)
    {
        int a, b,c; tie(a,b,c)=e;
        if(c==1)
            seg.add(a,a+s+1,1,0,0,seg.siz);
        if(c==-1)
            seg.add(a,a+s+1,-1,0,0,seg.siz);
        sol=max(sol,seg.data[0]); 
        //cout<<a<<" "<<b<<" "<<c<<"   "<<seg.range(0,maxer,0,0,seg.siz)<<'\n';
    }
   // for(int i=0; i< seg.siz;i++)cout<<seg.data[i];
    cout<<sol;
    return 0;
}