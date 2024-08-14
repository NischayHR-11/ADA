#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int matrix[100][100],opcount=0;

int min(int a,int b){

    return (a<b)?a:b;
}

void warshall(int n){

    for(int k=0;k<n;k++){

        for(int i=0;i<n;i++){

            for(int j=0;j<n;j++){

                opcount++;
                matrix[i][j]= matrix[i][j] || (matrix[i][k] && matrix[i][k]);
            }
        }
    }
}

void genratematrix(int n){

    srand(time(NULL));

    for(int i=0;i<n;i++){

        for(int j=0;j<n;j++){

            matrix[i][j]= (i==j)?0:rand()%n;
        }
    }
}

void plotter(){

    FILE *f1;

    for(int v=1;v<=10;v++){

        genratematrix(v);
        warshall(v);
        f1=fopen("w.txt","a");
        fprintf(f1,"%d %d\n",v,opcount);
        opcount=0;
        fclose(f1);
    }
}

int main(){

    plotter();
    printf("genrated ...\n");
}