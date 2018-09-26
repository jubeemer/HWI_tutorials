#include <stdint.h>
#include <iostream>

using namespace std;

// This is a data type representing a CAN Message. Only 28 out of the 32 bits
// in the arbitration ID will be used.
struct CANMessage {
    uint32_t arbID;
    uint64_t frame;
};


int main() {
    
    // PART 1 (Write a message)
    // In this part of the tutorial, you will fill a CANMessage object with the
    // appropriate arbitration ID and data. We will use the 'date' format
    // outlined in the README.
    CANMessage date_msg1;

    // First, we'll write the arbitration ID. We will follow the format used 
    // for Talon SRXs described in the README.
    uint32_t msg_type = 0x0072A3D9 // 11100101010001111011001
    uint8_t device_id = 0x06       // 000110

    // TODO: Set the arbID data member of date_msg1 to the appropriate bit
    // string. The format, as outlined in the README, is 29 bits: 
    // - 6 bits [5:0] are the device ID 
    // - 23 bits [28:6] are the message type.

    uint32_t arbID = // TODO

    date_msg1.arbID = arbID;

    // Now, we'll write the data frame. The struct for a CAN Message has 64
    // bits for data. In our date message example, only the first 24 bits
    // are used.
    //
    // Set the frame data member of date_msg1 to the appropriate bit
    // string. The format, as outlined in the README, is 24 bits:
    // - 5 bits [4:0] specify the date (1 - 31)
    // - 4 bits [8:5] specify the month (1 - 12)
    // - 13 bits [21:9] specify the year (0 - 4096)
    // - 2 bits [23:22] are unused
    //
    // TODO: Set the data frame to represent the date 3 August 2007

    uint8_t day1 = // TODO
    uint8_t month1 = // TODO
    uint16_t year1 = // TODO

    uint64_t frame = // TODO

    date_msg1.frame = frame;


    // PART 2 (Decode a message)
    // In this part, you are provided a CANMessage object and you are to
    // decode the date.

    CANMessage date_msg2;
    date_msg2.arbID = 0x0072A3D9
    date_msg2.frame = 0x000F9B76

    uint8_t day2 = // TODO
    uint8_t month2 = // TODO
    uint16_t year2 = // TODO

    ///////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////


    // PART 1 CHECK
    cout << "Checking Part 1 - Arbitration ID..." << endl;
    if(date_msg1.arbID == 0x1CA8F545)
        cout << "PASS!" << endl;
    else
        cout << "FAILED - Arbitration ID Incorrect." << endl;

    cout << "Checking Part 1 - Data Frame..." << endl;
    if(date_msg1.frame == 0x000FAF03)
        cout << "PASS!" << endl;
    else
        cout << "FAILED - Data Frame Incorrect."


    // PART 2 CHECK
    cout << "Checking Part 2 - Day..." << endl;
    if(day2 == 0x15)
        cout << "PASS!" << endl;
    else
        cout << "FAILED - Day Incorrect." << endl;

    cout << "Checking Part 2 - Month..." << endl;
    if(day2 == 0x0B)
        cout << "PASS!" << endl;
    else
        cout << "FAILED - Month Incorrect." << endl;

    cout << "Checking Part 2 - Year..." << endl;
    if(day2 == 0x07CD)
        cout << "PASS!" << endl;
    else
        cout << "FAILED - Year Incorrect." << endl;




}