#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int count=0;

int bubbleSort(int a[],int n){

for(int i=0;i<n-1;i++){

    for(int j=0;j<n-i-1;j++){

        if(a[j]>a[j+1]){
            count++;
            int t=a[j];
            a[j]=a[j+1];
            a[j+1]=t;
        }
    }
}

return count;

}

int insertionSort(int a[],int n){

    for(int i=1;i<n;i++){

        int s=a[i];
        int j=i-1;
        while(j>=0 && s<a[j]){
            count++;
            a[j+1]=a[j];
            j--;
        }

        a[j+1]=s;
    }

    return count;
}

int selectionSort(int a[],int n){

    for(int i=0;i<n;i++){

        int s=i;
        for(int j=i+1;j<n;j++){

            count++;

            if(a[j]<a[s]){
                s=j;
            }
        }

        int t=a[i];
        a[i]=a[s];
        a[s]=t;

    }
}

int plotter(int choice){

    int r,*a,n=4;
    FILE *f1,*f2,*f3;
    srand(time(NULL));

    while(n<=1034){

    if(choice==1){

        a=(int *)malloc(n*sizeof(int));

        //best

        for(int i=0;i<n;i++)
        a[i]=i+1;

        count=0;
        r=bubbleSort(a,n);
        f1=fopen("b_b.txt","a");
        fprintf(f1,"%d %d\n",n,count);
        fclose(f1);

        //avg

        for(int i=0;i<n;i++)
        a[i]=rand()%n;

        count=0;
        r=bubbleSort(a,n);
        f2=fopen("avg_b.txt","a");
        fprintf(f2,"%d %d\n",n,count);
        fclose(f2);

        //worst

        for(int i=0;i<n;i++)
        a[i]=n-i;

        count=0;
        r=bubbleSort(a,n);
        f3=fopen("w_b.txt","a");
        fprintf(f3,"%d %d\n",n,count);
        fclose(f3);

        n=n*2;

    }else if (choice==2){

     a=(int *)malloc(n*sizeof(int));

        //best

        for(int i=0;i<n;i++)
        a[i]=i+1;

        count=0;
        r=insertionSort(a,n);
        f1=fopen("b_i.txt","a");
        fprintf(f1,"%d %d\n",n,count);
        fclose(f1);

        //avg

        for(int i=0;i<n;i++)
        a[i]=rand()%n;

        count=0;
        r=bubbleSort(a,n);
        f2=fopen("avg_i.txt","a");
        fprintf(f2,"%d %d\n",n,count);
        fclose(f2);

        //worst

        for(int i=0;i<n;i++)
        a[i]=n-i;

        count=0;
        r=bubbleSort(a,n);
        f3=fopen("w_i.txt","a");
        fprintf(f3,"%d %d\n",n,count);
        fclose(f3);

        n=n*2;

    }else{
                
        for(int i=0;i<n;i++)
        a[i]=rand()%n;

        count=0;
        r=bubbleSort(a,n);
        f1=fopen("General_s.txt","a");
        fprintf(f1,"%d %d\n",n,count);
        fclose(f1);
        n=n*2;
    }

    }

}

int main(){

    plotter(1);
    plotter(2);
    plotter(3);
    printf("SELECTION SORT HAS ONLY ONE GENERAL GRAPH\n");
    printf("GENERATED ....\n");

    
}