//
// Created by Ella Grace Collard on 9/14/22.
//

#ifndef ASSIGNMENT2_SENTIMENT_TWEETCLASSIFIER_H
#define ASSIGNMENT2_SENTIMENT_TWEETCLASSIFIER_H

#include "DSVector.h"
#include "Tweet.h"
#include "Word.h"

class TweetClassifier {
private:

    DSVector<Tweet> tweets;
    DSVector<Tweet> testingTweets;
    DSVector<Word> classifier;
public:
    void inputData(char** args);
    void trainClassifier(char** args);
    void inputTesting(char** args);
    void classifyTesting(char** args);
    void output(char** args);
};


#endif //ASSIGNMENT2_SENTIMENT_TWEETCLASSIFIER_H
