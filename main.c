#include <stdlib.h>
#include <stdio.h>

#include "oo.h"


int main(void)
{
    veh_t v[2];

    v[0] = (veh_t)new_car (60, 120, 4);
    v[1] = (veh_t)new_moto (30, 120, "nk");

    for (int i=0; i<2; i++) {
        while (v[i]->get_dis (v[i])) {
            v[i]->frwd (v[i]);
            v[i]->show (v[i]);
            puts ("");
        }
        puts ("");
    }
    
    for (int i=0; i<2; i++) {
        free (v[i]);
        v[i] = NULL;
    }
    return 0;
}
