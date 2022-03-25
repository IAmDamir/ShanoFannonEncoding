//
// Created by Damir on 3/17/2022.
//

#pragma once

#ifndef TI_ASSIGNMENT_1_COMPARENODES_H
#define TI_ASSIGNMENT_1_COMPARENODES_H
class CompareNodes {
public:
  bool operator()(Node* l, Node* r){
    return l->getFrequency() > r->getFrequency();
  }
};
#endif //TI_ASSIGNMENT_1_COMPARENODES_H
