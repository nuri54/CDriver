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

static int  indexInternetSpeicher = 0;

void cmdWrite(){
    //Copy data to internalMemory and delete data
    //strcat(&internerspeicher,&data);
    memcpy(&internerspeicher + indexInternetSpeicher ,&data, strlen(data));
    indexInternetSpeicher += strlen(data) + 1 ;
    memset(&data[0],0, sizeof(data));
}
void cmdRead(){
    printf("%s\n", internerspeicher);

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
        data[4] = 'a';
        cmdWrite();
        cmdRead();
       data[0] = 't';
       data[1] = 'e';
       data[2] = 's';
       data[3] = 't';
        cmdWrite();
        cmdRead();
}

