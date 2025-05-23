#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// Sayıyı binary'ye çeviren fonksiyon
void convertToBinary(int number, vector<int>& binary) {
    while (number > 0) {
        binary.push_back(number % 2);
        number /= 2;
    }
    if (binary.empty()) binary.push_back(0); // 0 için
}

// Binary'yi yazdıran fonksiyon
void printBinary(vector<int>& binary) {
    for (int i = binary.size() - 1; i >= 0; i--) {
        cout << binary[i];
    }
    cout << endl;
}

// Ana fonksiyon
int main() {
    int number;
    cout << "Enter a non-negative integer: ";
    cin >> number;

    if (number < 0) {
        cerr << "Error: Negative numbers not allowed!" << endl;
        return 1;
    }

    vector<int> binary;
    convertToBinary(number, binary);

    cout << "Binary: ";
    printBinary(binary);

    // Dosyaya yazma
    ofstream file("output.txt");
    if (file.is_open()) {
        file << "Number: " << number << endl;
        file << "Binary: ";
        for (int i = binary.size() - 1; i >= 0; i--) {
            file << binary[i];
        }
        file << endl;
        file.close();
        cout << "Binary written to output.txt" << endl;
    }
    else {
        cerr << "Error opening file!" << endl;
    }

    return 0;
}

