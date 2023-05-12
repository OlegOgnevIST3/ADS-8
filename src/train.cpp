// Copyright 2021 NNTU-CS
#include "train.h"
Train::Train():first(nullptr), countOp(0) {}
void Train::addCage(bool isLightOn) {
  Cage* cage = new Cage;
  cage->next = nullptr;
  cage->prev = nullptr;
  Cage* temp;
  cage->light = isLightOn;
  if (first == nullptr) {
    first = cage;
  } else {
    if (first->next == nullptr) {
      first->next = cage;
      first->prev = cage;
      cage->prev = first;
      cage->next = first;
    } else {
      temp = first;
      while (temp->next != first) {
        temp = temp->next;
      }
      temp->next = cage;
      cage->prev = temp;
      cage->next = first;
      first->prev  = cage;
    }
  }
  countOp = 0;
}
int Train::getLength() {
  Cage* temp;
  int cageCount;
  countOp = 0;
  first->light = true;
  while (first->light == true) {
    temp = first->next;
    while (temp->light == false) {
      temp = temp->next;
      countOp++;
    }
    countOp++;
    temp->light = false;
    cageCount = 1;
    while (temp->prev != first) {
      temp = temp->prev;
      countOp++;
      cageCount++;
    }
    countOp++;
  }
  return cageCount;
}
int Train::getOpCount() {
  if (countOp == 0)
    getLength();
  return countOp;
}
