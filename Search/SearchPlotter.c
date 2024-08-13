#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int countb=0;

int LinearSearch(int a[],int key,int n){

    int count=0;

    for(int i=0;i<n;i++){

        count++;

        if(a[i]==key){
            return count;
        }
    }

    return count-1;
}

int binarySearch(int a[],int key,int s,int e){

    countb++;

    int mid=(s+e)/2;

    if(s>e){
        return countb-1;
    }

    if(a[mid]==key){

        return countb;
    }

    if(mid<key){

        return binarySearch(a,key,mid+1,e);
    }else{
        return binarySearch(a,key,s,mid-1);
    }

}

void plotter(int choice){

    int n=4;int count=0;int *a;
    srand(time(NULL));
    FILE *f1,*f2,*f3;

    if(choice==1){

        while(n<=1034){

        a=(int *)malloc(n*sizeof(int));

        //best

        for(int i=0;i<n;i++)
        a[i]=1;

        count=LinearSearch(a,1,n);

        f1=fopen("b_l.txt","a");
        fprintf(f1,"%d %d\n",n,count);
        fclose(f1);
        count=0;

        //avg

        for(int i=0;i<n;i++)
        a[i]=rand()%n;

        count=LinearSearch(a,rand()%n,n);

        f2=fopen("avg_l.txt","a");
        fprintf(f2,"%d %d\n",n,count);
        fclose(f2);
        count=0;

        //worst

        for(int i=0;i<n;i++)
        a[i]=1;

        count=LinearSearch(a,0,n);

        f3=fopen("w_l.txt","a");
        fprintf(f3,"%d %d\n",n,count);
        fclose(f3);
        count=0;

        n=n*2;

        }

        free(a);

    }else{


        while(n<=1034){

        a=(int *)malloc(n*sizeof(int));

        //best

        for(int i=0;i<n;i++)
        a[i]=1;
        int mid=(n-1)/2;
        a[mid]=0;

        countb=0;
        count=binarySearch(a,0,0,n-1);

        f1=fopen("b_b.txt","a");
        fprintf(f1,"%d %d\n",n,count);
        fclose(f1);

        //avg

        for(int i=0;i<n;i++)
        a[i]=i+1;

        countb=0;
        count=binarySearch(a,rand()%n,0,n-1);

        f2=fopen("avg_b.txt","a");
        fprintf(f2,"%d %d\n",n,count);
        fclose(f2);

        //worst

        for(int i=0;i<n;i++)
        a[i]=1;

        countb=0;
        count=binarySearch(a,0,0,n-1);

        f3=fopen("w_b.txt","a");
        fprintf(f3,"%d %d\n",n,count);
        fclose(f3);

        n=n*2;

        }
    }
}

int main(){

    plotter(1);
    plotter(2);
    printf("GENERTED ....\n");
}