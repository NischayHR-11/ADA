#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int matrix[100][100],visited[100];
int count=0;int opcount=0;int dfscount=0;int iscylic=0;


void reset(int n){

    for(int i=0;i<n;i++)
    visited[i]=0;

    count=0;opcount=0;iscylic=0;dfscount=0;

}

void dfs(int n,int start,int parent){

    visited[start]=1;
    count++;

    for(int i=0;i<n;i++){

        opcount++;

        if(i!=parent && visited[i] && matrix[start][i] ){
            iscylic=1;
        }

        if(visited[i]==0 && matrix[start][i]){

            dfs(n,i,start);
        }
    }
}

void Plotter(int choice){

    FILE *f1;

    for(int v=0;v<=10;v++){

        for(int i=0;i<v;i++){

            for(int j=0;j<v;j++){

                if(choice==1){

                    matrix[i][j]= (i==j)?0:1; //best
                }else{
                    matrix[i][j]= (j==i+1)?1:0; //worst
                }
            }
        }


        reset(v);
        dfs(v,0,-1);

        if(choice==1){

            f1=fopen("b_dfs.txt","a");
            fprintf(f1,"%d %d\n",v,opcount);
            fclose(f1);

        }else{

            f1=fopen("w_dfs.txt","a");
            fprintf(f1,"%d %d\n",v,opcount);
            fclose(f1);
        }
    }


}

void tester(){

    int n;
    printf("ENTER THE NUMBER OF NODES REQUIRED : \n");
    scanf("%d",&n);

    printf("ENTER THE ADJACENCY MATRIX :\n");

    for(int i=0;i<n;i++){

        for(int j=0;j<n;j++){

            scanf("%d",&matrix[i][j]);
        }
    }

    printf("ADJACENCY MATRIX IS :\n");

    for(int i=0;i<n;i++){

        for(int j=0;j<n;j++){

            printf("%d ",&matrix[i][j]);
        }

        printf("\n");
    }

    dfscount++;

    reset(n);
    dfs(n,0,-1);

    if(count!=n){

        printf("GRAPH IS DISCONNECTED !!\n");
        int start=1;

        while(count==n){

            if(!visited[start]){

                dfscount++;
                dfs(n,start,-1);
                count++;
            }
        }

    }else{
        printf("GRAPH IS CONNECTED..\n");
    }

    printf("NUMBER OF COMPONENTS OF GRAPH : %d\n",dfscount);

    if(iscylic){
        printf("GRAPH IS CYLIC !! \n");
    }else{
        printf("Graph is Not Cyclic.. \n");
    }
}

int main(){

    Plotter(1);
    Plotter(2);
    printf("GENERATED...\n");
}