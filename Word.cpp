//
// Created by Ella Grace Collard on 9/14/22.
//

#include "Word.h"

void Word::incrementNegativeOccurrences() {
    numNegativeOccurrences += 1;
}

void Word::incrementPositiveOccurrences() {
    numPositiveOccurrences += 1;
}

int Word::getSentiment() {
    if (numPositiveOccurrences >= numNegativeOccurrences){
        return 4;
    }
    return 0;

}

bool Word::operator<(const Word &rhs) {
    if(word < rhs.word){
        return true;
    }
    return false;
}

bool Word::operator==(const Word &rhs) {
    if(word == rhs.word){
        return true;
    }
    return false;
}

Word::Word(char * worddd) {
    word = worddd;
    numPositiveOccurrences = 0;
    numNegativeOccurrences = 0;
}

Word::Word() {
    word = "default constructor";
    numNegativeOccurrences = 0;
    numPositiveOccurrences = 0;
}
