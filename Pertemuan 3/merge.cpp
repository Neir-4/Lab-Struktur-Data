#include <iostream>
#include <vector> //agar bisa pakai vector
using namespace std;

//sub program
void merge(vector<int>& arr, int left, int mid, int right) {
    
    //menentukan ukuran dua sub array
    int n1 = mid - left + 1;  //kiri
    int n2 = right - mid;    //kanan


    vector<int> L(n1), R(n2);//buat array untuk nilai di kiri dan di kanan

    //masukkan nilai utk array kiri
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    //masukkan nilai untuk array kanan
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    //indeks pertama dari kedua array
    int i = 0;    
    int j = 0;      
    int k = left;

    //perulangan untuk menggabungkan kedua array
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    //perulangan untuk menyalin sisa elemen dari array L
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    //perulangan untuk menyalin sisa elemen dari array R
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Fungsi utama merge sort
void mergeSort(vector<int>& arr, int left, int right) {
    //cek jika yang nilai kiri besar dari kanan atau tidak
    if (left >= right)
        return;//kalau lebih besar, sub program berhenti
    int mid = left + (right - left) / 2;//membuat variabel nilai tengah

    mergeSort(arr, left, mid);//pemanggilan rekursif (mulai kembali sub program ini)
    mergeSort(arr, mid + 1, right);//pemanggilan rekursif lagi tapi untuk nilai tengah ditambah 1
   
    merge(arr, left, mid, right);//masuk sub program merge
}

//sub program untuk menampilkan isi dari vector
void printArray(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

//program utama
int main() {
    //minta masukan berapa elemen data
    int n;
    cout << "Masukkan jumlah elemen data: ";
    cin >> n;
   
    //elemen data akan diisi dan disimpan di vector
    vector<int> data(n);
    cout << "Masukkan elemen-elemen data: ";
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }
    
    //menampilkan array yang belum diurutkan
    cout << "Array sebelum diurutkan: ";
    printArray(data);
    
    //memulai sub program untuk melakukan pengurutan 
    mergeSort(data, 0, n - 1);
    
    //data yang telah terurut ditampilkan
    cout << "Array setelah diurutkan: ";
    printArray(data);
   
    return 0;
}