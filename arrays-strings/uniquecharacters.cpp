#include <string>
#include <vector>
#include <iostream>
#include <bitset>

using namespace std;

/* For simplicity assume char set is ASCII (if not, we need to increase the
storage size. The rest of the logic would be the same.)
Time complexity is O(n), where n is the length of the string, and space
complexity is O(n).*/
bool isUniqueChars(const string &str){
  if (str.length() > 128) {
    return false;
  }
  vector<bool> char_set(128);
  for (int i = 0; i < str.length(); i++){
    int val = str[i];
    if (char_set[val]){
      return false;
    }
    char_set[val] = true;
  }
  return true;
}

/* We can reduce the space usage a little bit by using a bit vector. We will
assume in the below code, that the string is only lower case 'a' to 'z'. This
will allow us to use just a single int. */
bool isUniqueChars_bitvector(const string &str) {
  // Reduce space usage by a factor of 8 using bitvector.
  // Each boolean otherwise occupies a size of 8 bits.
  bitset<256> bits(0);
  for(int i = 0; i < str.length(); i++) {
    int val = str[i];
    if(bits.test(val) > 0) {
      return false;
    }
    bits.set(val);
  }
  return true;
}

/* Alternatively, we could every char og the string with every other char of
the string for duplicate occurances. This will take O(n^2) time and no space.
If we are allowed to destroy the input string, we could sort the string in
O(n log n) time and then linearly check the string for neighboring characters
that are identical. Careful, though - many sorting algorithms take up extra
space. */
bool isUniqueChars_noDS(const string &str) {
  for( int i = 0; i < str.length()-1; i++) {
    for( int j = i+1; j < str.length(); j++) {
      if(str[i] == str[j]) {
        return false;
      }
    }
  }
  return true;
}

int main(){
  vector<string> words = {"abcde", "hello", "apple", "kite", "paddle"};
  for(auto word : words) {
    cout << word << string(": ") << boolalpha << isUniqueChars(word) << endl;
  }
  cout << endl << "Using no data structrues" << endl;
  for(auto word : words) {
    cout << word << string(": ") << boolalpha << isUniqueChars_noDS(word) << endl;
  }
  return 0;
}
