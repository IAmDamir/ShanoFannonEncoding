//
// Created by Damir on 3/14/2022.
//

#include "FileManager.h"
#include "iostream"
#include "../StringValidator.h"


FileManager::FileManager(const string &fileName) {
  file.open(fileName, ios::in | ios::out | ios::app);
}

FileManager::~FileManager() {
  file.close();
}

map<char, float> FileManager::getFrequencies(long fileSize) {
  file.seekg (ios::beg);
  map<char, float> result;
  string str;
  // going through every line in the file
  while(getline(file, str)) {
    // going through every character in the line and assigning values to the map
    for (const char& ch : str) {
      // the default value of int in map is 0, so increment works without exceptions
      result[ch]++;
    }
  }

  for (auto& pair: result) {
    pair.second /= static_cast<float>(fileSize);
  }

  return result;
}

long FileManager::getSize() {
  // position the pointer to the end
  file.seekp(0, ios::end);

  return file.tellp();
}

void FileManager::outputFrequencies(const map<char, float>& frequencies) {
  // uses set to sort every pair by frequency
  // it will be sorted in ascending order
  set<pair<float, char>> orderedFrequencies;  // The new (temporary) container.

  for (auto const &[k, v] : frequencies)
    orderedFrequencies.emplace(v, k);  // Flip the pairs.
  // outputting frequency of every char in the file
  // using rend and rbegin to output frequencies in reversed(descending) order
  // if frequencies is the same for some characters it will output in reversed alphabetical order
  // if it is not appropriate we could use vector instead of set and sort it manually
  for_each(orderedFrequencies.rbegin(), orderedFrequencies.rend(),
           [](pair<float, const char> pair) {
             // we will use this string as output
             // assigning character value from pair into string
             string ch{pair.second};
             validateChar(ch);

             // outputting
             // %-2s means output string (%s) taking space of 2 chars (2) with left align (-)
             // we use ch.c_str() to turn ch to char*, because printf requires c styled string
             // %.3f means output float (%f) with precision of 3 digits
             printf("%-2s - %.3f\n", ch.c_str(), pair.first);
           });
}

void FileManager::close() {
  file.close();
}
