#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int count=0;

int partition(int a[],int s,int e){

    int p=a[s];
    int i=s+1,j=e;

    while(i<=j){

        while(a[i]<=p){

            count++;
            i++;
        }
        while(a[j]>p){

            count++;
            j--;
        }

        if(i<j){

        int t=a[i];
        a[i]=a[j];
        a[j]=t;

        }
    }

    int t=a[s];
    a[s]=a[j];
    a[j]=t;

    return j;

}

void quickSort(int a[],int s,int e){

    if(s<e){

        int p=partition(a,s,e);
        quickSort(a,s,p-1);
        quickSort(a,p+1,e);
    }
}

void plotter(){

    FILE *f1,*f2,*f3;
    srand(time(NULL));
    int n=4,*a;

    while(n<=1034){

        a=(int *)malloc(n*sizeof(int));

        //best

        for(int i=0;i<n;i++)
        a[i]=5;

        quickSort(a,0,n-1);
        f1=fopen("b_q.txt","a");
        fprintf(f1,"%d %d\n",n,count);
        count=0;
        fclose(f1);

        // worst

        for(int i=0;i<n;i++){
        
        a[i]=i+1;
        }

        quickSort(a,0,n-1);
        f2=fopen("w_q.txt","a");
        fprintf(f2,"%d %d\n",n,count);
        count=0;
        fclose(f2);

        //avg

        for(int i=0;i<n;i++)
        a[i]=rand()%n;

        quickSort(a,0,n-1);
        f3=fopen("avg_q.txt","a");
        fprintf(f3,"%d %d\n",n,count);
        count=0;
        fclose(f3);


        n=n*2;
    }
    
}

int main(){

    plotter();
    printf("GENERATED ..\n");
}