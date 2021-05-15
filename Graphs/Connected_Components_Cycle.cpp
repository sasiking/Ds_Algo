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

int co = 0;
int n;
vector<int> a[MAX_N];
unordered_map<int,int> visited;

void dfs(int point){
    visited[point] = 1;
    for(auto x:a[point])
        if(!visited[x])
            dfs(x);
}

//No.of dfs Calls on the graph reviels the no of connected Components

int FindComponents(){
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            co++;
            dfs(i);
        }
    }
    return co;
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
    for(int i=1;i<=n;i++){
        visited[i]=0;
        a[i].eb(i);
    }
    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        a[x].eb(y);
        a[y].eb(x);
    }

    int cc = FindComponents();
    if(cc==1 && e==n-1)
        cout<<"YES";
    else
        cout<<"NO";
    cout<<endl;
}