#include<stdio.h>
#include<stdlib.h>
#define size 11

int main()
{

    int A[size][size] = {
    /*1*/ { 0, 5, 6, 1, 0, 0, 0, 0, 0, 0, 0 },
    /*2*/ { 5, 0, 0, 0, 2, 0, 2, 0, 0, 0, 0 },
    /*3*/ { 6, 0, 0, 0, 1, 3, 0, 0, 0, 0, 0 },
    /*4*/ { 1, 0, 0, 0, 0, 2, 3, 0, 0, 0, 0 },
    /*5*/ { 0, 2, 1, 0, 0, 0, 0, 7, 7, 0, 0 },
    /*6*/ { 0, 0, 3, 2, 0, 0, 0, 7, 0, 3, 0 },
    /*7*/ { 0, 2, 0, 3, 0, 0, 0, 0, 4, 4, 0 },
    /*8*/ { 0, 0, 0, 0, 7, 7, 0, 0, 0, 0, 5 },
    /*9*/ { 0, 0, 0, 0, 7, 0, 4, 0, 0, 0, 4 },
    /*10*/{ 0, 0, 0, 0, 0, 3, 4, 0, 0, 0, 4 },
    /*11*/{ 0, 0, 0, 0, 0, 0, 0, 5, 4, 4, 0 }
    };
    int visited[size] = {0};
    int i, j, p=0, q=0;
    int arr[size]={1,2,3,4,5,6,7,8,9,10,11};
    int min;
    int flag=0;
    for(i=0;i<size;i++){
        for(j=0;j<size;j++){
            if(flag ==0 && A[i][j]!=0){
                flag=1;
                p=i;
                q=j;
                min=A[p][q];
            }
            else if(flag == 1 && A[i][j]<min && A[i][j]!=0){
                    p=i;
                    q=j;
                    min = A[i][j];
            }
        }
    }
    visited[p]=1;
    visited[q]=1;
    int flag1=0;
    int weight;
    int p1,q1,min1,kn=0;
    printf("MST edges: \n");
    printf("%d--%d \t (%d - weight)", arr[p], arr[q], A[p][q]);
    do{
        for(i=0;i<size;i++){
            for(j=0;j<size;j++){
                if(visited[i]==1 && visited[j]==0 && A[i][j]!=0){
                    if(flag1==0){
                        flag1 = 1;
                        p1 = i;
                        q1 = j;
                        min1=A[i][j];    
                    }else if(flag1 == 1 && A[i][j]< min1){
                        p1 = i;
                        q1 = j;
                        min1 = A[i][j];
                    }
                }
            }
        }
        visited[q1]=1;
        flag1=0;
        printf("\n%d--%d \t (%d - weight)", arr[p1], arr[q1], A[p1][q1]);

        kn++;
    }while(kn < size-2);

    return 0;
}