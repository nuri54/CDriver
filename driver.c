#include "stdlib.h"
// status
#define ready 00
#define busy 01
#define error 02

// command
#define idle 00
#define read 01
#define write 02
#define reset 04
#define delete 08

#define Kib 1024

unsigned char status;
unsigned char command;
//unsigned char data[20];
unsigned  char internerspeicher[20];
unsigned char *data;
void init() {
    data = malloc(20);
    status = ready;
    command = idle;
}

void loop(){
    if(command==write){
        //
    }
}

