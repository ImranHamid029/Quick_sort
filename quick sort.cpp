#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    ifstream file("data.CSV"); 

    if (!file) {
        cout << "Gagal membuka file." << endl;
        return 1;
    }

    vector<int> arr; 
    int value;

    while (file >> value) {
        arr.push_back(value);
    }

    file.close();
    int size = 1000000;

    
    cout << "Data sebelum diurutkan: " << endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    quickSort(arr, 0, size - 1);

    cout << endl;
    cout<<endl;
    cout << "Data setelah diurutkan: " << endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

