#include "stdlib.h"
#include "string.h"
#include "stdio.h"

enum status{
    READY = 0,
    BUSY = 1,
    ERROR = 2,
};
enum command{
    IDLE = 0,
    READ = 1,
    WRITE = 2,
    RESET = 4,
    DELETE = 8,
};
#define KIB 1024

unsigned char status = READY;
unsigned char command = IDLE;

unsigned char data[20];
unsigned  char internerspeicher[KIB];

void cmdWrite(){
    //Copy data to internalMemory and delete data
    strcat(&internerspeicher,&data);
    memset(&data[0],0, sizeof(data));
}
void cmdRead(){
    printf("%s", internerspeicher);

}
void cmdDelete(){
    memset(&data[0],0, sizeof(data));
    memset(&internerspeicher[0],0, sizeof(internerspeicher));
}

void test(){
        data[0] = 'm';
        data[1] = 'e';
        data[2] = 'i';
        data[3] = 'n';
        cmdWrite();
    //printf("%s", internerspeicher);
       data[0] = 't';
       data[1] = 'e';
       data[2] = 's';
       data[3] = 't';
        cmdWrite();
        cmdRead();
        cmdDelete();
        cmdRead();
}

