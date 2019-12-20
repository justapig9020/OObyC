#ifndef _OO_H_
#define _OO_H_

typedef struct vehicle * veh_t;
typedef struct car * car_t;
typedef struct moto * moto_t;

struct vehicle
{
    int spd;        // speed
    int dis;        // distance to distination
    int (*frwd)(veh_t);
    int (*get_dis)(veh_t);
    void (*show)(veh_t);
};

struct car
{
    struct vehicle v;
    int cry;        // number of carry albe people
};

struct moto
{
    struct vehicle v;
    char *type;
};

veh_t new_veh(int, int);
car_t new_car(int, int, int);
moto_t new_moto(int, int, char *);

#endif
