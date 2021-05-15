#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define f(i,n) for(int i = 0;i <(int)(n);++i)
#define fr(i,n) for(int i = (int)(n) - 1;i>=0;i--)
#define rep(i,a,b) for(int i = (int)(a); i<=(int) (b); ++i)
#define repr(i,a,b) for(int i = (int)(b); i>=(int) (a); i--)
#define ar array
#define ll long long
#define rnd(x) cout<<setprecision((int)(x) +1)
#define nl "\n"

typedef vector<int> vi;
typedef pair<int, int> pi;

#ifndef ONLINE_JUDGE
#define debug(x) cerr<<#x<<" = ";_print(x); cerr<<endl;
#else
#define debug(x)
#endif

template<class T> void _print(T a){
    cerr<<a; 
}

template<class T> void _print(vector<T> vi){
    cerr<<"[ ";
    for(T i:vi){
        _print(i);
        cerr<<" ";
    }
    cerr<<"]"; 
}

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

int n;
vi adj[MAX_N];

int indeg[MAX_N];
queue<int> q;

//Kahn's Algorithms

void toposort(){
	//Finding the indegree of every vertex
	rep(i,1,n){
		for(auto x:adj[i])
		indeg[x]++;
	}
	rep(i,1,n){
		if(indeg[i]==0)
			q.push(i);
	}
	int c=0;
	//Bfs solution implentation
	while(!q.empty()){
		int top = q.front();
		q.pop();
		c++;
		for(auto x:adj[top]){
			indeg[x]--;
			if(indeg[x]==0)
				q.push(x);
		}
	}
	if(c==n)
		cout<<"No Cycle";
	else
		cout<<"Cycle Detected";
	cout<<nl;
}

void Solve(){
	int e;
	cin>>n>>e;
	f(i,e){
	    int x,y;
	    cin>>x>>y;
	    adj[x].eb(y);
	}
	toposort();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("output.txt","w",stdout);
        freopen("error.txt","w",stderr);
    #endif
    int t = 1;
    //cin>>t;
    while(t--){
        Solve();
    }
}