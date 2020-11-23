#include <SoftwareSerial.h>
#include <RDM6300.h>

//Inicializa a serial nos pinos 2 (RX) e 3 (TX)
SoftwareSerial RFID(2, 3);



uint8_t Payload[6]; // used for read comparisons

class RFID
{
public:
  bool leuDado;
  String CardID;
  String RFID(){
    
    uint8_t c = RFID.read();
    
    if (RDM6300.decode(c))
    {
      CardID = "";
      Serial.print("ID TAG: ");
      //Mostra os dados no serial monitor
      for (int i = 0; i < 5; i++) {
        Serial.print(Payload[i], HEX);
        Serial.print(" ");
        CardID += String(Payload[i], HEX);
      }
      Serial.println();

      return CardID;
    }

    return "0";
  }

  bool LeuDado()
  {
    return leuDado;
  }
private:
};
