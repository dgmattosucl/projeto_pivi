#include "RFID.h"
#include "LCD.h"
#include "COMUNICACAO.h"
#include "DISTANCIA.h"
#include "MLX90.h"
#include "SIRENE.h"
#include "DHT11.h"

//Variaveis de controle de tempo de envio de informações metereológicas
long intervaloEnvioDadosMet = 1000;
long ultimoEnvioDadosMet = 0;

//Variaveis de controle de tempo de leitura de temperatura de usuário
long duracaoLeituraTempUsuario = 10000;
long ultimaLeituraTempUsuario = 0;
bool temperaturaFoiLida = false;

//Tempo em que o arduíno foi ligado
unsigned long tempoEmExecucao;

//Hardware
RFID sensorRfid;
LCD displayLcd;
DISTANCIA sensorDistancia;
COMUNICACAO comunicacao;
MLX90 sensorMLX90;
SIRENE sirene;
DHT11 sensorDHT11;

//SETUP 
void setup()
{
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);  
}

//LOOP 
void loop()
{
  //Tempo que o app está em execução  
  tempoEmExecucao = millis();
  
  //Exibe mensagem de aguardando RIF
  displayLcd.AguardandoRFID();
  
  //Verifica se o sensor RFID leu algum dado
  if (sensorRfid.LeuDado())
  {
    //Armazena momento em que o RFID leu algum dado
    ultimaLeituraTempUsuario = tempoEmExecucao;

    //Inicia loop de verificação de leitura de dados do usuário e roda enquanto ainda ter tempo para tentar ler o usuário e a temperatura ainda não tiver sido lida
    while(aindaTentarLerTempUsuario() && !temperaturaFoiLida){
      //Tempo que o app está em execução  
      tempoEmExecucao = millis();

      //ExibindoMsgNoDisplay
      displayLcd.AproximeSe();

      //Se o usuário está na distância válida
      if (sensorDistancia.EstaNaDistanciaValida()){
        //Avisa à main que a temperaturaFoiLida;
        temperaturaFoiLida = true;

        //ExibindoMsgNoDisplay
        displayLcd.LendoTemperatura();
        delay(1000);

        //Verificando se a temperatura coletada foi válida
        if (sensorMLX90.TemperaturaValida()){
          //ExibindoMsgNoDisplay
          displayLcd.Liberado();
        }else{
          //ExibindoMsgNoDisplay
          displayLcd.NaoLiberado();

          //Disparando Sirene
          sirene.DispararSirene();          
        }               
      }

      //Enviando dados de leitura do usuário
      comunicacao.EnviaDadosUsuario(sensorMLX90.TemperaturaAtual());
    }

    //Variavel de controle para TESTES (SIMULA O LEITOR RFID SENDO LIDO ASSIM QUE O ARDUÍNO É INICIADO)
    sensorRfid.leuDado = false;
  }else{
    if (deveEnviarDados()){
      //Enviando dados de leitura do sensor meteorologico
      comunicacao.EnviaDadosMeteorologicos(sensorDHT11.TemperaturaAmbiente(), sensorDHT11.Umidade());
    }
  }
}

//Método que verifica o momento em que os dados deverão ser enviados
boolean deveEnviarDados(){
  if (tempoEmExecucao > (ultimoEnvioDadosMet + intervaloEnvioDadosMet)){    
    ultimoEnvioDadosMet = tempoEmExecucao;  
    return true;
  } else{
    return false;
  }
}

//Método que verifica se ainda está no período de ler a temperatura do usuário
boolean aindaTentarLerTempUsuario(){  
  if (tempoEmExecucao > (ultimaLeituraTempUsuario + duracaoLeituraTempUsuario)){
    return false;
  }else{
    return true;
  }
}
