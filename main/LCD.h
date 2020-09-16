class LCD{
  public:
    LCD(){}
    void AguardandoRFID(){
      ExibeMsg(msgAguardando);
    }

    void AproximeSe(){
      ExibeMsg(msgAproximeSe);   
    }

    void LendoTemperatura(){
      ExibeMsg(msgLendoTemperatura);
    }

    void Liberado(){
      ExibeMsg(msgLiberado);
    }

    void NaoLiberado(){
      ExibeMsg(msgNaoLiberado);
    }
  private:
    String ultimaMsg;
    String msgAguardando = "Aguardando RFID";
    String msgAproximeSe = "Aproxime-se";
    String msgLendoTemperatura = "Lendo Temperatura";
    String msgLiberado = "Liberado";
    String msgNaoLiberado = "Não Liberado";

    void ExibeMsg(String msg){
      if (ultimaMsg != msg){
        Serial.println(msg);
        ultimaMsg = msg;
      }
    }
};
