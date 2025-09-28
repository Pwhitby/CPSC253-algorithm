#ifndef ENCRYPT_H
#define ENCRYPT_H

#include <string>

using namespace std;

bool isTxtFile(const string& file);

void encryptFile(const string& inputFile, const string& outputFile, int key);

void decryptFile(const string& inputFile, const string& outputFile, int key);

string xorencrypt(const string& input, int key);

string transpose(const string& input, int key);

string detranspose(const string& input, int key);

string encrypt(const string& plaintext, int key);

string decrypt(const string& ciphertext, int key);

#endif //ENCRYPT_H