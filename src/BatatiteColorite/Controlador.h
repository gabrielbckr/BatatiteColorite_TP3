#ifndef __CONTROLADOR_PID_ROBOTICA__
#define __CONTROLADOR_PID_ROBOTICA__


class Controlador
{
    double Kp = 0;
    double Kd = 0;
    double Ki = 0;
    double TempoAnterior = 0;
    double SomatorioErro = 0;
    double ErroAnterior = 0;
    
    Controlador();
    
    void Tunning(double _Kp, double _Ki = 0 , double _Kd = 0 );

    double LeiDeControle(double erro);


};



#endif
