#include<bits/stdc++.h>
#define N 3
using namespace std;

struct Node {
    Node* parent;
    int x,y;
    int min_cost;
    int level;
    int puzzle[N][N];
};

void printMatrix(int initial[N][N]){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<initial[i][j]<<" ";
        }cout<<endl;
    }
}
Node* newNode(int puzzle[N][N],int x,int y,int newX,int newY,int level,Node* parent){
    Node* node =new Node;
    node->parent=parent;
    
    memcpy(node->puzzle,puzzle,sizeof(node->puzzle));
    
    int temp=puzzle[x][y];
    puzzle[x][y]=puzzle[newX][newY];
    puzzle[newX][newY]=temp;
    
    node->x=newX;
    node->y=newY;
    node->level=level;
    node->min_cost=INT_MAX;
    
    return node;
}

int calculatecost(int initial[N][N],int final[N][N]){
    int count=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(!initial[i][j] && initial[i][j]!=final[i][j]){
                count++;
            }
        }
    }
    return count;
}

void displayPath(Node* root){
    if(root==NULL){
        return;
    }
    
    displayPath(root->parent);
    printMatrix(root->puzzle);

    // Now we need to calculate f(n) i.e equal to sum of h(n) + g(n) so we have
    cout << "f : " << root->min_cost + root->level << " | ";
    cout << "g :" << root->level << endl;
}
struct compare{
    bool operator() (const Node* LHS,const Node* RHS) const{
        return (LHS->min_cost + LHS->level) > (RHS->min_cost + RHS->level);
    }
};

bool isSafe(int x,int y){
    return (x>=0 && y>=0 && y<N && x<N);
}

int row[] = {1, 0, -1, 0};
int col[] = {0, -1, 0, 1};
void solve(int initial[N][N],int final[N][N],int x,int y){
    priority_queue<Node*,vector<Node*>,compare> pq;
    Node* root = newNode(initial,x,y,x,y,0,NULL);
    root->min_cost=calculatecost(initial,final);
    
    pq.push(root);
    while(!pq.empty()){
        Node* min= pq.top();
        pq.pop();
        
        if(min->min_cost == 0){
            displayPath(min);
            return;
        }
        for(int i=0;i<4;i++){
            if(isSafe(min->x+row[i],min->y+col[i])){
                Node* child = newNode(min->puzzle,x,y,min->x+row[i],min->y+col[i],min->level+1,min);
                child->min_cost=calculatecost(min->puzzle,final);
                pq.push(child);
            }
        }
    }
    
}
int main(){
    int initial[N][N]={
        {1,2,3},
        {5,6,0},
        {7,8,4}
    };
    
    int final[N][N]={
        {1,2,3},
        {5,8,6},
        {0,7,4}
    };
    
    int x=1,y=2;
    
    solve(initial,final,x,y);
    
}