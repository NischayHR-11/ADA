#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int count=0;int bfscount=0;int iscylic=0;int opcount=0;
int visited[100];
int matrix[100][100];

void bfs(int n,int start){

    int queue[n],parent[n];

    int rear=-1,front=-1;
    visited[start]=1;
    count++;
    queue[++rear]=start;
    parent[rear]=-1;

    while(front!=rear){

        start=queue[++front];
        int parentnode=parent[front];

        printf("-->%c",65+start);

        for(int i=0;i<n;i++){

            opcount++;

            if(i!=parentnode && matrix[start][i] && visited[i]){
                iscylic=1;
            }

            if(matrix[start][i] && visited[i]==0){

                queue[++rear]=i;
                visited[i]=1;
                parent[i]=start;
                count++;
            }
        }
    }
}

void reset(int n){

    for(int i=0;i<n;i++)
    visited[i]=0;

    opcount=0;count=0;iscylic=0;bfscount=0;
}

void plotter(int choice){

   
   FILE *f1;

   for(int v=1;v<=10;v++){


    for(int i=0;i<v;i++){

        for(int j=0;j<v;j++){

            if(choice==1){

                matrix[i][j]= (i==j)?0:1;  //best case (compete matrix)
            }else{
                matrix[i][j]= (j==i+1)?1:0;  //worst case (sparse matrix) (linear matrix);
            }
        }
    }

    reset(v);
    bfs(v,0);

    if(count!=v){

        int start=1;

        while(count !=v){

            if(visited[start]!=1){

                bfs(v,start);
                count++;
            }

            start++;
        }

    }

    if(choice==1){

        f1=fopen("b_bfs.txt","a");
        fprintf(f1,"%d %d\n",v,opcount);
        fclose(f1);

    }else{

        f1=fopen("w_bfs.txt","a");
        fprintf(f1,"%d %d\n",v,opcount);
        fclose(f1);
    }

   }

}

void tester() {
    int n, i, j, start;
    printf("Enter the number of nodes in the matrix:\n");
    scanf("%d", &n);
    printf("Enter the Adjacency Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("The Adjacency Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    reset(n); // Reset data before traversal
    printf("Breadth First Search Traversal:\n");
    bfs(n, 0);
    bfscount++;

    if (count == n) {
        printf("\nGraph is connected.\n");
    } else {
        printf("\nThe matrix is not connected.\n");
        start = 1;
        while (count != n) {
            if (visited[start] != 1) {
                bfs(n, start);
                bfscount++;
                printf("\n");
            }
            start++;
        }
    }

    printf("\nThe number of components in the matrix is %d\n", bfscount);
    if (iscylic) {
        printf("\nThe matrix is cyclic\n");
    } else {
        printf("\nThe matrix is acyclic\n");
    }
}

int main(){

    plotter(1);
    plotter(2);
    printf("GENERATED ...\n");
}