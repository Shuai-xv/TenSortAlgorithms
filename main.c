/*
 * @Description: 
 * @Version: 1.0
 * @Autor: shuai
 * @Date: 2020-08-23 20:58:18
 * @LastEditTime: 2020-08-27 19:58:18
 */
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "Lib/sort.h"

void ArrayInit(int arr[],int len){
    srand(time(NULL));
    for (int i = 0; i < len; i++)
    {
        arr[i]=rand()%256;
    }
    
}
void PrintArray(int arr[],int len){
    for (int i = 0; i < len; i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\n");
}
int main(int argc, char const *argv[])
{

    int arr[12];
    // ArrayInit(arr,sizeof(arr)/sizeof(int));
    // PrintArray(arr,sizeof(arr)/sizeof(int));
    // printf("Max=%d\n",GetMax(arr,sizeof(arr)/sizeof(int)));
    //----------------------------------------------
    ArrayInit(arr,sizeof(arr)/sizeof(int));
    printf("Bubble Sort:\n");
    BubbleSort(arr,sizeof(arr)/sizeof(int));
    PrintArray(arr,sizeof(arr)/sizeof(int));
    //----------------------------------------------
    ArrayInit(arr,sizeof(arr)/sizeof(int));
    printf("Selection Sort:\n");
    SelectSort(arr,sizeof(arr)/sizeof(int));
    PrintArray(arr,sizeof(arr)/sizeof(int));
    //----------------------------------------------
    ArrayInit(arr,sizeof(arr)/sizeof(int));
    printf("Quick Sort:\n");
    QuickSort(arr,sizeof(arr)/sizeof(int));
    PrintArray(arr,sizeof(arr)/sizeof(int));
    //----------------------------------------------
    ArrayInit(arr,sizeof(arr)/sizeof(int));
    printf("Insertion Sort:\n");
    InsertionSort(arr,sizeof(arr)/sizeof(int));
    PrintArray(arr,sizeof(arr)/sizeof(int));
    //----------------------------------------------
    ArrayInit(arr,sizeof(arr)/sizeof(int));
    printf("Shell Sort:\n");
    ShellSort(arr,sizeof(arr)/sizeof(int));
    PrintArray(arr,sizeof(arr)/sizeof(int));
    return 0;
}
