#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void incrementByPosition(int a[], int n) {
    for (int i = 0; i < n; i++)
        a[i] += (i+1);
}


void incrementByPointer(int *a, int n) {
    for (int *i = a; i<a+n; i++) {
        *i += (i - a + 1);
    }
}

void swap(void *a, void *b, size_t s) {
    char *temp = malloc(s);
    memcpy(temp, a, s);
    memcpy(a, b, s);
    memcpy(b, temp, s);
    free(temp);
}


void selectionSort(int a[], int n) {
    for (int s = 0; s < n; s++) {
        int min = a[s], mindex = s;
        for (int i = s+1; i < n; i++) {
            if (a[i] < min) {
                min = a[i];
                mindex = i;
            }
        }
        swap(a+s, a+mindex, sizeof(int));
    }
}


void insertionSort(int a[], int n) {
    for (int s = 1; s < n; s++) {
        for (int i = s; i > 0; i--) {
            if (a[i] < a[i-1])
                swap(a+i, a+i-1, sizeof(int));
            else break;
        }
    }
}

int *merge(int a[], int b[], int an, int bn) {
    int *c = malloc(sizeof(int)*(an+bn));
    int ai = 0, bi = 0, next;
    while (ai + bi < an + bn) {
        if (ai == an)
            next = b[bi++];
        if (bi == bn)
            next = a[ai++];
        if (a[ai] < b[bi])
            next = a[ai++];
        else next = b[bi++];
        c[ai+bi-1] = next;
    }
    return c;
}

void mergeSort(int a[], int n) {
    if (n == 1) return;
    int m = n/2;
    mergeSort(a, m);
    mergeSort(a+m, n-m);
    int *tmp = merge(a, a+m, m, n-m);
    memcpy(a, tmp, sizeof(int)*n);
    free(tmp);
}


void quickSort(int a[], int n) {
    if (n < 2) return;
    int x = a[0], m = 0;
    swap(a, a+n-1, sizeof(int));
    for (int i = 0; i < n; i++) {
        if (a[i] <= x) {
            swap(a+i, a+m, sizeof(int));
            m++;
        }
    }
    quickSort(a, m-1);
    quickSort(a+m, n-m);
}

int binSearch(int a[], int n, int t) {
    int m = n/2;
    if (t == a[m]) return m;
    if (t < a[m]) return binSearch(a, m, t);
    return m+binSearch(a+m, n-m, t);
}

int linSearch(int a[], int n, int t) {
    for (int i = 0; i < n; i++) {
        if (a[i] == t) return i;
    }
}

int gcd(int a, int b) {
    if (b) return gcd(b, a%b);
    return a;
}

int fib(int n) {
    int old = 1, older = 1, cur;
    if (n<3) return 1;
    for (int i = 0; i < (n-2); i++) {
        cur = old + older;
        older = old;
        old = cur;

    }
    return cur;
}

int cmp(const int *a, const int *b) {
    return *a-*b;
}

int main(void)
{
    int list[9] = {5,9,4,3,2,8,7,1,3};
    qsort(list, 9, sizeof(int), cmp);

    //incrementByPointer(list, 5);
    for (int i = 0; i < 9; i++)
        printf("%d ", list[i]);
}
