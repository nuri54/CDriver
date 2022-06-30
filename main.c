#include "driver.c"
#include <unistd.h>

//  inputData -> data -> internerspeicher
void dataWrite(unsigned char inputData[]){
    int iterationcount = sizeof(inputData)/20;
    if(sizeof(inputData)%20 != 0 ) iterationcount++;

    for (int i = 0; i < iterationcount; i++) {
        for (int j = 0; j < 20 ; j++) {
            data[i] = 'x';
        }
        command = WRITE;
        status = BUSY;
        // @ TODO status == ERROR case
        if(status != READY) sleep(2);
    }
}
//  loop(internerspeicher -> data and output)
void dataRead(){
    command = READ;
    status = BUSY;
    if(status != READY) sleep(2);
}
// sets read/write pointer from internerspeicher to 0
void dataReset(){
    command = RESET;
    status = BUSY;
    if(status != READY) sleep(2);
}
// Deletes everything inside data and internerspeicher and sets pointer to 0
void dataDelete(){
    command = DELETE;
    status = BUSY;
    if(status != READY) sleep(2);
}
int main(int argc, char const *argv[]) {
    init();

    unsigned char data512[512];
    unsigned char data2048[2048];
    unsigned char data252[252];

    dataWrite(data512);
    dataRead();
    dataReset();
    dataDelete();

    //dataWrite(data2048);
    //dataWrite(252);



    return 0;

}
