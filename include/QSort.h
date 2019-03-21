#ifndef QSort_h
#define QSort_h

template <typename T>
void swap(T *i, T *j);

template <typename T>
void QSort(T *st, T *ed);

template <typename T>
void stackQSort(T *array, int number);

template <typename T>
T *top_k(T *array, int number, int k);

#endif