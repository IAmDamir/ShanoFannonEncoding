//
// Created by Damir on 3/21/2022.
//

#pragma once
#ifndef TI_ASSIGNMENT_1_CALCULATEDATACOMPRESSION_H
#define TI_ASSIGNMENT_1_CALCULATEDATACOMPRESSION_H

#include <fstream>
#include <limits>
#include <vector>
#include "../Step2/Node.h"

using namespace std;

class CalculateDataCompression {
public:
  CalculateDataCompression(const string& inputFile, const string& outputFile);
  ~CalculateDataCompression();

  void outputCompressionRatio(const vector<Node*> &characters);

  unsigned long getNumberOfBitsIn();
  unsigned long getNumberOfBitsOut();
  float getAverageCodeLength(const vector<Node*> &characters);
  void close();
private:
  ifstream in;
  ifstream out;
  unsigned long numberOfBitsIn;
  unsigned long numberOfBitsOut;

};


#endif //TI_ASSIGNMENT_1_CALCULATEDATACOMPRESSION_H
