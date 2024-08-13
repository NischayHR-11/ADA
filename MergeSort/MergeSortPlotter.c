#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int count=0;

void merge(int a[],int s,int e){

    int mid=(s+e)/2;
    int i=s;
    int j=mid+1;
    int t[e];int k=s;
    
    while(i<=mid && j<=e){

        count++;

        if(a[i]<a[j]){

            t[k++]=a[i++];
        }else{

            t[k++]=a[j++];
        }
    }

    while(i<=mid){
        t[k++]=a[i++];
    }

    while(j<=e){
        t[k++]=a[j++];
    }

    for(int i=s;i<=e;i++){

        a[i]=t[i];
    }
}

void MergeSort(int a[],int s,int e){

    if(s<e){

        int mid=(s+e)/2;
        MergeSort(a,s,mid);
        MergeSort(a,mid+1,e);
        merge(a,s,e);
    }
}

void worst(int arr[],int s,int e){

    if(s<e){
        
    int i,j;
    int mid=(s+e)/2;
    int n1=mid-s+1;
    int n2=e-mid;
    int a[n1],b[n2];

    for(i=0;i<n1;i++){
        a[i]=arr[2*i];
    }

    for(i=0;i<n2;i++){
        b[i]=arr[2*i+1];
    }

    worst(arr,s,mid);
    worst(arr,mid+1,e);

    for(int i=0;i<n1;i++){
        arr[i]=a[i];
    }

    for(int i=mid+1;i<n2;i++){
        arr[i]=b[i];
    }

    }

}

void plotter(){

    FILE *f1,*f2,*f3;
    srand(time(NULL));
    int r,*a,n=4;

    while(n<=1034){

        a=(int *)malloc(n*sizeof(int));

        //best

        for(int i=0;i<n;i++)
        a[i]=i+1;

        MergeSort(a,0,n-1);
        f1=fopen("b_m.txt","a");
        fprintf(f1,"%d %d\n",n,count);
        count=0;
        fclose(f1);

        //avg

        for(int i=0;i<n;i++)
        a[i]=rand()%n;

        MergeSort(a,0,n-1);
        f2=fopen("avg_m.txt","a");
        fprintf(f2,"%d %d\n",n,count);
        count=0;
        fclose(f2);

        //worst

        worst(a,0,n-1);
        MergeSort(a,0,n-1);
        f3=fopen("w_m.txt","a");
        fprintf(f3,"%d %d\n",n,count);
        count=0;
        fclose(f3);

        n=n*2;

    }

}

int main(){

    plotter();
    printf("GENERATED ....\n");
}