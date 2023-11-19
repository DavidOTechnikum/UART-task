AUTHOR:  David OBERLEITNER, ic22b011@technikum-wien.at

DATE:    November 17, 2023

SUMMARY: This project aims to fullfil the UART Task.

## Circuitry

You do not need to add/change any components or connection wires to the Nucleo Development Board. 

---

## Pins

The following pins are used for this project:

+ A6, A8 are configured as outputs to drive the RGB LED (red, green)

---

## Timers

The following timers are used for this project: 

+ TIM6

---

## Other peripherals

The following peripherals are used for this project: 

+ USART2
+ RNG

---

## Usage

The following steps outline the usage of this project:

+ Unzip the project
+ Flash the project onto the Nucleo Development Board
+ Start a terminal program (hterm recommended)
+ Connect terminal to port and ensure that on entering an input, "\n" is sent. 
+ Once the connection is established, the terminal should receive the message READY. 
+ Now a request for a random number can be sent in the following frame format: "#r,<minimum>:<maximum>\n"
+ In case of wrong format, the Nucleo responds with "NACK\n" and the red LED flashes. 
+ In case of correct format and numbers, the Nucleo responds with "ACK\n" and the green LED flashes.
+ Then, the Nucleo responds with a reply frame of the following format: "#a,<random number>\n"
+ The Nucleo waits for an "ACK\n". If any other message is sent, it will resend the reply frame and the red LED flashes. 
+ In case of "ACK\n", the green LED flashes and the Nucleo resets back to ready for new requests. 

---

## Notes

+ All the functions dealing with the hardware directly as well as summarizing functions were put
+ into the main.c-file. All the functions dealing with the frame itself were put into frame_func.c. 