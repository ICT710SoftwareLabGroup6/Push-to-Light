#include "mbed.h"

DigitalOut led1(LED1);
DigitalOut led2(LED2);
InterruptIn sw(PC_13);
EventQueue queue(32 * EVENTS_EVENT_SIZE);
Thread t;

void toggle(void) {
 
    led2 = !led2;

}
int main() {
	led2 = 0;          //initial value, set led2 turn off.
	
	t.start(callback(&queue, &EventQueue::dispatch_forever));
    sw.rise(toggle);                           // when you pushed blue button, the led2 turn on. 
    sw.fall(queue.event(toggle));            // when you released blue botton, the led2 turn off. 
	
	
	   //led1 blink.
	while(1) {                    
         led1 = 1; // LED is ON
         wait(0.2); // 200 ms
         led1 = 0; // LED is OFF
         wait(0.8); // 800 ms
     }


   
}
