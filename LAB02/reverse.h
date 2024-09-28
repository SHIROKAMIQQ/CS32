#ifndef REVERSE_H
#define REVERSE_H

struct node {
    int val;
    struct node *next;
};

struct node *reverse(struct node *head);

#endif
