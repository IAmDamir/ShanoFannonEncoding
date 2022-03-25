//
// Created by Damir on 3/21/2022.
//

#include <iostream>
#include "CalculateDataCompression.h"

CalculateDataCompression::CalculateDataCompression(const string &inputFile, const string &outputFile) {
  in.open(inputFile, std::ifstream::ate | std::ifstream::binary);
  out.open(outputFile, std::ifstream::ate | std::ifstream::binary);

  numberOfBitsIn = in.tellg() * sizeof(char) * 8;
  numberOfBitsOut = out.tellg();
}

CalculateDataCompression::~CalculateDataCompression() {
  in.close();
  out.close();
}

void CalculateDataCompression::outputCompressionRatio(const vector<Node *> &characters) {
  printf("Number of bits in the original text: %lu bits\n"
         "Number of bits in the compressed text: %lu bits\n"
         "Compression ratio = %.2f\n"
         "Average code length = %.2f bits/symbol",
         numberOfBitsIn, numberOfBitsOut,
         static_cast<float>(numberOfBitsIn)/numberOfBitsOut,
         getAverageCodeLength(characters));
}

unsigned long CalculateDataCompression::getNumberOfBitsIn() {
  return numberOfBitsIn;
}

unsigned long CalculateDataCompression::getNumberOfBitsOut() {
  return numberOfBitsOut;
}

float CalculateDataCompression::getAverageCodeLength(const vector<Node *> &characters) {
  float averageCodeLength = 0.0;
  for (const auto& node:characters) {
    averageCodeLength += node->getCode().size();
  }

  averageCodeLength /= characters.size();

  return averageCodeLength;
}

void CalculateDataCompression::close() {
  in.close();
  out.close();
}
