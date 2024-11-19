#include <stdio.h>
#include <stdlib.h>
#include "conio.h"

int main()
{
    int size;
    int flag=1;
    while(flag){
        printf("Enter size of Matrix: ");
        if(scanf("%d",&size)!=1 || size%2==0 || size<=0){
            printf("Not a valid input, please try again (only odd postive integers are allowed)\n");
            while (getchar() != '\n');
        }else
            flag=0;
        }
    system("clear");
    printf("Matrix of size %dx%d", size,size);
    int row=1, col=(size+1)/2, num;
    for(num=1; num<=size*size; num++){
        gotoxy(col*4,row*3);
        sleep(2);
        printf("%d", num);

        if(num%size==0){
            row++;
            if(row>size)
                row=1;
        }
        else{
            row--;
            col--;

            if(row<1)
                row=size;
            if(col<1)
                col=size;
        }
    }
    return 0;
}
