#ifndef __CONTROLADOR_PID_ROBOTICA__
#define __CONTROLADOR_PID_ROBOTICA__


class Controlador
{
    double Kp = 0;
    double Kd = 0;
    double Ki = 0;
    double erroAnterior = 0;
    double somatorio = 0;
    
    Controlador();
    
    void Tunning(double _Kp, double _Ki = 0 , double _Kd = 0 );

    double LeiDeControle(double erro);


};



#endif