#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    int key = 13;

    // Helper to encrypt/decrypt (XORing twice returns the original character)
    string processXOR(string s) {
        for(auto &ch : s){
            ch ^= key;
        }
        return s;
    }

public:
    string encode(vector<string>& strs) {
        string encrypt = "";
        for(auto &s : strs){
            // 1. Encrypt the string first
            string encryptedStr = processXOR(s);
            // 2. Append [length] + [#] + [encrypted_string]
            encrypt += to_string(encryptedStr.size()) + "#" + encryptedStr;
        }
        return encrypt;
    }

    vector<string> decode(string s) {
        vector<string> decrypt;
        int i = 0;
        
        while (i < s.size()) {
            // 1. Find the delimiter '#'
            int j = i;
            while (s[j] != '#') {
                j++;
            }
            
            // 2. Extract the length of the upcoming string
            int length = stoi(s.substr(i, j - i));
            
            // 3. Extract the encrypted string substring (right after the '#')
            string encryptedSub = s.substr(j + 1, length);
            
            // 4. Decrypt it using the same XOR operation and add to results
            decrypt.push_back(processXOR(encryptedSub));
            
            // 5. Move our pointer past the processed string to the next length block
            i = j + 1 + length;
        }
        
        return decrypt;
    }
};