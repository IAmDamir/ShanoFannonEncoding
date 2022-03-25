//
// Created by Damir on 3/14/2022.
//

#pragma once
#ifndef TI_ASSIGNMENT_1_FILEMANAGER_H
#define TI_ASSIGNMENT_1_FILEMANAGER_H

#include <fstream>
#include <map>
#include <limits>
#include <set>
#include <iomanip>

using namespace std;

class FileManager {
public:
  explicit FileManager(const string& fileName = "");
  ~FileManager();

  long getSize();

  map<char, float> getFrequencies(long fileSize);
  static void outputFrequencies(const map<char, float>& frequencies);
  void close();
private:
  fstream file;
};


#endif //TI_ASSIGNMENT_1_FILEMANAGER_H
