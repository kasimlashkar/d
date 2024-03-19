#include<stdio.h>
void bfs(int);
void dfs(int);
int graph[10][10],n,visited[20];

int main()
{
	int i,j,start;
	printf("Enter the number of vertices\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
		visited[i]=0;
	printf("Enter the adjacency matrix\n");
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				scanf("%d",&graph[i][j]);
	printf("Enter starting vertex\n");
  	scanf("%d",&start);
	bfs(start-1);
	printf("Vertices which can be reached from vertex %d using BFS are: \n",start);
       	 for(i=0;i<n;i++)
			if(visited[i])
				printf("%4d",i+1);
	printf("\n");
	for(i=0;i<n;i++)
			visited[i]=0;
	dfs(start);
	printf("Vertices which can be reached from vertex %d using DFS are: \n",start);
       	 for(i=0;i<n;i++)
			if(visited[i])
				printf("%4d",i+1);

}


void bfs(int start)
{
  	int q[20],r=-1,f=0,fv,i;
  	visited[start]=1;
  	q[++r]=start;
	while(f<=r)
	{
			fv=q[f++];
			for(i=0;i<n;i++)
			{
				if(graph[fv][i]&&!visited[i])
				{
					visited[i]=1;
					q[++r]=i;
				}
			}

	}
}

void dfs(int start)
{
	int i;
	visited[start]=1;
   	for(i=0;i<n;i++)
	{
			if(graph[start][i]&&!visited[i])
				dfs(i);
 	}
}
