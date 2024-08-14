#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int matrix[100][100],visited[100],topo[100],indegree[100];
int a[100],front,rear,count,k,opcount;

void reset(int n){

    for(int i=0;i<n;i++){
        visited[i]=0;
        topo[i]=0;
        indegree[i]=0;
    }

    front=0;rear=-1;count=0;k=0;opcount=0;
}

void calculateIndegree(int n){

    for(int i=0;i<n;i++){

        for(int j=0;j<n;j++){

            opcount++;

            if(matrix[j][i]==1){
                indegree[i]++;
            }
        }

        if(indegree[i]==0){

            visited[i]=1;
            rear=(rear+1)%n;
            a[rear]=i;
            count++;
        }
    }

}


void SourceRemoval(int n){

    while(count!=0){

    int rem = a[front];
    front=(front+1)%n;
    count--;
    topo[k++]=rem;

    for(int i=0;i<n;i++){

        opcount++;

        if(matrix[rem][i]==1)
        indegree[i]--;

        if(indegree[i]==0 && visited[i]==0){
            visited[i]=1;
            rear=(rear+1)%n;
            a[rear]=i;
            count++;
        }
    }

    }

    

}

void plotter(int choice){

    FILE *f1;

    for(int v=0;v<=10;v++){

        for(int i=0;i<v;i++){

            for(int j=0;j<v;j++){

                if(choice==1){

                    matrix[i][j]= (i==j)?0:1;
                }else{
                    matrix[i][j]= (j==i+1)?1:0;
                }
            }
        }

        reset(v);
        calculateIndegree(v);
        SourceRemoval(v);

        if(choice==1){

            f1=fopen("b_sr.txt","a");
            fprintf(f1,"%d %d\n",v,opcount);
            fclose(f1);
        }else{

            f1=fopen("w_sr.txt","a");
            fprintf(f1,"%d %d\n",v,opcount);
            fclose(f1);
        }

    }
}

int main(){

    plotter(1);
    plotter(2);
    printf("generated ...\n");
}