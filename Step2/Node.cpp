//
// Created by Damir on 3/16/2022.
//

#include "Node.h"

Node::Node(float frequency, char character, const std::string& code) {
  this->frequency = frequency;
  this->character = character;
  this->code = code;
  //right = left = nullptr;
}

Node::Node() {
  this->frequency = 0;
  this->character = '\0';
  this->code = "";
  //right = left = nullptr;
}

Node::~Node() = default;


float Node::getFrequency() const {
  return frequency;
}


void Node::setFrequency(float frequency) {
  Node::frequency = frequency;
}

char Node::getCharacter() const {
  return character;
}

void Node::setCharacter(char character) {
  Node::character = character;
}

const std::string &Node::getCode() const {
  return code;
}

void Node::setCode(const std::string &code)  {
  Node::code = code;
}