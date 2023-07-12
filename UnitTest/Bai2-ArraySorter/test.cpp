#include "pch.h"

class ArraySorter {
private:
    int* arr;
    int size;

public:
    ArraySorter(int array[], int arraySize) : arr(array), size(arraySize) {}

    void BubbleSort() {
        for (int i = 0; i < size - 1; ++i) {
            for (int j = 0; j < size - i - 1; ++j) {
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    void PrintArray() {
        for (int i = 0; i < size; ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
};


TEST(ArraySorterTest, BulbleSortTest) {
    int array[] = { 7, 5, 23, 11, 8, 14 };
    ArraySorter sortArray(array, 6);
    sortArray.BubbleSort();

    EXPECT_EQ(array[0], 5);
    EXPECT_EQ(array[1], 7);
    EXPECT_EQ(array[2], 8);
    EXPECT_EQ(array[3], 11);
    EXPECT_EQ(array[4], 14);
    EXPECT_EQ(array[5], 23);
}