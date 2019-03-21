#include "iostream"
#include "QSort.h"
#include "stack"

//改自快速排序算法
//思路为排序时仅排序较大的一些数据，直到待排数据少于k，此时便是top_k，然后对这些数据进行再一次排序
//但是数据量少时，快排选取temp的值会造成一些困扰
using namespace std;

template <typename T>
void swap(T *i, T *j)
{
    T temp;
    temp = *i;
    *i = *j;
    *j = temp;
}

template <typename T>
void QSort(T *st, T *ed)
{
    cout << "--------------QSort--------------" << endl;
    if ((ed - st) > 1){
        T temp = st[(ed - st + 1) / 2];
        cout << "temp: " << temp << endl;

        T *i = st;
        T *j = ed;
        
        while (i < j){
            while(*i < temp){
                //cout << "*i: " << *i << endl;
                i++;
            }

            while(*j > temp){
                //cout << "*j: " << *j << endl;
                j--;
            }

            if(i<j){
                swap(i, j);
            }
        };
        //cout << *i << " ******* " << *j << endl;
        //cout << *st << " ******* " << *ed << endl;
        QSort(st, j);
        QSort(j, ed);
    }
}

template <typename T>
void stackQSort(T *array, int number)
{
    cout << "---------------stack-----------------" << endl;

    stack<T *> STACK;
    STACK.push(array);
    STACK.push(array + (number - 1));

    T *st;
    T *ed;

    do{
        ed = STACK.top();
        STACK.pop();
        st = STACK.top();
        STACK.pop();

        if ((ed - st) > 1){
            T temp = st[(ed - st + 1) / 2];
            //cout << "temp: " << temp << endl;
            
            T *i = st;
            T *j = ed;
            
            while (i < j){
                while(*i < temp){
                    //cout << "*i: " << *i << endl;
                    i++;
                    }

                while(*j > temp){
                    //cout << "*j: " << *j << endl;
                    j--;
                    }

                if(i<j){
                    swap(i, j);
                    }
            };
            STACK.push(st);
            STACK.push(j);
            STACK.push(j);
            STACK.push(ed);
        };
    } while (!STACK.empty());
}

template <typename T>
T *top_k(T *array, int number, int k)
{
    cout << "---------------top_k-----------------" << endl;
    if(k <= number){
        stackQSort(array, number);
        return array;
    }
}