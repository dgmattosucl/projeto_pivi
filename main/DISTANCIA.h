#include <HCSR04.h>
class DISTANCIA
{
public:
  bool distanciaValida;
  DISTANCIA(){
    triggerPin = 2;
    echoPin = 3;
    distanceSensor(triggerPin, echoPin);
    distanciaValidaMax = 10.0;
    distanciaValidaMin = 1.0;
  }

  bool EstaNaDistanciaValida(){
    if (distanceSensor.measureDistanceCm() > distanciaValidaMin && distanceSensor.measureDistanceCm() < distanciaValidaMax){
      return true;
    }else{
      return false;
    }    
  }
private:
  int triggerPin;
  int echoPin;
  double distanciaValidaMax;
  double distanciaValidaMin;
  UltraSonicDistanceSensor distanceSensor;
};