
#include <iostream>
#include <string>
#include <math.h> 

using namespace std;

int myAtoi(string s) {
  int n = s.length();

  int signRead = 0;

  int digits[13];
  int pos = 0;
  int sumDigit = 0;

  for (int i = 0; i < n; i++) {
    char c = s[i];

    if (c == 32) {
      if (signRead > 0 || pos > 0) break;            
      continue;
    }
    else if (c > 47 && c < 58) {

      if (pos > 0 && sumDigit == 0) {
        if (c == 48) continue;
      }

      digits[pos] = c;
      pos++;
      sumDigit += c-48;

      if (pos > 12) break;
      continue;
    } 
    else if (c == 45 || c == 43) {
      if (signRead > 0 || pos > 0) break;            
      signRead = c;
      continue;
    }

    break;
  }

  long res = 0;
  for (int i = 0; i < 13; i++) {
    if (pos == i) break;
    res += (digits[i]-48) * pow(10,pos-1-i);
  }
  res = signRead == 45 ? -res : res;

  int actualResult = 0;

  if (res < -2147483648) actualResult = -2147483648;
  else if (res > 2147483647) actualResult = 2147483647;
  else actualResult = res;

  return actualResult;
}    

int main() 
{
    return 0;
}