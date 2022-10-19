#include<stdio.h>
int adj[10][10]={0}, visited[10]={0};
void BFS(int node){
    int q[10], i, n, f=-1, r=-1;
    visited[node]=1;
    q[++r]=node;
    while(f!=r){
        node=q[++f];
        printf("%d\t", node);
        for(i=1; i<=n; i++){
            if(adj[node][i]==1 && visited[i]==0){
                visited[i]=1;
                q[++r]=i;
            }
        }
    }
}
int main(){
    int e, v, v1, v2, node;
    printf("\nEnter the number vertex:");
    scanf("%d", &v);
    printf("\nEnter the number of edges:");
    scanf("%d", &e);
    for(int i=1; i<=e; i++){
        printf("\nEnter the vertex:");
        scanf("%d%d", &v1, &v2);
        adj[v1][v2]=adj[v2][v1]=1;
    }
    printf("\nEnter the starting node:");
    scanf("%d", &node);
    BFS(node);
    return 0;
}