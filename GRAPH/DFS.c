//Implementing Depth first search
#include<stdio.h>
int adj[10][10]={0}, visited[10]={0};
void DFS(int node){
    int i, n;
    visited[node]=1;
    printf("%d\t", node);
    for(i=1; i<=n; i++){
        if(adj[node][i]==1 && visited[i]==0){
            DFS(i);
        }
    }
}
int main(){
    int i, e, v, v1, v2, node;
    printf("\nEnter the number of vertex:");
    scanf("%d", &v);
    printf("\nEnter the number of edges:");
    scanf("%d", &e);
    for(i=1; i<=e; i++){
        printf("\nEnter the edges details:");
        scanf("%d%d", &v1, &v2);
        adj[v1][v2]=adj[v2][v1]=1;
    }
    printf("\nEnter the starting node:");
    scanf("%d", &node);
    DFS(node);
    return 0;
}