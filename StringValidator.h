//
// Created by Damir on 3/21/2022.
//

#pragma once
#ifndef TI_ASSIGNMENT_1_STRINGVALIDATOR_H
#define TI_ASSIGNMENT_1_STRINGVALIDATOR_H
#include <cstddef>
#include <string>

using namespace std;
inline void ReplaceAll(string &str, const string &from, const string &to) {
  size_t start_pos = 0;
  while((start_pos = str.find(from, start_pos)) != string::npos) {
    str.replace(start_pos, from.length(), to);
    start_pos += to.length(); // Handles case where 'to' is a substring of 'from'
  }
}

inline void validateChar(string &ch) {
  // checking if last char is whitespace, if so assigning different value to our string
  // let's use sp instead whitespace, because 2 chars looks better than the whole word
  if (ch.at(ch.length()-1) == ' ') {
    ch.pop_back();
    ch += "sp";
  }
  // nl is for
  // newline
  ReplaceAll(ch, "\r", "nl");
  ReplaceAll(ch, "\n", "nl");
  // ht is for   horizontal tab
  ReplaceAll(ch, "\t", "ht");
  // vt is for
  //           vertical tab
  ReplaceAll(ch, "\v", "vt");
}
class StringValidator {};


#endif //TI_ASSIGNMENT_1_STRINGVALIDATOR_H
