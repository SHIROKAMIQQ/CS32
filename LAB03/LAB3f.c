#include "excitingnesses.h"
#include <stdlib.h>
#include <stdio.h>
void PrintList(long long int* arr, int length) {
    if (length == 0) {
        printf("NULL");
        return;
    }

    for (int i = 0; i < length; i++) {
        printf("%lld ", arr[i]);
    }
    printf("\n");
}
int64 excitingness(int n, int64* l, int* pnkref, int64* niceness_sumref, int* pnkbool){
    if (n == 1) {
        return 0;
    }
    
    int64 niceness_sum = l[0];
    int64 pnk = 0;

    pnkbool[0] = 0;
    pnkbool[n-1] = 0;
    for (int i = 1; i < n-1; i++) {
        niceness_sum += l[i];
        if ((l[i-1] < l[i] && l[i+1] < l[i])
        || (l[i] < l[i-1] && l[i] < l[i+1])) {
            pnk++;
            pnkbool[i] = 1;
        } else {
            pnkbool[i] = 0;
        }
    }
    niceness_sum += l[n-1];
    
    //printf("%lld %lld \n", niceness_sum, pnk);
    *niceness_sumref = niceness_sum;
    *pnkref = pnk;
    return niceness_sum * pnk;
}

int64 *excitingnesses(int n, int64 *l) {
    if (n == 1) {
        return 0;
    }
    
    int64* ret = (int64*)malloc(n*sizeof(int64));
    int64* niceness_sumref = (int64*)malloc(sizeof(int64));
    int* pnkref = (int*)malloc(sizeof(int));
    int* pnkbool = (int*)malloc(n*sizeof(int));

    int64 Ei = excitingness(n, l, pnkref, niceness_sumref, pnkbool);

    ret[0] = Ei - (*niceness_sumref)*(pnkbool[1]) - (l[0]*(*pnkref-(pnkbool[1])));

    ret[n-1] = Ei - (*niceness_sumref)*(pnkbool[n-2]) - (l[n-1]*(*pnkref-(pnkbool[n-2])));

    for (int i = 1; i < n-1; i++) {
        int temp_pnk = *pnkref - (pnkbool[i-1] + pnkbool[i+1] +pnkbool[i]);
        if (
            i != 1 && (
            (l[i-1] > l[i+1] && l[i-1] > l[i-2]) ||
            (l[i-1] < l[i+1] && l[i-1] < l[i-2])
            )
        )
            temp_pnk++;

        if (
            i != n-2 && (
            (l[i+1]  > l[i+2] && l[i+1] > l[i-1]) ||
            (l[i+1]  < l[i+2] && l[i+1] < l[i-1])
            )
        )
            temp_pnk++;

        int64 E = (*niceness_sumref - l[i]) * temp_pnk;

        ret[i] = E;
    }

    return ret;
}

int main() {
    long long int l1[11] = {1,3,4,4,4,2,6,1,2,5,1};
    PrintList(excitingnesses(11, l1), 11);
}