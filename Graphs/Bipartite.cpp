#include <bits/stdc++.h>
using namespace std;
#define eb emplace_back
#define debug(x) cerr<<#x<<x;
#define f(i,n) for(int i = 0;i <(int)(n);++i)
#define rep(i,a,b) for(int i = (int)(a); i<=(int) (b); ++i)
typedef vector<int> vi;
typedef pair<int, int> pi;
const int MAX_N = 1e5 + 1;
int co = 0;
int n;
vector<int> a[MAX_N];
int visited[MAX_N];
int col[MAX_N];

bool dfs(int n,int c){
    visited[n] = 1;
    col[n] = c;
    for(auto x:a[n]){
        if(!visited[x]){
            if(dfs(x, c^1)==false)
                return false;
        }
        else if(col[n]==col[x])
            return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int t,e;
    cin>>t;
    rep(i,1,t){
        cin>>n>>e;
        rep(i,1,n)
            a[i].clear(), visited[i] = 0;
        f(i,e){
            int x,y;
            cin>>x>>y;
            a[x].eb(y);
            a[y].eb(x);
        }
        bool flag = true;
        rep(i,1,n){
            if(!visited[i]){
                bool res = dfs(i,0);
                if(res == false){
                    flag = false;
                    break;
                }
            }
        }
        cout<<"Scenario #"<<i<<":"<<endl;
        flag==false?cout<<"Suspicious bugs found!":cout<<"No suspicious bugs found!";
        cout<<endl;
        // rep(i,1,n){
        //     cout<<i<<" -> ";
        //     for(auto x:a[i])
        //         cout<<x<<" ";
        //     cout<<endl;
        // }
    }
}