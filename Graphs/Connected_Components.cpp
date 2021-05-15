#include <bits/stdc++.h>
using namespace std;
 
#define eb emplace_back
#define fi  first
#define se second
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define debug(x) cerr<<#x<<x;
#define forn(i,n) for(int i = 0;i <(int)(n);++i)
#define fora(i,a,b) for(int i = (int)(a); i<=(int) (b); ++i)
#define ar array
#define ll long long
//#define ps(x,y) fixed<<setprecision(y)<<x
 
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
    if(visited[point])
        return;
    visited[point] = 1;
    for(auto x:a[point])
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
    for(auto x:a){
        for(auto i:x)
            cout<<i<<" ";
    }
    cout<<endl;
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
    cout<<FindComponents()<<endl;
}