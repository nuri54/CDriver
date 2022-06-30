#include <string.h>
#include <stdio.h>
#include  <pthread.h>

enum status {
    READY = 0,
    BUSY = 1,
    ERROR = 2,
};
enum command {
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
static unsigned char internerspeicher[KIB];

static int indexInternerSpeicher = 0;

pthread_t IOManager;

void cmdWrite() {
    status = BUSY;
    command = IDLE;
    //Copy data to internalMemory
    memcpy(internerspeicher + indexInternerSpeicher, data, sizeof(data));

    // task wants us to use sizeof() below, but that would make printing
    // difficult, because C stops the string at the first 0 encounter
    indexInternerSpeicher += strlen(data);

    //delete data
    memset(&data[0], 0, sizeof(data));

    // no space left in "internerspeicher"
    if (indexInternerSpeicher > 1003) {
        status = ERROR;
    }
    else  status = READY;
}

void cmdRead() {
    command = IDLE;
    for (int i = 0; i < sizeof(internerspeicher)/ sizeof(data); i++) {
        memcpy(data, internerspeicher, sizeof(data));
        printf("%s\n", data);
    }
    status = READY;
}

void cmdDelete() {
    command = IDLE;
    memset(&data[0], 0, sizeof(data));
    memset(&internerspeicher[0], 0, sizeof(internerspeicher));
    indexInternerSpeicher = 0;
    status = READY;
}

void cmdReset() {
    command = IDLE;
    indexInternerSpeicher = 0;
    status = READY;
}

void *dataProcessor(void *arg) {
    // not sure what to do when status is BUSY and command is idle
    while (1) {
        if (status != BUSY) {
            if (status == ERROR) {
                fprintf(stderr, "");
            }
            if (command == WRITE && strlen(data) > 0) {
                cmdWrite();
            }
            if (command == DELETE) {
                cmdDelete();
            }
            if (command == RESET) {
                cmdReset();
            }
            if (command == READ) {
                cmdRead();
            }
        }
    }
    return NULL;
}

void init(){
    pthread_create(&IOManager, NULL, dataProcessor, NULL);
}


void test() {
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


