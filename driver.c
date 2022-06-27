#include "stdlib.h"

enum status{
    READY = 00,
    BUSY = 01,
    ERROR = 02,
}statusConst;
enum command{
    IDLE = 00,
    READ = 01,
    WRITE = 02,
    RESET = 04,
    DELETE = 8,
}commandConst;
#define KIB 1024

unsigned char status = READY;
unsigned char command = IDLE;

unsigned char data[20];
unsigned  char internerspeicher[KIB];

void loop(){

    }


