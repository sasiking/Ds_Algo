#include<bits/stdc++.h>
using namespace std;
int edge[21];
vector<int> adj[501];
vector<int> bestPair(int x,int y){
    vector<int> sol;
    for(int i=0;i<y;i++){
        for(int j=0;j<adj[x].size();j++){
            cerr<<"Hello "<<adj[x][j]<<" Edge = "<<edge[i];
            if(adj[x][j]==edge[i]){
                cerr<<"Pokodi";
                sol.emplace_back(x);
                sol.emplace_back(edge[i]);
                cerr<<sol[0]<<" Solution "<<sol[1]<<endl;
                return sol;
            }
        }
    }
    for(int i=0;i<y;i++){
        if(adj[edge[i]].size()>0){
            sol.emplace_back(edge[i]);
            sol.emplace_back(adj[edge[i]][0]);
            return sol;
        }
    }
    sol.emplace_back(0);
    sol.emplace_back(0);
    return sol;
}
void delEdge(int u, int v)
{
    for (int i = 0; i < adj[u].size(); i++) {
        if (adj[u][i] == v) {
            adj[u].erase(adj[u].begin() + i);
            break;
        }
    }
    for (int i = 0; i < adj[v].size(); i++) {
        if (adj[v][i] == u) {
            adj[v].erase(adj[v].begin() + i);
            break;
        }
    }
}
int main()
{
    int N; // the total number of nodes in the level, including the gateways
    int L; // the number of links
    int E; // the number of exit gateways
    cin >> N >> L >> E; cin.ignore();
    for (int i = 0; i < L; i++) {
        int N1; // N1 and N2 defines a link between these nodes
        int N2;
        cin >> N1 >> N2; cin.ignore();
        adj[N1].emplace_back(N2);
        adj[N2].emplace_back(N1);
    }
    for(int i=0;i<N;i++){
	    cerr<<i<<" -> ";
	for(auto x:adj[i])
		cerr<<x<<" ";
	cerr<<endl;
}
    for (int i = 0; i < E; i++) {
        int EI; // the index of a gateway node
        cin >> EI; cin.ignore();
        edge[i] = EI;
    }

    // game loop
    while (1) {
        int SI; // The index of the node on which the Skynet agent is positioned this turn
        cin >> SI; cin.ignore();
        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;
        vector<int> ans = bestPair(SI, E);
        cerr<<"Si ="<<SI;
        int a = ans[0];
        int b = ans[1];
        delEdge(a,b);
        cout<<a<<" "<<b<<endl;
    }
}