#include <iostream>
using namespace std;

// Linear Search Class
class LinearSearch {
public:
    int search(int data[], int size, int target) {
        for (int i = 0; i < size; i++) {
            if (data[i] == target)
                return i;
        }
        return -1;
    }
};

// Binary Search Class
class BinarySearch {
public:
    int search(int data[], int size, int target) {
        int left = 0, right = size - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (data[mid] == target)
                return mid;
            else if (data[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }
};

// Bubble Sort Class
class BubbleSort {
public:
    void sort(int data[], int size) {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (data[j] > data[j + 1]) {
                    swap(data[j], data[j + 1]);
                }
            }
        }
    }
};

// Selection Sort Class
class SelectionSort {
public:
    void sort(int data[], int size) {
        for (int i = 0; i < size - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < size; j++) {
                if (data[j] < data[minIndex])
                    minIndex = j;
            }
            swap(data[i], data[minIndex]);
        }
    }
};

// Insertion Sort Class
class InsertionSort {
public:
    void sort(int data[], int size) {
        for (int i = 1; i < size; i++) {
            int key = data[i];
            int j = i - 1;
            while (j >= 0 && data[j] > key) {
                data[j + 1] = data[j];
                j--;
            }
            data[j + 1] = key;
        }
    }
};

// Main Function
int main() {
    int data[] = {34, 7, 23, 32, 5, 62};
    int size = sizeof(data) / sizeof(data[0]);
    int target = 23;

    // Linear Search
    LinearSearch linearSearch;
    int linearResult = linearSearch.search(data, size, target);
    cout << "Linear Search: " << (linearResult != -1 ? "Found at index " : "Not found") << linearResult << endl;

    // Bubble Sort
    BubbleSort bubbleSort;
    bubbleSort.sort(data, size);
    cout << "Bubble Sort: ";
    for (int i = 0; i < size; i++) cout << data[i] << " ";
    cout << endl;

    // Binary Search (on sorted data)
    BinarySearch binarySearch;
    int binaryResult = binarySearch.search(data, size, target);
    cout << "Binary Search: " << (binaryResult != -1 ? "Found at index " : "Not found") << binaryResult << endl;

    // Selection Sort
    int selectionData[] = {34, 7, 23, 32, 5, 62};
    SelectionSort selectionSort;
    selectionSort.sort(selectionData, size);
    cout << "Selection Sort: ";
    for (int i = 0; i < size; i++) cout << selectionData[i] << " ";
    cout << endl;

    // Insertion Sort
    int insertionData[] = {34, 7, 23, 32, 5, 62};
    InsertionSort insertionSort;
    insertionSort.sort(insertionData, size);
    cout << "Insertion Sort: ";
    for (int i = 0; i < size; i++) cout << insertionData[i] << " ";
    cout << endl;

    return 0;
}
