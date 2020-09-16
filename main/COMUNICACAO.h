class COMUNICACAO
{
  public:
    COMUNICACAO(){}
  
    void EnviaDadosMeteorologicos(double temperatura, double umidade){
     Serial.print("Envia dados Metereológicos - Temperatura ambiente: ");
     Serial.print(temperatura);
     Serial.print(" Umidade: ");
     Serial.println(umidade);
    }

    void EnviaDadosUsuario(double temperatura){
      Serial.print("Envia dados do Usuario - Temperatura: ");
      Serial.println(temperatura);
    }
  private: 
};
