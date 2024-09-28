#ifndef REVERSE2_H
#define REVERSE2_H

struct node {
    int val;
    struct node *prev;
    struct node *next;
};

struct node *reverse(struct node *head);

#endif
