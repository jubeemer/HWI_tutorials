This is a short tutorial intended to explain the basics of the CAN protocol. 
For a more thorough explanation, see https://en.wikipedia.org/wiki/CAN_bus. 
The sections titled Data Transmission, ID Allocation, and Frames are most 
relevant for the work we will be doing in MRover.

What is CAN?
============
A CAN bus (Controller Area Network) is, in short, a bus that allows 
different microcontrollers to communicate with each other without the 
presence of a host computer. A "bus" can be thought of as a network of wires
that carry 1s and 0s between the microcontrollers connected to it. CAN is 
commonly used in vehicles, where there are many individual ECUs (Electronic 
Control Unit, or a car's computer) distributed throughout the vehicle. On
MRover, we use a CAN bus for communication between the Rover's onboard computer
and the Talon SRX motor controllers. CAN messages can be used to send drive
commands, read encoder values, and set internal variables of the Talons such as
control mode and closed-loop control gains.

What does a CAN Message look like?
==================================
There are two primary parts of a CAN message relevant to us: the arbitration ID
and the data frame. 

Arbitration ID
--------------
The arbitration ID is an 11 (or 29) bit identifier that serves as both a message
identifier and a sort of priority code. A CAN bus has at least two computers
communicating on it- often times both have messsages to transmit. Both cannot
transmit simultaneously, so each begins by transmitting their arbitration ID.
The lowest arbitration ID will win and be transmitted on the bus. The details
of how this works aren't super important - read the section 'Data Transmission'
at the wikipedia link above for details.

For communicating with the Talon SRX, the arbitration ID of the message is of
the 29 bit format. It consists of 20 bits specifying the "type" of message
followed by 6 bits specifying the device ID (3 bits are unused).

Data Frame
----------
The important part of a CAN message, the actual data to be transmitted, is
contained in the data frame. The data frame can be up to 8 bytes (64 bits)
long. For a CAN bus in industry, the manufacturer of the product will specify a
sort of library of messages, specifying the data contained in each and which
bits correspond to what data.

Here's a small example: imagine a 3 byte (24 bit) CAN message specifying the
current date. 
- Bits [4:0] (that notation means bits 4 through 0) are a 5-bit number
  specifying the day.
- Bits [8:5] are a 4-bit number specifying the day.
- Bits [21:9] are a 13-bit number specifying the year.

Starter Code
============
Fill out the provided starter code to practice with CAN messages. You'll need
to be comfortable with binary, hexadecimal, bit-shifting and bit-masking to
work with CAN messages on MRover. This tutorial will provide an intro to these
topics- feel free to ask for help if you haven't seen them before!