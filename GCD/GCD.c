#include<stdio.h>
#include<stdlib.h>


int modifiedEuclids(int m ,int n){

    int count=0;
    int min=m<n?m:n;

    while(1){
        count++;
        if(m%min==0){
            count++;
            if(n%min==0){
                return count;
            }
        }

        min--;
    }


}

int consec(int m,int n){

    int count=1;

    if(m!=n){

        (m>n)?(m=m-n):(n=n-m);
        count++;
    }

    return count;
}

void plotter(int choice){

    int m,n,count,maxcount,mincount;
    FILE *f1,*f2;


}