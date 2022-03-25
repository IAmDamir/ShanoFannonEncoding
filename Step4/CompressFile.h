//
// Created by Damir on 3/21/2022.
//

#pragma once
#ifndef TI_ASSIGNMENT_1_COMPRESSFILE_H
#define TI_ASSIGNMENT_1_COMPRESSFILE_H

#include <fstream>
#include <vector>
#include "../Step2/Node.h"

using namespace std;

class CompressFile {
public:
  CompressFile(const string& inputFile, const string& outputFile);
  ~CompressFile();

  string ShannonFanoToBinary(const vector<Node*> &characters);
  void close();
private:
  ifstream in;
  ofstream out;

  static string findCodeByChar(const vector<Node*> &characters, char ch);
};


#endif //TI_ASSIGNMENT_1_COMPRESSFILE_H
