#include<stdio.h>
#include<stdlib.h>


int Euclid(int m,int n)
{
    int r;
    int count=0;
    while(n)
    {
    count++;
    r=m%n;
    m=n;
    n=r;
    }
    return count;
}

int consec(int m ,int n){

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

int modifiedEuclids(int m,int n){

    int count=1;

    if(m!=n){

        (m>n)?(m=m-n):(n=n-m);
        count++;
    }

    return count;
}

void plotter(int choice){

    int m,n,i,count,maxcount,mincount;
    FILE *f1,*f2;

    for(i=10;i<100;i+=10){

        mincount=10000;
        maxcount=0;

        for(m=2;m<=i;m++){

            for(n=2;n<=i;n++){

                count=0;

                if(choice==1){
                    count=Euclid(m,n);
                }else if(choice==2) {
                    count= modifiedEuclids(m,n);
                }else{
                    count= consec(m,n);
                }

                if(count> maxcount){
                    maxcount=count;
                }
                if(count<mincount){
                    mincount=count;
                }
            }
        }
        
        if(choice ==1){

            f1=fopen("B_E.txt","a");
            f2=fopen("W_E.txt","a");

        } else if(choice==2){

           f1=fopen("B_ME.txt","a");
            f2=fopen("W_ME.txt","a"); 
        }else{

            f1=fopen("B_C.txt","a");
            f2=fopen("W_C.txt","a");
        }

        fprintf(f1,"%d %d\n",i,mincount);
        fclose(f1);
        fprintf(f2,"%d %d\n",i,maxcount);
        fclose(f2);
    }

}

int main(){

    plotter(1);
    plotter(2);
    plotter(3);
    printf("Text Files Generated Successfuly..\n");
    return 0;
}