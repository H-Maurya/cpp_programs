//Implement adjacency list representation of a user input graph. Apply BFT and DFT algorithms for this representation.
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FileIO freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

class node{
    public:
    int data;
    node* next = NULL;
    node(){};
    node(int data){
        this->data = data;
    }
};

void insert(node* &head,int data){
    node* temp = head;
    while(temp->next){
        temp = temp->next;
    }
    temp->next = new node(data);
}

void print(node* head){
    while(head){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

void printAdjList(node *adj,int n){
    for(int i=0;i<n;i++){
        print((adj+i));
    }
}

void BFS(node* graph,int n){
    int pred[n+1],dist[n+1],color[n+1];
    for(int i=1;i<=n+1;i++){
        pred[i] = -1;
        dist[i] = INT_MAX;
        color[i] = 0;
    }
    color[1] = 1;
    dist[1] = 0;
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        node* temp = graph + u - 1;
        while(temp){
            if(color[temp->data] == 0){
                dist[temp->data] = dist[u] + 1;
                pred[temp->data] = u;
                color[temp->data] = 1;
                q.push(temp->data);
            }
            temp = temp->next;
        }
        color[u] = 2;
    }
    cout<<endl;
    for(int i=1;i<=n;i++){
        cout<<dist[i]<<" ";
    }
}

void DFS(node* graph,int n){
    int pred[n+1],dist[n+1],color[n+1];
    for(int i=1;i<=n+1;i++){
        pred[i] = -1;
        dist[i] = INT_MAX;
        color[i] = 0;
    }
    color[1] = 1;
    dist[1] = 0;
    stack<int> s;
    s.push(1);
    while(!s.empty()){
        int u = s.top();
        s.pop();
        node* temp = graph + u - 1;
        while(temp){
            if(color[temp->data] == 0){
                dist[temp->data] = dist[u] + 1;
                pred[temp->data] = u;
                color[temp->data] = 1;
                s.push(temp->data);
            }
            temp = temp->next;
        }
        color[u] = 2;
    }
    cout<<endl;
    for(int i=1;i<=n;i++){
        cout<<dist[i]<<" ";
    }
}

int main(){
    
    int n,edge;
    cout<<"Enter number of elements and edges."<<endl;
    cin>>n>>edge;
    node arr[n];
    for(int i=0;i<n;i++){
        arr[i].data = i+1;
    }
    for(int i=1;i<=edge;i++){
        int v1,v2;
        cout<<"Enter the path : ";
        cin>>v1>>v2;
        for(int i=0;i<n;i++){
            if(arr[i].data == v1){
                node* toSend = (arr+i);
                insert(toSend,v2);
            }
            if(arr[i].data == v2){
                node* toSend = (arr+i);
                insert(toSend,v1);
            }
        }
    }
    cout<<"Adjacency List "<<endl;
    printAdjList(arr,n);
    cout<<"Breadth First Traversal : ";
    BFS(arr,n);
    cout<<endl;
    cout<<"Depth First Traversal : ";
    DFS(arr,n);
    return 0;
}
