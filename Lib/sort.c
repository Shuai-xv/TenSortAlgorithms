/*
 * @Description: aim to realize ten sort algorithms,from small to large
 * @Version: 1.0
 * @Autor: shuai
 * @Date: 2020-08-23 21:03:27
 * @LastEditTime: 2020-08-28 20:23:43
 */
#include "sort.h"

int GetMax(int arr[], int len)
{
    int res = 0;
    for (int i = 0; i < len; i++)
    {
        if (arr[i] > res)
            res = arr[i];
    }
    return res;
}
void swap(int *n1, int *n2)
{
    *n1 = *n1 ^ *n2;
    *n2 = *n1 ^ *n2;
    *n1 = *n1 ^ *n2;
}
/**
 * @brief:  冒泡排序Bubble Sort
 * @param array pointer and its length
 * @retval: void
 */
void BubbleSort(int arr[], int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - 1; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(arr + j, arr + j + 1);
        }
    }
}
/**
 * @brief:  选择排序Selection Sort
 * @param array pointer and its length
 * @retval: void
 */
void SelectSort(int arr[], int len)
{
    int max = 0, index = 0;
    for (int j = 0; j < len-1; j++)
    {
        //find the max number and its index in remaining number
        for (int i = 0; i < len-j; i++)
        {
            if (arr[i] > max)
            {
                max = arr[i];
                index = i;
            }
        }
        //Move the remaining unsorted numbers forward one place
        for (int k = index; k < len -1 - j; k++)
        {
            arr[k] = arr[k + 1];
        }
        //put the max num in back sorted sequence
        arr[len-j-1] = max;
        max = 0;
    }
}
//Quick Sort快速排序
void QuickSort(int arr[],int len){
    if(len<=1)
        return;
    else
    {
        int pivot=arr[(int)((len+1)/2)];
        int larger_num[len];//store number biger than pivot
        int index_ln=0,index_ar=0;
        for (int i = 0; i < len; i++)
        {
            if(i==(int)((len+1)/2))
                continue;
            if(arr[i]>=pivot)
            {
                larger_num[index_ln]=arr[i];
                index_ln++;
                // index_ar=i;
            }
            else
            {
                arr[index_ar]=arr[i];
                index_ar++;
            }
            
        }
        arr[index_ar]=pivot;
        for (int i = index_ar+1; i < len; i++)
        {
            arr[i]=larger_num[i-index_ar-1];
        }
        QuickSort(arr,index_ar);
        QuickSort(arr+index_ar+1,len-index_ar-1);
    }
    
}
/**
 * @brief: 插入排序Insertion sort
 * @param
 * @retval: 
 */
void InsertionSort(int arr[],int len){
    if(len==1)
        return;
    for (int i = 1; i < len; i++)
    {
        if(arr[i]<arr[i-1])
        { 
            swap(arr+i,arr+i-1);
            InsertionSort(arr,i);
        }
    }
    
}

/**
 * @brief: 希尔排序Shell Sort
 * @param : 
 * @retval: 
 */
void ShellSort(int arr[],int len){
    int increnment=len;
    int index=0;
    do{
        increnment=(int)(len/2);
        for (int i = 0; i < increnment; i++)
        {
            //Insertion Sort:'increment' number to be sorted
            for (index = i+increnment; index < len; index+=increnment)
            {
                int tmp_ind=index;
                while (tmp_ind-increnment>=0&&arr[tmp_ind]>arr[tmp_ind-increnment])
                {
                    swap(arr+tmp_ind,arr+tmp_ind-increnment);
                    tmp_ind-=increnment;
                }
            }
        }
    }while(increnment>1);
    
    // if(increnment==1)return;
    
}