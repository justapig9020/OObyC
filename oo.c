#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "oo.h"

static int frwd(veh_t v)
{
    v->dis -= v->spd;
    return v->dis <= 0;
}

static int get_dis(veh_t v)
{
    return v->dis;
}

static void show_veh(veh_t v)
{
    printf ("== veh ==\nspd %d\ndis %d\n", v->spd, v->dis);
}

static void show_car(veh_t v)
{
    car_t c;
    c = (car_t)v;
    printf ("== car ==\nspd %d\ndis %d\ncarry %d\n", c->v.spd, c->v.dis, c->cry);
}

static void show_moto(veh_t v)
{
    moto_t m;
    m = (moto_t)v;
    printf ("== moto ==\nspd %d\ndis %d\ntype %s\n", m->v.spd, m->v.dis, m->type);
}

veh_t new_veh(int s, int d)
{
    veh_t v;
    v = malloc (sizeof(struct vehicle));
    v->spd = s;
    v->dis = d;
    v->frwd = frwd;
    v->get_dis = get_dis;
    v->show = show_veh;
    return v;
}

car_t new_car(int s, int d, int cr)
{
    car_t c;
    veh_t v;

    c = malloc (sizeof(struct car));
    v = new_veh (s, d);

    memcpy (&(c->v), v, sizeof(struct vehicle));
    free (v);
    v = NULL;

    c->v.show = show_car;
    c->cry = cr;
    return c;
}

moto_t new_moto(int s, int d, char *ty)
{
    moto_t c;
    veh_t v;

    c = malloc (sizeof(struct moto));
    v = new_veh (s, d);

    memcpy (&(c->v), v, sizeof(struct vehicle));
    free (v);
    v = NULL;

    c->v.show = show_moto;
    c->type = ty;
    return c;
}
