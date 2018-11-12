#include<iostream>
#include<map>

using namespace std;

int main() {
    map<char, unsigned char> prime_map;
    
    prime_map['a'] = 2;
    prime_map['b'] = 3;
    prime_map['c'] = 5;
    prime_map['d'] = 7;
    prime_map['e'] = 11;
    prime_map['f'] = 13;
    prime_map['g'] = 17;
    prime_map['h'] = 19;
    prime_map['i'] = 23;
    prime_map['j'] = 29;
    prime_map['k'] = 31;
    prime_map['l'] = 37;
    prime_map['m'] = 41;
    prime_map['n'] = 43;
    prime_map['o'] = 47;
    prime_map['p'] = 53;
    prime_map['q'] = 59;
    prime_map['r'] = 61;
    prime_map['s'] = 67;
    prime_map['t'] = 71;
    prime_map['w'] = 73;
    prime_map['x'] = 79;
    prime_map['y'] = 83;
    prime_map['z'] = 89;
    
    string anagram_test;
    int test_len;
    
    cin >> anagram_test;
    cin >> test_len;
    
    map<unsigned char, int> result_map;
    
    for (int i=0; i<(anagram_test.length()-test_len+1); i++) {
        unsigned char counter=1;
        
        for (int j=0; j<test_len; j++) {
            counter *= prime_map[anagram_test[j]];
        }
        
        if (result_map.find(counter) == result_map.end()) {
            result_map[counter] = 1;
        } else {
            result_map[counter]++;
        }
    }
    
    for (auto it: result_map) {
        //cout << it.first << "\n";
        
        int a = (int)it.first;
    
        if (it.second > 1) {
            cout << it.second << " instances of number: " << a << "!\n";
        }
    }
}
