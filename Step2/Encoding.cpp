//
// Created by Damir on 3/21/2022.
//

#include "Encoding.h"


// characters should contain all characters that was in the text in ascending order
// midstep contain all steps to make nodes
void Encoding::fanoShannon(const vector<Node*>& characters, vector<int>& midstep, int beg, int end, int& iteration){
  if(beg==end) {
    --iteration;
    return;
  }

  printf("Step %d\n", iteration);
  int y=beg;
  int z=end;
  float sum_left = 0;
  float sum_right = 0;
  while(y<=z){
    if(sum_left<=sum_right){
      sum_left+=characters[y]->getFrequency();
      y++;
    }
    else{
      sum_right+=characters[z]->getFrequency();
      z--;
    }
  }

  for(int h=beg;h<y;h++){
    characters[h]->setCode(characters[h]->getCode()+"0");
  }

  for(int h=y;h<=end;h++){
    characters[h]->setCode(characters[h]->getCode()+"1");
  }

  int nodeCounter = 0;

  // if y was not added already add it and sort midstep
  if (std::find(midstep.begin(), midstep.end(), y) == midstep.end()) {
    midstep.push_back(y);
    std::sort(midstep.begin(), midstep.end());
  }

  int prevMidStep = 0;
  for (int i : midstep) {
    float tempSum = 0;
    string ch;
    string code = characters[i-1]->getCode();
    for (int j = prevMidStep; j < i; ++j) {
      tempSum+=characters[j]->getFrequency();
      ch.push_back(characters[j]->getCharacter());
      validateChar(ch);
      ch.push_back(' ');
    }
    if (tempSum != 0 && ++nodeCounter)
      // %d means output int
      // %.3f means output float (%f) with precision of 3 digits
      // %s means output c styled string
      printf("Node%-2d: (%s) %s - sum %.3f\n", nodeCounter, code.c_str(), ch.c_str(), tempSum);
    prevMidStep = i;
  }

  fanoShannon(characters, midstep, beg, y-1, ++iteration);
  fanoShannon(characters, midstep, y, end, ++iteration);
}

void Encoding::Encode(const map<char, float>& frequencies, vector<Node*>& characters) {
  // Using new keyword to create characters, need to delete them after
  for (auto& pair:frequencies) {
    characters.push_back(new Node(pair.second, pair.first));
  }

  std::sort(characters.begin(), characters.end(), CompareNodes());
  vector<int> midstep;

  midstep.push_back(characters.size());

  int iteration = 0;

  fanoShannon(characters, midstep, 0, characters.size()-1, iteration);
}