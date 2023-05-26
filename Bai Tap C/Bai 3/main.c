/*
* File: main.c
* Author: Quang Linh
* Date: 29/04/2023
* Description: Nhập ngày tháng năm và trả về kết quả thứ trong tuần.
*/
#include <stdio.h>
#include <stdint.h>

typedef struct{
    uint8_t date;
    uint8_t month;
    uint16_t year;
}Time;

const Time rootTime = {1, 1, 1900};


/*
* Function: daysInMonth
* Description: Trả về số lượng ngày của 1 tháng bất kỳ
* Input:
*   month - tháng cần tính ngày
*   thoiGian - năm để xác định nhuận hay không
*Output:
*   trả về số lượng ngày trong tháng
*/
uint8_t daysInMonth(int month, Time thoiGian)
{
    switch(month)
    {
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;

        case 2:
            if (thoiGian.year%4==0)     return 29;
            else    return 28;

        default:
            return 31;
    }
}


/*
* Function: soNamNhuan
* Description: tính số năm nhuận từ năm gốc đến năm đang xét
* Input:
*   thoiGian - thời gian đang xét
*Output:
*   trả về số năm nhuận
*/
uint8_t soNamNhuan(Time thoiGian)
{
    uint8_t count=0;

    for (uint16_t i=rootTime.year; i<=thoiGian.year; i++)
    {
        if (i%4==0)
        {
            count++;
            if ((i%100==0)&(i%400!=0))    count--;  
        }
    }

    if ((thoiGian.year%4==0)&(thoiGian.year%400==0)&(thoiGian.month<3))    count--;

    return count;
}

/*
* Function: daysCalculator
* Description: tính số ngày từ năm gốc đến năm đang xét
* Input:
*   thoiGian - thời gian đang xét
*Output:
*   trả về số ngày
*/
uint32_t daysCalculator(Time thoiGian)
{
    uint32_t days=0;
    for(int i=rootTime.month; i<thoiGian.month; i++)
    {
        days+=daysInMonth(i, thoiGian);
    }
    
    days=(thoiGian.date-rootTime.date)+days+(thoiGian.year-rootTime.year)*365+soNamNhuan(thoiGian);
    return days;
}

/*
* Function: dayInWeek
* Description: In ra thứ trong tuần theo số ngày chênh lệch sau khi lấy khoảng cách ngày chia 7 lấy dư
* Input:
*   days - khoảng cách theo ngày từ năm gốc đến năm đang xét
*/
void dayInWeek(uint32_t days)
{
    uint8_t dayInWeek=days%7;

    switch (dayInWeek)
    {
    case 0: printf("la Thu Hai (Monday)"); break;
    case 1: printf("la Thu Ba (Tuesday)"); break;
    case 2: printf("la Thu Tu (Wednesday)"); break;
    case 3: printf("la Thu Nam (Thurday)"); break;
    case 4: printf("la Thu Sau (Friday)"); break;
    case 5: printf("la Thu Bay (Saturday)"); break;
    case 6: printf("la Chu Nhat (Sunday)"); break;
    }
}

/*
* Function: isValidDate
* Description: Xác định thời gian đang xét có tồn tại hay không
* Input:
*   thoiGian - thời gian
Output:
*   Trả về 0: thời gian đang xét có tồn tại
*   Trả về 1: thời gian đang xét không tồn tại
*/
uint8_t isValidDate(Time thoiGian)
{
    if ((thoiGian.month<13)||(thoiGian.month>0))
    {
        if (thoiGian.date<=daysInMonth(thoiGian.month,thoiGian))    return 0;
    }
    
    printf("Ngay khong ton tai moi nhap lai!!!\n");
    return 1;
}



int main(int argc, char const *argv[])
{

    Time pTime;
    uint32_t days;
    do
    {
        printf("Nhap ngay: ");
        scanf("%d",&(pTime.date));
        printf("Nhap thang: ");
        scanf("%d",&(pTime.month));
        printf("Nhap nam: ");
        scanf("%d",&(pTime.year));
    } 
    while (isValidDate(pTime));

    printf("Ngay %d thang %d nam %d: ", pTime.date, pTime.month, pTime.year);
    days=daysCalculator(pTime);
    dayInWeek(days);
    return 0;
}
