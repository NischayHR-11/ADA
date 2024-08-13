#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int count=0;

int StringMatch(char text[],char pattern[],int n,int m){

    count=0;

    for(int i=0;i<=n-m;i++){

        int j;

        for(j=0;j<m;j++){

            count ++;

            if(text[i+j]!=pattern[j]){
                break;
            }

        }

        if(j==m){
            return count;
        }
    }

    return count;
}

void plotter(){

    char text[1000];char *pattern;
    int m=10;
    FILE *f1,*f2,*f3;int n=1000;

    for(int i=0;i<n;i++)
    text[i]='a';

    while(m<=1000){

        pattern=(char *)malloc(m*sizeof(char));
        //best
        count=0;
        for(int i=0;i<m;i++){
            pattern[i]='a';
        }

        StringMatch(text,pattern,n,m);
        f1=fopen("b_s.txt","a");
        fprintf(f1,"%d %d\n",m,count);
        fclose(f1);

        //worst
        count=0;
        pattern[m-1]='b';

        StringMatch(text,pattern,n,m);
        f2=fopen("w_s.txt","a");
        fprintf(f2,"%d %d\n",m,count);
        fclose(f2);

        // avg
        count=0;
        for(int i=0;i<m;i++){
            pattern[i]= 97+rand()%3;
        }

        StringMatch(text,pattern,n,m);
        f3=fopen("avg_s.txt","a");
        fprintf(f3,"%d %d\n",m,count);
        fclose(f3);

        free(pattern);

        if(m<100)
        m=m+10;
        else
        m=m+100;
    }
}

int main(){

    plotter();
    printf("GENERATED ...\n");
}