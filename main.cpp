#include <iostream>
#include <set>
#include <memory>
#include "StringValidator.h"
#include "Step1/FileManager.h"
#include "Step2/Node.h"
#include "Step2/Encoding.h"
#include "Step3/TraverseShannonFano.h"
#include "Step4/CompressFile.h"
#include "Step5/CalculateDataCompression.h"

int main() {
  long fileSize;
  // input and output files
  static string fileIn( R"(..\text.txt)");
  static string fileOut(R"(..\new.txt)");

  map<char, float> frequencies;
  FileManager fileManager(fileIn);
  fileSize = fileManager.getSize();

  cout << "STEP 1" << endl;
  frequencies = fileManager.getFrequencies(fileSize);
  FileManager::outputFrequencies(frequencies);
  fileManager.close();

  vector<Node*> characters;

  cout << "STEP 2" << endl;
  Encoding encoding;
  encoding.Encode(frequencies, characters);

  cout << "STEP 3" << endl;
  TraverseShannonFano::outputShannonFano(characters);

  cout << "STEP 4" << endl;
  CompressFile compressFile(fileIn, fileOut);
  cout << compressFile.ShannonFanoToBinary(characters) << endl;
  compressFile.close();

  cout << "STEP 5" << endl;
  CalculateDataCompression calculateDataCompression(fileIn, fileOut);
  calculateDataCompression.outputCompressionRatio(characters);

  // Deleting characters since they were created using new keyword
  for (auto& ch:characters) {
    delete(ch);
  }
  return 0;
}

