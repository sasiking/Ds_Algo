#include <bits/stdc++.h>
using namespace std;
 
#define eb emplace_back
#define mp make_pair
#define fi  first
#define se second
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define debug(x) cerr<<#x<<" = "<<x<<endl;
#define f(i,n) for(int i = 0;i <(int)(n);++i)
#define rep(i,a,b) for(int i = (int)(a); i<=(int) (b); ++i)
#define deb(x) cout<<#x<< " = "<< x<<endl
#define ll long long
 
typedef vector<int> vi;
typedef pair<int, int> pi;
 
const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
 
int co = 0;
int n;
vi a[MAX_N];
vi visited(MAX_N,0);
int cc_size;

void dfs(int v){
    visited[v] = 1;
    cc_size++;
    for(auto x:a[v]){
        if(!visited[x])
            dfs(x);
    }
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
    while(t--){
        cin>>n>>e;
        rep(i,1,n)
            a[i].clear(), visited[i] = 0; 
        f(i,e){
            int x,y;
            cin>>x>>y;
            a[x].eb(y);
            a[y].eb(x);
        }
        ll sol=1;
        int co = 0;
        rep(i,1,n){
            cc_size=0;
            if(!visited[i]){
                dfs(i);
                co++;
                sol = (sol * cc_size) % MOD;
            }
        }
        cout<<co<<" "<<sol<<endl;
    }
}