class MLX90
{
  public:
    double temperaturaAtual;
    MLX90(){}

    bool TemperaturaValida(){
      if (TemperaturaAtual() > temperaturaMinAceitavel && TemperaturaAtual() < temperaturaMaxAceitavel){
         return true;
      }else{
        return false;
      }
    }

    double TemperaturaAtual(){
      return 35.5;
    }
  private:
    double temperaturaMaxAceitavel = 37;
    double temperaturaMinAceitavel = 35;
};
