#ifndef TASK_ORDER_H
#define TASK_ORDER_H

typedef struct dependency {
    int task;
    int prerequisite_task;
} dependency;

int *find_task_order(int n, int d, dependency *deps);

#endif
