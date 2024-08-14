#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int matrix[100][100],opcount=0,wt[100],profit[100];

int max(int a,int b){

    return (a>b)?a:b;
}

int knapsack(int item,int cap){

    for(int i=0;i<=item;i++){

        for(int j=0;j<=cap;j++){

            if(i==0 || j==0){

                matrix[i][j]=0;
            }else{

                opcount++;

                if(j<wt[i]){

                    matrix[i][j]=matrix[i-1][j];
                }else{

                    matrix[i][j]=max(matrix[i-1][j],(matrix[i-1][j-wt[i]]+profit[i]));
                }
            }
        }
    }

    return matrix[item][cap];
}

void plotter(){

    FILE *f1;int n=0;

    int items,cap,maxprofit;

    while(1){

    printf("1.continue\n2.exit\n");
    scanf("%d",&n);

    if(n==1){

        printf("ENTER THE NUMBER OF ITEMS :\n");
        scanf("%d",&items);
        printf("ENTER THE CAPACITY : \n");
        scanf("%d",&cap);

        printf("ENTER THE DETAILS :\n");

        for(int i=1;i<items;i++){

            printf("ITEM %d :\n",i);
            printf("WEIGHT :\n");
            scanf("%d",&wt[i]);
            printf("profit :\n");
            scanf("%d",&profit[i]);
            printf("\n");
        }

        maxprofit=knapsack(items,cap);

        printf("Knapsack Table :\n");

        for(int i=0;i<=items;i++){

            for(int j=0;j<=cap;i++){

                printf("%d ",matrix[i][j]);
            }

            printf("\n");
        }

            printf("MAXIMUM PROFIT : %d \n",maxprofit);

            printf("\nItems included in the knapsack:\n");
            int w = cap;
            for(int i = items; i > 0; i--) {

                if(matrix[i][w] != matrix[i - 1][w]) {
                    printf("Item %d (Weight: %d, Profit: %d)\n", i, wt[i], profit[i]);
                    w -= wt[i];
                }
            }

            f1=fopen("k.txt","a");
            fprintf("%d %d\n",cap,opcount);
            fclose(f1);

    }
    else{
        exit(0);
    }
}

}

int main(){

    plotter();
    printf("genetrated ...\n");
}