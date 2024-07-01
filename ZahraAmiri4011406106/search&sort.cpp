#include <iostream>
#include <vector>
//zahraamiri  4011406106
using namespace std;

class SearchSort {
public:
    // Linear Search
    int linearSearch(vector<int> arr, int key) {
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == key) {
                return i;
            }
        }
        return -1;
    }

    // Binary Search
    int binarySearch(vector<int> arr, int key) {
        int left = 0;
        int right = arr.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (arr[mid] == key) {
                return mid;
            } else if (arr[mid] < key) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return -1;
    }

    // Bubble Sort
    void bubbleSort(vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
    }

    // Merge Sort
    void merge(vector<int>& arr, int l, int m, int r) {
        
    }

    void mergeSort(vector<int>& arr, int l, int r) {
        // merge sort
    }

    // Selection Sort
    void selectionSort(vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
            }
            swap(arr[i], arr[minIndex]);
        }
    }

    // Insertion Sort
    void insertionSort(vector<int>& arr) {
        int n = arr.size();
        for (int i = 1; i < n; i++) {
            int key = arr[i];
            int j = i - 1;

            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }

            arr[j + 1] = key;
        }
    }
};

int main() {
    SearchSort ss;

    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};

    // Linear Search
    int linearIndex = ss.linearSearch(arr, 22);
    cout << "Linear Search: Index of 22 is " << linearIndex << endl;

    // Binary Search
    ss.selectionSort(arr);
    int binaryIndex = ss.binarySearch(arr, 22);
    cout << "Binary Search: Index of 22 is " << binaryIndex << endl;

    // Bubble Sort
    vector<int> bubbleArr = {64, 34, 25, 12, 22, 11, 90};
    ss.bubbleSort(bubbleArr);
    cout << "Bubble Sort:";
    for (int num : bubbleArr) {
        cout << " " << num;
    }
    cout << endl;

    // Merge Sort
    vector<int> mergeArr = {64, 34, 25, 12, 22, 11, 90};
    ss.mergeSort(mergeArr, 0, mergeArr.size() - 1);
    cout << "Merge Sort:";
    for (int num : mergeArr) {
        cout << " " << num;
    }
    cout << endl;

    // Selection Sort
    vector<int> selectionArr = {64, 34, 25, 12, 22, 11, 90};
    ss.selectionSort(selectionArr);
    cout << "Selection Sort:";
    for (int num : selectionArr) {
        cout << " " << num;
    }
    cout << endl;

    // Insertion Sort
    vector<int> insertionArr = {64, 34, 25, 12, 22, 11, 90};
    ss.insertionSort(insertionArr);
    cout << "Insertion Sort:";
    for (int num : insertionArr) {
        cout << " " << num;
    }
    cout << endl;

    return 0;
}
