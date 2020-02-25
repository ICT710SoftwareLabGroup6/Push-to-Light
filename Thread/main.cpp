#include "mbed.h"
 
DigitalOut led1(LED1);
DigitalOut led4(LED4);
DigitalIn  But (USER_BUTTON);
Thread thread;
 
void led1_thread() {
    while (true) {
        led1 = !But; 
        wait(0.1);
    }
}
int main() {
    thread.start(led1_thread);
        while (true) {
        led4 = 1;
        wait(0.5); 
        led4 = 0;
        wait(0.5); 
    }
}
