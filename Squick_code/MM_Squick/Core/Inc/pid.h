#ifndef INC_PIDH
#define INC_PIDH


/*
 * Kod został sporządzony przez Doktora Wojciecha Domskiego
 * na potrzeby zajęć laboratorium Sterowniki Robotów
 * 6 semestr kierunku AiR wydział elektroniki
 *
 * Komentarze oraz treść głównych obliczeń uzupełniona w ramach zajęć przez
 * Patryka Szydlika ind. 248949
 *
 */


#include <stdint.h>

typedef struct {
    int32_t p;
    int32_t i;
    int32_t d;
    int32_t p_val;
    int32_t i_val;
    int32_t d_val;
    int32_t p_max;
    int32_t i_max;
    int32_t d_max;
    int32_t p_min;
    int32_t i_min;
    int32_t d_min;
    uint8_t f;
    uint32_t power;
    int32_t dv;
    int32_t mv;
    int32_t e_last;
    int32_t sum;
    int32_t total_max;
    int32_t total_min;
    int32_t control;
    int32_t dt_ms;
} cpid_t;

void pid_init(cpid_t * pid, float p, float i, float d, uint8_t f, int32_t dt_ms);
int32_t pid_calc(cpid_t * pid, int32_t mv, int32_t dv);
int32_t pid_scale(cpid_t * pid, float v);

#endif /* INC_PIDH */
