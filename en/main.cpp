#include <iostream>
#include <string>
#include <fstream>
#include "encrypt.h"

using namespace std;

int main(){
    int choice;
    string inputFile, outputFile;
    int key;
    //take user input
    cout << "Enter the Input file name(ensure its only a txt file): ";
    cin >> inputFile;
    //check if not txt file
    if(!isTxtFile(inputFile)){
        cerr << "please only use a txt file " << endl;
        return 1;
    }
    //get output file and key
    cout << "Enter the Output file name: ";
    cin >> outputFile;
    cout << "Enter a key: ";
    cin >> key;

    cout << "\n----------------------" << endl;
    cout << "|1. Encrypt a file   |" << endl;
    cout << "|2. Decrypt a file   |" << endl;
    cout << "----------------------\n";
    cout << "Enter your choice: ";
    cin >> choice;


    if(choice == 1){
        encryptFile(inputFile, outputFile, key);

        cout <<"\n\n" << inputFile << " encrypted! " << endl;
    }
    else if(choice == 2){
        decryptFile(inputFile, outputFile, key);

        cout <<"\n\n" << inputFile << " decrypted! " << endl;
    }
    else{
        cout << "invalid choice " << endl;
    }

    return 0;
}


