#include <iostream>
#include <fstream>
#include <string>

using std::cout, std::endl, std::cin, std::string, std::ifstream, std::ofstream;

string encrypt(string plaintext, int key);
string decrypt(string ciphertext, int key);
void encryptfile(string inputFile, string outputFile, int key);
void decryptfile(string inputFile, string outputFile, int key);

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

string encrypt(string plaintext, int key){

}

string decrypt(string ciphertext, int key){
    
}

void encryptfile(string inputFile, string outputFile, int key){
    ifstream inFile(inputFile);
    ofstream outfile(outputFile);
    string line;

    if(!inputFile.is_open() || !outputFile.is_open()){
        throw std::runtime_error("Could not open file");
        return;
    }

    inputFile.close();
    outputFile.close();
}

void decryptfile(string inputFile, string outputFile, int key){
    ifstream inFile(inputFile);
    ofstream outfile(outputFile);
    string line;

    if(!inputFile.is_open() || !outputFile.is_open()){
        throw std::runtime_error("Could not open file");
        return;
    }

    inputFile.close();
    outputFile.close();
}

