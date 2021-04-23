#include "mbed.h"
#include "mbed_rpc.h"

/**
*  This example program has been updated to use the RPC implementation in the new mbed libraries.
*  This example demonstrates using RPC over serial
*/

//Use the RPC enabled wrapped class  - see RpcClasses.h for more info
RpcDigitalOut myled(LED1,"myled");
RpcDigitalOut myled2(LED2,"myled2");
RpcDigitalOut myled3(LED3,"myled3");
BufferedSerial pc(USBTX, USBRX);

int main() {
   //The mbed RPC classes are now wrapped to create an RPC enabled version - see RpcClasses.h so don't add to base class
   // receive commands, and send back the responses
   char buf[256], outbuf[256];
   int flag = 1;

   FILE *devin = fdopen(&pc, "r");
   FILE *devout = fdopen(&pc, "w");

   while(1) {
      memset(buf, 0, 256);      // clear buffer

      /*for(int i=0; ; i++) {
            char recv = fgetc(devin);
            if (recv == '\n') {
               printf("\r\n");
               break;
            }
            buf[i] = fputc(recv, devout);
      }*/
      if (flag) {
        buf[0] = '/';
        buf[1] = 'm';
        buf[2] = 'y';
        buf[3] = 'l';
        buf[4] = 'e';
        buf[5] = 'd';
        buf[6] = '3';
        buf[7] = '/';
        buf[8] = 'w';
        buf[9] = 'r';
        buf[10] = 'i';
        buf[11] = 't';
        buf[12] = 'e';
        buf[13] = ' ';
        buf[14] = '1';
        RPC::call(buf, outbuf);

        buf[0] = '/';
        buf[1] = 'm';
        buf[2] = 'y';
        buf[3] = 'l';
        buf[4] = 'e';
        buf[5] = 'd';
        buf[6] = '2';
        buf[7] = '/';
        buf[8] = 'w';
        buf[9] = 'r';
        buf[10] = 'i';
        buf[11] = 't';
        buf[12] = 'e';
        buf[13] = ' ';
        buf[14] = '0';
        flag = 0;
      } else {
          buf[0] = '/';
        buf[1] = 'm';
        buf[2] = 'y';
        buf[3] = 'l';
        buf[4] = 'e';
        buf[5] = 'd';
        buf[6] = '3';
        buf[7] = '/';
        buf[8] = 'w';
        buf[9] = 'r';
        buf[10] = 'i';
        buf[11] = 't';
        buf[12] = 'e';
        buf[13] = ' ';
        buf[14] = '0';
        RPC::call(buf, outbuf);

        buf[0] = '/';
        buf[1] = 'm';
        buf[2] = 'y';
        buf[3] = 'l';
        buf[4] = 'e';
        buf[5] = 'd';
        buf[6] = '2';
        buf[7] = '/';
        buf[8] = 'w';
        buf[9] = 'r';
        buf[10] = 'i';
        buf[11] = 't';
        buf[12] = 'e';
        buf[13] = ' ';
        buf[14] = '1';
        flag = 1;
      }
      //printf("%s\r\n", buf);
      ThisThread::sleep_for(1s);
      //Call the static call method on the RPC class
      RPC::call(buf, outbuf);
      //printf("%s\r\n", outbuf);
   }
}