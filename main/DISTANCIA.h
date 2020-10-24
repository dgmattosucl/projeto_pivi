class DISTANCIA
{
public:
  DISTANCIA(){}

  bool EstaNaDistanciaValida(double distance){
    if (distance > 0 && distance <= 10){
      return true;
    }else{
      return false;
    }
  }
private:
  
};
