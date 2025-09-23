#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string encrypt(string plaintext);
string decrypt(string ciphertext);
void encryptfile(string inputFile, string outputFile);
void decryptfile(string inputFile, string outputFile);

int main(){
    int choice;
    string inputFile, outputFile;

    cout << "1. Encrypt a file" << endl;
    cout << "2. Decrypt a file" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    cout << "Enter the Input file name: ";
    cin >> inputFile;
    cout << "Enter the Output file name: ";
    cin >> outputFile;

    switch(choice){
        case 1:
            encryptfile(inputFile, outputFile);
            break;
        case 2:
            decryptfile(inputFile, outputFile);
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
    }

    return 0;
}

string encrypt(string plaintext){
    string ciphertext = plaintext;
    ciphertext = string(ciphertext.rbegin(), ciphertext.rend());

    return ciphertext;
}

string decrypt(string ciphertext){
    string plaintext = ciphertext;
    plaintext = string(plaintext.rbegin(), plaintext.rend());

    return plaintext;
}

void encryptfile(string inputFile, string outputFile){
    ifstream inFile(inputFile);
    ofstream outFile(outputFile);
    string line;

    if(!inFile.is_open() || !outFile.is_open()){
        throw std::runtime_error("Could not open file");
    }

    while(getline(inFile, line)){
        outFile << encrypt(line) << endl;
    }

    inFile.close();
    outFile.close();
}

void decryptfile(string inputFile, string outputFile){
    ifstream inFile(inputFile);
    ofstream outFile(outputFile);
    string line;

    if(!inFile.is_open() || !outFile.is_open()){
        throw std::runtime_error("Could not open file");
    }

    while(getline(inFile, line)){
        outFile << decrypt(line) << endl;
    }

    inFile.close();
    outFile.close();
}

