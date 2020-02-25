#include "mbed.h"

DigitalOut led(LED1);
InterruptIn btn(PC_13);
EventQueue queue(32 * EVENTS_EVENT_SIZE);
Thread t;

void toggle(void) {
 
   
    led = !led;
}



int main() {
    led = 0;
    t.start(callback(&queue, &EventQueue::dispatch_forever));
    
    btn.rise(toggle);

    btn.fall(queue.event(toggle));
}