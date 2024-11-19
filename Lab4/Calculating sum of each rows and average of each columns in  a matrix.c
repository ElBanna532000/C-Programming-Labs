#include<stdio.h>
#include<stdlib.h>

int main(){

    int row=3, col=4, flag;
    float avg;
    int matrix[row][col];
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            flag=1;
            while(flag){
                printf("Enter a number for index [%d][%d]: ",i,j);
                if(scanf(" %d", &matrix[i][j])!=1){
                    printf("Not a valid input, please try again\n");
                    while (getchar() != '\n');
                }
                else
                    flag=0;
            }
        }
    }

    for(int i=0; i<row; i++){
        int sumRow=0;
        for(int j=0; j<col; j++){
            sumRow+=matrix[i][j];
        }
        printf("Sum of row %d is: %d\n", i, sumRow);
    }

    for(int j=0; j<col;j++){
        int sumCol=0, count=0;
        for(int i=0; i<row; i++){
            sumCol+=matrix[i][j];
            count++;
        }
        avg=(float)sumCol/(float)count;
        printf("Average of column %d is: %.2f\n", j, avg);

    }

    return 0;
}
