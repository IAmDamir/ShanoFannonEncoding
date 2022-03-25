//
// Created by Damir on 3/21/2022.
//

#pragma once
#ifndef TI_ASSIGNMENT_1_ENCODING_H
#define TI_ASSIGNMENT_1_ENCODING_H

#include "../StringValidator.h"
#include "Node.h"
#include "CompareNodes.h"
#include <map>
#include <vector>
#include <queue>
#include <iomanip>
#include <iostream>

using namespace std;

class Encoding {
public:
  ~Encoding() = default;
  void Encode(const map<char, float>& frequencies, vector<Node*>& characters);

  void fanoShannon(const vector<Node*>& characters, vector<int>& midstep, int beg,int end,int& iteration);
};


#endif //TI_ASSIGNMENT_1_ENCODING_H
