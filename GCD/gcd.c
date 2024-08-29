#include<stdio.h>
#include<stdlib.h>

int e(int m,int n){

    int count=0;

    while(n){

        count++;
        int r=m%n;
        m=n;
        n=r;
    }

    return count;
}

int me(int m ,int n){

    int count=1;

    while(m!=n){

        (m>n)?(m=m-n):(n=n-m);
        count++;
    }

    return count;
}

int consecutive(int m,int n){

    int count=0;

    int min = m < n ? m : n;

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

void plotter(int choice){

    int count,mincount,maxcount;
    FILE *f1,*f2;
    int i,m,n;

    for(i=10;i<100;i=i+10){

        mincount=99999;
        maxcount=0;

        for(m=2;m<=i;m++){

            for(n=2;n<=i;n++){

                count=0;
                
                switch (choice)
                {

                case 1:

                    count=e(m,n);
                    break;

                case 2:

                    count=me(m,n);
                    break;

                case 3:

                    count=consecutive(m,n);
                    break;

                default:
                    break;
                }

                
                if(count>maxcount)
                maxcount=count;

                if(count<mincount)
                mincount=count;
            }

        }

        
            switch (choice)
                {
                    case 1:

                        f1=fopen("b_e.txt","a");
                        f2=fopen("w_e.txt","a");
                        break;

                    case 2:

                        f1=fopen("b_me.txt","a");
                        f2=fopen("w_me.txt","a");
                        break;
                    
                    case 3:

                        f1=fopen("b_c.txt","a");
                        f2=fopen("w_c.txt","a");
                        break;

                    default:
                        break;
                }

                fprintf(f1,"%d\t%d\n",i,mincount);
                fprintf(f2,"%d\t%d\n",i,maxcount);
                fclose(f1);
                fclose(f2);
    }


}

int main(){

    plotter(1);
    plotter(2);
    plotter(3);
}