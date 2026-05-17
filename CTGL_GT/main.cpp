#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "Converter.h" // Nhúng thư viện thuật toán tự viết

using namespace std;


void processData(string inputFile, string outputFile) {
    ifstream inFile(inputFile);
    ofstream outFile(outputFile);
    
    if (!inFile || !outFile) {
        cout << "Loi mo file doc/ghi!" << endl;
        return;
    }
    
    string line;
    int processCount = 0;
    while (getline(inFile, line)) {
        if (line != "") {
            outFile << infixToPostfix(line) << "\n";
            processCount++;
        }
    }
    
    inFile.close();
    outFile.close();
    cout << "Da xu ly va chuyen doi xong " << processCount << " bieu thuc sang " << outputFile << endl;
}

int main() {
    string inputFile = "input_100k.txt";
    string outputFile = "output_100k.txt";
    
    
    processData(inputFile, outputFile);
    
    return 0;
}