#ifndef RECORDTOOLS_H
#define RECORDTOOLS_H

#include <string>

void addRecord(std::string names[], int hp[], int attack[],
    int& count, int capacity);

void displayRecords(const std::string names[], const int hp[],
    const int attack[], int count);

double calculateAverageAttack(const int attack[], int count);

#endif