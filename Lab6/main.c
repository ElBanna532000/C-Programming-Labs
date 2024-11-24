#include <stdio.h>
#include <stdlib.h>
#include "conio.h"
#define DELETE 126 //4 keys
#define RIGHT 67 //3keys
#define LEFT 68 //3keys
#define HOME 72 //3 keys
#define BACKSPACE 127
#define SIZE 10
#define TERM '\0'
#define INSERT 45 

int main()
{
    char input[SIZE]={0};
    int cursor=0;
    int isInsertMode=0;
    //char choice;
    int length=0;

    printf("Enter anything:\n");
    while(1){
        int extKey;
        //int quadKey;
        //putchar(ch);
        char key = getch();

        if(key==27){
            getch();
            extKey=getch();
            //quadKey=getch();

            if(extKey == LEFT){
                if(cursor>0){
                    cursor--;   //1
                }
                system("clear");
                printf("%s", input);
                gotoxy(cursor+1, 1);
            }
            else if(extKey == RIGHT){
                if(cursor<length){
                    cursor++;
                }
                system("clear");
                printf("%s", input);
                gotoxy(cursor+1, 1);
            }

            else if(extKey == HOME){
                cursor=0;
                system("clear");
                printf("%s", input);
                gotoxy(1,1);
            }

            else if(extKey==51){
                int delKey=getch();
                if(delKey==DELETE){
                    if(cursor<length){
                    int i = cursor;
                    while(input[i]!=TERM){
                        input[i]=input[i+1];
                        i++;
                    }
                    length--;
                    system("clear");
                    printf("%s", input);
                    gotoxy(cursor+1, 1);
                    }
                }
            }
        }

        else if(key == BACKSPACE){
            if(cursor>0 ){
                int i = cursor-1;         // 012346
                while(input[i]!=TERM){    // abdef     c=3
                input[i]=input[i+1];
                i++;
                }
            cursor--;
            length--;
            system("clear");
            printf("%s", input);
            gotoxy(cursor + 1,1);
            }
        }
            //printf("\n\n\ncursor value is: %d", cursor);fff


        else if(key == INSERT){
            //enter insert mode
            if(!isInsertMode){  //if(1) --> normal mode
                //cursor--;
                length--;
                isInsertMode=1;
            }else{              //if(0) --> insert mode
                cursor++;
                length++;
                isInsertMode=0;
            }

            system("clear");
            printf("%s", input);
            gotoxy(cursor+1, 1);
        }

        else{
            if(cursor==length){     //mahmo
                input[cursor]=key;
                input[cursor+1]=TERM;
                length++;
                cursor++;
            }
            else if(cursor<length){
                int i=length;
                printf("%d\n\n\n", i);
                while(i>cursor){
                    input[i]=input[i-1];
                    i--;
                }
                input[cursor]=key;
                length++;
                cursor++;
                input[length]=TERM;
            }
            system("clear");
            printf("%s", input);
            gotoxy(cursor+1, 1);
        }
    }

    return 0;
}

