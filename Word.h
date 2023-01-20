//
// Created by Ella Grace Collard on 9/14/22.
//

#ifndef ASSIGNMENT2_SENTIMENT_WORD_H
#define ASSIGNMENT2_SENTIMENT_WORD_H
#include "DSString.h"


class Word {
public:
    //when called, these incrementing functions will add 1 to the number of negative and positive words
    void incrementNegativeOccurrences();
    void incrementPositiveOccurrences();

    //returns sentiment as int: 4 if there are more positive occurrences and 0 if there are more negative Occurrences
    int getSentiment();

    //operator less than; returns true if word is less than referenced word "rhs". false if otherwise.
    bool operator<(const Word& rhs);
    //operator equals; returns true if word and referenced word "rhs" are equal. false is otherwise.
    bool operator==(const Word& rhs);
    //constructor setting char* as word with 0 negative and positive occurrences
    Word(char*);
    //default constructor; word set as "default constructor" with 0 negative and positive occurrences
    Word();
private:

    //the word will be of type DSString
    DSString word;

    //integer counters for positive and negative words (used in increment functions)
    int numPositiveOccurrences;
    int numNegativeOccurrences;
};

#endif //ASSIGNMENT2_SENTIMENT_WORD_H
