#ifndef SORT_PAPERS_H
#define SORT_PAPERS_H

typedef enum stack_enum { STACK_A, STACK_B, STACK_C } stack;

void move(stack source, stack target);

void sort_papers(int n, int *p);

#endif
