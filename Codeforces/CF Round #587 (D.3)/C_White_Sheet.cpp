    #include <bits/stdc++.h>
    using namespace std;
    using ll =long long;
    using pii= pair<int,int>;
    using pll = pair<ll, ll>;
    #define  X first 
    #define  Y second 
    #define  pb push_back
    #define  pf push_front
    #define  mp make_pair
    #define all(x) begin(x), end(x)
     
    constexpr int MOD= 1e9 +7;
    void _speed()
    {
    	ios_base::sync_with_stdio(false);     cin.tie(NULL);
    }
    bool checkIfPointIsIn(pii coor,vector<pii> b)
    {
        if(b[1].Y<coor.Y || b[1].X<coor.X ||b[0].X>coor.X ||b[0].Y>coor.Y)
            return false;
        return true;
    }
    bool checkOverlappingOrContacting(vector<pii> a,vector<pii> b)
    {
         if(b[1].Y<a[0].Y || b[1].X<a[0].X ||a[1].X<b[0].X ||b[0].Y>a[1].Y)
            return false;
        return true;
    }
     
    int main() {
        _speed();
        vector<pii> rectWhite;
        vector<pii> rectBlack1;
        vector<pii> rectBlack2;
      
            int x1,x2,y1,y2;
            cin>>x1>>y1>>x2>>y2;
            rectWhite.pb({x1,y1});
            rectWhite.pb({x2,y2});
            rectWhite.pb({x1,y2});
            rectWhite.pb({x2,y1});
      
           
              cin>>x1>>y1>>x2>>y2;
            rectBlack1.pb({x1,y1});
            rectBlack1.pb({x2,y2});
            rectBlack1.pb({x1,y2});
            rectBlack1.pb({x2,y1});
       
             
            cin>>x1>>y1>>x2>>y2;
            rectBlack2.pb({x1,y1});
            rectBlack2.pb({x2,y2});
            rectBlack2.pb({x1,y2});
            rectBlack2.pb({x2,y1});
        int i=0;
        bool vis[4]={};
        int counter1=0;
        int counter2=0;
        for(auto vertex:rectWhite)
        {
            
            if(checkIfPointIsIn(vertex,rectBlack1))
            {
                counter1++;
                  vis[i]=1;
            }
            if(checkIfPointIsIn(vertex,rectBlack2))
            {
                 counter2++;
                 vis[i]=1;
            }
            i++;
        }
        if(counter1==4 || counter2==4 || 
        ( vis[0] &&  vis[1] && vis[2] && vis[3] && counter1+ counter2>=4 &&checkOverlappingOrContacting(rectBlack1,rectBlack2)))
        {
            cout<<"NO";
            
        }else{
            cout<<"YES";
        }
         return 0;
           
    }