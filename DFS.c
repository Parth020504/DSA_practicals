#include<stdio.h>
#include<stdbool.h>
#define MAX 100

int adjacencyMatrix[MAX][MAX];
bool visited[MAX];
int vertices;

void initGraph(int v){
    vertices=v;
    for(int i=0;i<MAX;i++){
        visited[i]=false;
        for(int j=0;j<MAX;j++){
            adjacencyMatrix[i][j]=0;
        }
    }
}

void addEdge(int start,int end){
    adjacencyMatrix[start][end]=1;
    adjacencyMatrix[end][start]=1;
}

void dfs(int vertex){
    visited[vertex]=true;
    printf("%d ",vertex);

    for(int i=0;i<vertices;i++){
        if(adjacencyMatrix[vertex][i]==1 && !visited[i]){
            dfs(i);
        }
    }
}

int main(){
    int edges,startVertex;

    printf("\nEnter the number of vertices: ");
    scanf("%d",&vertices);

    initGraph(vertices);
    printf("\nEnter the number of edges: ");
    scanf("%d",&edges);

    for(int i=0;i<edges;i++){
        int start,end;
        printf("\nEnter the edge (start end)");
        scanf("%d %d",&start,&end);
        addEdge(start,end);
    }

    printf("\nEnter the starting vertex for DFS: ");
    scanf("%d",&startVertex);

    printf("\nThe DFS traversal for graph starting from vertex %d is ",startVertex);
    dfs(startVertex);

    return 0;
}