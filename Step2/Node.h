//
// Created by Damir on 3/16/2022.
//

#pragma once
#ifndef TI_ASSIGNMENT_1_NODE_H
#define TI_ASSIGNMENT_1_NODE_H

#include <string>

class Node {
public:
  Node();
  explicit Node(float frequency, char character, const std::string& code = "");
  ~Node();

  float getFrequency() const;
  void setFrequency(float frequency);

  char getCharacter() const;
  void setCharacter(char character);

  const std::string &getCode() const;
  void setCode(const std::string &code);

private:
  float frequency;
  char character;
  std::string code;
};

#endif //TI_ASSIGNMENT_1_NODE_H
