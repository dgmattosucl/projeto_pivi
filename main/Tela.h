#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Inicializa o display no endereco 0x3F
LiquidCrystal_I2C lcd(0x3F,2,1,0,4,5,6,7,3, POSITIVE);

class Tela{
  public:
    Tela(){}
    void AguardandoRFID(int ln = 0){
      ExibeMsg(msgAguardando,0,ln);
    }

    void AproximeSe(int ln = 0){
      ExibeMsg(msgAproximeSe,0,ln);   
    }

    void LendoTemperatura(int ln = 0){
      ExibeMsg(msgLendoTemperatura,0,ln);
    }

    void Liberado(int ln = 0){
      ExibeMsg(msgLiberado,0,ln);
    }

     void ExibeTemp(double temperatura){
      ExibeMsg(msgTemperaturaLida+temperatura,0,1);
    }

    void NaoLiberado(int ln = 0){
      ExibeMsg(msgNaoLiberado,0,ln);
    }

    void lcdBacklight(int vt){
        lcd.setBacklight(vt);
    }

    void lcdShow(String txt, int pos, int ln) {
        lcd.setCursor(pos,ln);
        lcd.print(txt);
    }

    void clearLCDLine(int line)
    {               
        lcd.setCursor(0,line);
        for(int n = 0; n < 16; n++)
        {
                lcd.print(" ");
        }
    }
  private:
    String ultimaMsgL1;
    String ultimaMsgL2;
    String msgAguardando = "Aguardando RFID";
    String msgAproximeSe = "Aproxime-se";
    String msgLendoTemperatura = "Mendindo...";
    String msgLiberado = "Liberado";
    String msgNaoLiberado = "Não Liberado";
    String msgTemperaturaLida = "Temp: ";
    
    
    void ExibeMsg(String msg, int pos = 0, int ln = 0){
     
      if (UltimaMsgDiferente(msg,ln)){
        clearLCDLine(ln);
        Serial.println(msg);
        lcdShow(msg,pos,ln);
        SetUltimaMsg(msg,ln);
      }
    }
    
    bool UltimaMsgDiferente(String txt, int ln)
    {
      String chkMsg;
      if(ln == 0){
        chkMsg = ultimaMsgL1;
      }else{
        chkMsg = ultimaMsgL2;
      }
      
      if(txt == chkMsg){
        return false;
      }else{
        return true;
      } 
    }
    void SetUltimaMsg(String txt, int ln)
    {
       if(ln == 0){
        ultimaMsgL1 = txt;
       }else{
        ultimaMsgL2 = txt;
       }
    }
};
