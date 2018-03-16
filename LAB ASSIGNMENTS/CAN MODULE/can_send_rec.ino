#include <SPI.h>
#include "mcp_can.h"

const int SPI_CS_PIN = 9;

MCP_CAN CAN(SPI_CS_PIN);                                    // Set CS pin

void setup()
{
    Serial.begin(9600);

    while (CAN_OK != CAN.begin(CAN_500KBPS))              // init can bus : baudrate = 500k
    {
        Serial.println("CAN BUS Shield init fail");
        Serial.println("Init CAN BUS Shield again");
        delay(100);
    }
    Serial.println("CAN BUS Shield init ok!");
}

void loop()
{
    unsigned char len = 0;
    unsigned char buf[8];

    if(CAN_MSGAVAIL == CAN.checkReceive())            // check if data coming
    {
        CAN.readMsgBuf(&len, buf);    // read data,  len: data length, buf: data buf

        unsigned char canId = CAN.getCanId();
        unsigned char defId = 112;
        unsigned char defId2 = 113;
        if(canId == defId){
          Serial.println("-----------------------------");
          Serial.println("get data from ID: ");
          Serial.println(canId);

          Serial.println("Point 1");
          /*for(int i = 0; i<len; i++)    // print the data
          {
              Serial.print(buf[i]);
              Serial.print("\t");
          }*/
          Serial.print(buf[len-1]);
          Serial.println();
        }
        if(canId == defId2){
          Serial.println("-----------------------------");
          Serial.println("get data from ID: ");
          Serial.println(canId);
          Serial.println("Point 2");
          /*for(int i = 0; i<len; i++)    // print the data
          {
              Serial.print(buf[i]);
              Serial.print("\t");
          }*/
          Serial.print(buf[len-1]);
          Serial.println();
        }
        
    }

    if(Serial.available()) {
      Serial.println("sendind data");
      int index = Serial.read() - 49;
      Serial.println(index);
      // send data:  id = 0x00, standard frame, data len = 8, stmp: data buf
      unsigned long id[3] = {0x70, 0x71, 0x72};
      Serial.println(id[index]);
      SendData(id[index]);
      //CAN.sendMsgBuf(0x70,0, 8, stmp); 
    }
}

void SendData(unsigned long id) {
  Serial.println("Sending data...");
  unsigned char stmp[8] = {0, 1, 2, 3, 4, 5, 6, 7};
  CAN.sendMsgBuf(id,0, 8, stmp);
  delay(1000);
}

//END FILE
