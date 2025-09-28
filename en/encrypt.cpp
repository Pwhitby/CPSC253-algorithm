#include "encrypt.h"
#include <fstream>
#include <cctype>
#include <filesystem>
#include <string>

using namespace std;

bool isTxtFile(const string& file){
    size_t dot = file.rfind('.');
    if(dot == string::npos) return false;
    string ext = file.substr(dot);
    return ext == ".txt";
}

void encryptFile(const string& inputFile, const string& outputFile, int key){
    ifstream inFile(inputFile);
    ofstream outFile(outputFile);
    string line;

    if(!inFile.is_open() || !outFile.is_open()){
        throw std::runtime_error("Could not open file");
        return;
    }

    while(getline(inFile, line)){
        outFile << encrypt(line, key) << endl;
    }

    inFile.close();
    outFile.close();
}

void decryptFile(const string& inputFile, const string& outputFile, int key){
    ifstream inFile(inputFile);
    ofstream outFile(outputFile);
    string line;
    
    if(!inFile.is_open() || !outFile.is_open()){
        throw std::runtime_error("Could not open file");
        return;
    }

    while(getline(inFile, line)){
        outFile << decrypt(line, key) << endl;
    }

    inFile.close();
    outFile.close();
}

string xorencrypt(const string& input, int key){
    string result = input;
    for(size_t i = 0; i < result.length(); i++){
        result[i] ^= key;
    }

    return result;
}

string transpose(const string& input, int key){
    int size = ((input.length() + key - 1) / key) * key;
    string grid(size, 'X');
    int numRows = (grid.length()) / key;
    //fill row by row
    for(int i = 0; i < input.length(); i++){
        grid[i] = input[i];
    }

    //read column by column
    string result;
    for(int col = 0; col < key; col++){
        for(int row = 0; row < numRows; row++){
            result += grid[row * key + col];
        }
    }

    return result;
}

string detranspose(const string& input, int key){
    int numRows = (input.length() + key - 1) / key;
    int size = numRows * key;

    string grid(size, 'X');

    int index = 0;

    for (int col = 0; col < key; col++){
        for(int row = 0; row < numRows; row++){
            int gridIndex = row * key + col;
            if(index < input.length()){
                grid[gridIndex] = input[index++];
            }
        }
    }

    string result;
    for(int i = 0; i < input.length(); i++){
        result += grid[i];
    }

    return result;
}

string encrypt(const string& plaintext, int key){
    string ciphertext = plaintext;

    ciphertext = string(ciphertext.rbegin(), ciphertext.rend());

    ciphertext = transpose(ciphertext, key);

    ciphertext = xorencrypt(ciphertext, key);

    return ciphertext;
}

string decrypt(const string& ciphertext, int key){
    string plaintext = ciphertext;

    plaintext = xorencrypt(plaintext, key);

    plaintext = detranspose(plaintext, key);

    plaintext = string(plaintext.rbegin(), plaintext.rend());

    while(!plaintext.empty() && plaintext.front() == 'X'){
        plaintext.erase(0,1);
    }
    return plaintext;
}