class SIRENE
{
public:
  SIRENE(){}

    void DispararSirene(){
      IniciarSirene();
      delay(2000);
      PararSirene();
    }
private:
    bool tempoDisparoSirene;

    void IniciarSirene(){
      Serial.println("Iniciando Sirene");
    }

    void PararSirene(){
      Serial.println("Parando Sirene");
    }
};
