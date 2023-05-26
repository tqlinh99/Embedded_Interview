/*
* File: main.c
* Author: Quang Linh
* Date: 29/04/2023
* Description: Tạo mảng số nguyên ngẫu nhiên có kích thước tùy ý, đếm số lượng xuất hiện của các phần tử.
*/
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

typedef struct
{
    int *ptr;
    uint16_t size;
}typeArr;

/*
* Function: createArray
* Description: tạo mảng có giá trị các phần tử ngẫu nhiên từ 0->6
* Input:
*   arr - biến dạng con trỏ để lưu địa chỉ các phần tử và kích thước của mảng
*/
void createArray(typeArr *arr)
{
    printf("Nhap so phan tu mang: ");
    scanf("%d", &(arr->size));

    arr->ptr=(int*)malloc(arr->size*sizeof(uint8_t));

    srand((int)time(0));

    for(uint16_t i=0; i<arr->size;i++)
    {
       arr->ptr[i]= rand()%6;
       printf("arr[%d]= %d\n", i, arr->ptr[i]);
    }
}

/*
* Function: sortMintoMax
* Description: sắp xếp các phần tử trong mảng theo thứ tự tăng dần giá trị
* Input:
*   arr - biến dạng con trỏ để lưu địa chỉ các phần tử và kích thước của mảng
*/
void sortMintoMax(typeArr *arr)
{
    uint8_t temp;
    for(uint16_t i=0; i<arr->size;i++)
    {
        for(uint16_t j=i+1; j<arr->size;j++)
        {
            if(arr->ptr[i]>arr->ptr[j])         //nếu phần tử i > phần tử j thì swap
            {    
                temp=arr->ptr[i];
                arr->ptr[i]=arr->ptr[j];
                arr->ptr[j]=temp;
            } 
        }
    }
}

/*
* Function: countArray
* Description: đếm số lượng xuất hiện của phần tử trong mảng 
* Input:
*   arr - biến để lưu giá trị các phần tử và kích thước của mảng
*/
void countArray(typeArr arr)
{
    for(uint16_t i=0; i<arr.size;i++)
    {
        uint8_t count = 1;
        for(uint16_t j=i+1; j<(arr.size)+1;j++)
        {
            if (arr.ptr[i]==arr.ptr[j])
                count++;
            else
            {
                printf("So %d xuat  hien: %d lan\n", arr.ptr[i],count);
                i=j-1;
                break;
            }        
        }     
    } 
}


/*
* Function: freeMem
* Description: giải phóng bộ nhớ cấp phát động
* Input:
*   arr
*/
void freeMem(typeArr *arr)
{
    free(arr->ptr);
}


int main(int argc, char const *argv[])
{
    typeArr Array;
    createArray(&Array);
    sortMintoMax(&Array);
    countArray(Array);  
    freeMem(&Array);
    return 0;
}

