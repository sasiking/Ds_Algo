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
#define fr(i,n) for(int i = (int)(n) - 1;i>=0;i--)
#define rep(i,a,b) for(int i = (int)(a); i<=(int) (b); ++i)
#define repr(i,a,b) for(int i = (int)(b); i>=(int) (a); i--)
#define deb(x) cout<<#x<< " = "<< x<<endl
#define ar array
#define ll long long
 
typedef vector<int> vi;
typedef pair<int, int> pi;
 
const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

int n;
vi a[MAX_N];
int visited[MAX_N];

bool dfs(int src,int parent){
    visited[src] = 1;
    for(auto x:a[src]){
        if(!visited[x]){
            //cout<<x<<" "<<src<<" ";
            if(dfs(x,src)==true)
                return true;
        }
        else if(x!=parent){
            //cout<<x<<" else if "<<src<<" "; 
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int e;
    cin>>n>>e;
    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        a[x].eb(y);
        a[y].eb(x);
    }
    for(int i=1;i<=n;i++){
        for(auto x:a[i])
            cout<<x<<" ";
        cout<<endl;
    }
    bool sol = dfs(1,0);
    if(sol == true)
        cout<<"Cycle Exists";
    else
        cout<<"Cycle Don't exist";
    cout<<endl;
}