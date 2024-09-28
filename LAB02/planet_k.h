#ifndef PLANET_K_H
#define PLANET_K_H

struct planet {
    int planet_id;
    struct planet *portal;
};

struct planet *planet_k(struct planet *x, long long int k);

#endif
