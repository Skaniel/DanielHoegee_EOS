#include <iostream>
#include <string>
using namespace std;

string translate(string line, string argument) {
    string result;

    for(unsigned int x = 0; x <line.size(); x++){
        char letter = line[x];
        int encrypt_letter = letter + stoi(argument);

        if(isalpha(letter)) {
            if (encrypt_letter <= 'z') {
                if (encrypt_letter > 'z'){
                    result.append(1, encrypt_letter - 26);
                }
                else if (encrypt_letter < 'a') {
                result.append(1, encrypt_letter + 26);
                }
                else {
                result.append(1, encrypt_letter);
                }
            }

            else{
                if (encrypt_letter > 'Z'){
                    result.append(1, encrypt_letter - 26);
                }
                else if (encrypt_letter < 'A') {
                    result.append(1, encrypt_letter + 26);
                }
                else {
                    result.append(1, encrypt_letter);
                }
            }
        }
        else{
            result.append(1, letter);
        }
    }
    return result;
}
int main(int argc, char *argv[])
{   string line;

    if(argc != 2)
    { cerr << "Deze functie heeft exact 1 argument nodig" << endl;
        return -1; }

    while(getline(cin, line))
    { cout << translate(line, argv[1]) << endl; }

    return 0;
}
