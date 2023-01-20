//
// Created by Ella Grace Collard on 9/6/22.
//

#include "Tweet.h"
#include <sstream>

void Tweet::calculateTweetSentiment(DSVector<Word> & classifier) {
    stringstream words(tweet.c_str());
    char temp[500];
    while(words.getline(temp, 500, ' ')) {
        Word butt(temp);
        auto found = std::find(classifier.begin(), classifier.end(), butt);

        // if the word we are looking for is not in our classifier
        if (found == classifier.end()) {
            // ignore it
        }
        // if the word is in the classifier
        else{
            // check the sentiment of the word
            // if it is positive (4),
            if (found->getSentiment() == 4)
                this->incrementPositiveWords();
            else
                this->incrementNegativeWords();
        }
    }

    if(numPositiveWords >= numNegativeWords)
        sentiment = 4;
    else
        sentiment = 0;
}

int Tweet::getTweetSentiment() {
    return sentiment;
}

void Tweet::incrementPositiveWords() {
    numPositiveWords += 1;
}

void Tweet::incrementNegativeWords() {
    numNegativeWords += 1;
}

DSString Tweet::returnID() {
    return ID;
}

Tweet::Tweet() {
    tweet = "default constructor";
    ID = "n/a";
    sentiment = 0;
    numPositiveWords = 0;
    numNegativeWords = 0;
}

Tweet::Tweet(int sentiment, DSString ID, DSString tweetwords) {
    this->sentiment = sentiment;
    this->ID = ID;
    this-> tweet = tweetwords;
    sentiment = 0;
    numPositiveWords = 0;
    numNegativeWords = 0;
}

const DSString &Tweet::getTweet() const {
    return tweet;
}

void Tweet::setTweet(const DSString &tweet) {
    Tweet::tweet = tweet;
}

const DSString &Tweet::getId() const {
    return ID;
}

void Tweet::setId(const DSString &id) {
    ID = id;
}

int Tweet::getSentiment() const {
    return sentiment;
}

void Tweet::setSentiment(int sentiment) {
    Tweet::sentiment = sentiment;
}

int Tweet::getNumPositiveWords() const {
    return numPositiveWords;
}

void Tweet::setNumPositiveWords(int numPositiveWords) {
    Tweet::numPositiveWords = numPositiveWords;
}

int Tweet::getNumNegativeWords() const {
    return numNegativeWords;
}

void Tweet::setNumNegativeWords(int numNegativeWords) {
    Tweet::numNegativeWords = numNegativeWords;
}
