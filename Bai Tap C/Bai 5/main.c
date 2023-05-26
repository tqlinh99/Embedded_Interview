/*
* File: main.c
* Author: Quang Linh
* Date: 29/04/2023
* Description: Tạo mảng ngẫu nhiên có 10000 phần tử, tìm 1 phần tử trong mảng.
*/
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>


/*
* Function: createArray
* Description: Tạo mảng ngẫu nhiên với 10000 phần tử có giá trị không trùng nhau
* Input:
*   arr[] - mảng số nguyên
*/
void createArray(uint16_t arr[])
{
    srand((int)time(0));
    for (uint16_t i = 0; i < 10000; i++)
    {
        arr[i]=rand();
        for (uint16_t j = 0; j < i; j++)
        {
            if (arr[j]!=arr[i]) continue;
            i--;
            break;                   
        } 
    } 
}


/*
* Function: sortArray
* Description: Sắp xếp các phần tử trong mảng theo thứ tự tăng dần
* Input:
*   arr[] - mảng số nguyên
*/
void sortArray(uint16_t arr[])
{
    uint16_t temp;
    for (uint16_t i = 0; i < 10000-1; i++)
    {
        for (uint16_t j = i+1; j < 10000; j++)
        {
            if (arr[i]>arr[j])
            {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }  
        }
    }   
}


/*
* Function: searchInArray
* Description: Tìm kiếm sự có mặt của 1 phần tử bất kỳ trong mảng
* Input:
*     num - số nguyên 
*   arr[] - mảng số nguyên
*/
uint16_t searchInArray(uint16_t num, uint16_t arr[])
{
    uint16_t initIndex=5000, indexShift=5000;
    for (uint8_t i = 1; i < 16; i++)
    {   
        if(num>arr[initIndex])
        {
            indexShift=(indexShift+(indexShift%2))/2;
            initIndex+=indexShift;
        }
        else if(num<arr[initIndex])
        {
            indexShift=(indexShift+(indexShift%2))/2;
            initIndex-=indexShift;
        }
        else 
        {
            printf("So lan lap: %d\n", i);
            return printf("Da tim thay so %d", num);
        }
    }
    return printf("Khong tim thay so %d !!!", num);
}




int main(int argc, char const *argv[])
{
    uint16_t array[10000];
    uint16_t number;

    createArray(array);
    sortArray(array);

    for (uint16_t i = 0; i < 10000; i++)
    {
        printf("%d ",array[i]);
    }

    while (1)
    {   
        printf("\n\nNhap so muon tim: ");
        scanf("%d", &number);

        searchInArray(number, array);                              
    }
    return 0;
}
