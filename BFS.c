#include<stdio.h>
#include<conio.h>
#define MAX 5

void bfs(int adj[][MAX], int visited[], int start){
    int queue[MAX],front=-1,rear=-1,i;
    queue[++rear]=start;
    visited[start]=1;

    while(rear!=front){
        start=queue[++front];
        printf("%c\t",start+65);

        for(i=0;i<MAX;i++){
            if(adj[start][i]==1 && visited[i]==0){
                queue[++rear]=i;
                visited[i]=1;
            }
        }
    }
}

int main(){
    int visited[MAX]={0};
    int adj[MAX][MAX];

    printf("\nEnter the adjacency matrix: ");
    for(int i=0;i<MAX;i++){
        for(int j=0;j<MAX;j++){
        scanf("%d",&adj[i][j]);
        }
    }
    bfs(adj,visited,0);
    return 0;
}