/*
* File: main.c
* Author: Quang Linh
* Date: 29/04/2023
* Description: Đọc 1 số nguyên bất kỳ từ dạng số qua dạng chữ (nhỏ hơn 4000000000)  .
*/
#include <stdio.h>
#include <stdint.h>


/*
* Function: quantityOfNumber
* Description: Tính số lượng chữ số có trong 1 số bất kỳ
*    Example: 56243 -> 5 chữ số
*             534   -> 3 chữ số
* Input:
*   number - số nguyên
*Output:
*   số lượng chữ số có trong biến number
*/
uint8_t quantityOfNumber(uint32_t number)
{
    uint8_t quantity=0;
    if (number==0)  return 1;

    while (number>0)
    {
        if (number%10==0)
        {
            quantity++;
            number=number/10;
            continue;
        }

        if(number==1)
        {
            quantity++;
            break;
        }

        number--;
    }
    return quantity;   
}


/*
* Function: extractNumber
* Description: Tách từng chữ số có trong một số và lưu vào mảng theo thứ tự tăng dần trọng số 
*    Example: 56243 -> [3, 4, 2, 6, 5]
* Input:
*   number - số nguyên
*   numberArray - mảng số nguyên
*/
void extractNumber(uint32_t number, uint8_t numberArray[])
{
    uint8_t count=0;
    uint8_t index=0;
    if (number==0)  numberArray[0]=0;
    
    while (number>0)
    {   
        if ((number%10==0)&(number>=10))
        {
            numberArray[index]=count;

            index++;
            number=number/10;
            count=0;
            continue;   
        }
        else if(number<10)
        {
            numberArray[index]=number;
            break;
        }
        count++;
        number--;
    }
}

/*
* Function: readTable
* Description: Bảng tra cứu cách đọc dạng chữ theo giá trị và vị trí 
* Input:
*   value - số nguyên
*   index - số nguyên
*/
void readTable(uint8_t value, uint8_t index)
{
    switch (value)
    {
    case 0: printf("Khong "); break;
    case 1: printf("Mot "); break;
    case 2: printf("Hai "); break;
    case 3: printf("Ba "); break;
    case 4: printf("Bon "); break;
    case 5: printf("Nam "); break;
    case 6: printf("Sau "); break;
    case 7: printf("Bay "); break;
    case 8: printf("Tam "); break;
    case 9: printf("Chin "); break;
    case 10: printf("Lam "); break;
    case 11: printf("Linh "); break;
    default: break;
    }  

    switch (index)
    {
    case 0: break;
    case 1: 
    case 4: 
    case 7: printf("Muoi "); break;
    case 2: 
    case 5: 
    case 8: printf("Tram "); break;
    case 3: printf("Nghin "); break;
    case 6: printf("Trieu "); break;
    case 9: printf("Ty "); break;
    }
}

/*
* Function: readNumber
* Description: Đọc giá trị theo vị trí trong các trường hợp khác nhau 
* Input:
*   numberArray[] - mảng số nguyên
*   size - số nguyên
*/
void readNumber(uint8_t numberArray[], uint8_t size)
{

    for (int8_t i = size-1; i >=0; i--)
    {
        if ((i==0||i%3==0)&(numberArray[i]==0))
        {   
            if (size==1)
                readTable(numberArray[i],i);
            else if(numberArray[i+1]!=0||numberArray[i+2]!=0)
                readTable(12,i);
            continue;
        }

        if ((i==0||i%3==0)&(numberArray[i]==5))
        {
            if ((size==1)||(numberArray[i+1]==0)||(numberArray[i+1]>10))
                readTable(numberArray[i],i);
            else if ((numberArray[i+1]>0)&(numberArray[i+1]<9)){
                readTable(10,0);
            readTable(12,i);}
            continue;
        }
        
        if ((i==1||(i-1)%3==0)&(numberArray[i]==0))     
        {
            if(numberArray[i-1]!=0)
                readTable(11,0);
            else
                readTable(12,0);
            continue;
        }

        if ((i==1||(i-1)%3==0)&(numberArray[i]==1))
        {    
            readTable(12,1);
            continue;
        }

        if ((i==2||(i-2)%3==0)&(numberArray[i]==0))
        {
            if((numberArray[i-1]==0)&numberArray[i-2]==0)
                readTable(12,0);
            else
                readTable(numberArray[i],i);
            continue;
        }
        readTable(numberArray[i],i);
    }
}



int main(int argc, char const *argv[])
{
    uint32_t number;

    printf("Nhap so bat ky: ");
    scanf("%d", &number);

    uint8_t numberArray[quantityOfNumber(number)];

    extractNumber(number,numberArray);
    readNumber(numberArray, quantityOfNumber(number));
    return 0;
}
