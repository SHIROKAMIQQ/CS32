#include "planet_k.h"
#include <stdlib.h>
#include <stdio.h>

long long int getLength(struct planet* head) {
    struct planet* current = head->portal;
    long long int length = 1;
    while (current != head) {
        length++;
        current = current->portal;
    }
    return length;
}

struct planet *planet_k(struct planet *x, long long int k){
    struct planet* current = x;
    k %= getLength(x);
    for (long long int i = 0; i < k; i++) {
        current = current->portal;
    }
    return current;
}

struct planet* BuildLinkedPlanets(int* dataset, int length){
    struct planet dummy;
    struct planet* current = &dummy;
    
    for (int i = 0; i < length; i++) {
        struct planet* newPlanet = (struct planet*)malloc(sizeof(struct planet));
        newPlanet->planet_id = dataset[i];
        newPlanet->portal = NULL;
        current->portal = newPlanet;
        current = current->portal; 
    }
    current->portal = dummy.portal;
    return dummy.portal;
}
void PrintLinkedPlanets(struct planet* head) {
    printf("%d ", head->planet_id);
    struct planet* current = head->portal;
    while (current != head) { 
        printf("%d ", head->planet_id);
        current = current->portal;
    }
    printf("\n");
}

int main() {
    int dataset[10] = {0,1,2,3,4,5,6,7,8,9};
    struct planet* linked_planets1 = BuildLinkedPlanets(dataset, 10);
    printf("%d\n", (planet_k(linked_planets1, 9))->planet_id); //9
    printf("%d\n", (planet_k(linked_planets1, 10))->planet_id); //0
    printf("%d\n", (planet_k(linked_planets1, 11))->planet_id); //1
    printf("%d\n", (planet_k(linked_planets1, 1000000000000000000))->planet_id); //0
}