//
// Created by Damir on 3/21/2022.
//

#include <iostream>
#include <stack>
#include "CompressFile.h"

CompressFile::CompressFile(const string& inputFile, const string& outputFile) {
  in.open(inputFile);
  out.open(outputFile);
}

CompressFile::~CompressFile() {
  in.close();
  out.close();
}

string CompressFile::ShannonFanoToBinary(const vector<Node *> &characters) {
  string sequenceOfBinaryDigits;
  in.seekg(ios_base::beg);
  out.seekp(ios_base::beg);

  string str((istreambuf_iterator<char>(in)),
             istreambuf_iterator<char>());

  for (const char& ch:str)
    sequenceOfBinaryDigits += findCodeByChar(characters, ch);

  out << sequenceOfBinaryDigits;
  return sequenceOfBinaryDigits;
}

string CompressFile::findCodeByChar(const vector<Node *> &characters, char ch) {
  for (auto& node:characters) {
    if (node->getCharacter() == ch)
      return node->getCode();
  }

  return "";
}

void CompressFile::close() {
  in.close();
  out.close();
}
