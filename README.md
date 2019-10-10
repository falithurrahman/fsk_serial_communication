#### Description
In this project, i performed serial communication using FSK (Frequency Shift Keying) with the help of IC TCM3105. I will explain you a brief explanation about FSK.

>FSK a frequency modulation scheme in which digital information is transmitted through discrete frequency changes of a carrier signal. The technology is used for communication systems such as telemetry, weather balloon radiosondes, caller ID, garage door openers, and low frequency radio transmission in the VLF and ELF bands. The simplest FSK is binary FSK (BFSK). BFSK uses a pair of discrete frequencies to transmit binary (0s and 1s) information.[2] With this scheme, the "1" is called the mark frequency and the "0" is called the space frequency.

<p align="center">
  <img  src="https://github.com/falithurrahman/fsk_serial_communication/blob/master/300px-Fsk.svg.png">
</p>

> Source : https://en.wikipedia.org/wiki/Frequency-shift_keying

The board i made was designed using Autodesk EAGLE using one layer printed circuit board. I will call this is *IC TCM3105 Board Module*. The schematic for the board and the board i designed can bee seen at the picture below. I will also attached the .sch and .brd file that i made at PCB folder. 

To perform serial communication we need 2 devices, each acts as transmitter and receiver. I will explain each of this device separatedly.
#### 1. Transmitter
In this project i used arduino nano as the microcontroller for transimtter that read the height data received from barometer sensor. The barometer sensor itself used I2C communication. The Tx and Rx pin of arduino nano will be connected to the TxD and RxD of the IC TCM3105 module. TxD and RxD means Transmitter Digital and Receiver Digital. Then the TxA and RxA will transmit the analog modulated signal through active speaker. TxA and RxA means Transmitter Analog and Receiver Analog. I connected active speaker and IC TCM3105 Board using 3.5mm audio jack. *But you have to remember using this method will make around you a little bit noisy.*

<p align="center">
  <img  src="https://github.com/falithurrahman/fsk_serial_communication/blob/master/transmitter_fsk.jpg">
</p>

#### 2. Receiver
I also used arduino nano connected with IC TCM3105 board for the receiver. The difference is, for the receiver i used pre-amp mic to receive the analog modulated signal that had been sent. This pre-amp mic is connected to the TxA and RxA. The TxD and RxD of the IC TCM3105 Module is connected to the Tx and Rx pin of arduino nano. Then for the final step i just need to connect LCD with arduino nano. If everything went well, the data read from barometer at the transmitter would be also available in the LCD of the receiver. 

<p align="center">
  <img  src="https://github.com/falithurrahman/fsk_serial_communication/blob/master/receiver_fsk.jpg">
</p>