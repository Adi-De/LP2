#include<bits/stdc++.h>
using namespace std;

class graph{
    int vertices;
    map<int,vector<int>> adjList;
    
    public:
    
    graph(){
        vertices=0;
    }
    graph(int n){
        vertices=n;
    }
    
    void addEdge(int i,int j){
        adjList[i].push_back(j);
        adjList[j].push_back(i);
    }
    
    void input(){
        for(int i=0;i<vertices;i++){
            int v1;
            cout<<"Enter Node:";
            cin>>v1;
            
            int cnt;
            cout<<"Enter No of adjacent nodes for "<<v1<<":";
            cin>>cnt;
            
            for(int j=0;j<cnt;j++){
                int v2;
                cout<<"Enter adjacent Node:";
                cin>>v2;
                addEdge(v1,v2);
                addEdge(v2,v1);
                cout<<endl;
            }
        }
    }
    
    int find(map<int,vector<int>> &level,int id){
        for(auto i:level){
            for(auto j:i.second){
                if(j==id){
                    return i.first;
                }
            }
        }
        return -1;
    }
    
    void bfs(){
        
        int st;
        cout<<"Enter Start Node:";
        cin>>st;
        
        map<int,int> visited;
        map<int,vector<int>> level;
        
        vector<int> ans;
        
        queue<int> q;
        q.push(st);
        visited[st]=1;
        level[0].push_back(st);
        while(!q.empty()){
            
            int t=q.front();
            q.pop();
            
            ans.push_back(t);
            
            for(auto u:adjList[t]){
                if(visited.find(u)==visited.end()){
                    
                    visited[u]=1;
                    int val=find(level,t);
                    level[val+1].push_back(u);
                    q.push(u);
                }
            }
        }
        
        for(auto i:ans){
            cout<<i<<" ";
        }
        
        for(auto i:level){
            cout<<"Level :"<<i.first<<":";
            for(auto j:i.second){
                cout<<j<<" ";
            }
            cout<<endl;
        }
        
    }
    void dfs_print(int st,vector<int> &ans,map<int,vector<int>> &level,map<int,int> &visited){
        visited[st]=1;
        ans.push_back(st);
        
        for(auto u:adjList[st]){
            if(visited.find(u)==visited.end()){
                visited[u]=1;
                int val=find(level,st);
                
                level[val+1].push_back(u);
                dfs_print(u,ans,level,visited);
            }
        }
    }
    void dfs(){
        map<int,int> visited;
        map<int,vector<int>> level;
        vector<int> ans;
        
        int st;
        cout<<"Enter start node:";
        cin>>st;
        level[0].push_back(st);
        dfs_print(st,ans,level,visited);
        
        for(auto i: ans){
            cout<<i<<" ";
        }
        cout<<"\n\n";
        cout<<"Level wise:"<<endl;
        
        for(auto i:level){
            cout<<"Level :"<<i.first<<"-->";
            for(auto j:i.second){
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }
};

int main(){
    
    graph g(6);
    g.input();
    
    g.dfs();
    g.bfs();
}
