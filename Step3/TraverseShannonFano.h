//
// Created by Damir on 3/23/2022.
//

#pragma once
#ifndef TI_ASSIGNMENT_1_TRAVERSESHANNONFANO_H
#define TI_ASSIGNMENT_1_TRAVERSESHANNONFANO_H


#include "../Step2/Node.h"
#include "../Step2/CompareNodes.h"
#include <vector>
#include <iostream>

using namespace std;

class TraverseShannonFano {
public:
  static inline void outputShannonFano(vector<Node*>& characters) {
    std::sort(characters.begin(), characters.end(), CompareNodes());

    for (auto& node:characters) {
      string ch, code;
      float frequency = node->getFrequency();
      code = node->getCode();
      ch.push_back(node->getCharacter());
      validateChar(ch);

      printf("%s - %.3f - %s\n", ch.c_str(), frequency, code.c_str());
    }
  }
};


#endif //TI_ASSIGNMENT_1_TRAVERSESHANNONFANO_H
