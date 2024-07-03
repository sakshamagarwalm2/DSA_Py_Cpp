//Graph Representation

#include<bits/stdc++.h>
using namespace std;

//defining some local dtype tp short as pd in pandas
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define vpii vector<pii>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define ff first
#define ss second
#define setBits(x) builtin_popcount(x)

const int N = 1e5+2,MOD = 1e9+7;

vi adj[N];//adj list, adjm matrix

//Graph Creation
int main(){
    //n represents the no. of nodes and m is the no. of edges in the graph
    int n,m;
    cin>>n>>m;

    //now a 2D matrix will be creted where we store ki konsa node kis node se conected hai and isko list me save kar lenge using vector jo empty lilst banayega
    vvi adjm(n+1, vi(n+1,0));

    rep(i,0,m){
        int u,v;
        cin>>u>>v;
        adjm[u][v]=1;
        adjm[v][u]=1; //for undirected graph
    }

    cout<<"adjacency matrix of above graph is given by: "<<endl;

    //printing the adjacency list
    rep(i,1,n+1){
        rep(j,1,n+1){
        cout<<adjm[i][j]<<" ";}
        cout<<endl;

    }

    //to check is ther edge between 3 and 7
    if(adjm[3][7]) cout<<"Edge between 3 and 7 exists."<<endl;
    else cout<<"Edge between 3 and 7 does not exist."<<endl;

    cout<<endl<<endl;

    cin>>n>>m;
    rep(i,0,m){
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout<<"adjacency list of above graph is given by: "<<endl;

    rep(i,1,n+1){
        cout<<i<<" -> ";
        for(auto x:adj[i]) cout<<x<<" ";
        cout<<endl;
    }
    
return 0;
}