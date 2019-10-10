#### Description
In this project, i performed serial communication using FSK (Frequency Shift Keying) with the help of IC TCM3105. I will explain you a brief explanation about FSK.

>FSK a frequency modulation scheme in which digital information is transmitted through discrete frequency changes of a carrier signal. The technology is used for communication systems such as telemetry, weather balloon radiosondes, caller ID, garage door openers, and low frequency radio transmission in the VLF and ELF bands. The simplest FSK is binary FSK (BFSK). BFSK uses a pair of discrete frequencies to transmit binary (0s and 1s) information.[2] With this scheme, the "1" is called the mark frequency and the "0" is called the space frequency.

<p align="center">
  <img  src="https://github.com/falithurrahman/fsk_serial_communication/blob/master/300px-Fsk.svg.png">
</p>

> Source : https://en.wikipedia.org/wiki/Frequency-shift_keying

The board i made was designed using Autodesk EAGLE using one layer printed circuit board. The schematic for the board and the board i designed can bee seen at the picture below. I will also attached the .sch and .brd file that i made at PCB folder. 

To perform serial communication we need 2 devices, each acts as transmitter and receiver. I will explain each of this device separatedly.
#### 1. Transmitter
In this project i used arduino nano as the microcontroller for transimtter that read the height data received from barometer sensor. The barometer sensor itself used I2C communication. Then the height data will be sent using serial communication to the receiver. 
#### 2. Receiver