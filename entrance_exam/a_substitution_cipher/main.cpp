#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<int> cipher(26, -1);
    vector<int> plain(26, -1);
    string cipher_str;
    string plain_str;
    string in;

    cin >> cipher_str >> plain_str >> in;

    if (cipher_str.size() != plain_str.size())
        return -1;

    for (unsigned int i = 0; i < cipher_str.size(); i++)
    {
        int cipher_char = cipher_str.at(i) - 65;
        int plain_char = plain_str.at(i) - 65;
        // offset 65
        if (cipher.at(cipher_char) == -1 && plain.at(plain_char) == -1)
        {
            cipher.at(cipher_char) = plain_char;
            plain.at(plain_char) = cipher_char;
        }
        else if (cipher.at(cipher_char) == plain_char && plain.at(plain_char) == cipher_char)
        {
            continue;
        }
        else
        {
            cout << "Failed" << endl;
            return 0;
        }
    }

    for (unsigned int i = 0; i < cipher.size(); i++)
    {
        if (cipher.at(i) == -1 || plain.at(i) == -1)
        {
            cout << "Failed" << endl;
            return 0;
        }
    }

    for (unsigned int i = 0; i < in.size(); i++)
    {
        int cipher_char = cipher.at(in.at(i) - 65);
        in.at(i) = cipher_char + 65;
    }
    cout << in << endl;

    return 0;
}