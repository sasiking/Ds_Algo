#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back
#define mp make_pair
#define fi  first
#define se second
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define f(i,n) for(int i = 0;i <(int)(n);++i)
#define fr(i,n) for(int i = (int)(n) - 1;i>=0;i--)
#define rep(i,a,b) for(int i = (int)(a); i<=(int) (b); ++i)
#define repr(i,a,b) for(int i = (int)(b); i>=(int) (a); i--)
#define deb(x) cout<<#x<< " = "<< x<<endl
#define ar array
#define ll long long

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
int visited[MAX_N];
queue<pi> q;

bool bfs(int src, int parent){
	visited[src] = 1;
	q.push({src,parent});

	while(!q.empty()){
		int tf = q.front().fi;
		int ts = q.front().se;
		q.pop();
		for(auto i:adj[tf]){
			if(!visited[i]){
				visited[i] = 1;
				q.push({i,tf});
			}
			else if(ts!=i)
				return true;
		}
	}
	return false;
}

void Solve(){
	int e;
	cin>>n>>e;
	rep(i,1,e){
		int x,y;
		cin>>x>>y;
		adj[x].eb(y);
		adj[y].eb(x);
	}
	int flag = 0;
	rep(i,1,n){
		if(!visited[i]){
			if(bfs(i,-1)){
				flag = 1;
				break;
			}
		}
	}
	if(!flag)
		cout<<"No Cycle Detected";
	else
		cout<<"Cycle Detected";
	cout<<endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("output.txt","w",stdout);
        freopen("error.txt","w",stderr);
    #endif
    Solve();
    return 0;
}