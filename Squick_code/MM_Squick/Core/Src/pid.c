/*
 * Kod został sporządzony przez Doktora Wojciecha Domskiego
 * na potrzeby zajęć laboratorium Sterowniki Robotów
 * 6 semestr kierunku AiR wydział elektroniki
 *
 * Komentarze oraz treść głównych obliczeń uzupełniona w ramach zajęć przez
 * Patryka Szydlika ind. 248949
 *
 */

#include "pid.h"

void pid_init(cpid_t * pid, float p, float i, float d, uint8_t f, int32_t dt_ms)
{
    uint32_t k;
    pid->power = 1;

    for (k = 0; k < f; ++k){
        pid->power = pid->power * 2;
    }
    pid->f = f;
    pid->p = (int32_t) (p * pid->power);
    pid->i = (int32_t) (i * pid->power);
    pid->d = (int32_t) (d * pid->power);
    pid->p_val = 0;
    pid->i_val = 0;
    pid->d_val = 0;
    pid->p_max = INT32_MAX;
    pid->p_min = INT32_MIN;
    pid->i_max = INT32_MAX;
    pid->i_min = INT32_MIN;
    pid->d_max = INT32_MAX;
    pid->d_min = INT32_MIN;
    pid->e_last = 0;
    pid->sum = 0;
    pid->total_max = INT32_MAX;
    pid->total_min = INT32_MIN;
    pid->dt_ms = dt_ms;
}

int32_t pid_calc(cpid_t * pid, int32_t mv, int32_t dv)
{
    int32_t p, i, d, e, total;
    pid->mv = mv;
    pid->dv = dv;

    //Wyliczony blad (uchyb) regulacji jako roznica miedzy wartoscia zadana a zmierzona
    e = pid->dv - pid->mv;
    //Obliczenie czlonu proporcjonalnego jako iloczyn wspolczynnika p oraz uchybu
    p = pid->p * e;

    if (p > pid->p_max)
        p = pid->p_max;
    else if (p < pid->p_min)
        p = pid->p_min;

    pid->p_val = p >> pid->f;



    // Wartosc czlon calkujacego to suma dotychczasowych wartości tego członu zaktualizowana
    // o najnowsza wartosc. Czyli uchyb mnożony przez wspolczynnik oraz chwile czasu z zachowaniem jednostki sekund
    i = pid->sum;
    i += (pid->dt_ms * pid->i * e)/1000;


    if (i > pid->i_max){
        i = pid->i_max;
    }else if (i < pid->i_min){
        i = pid->i_min;
        pid->sum = i;
    };

    pid->i_val = i >> pid->f;

    // Wartosc czlonu rozniczkujacego to iloczyn wspolczynnika pomnozony przez zmiane uchyba (de) oraz
    // pomnozony przez iloraz 1 i stalej czasowej rozniczkowania ( w tym wypadku mozna zapisac po prostu
    // jako dzielenie przez stala czasowa)
    d = (pid->d * (e - pid->e_last))/pid->dt_ms;

    if (d > pid->d_max){
    	d = pid->d_max;
    }else if (d < pid->d_min){
    	d = pid->d_min;
    };


    pid->d_val = d >> pid->f;


    total = p + i + d;

    if (total > pid->total_max)
        total = pid->total_max;
    else if (total < pid->total_min)
        total = pid->total_min;

    pid->control = total >> pid->f;
    pid->e_last = e;

    return pid->control;
}




int32_t pid_scale(cpid_t * pid, float v)
{
    return v * pid->power;
}
