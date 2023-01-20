//
// Created by Ella Grace Collard on 9/6/22.
//

#ifndef ASSIGNMENT2_SENTIMENT_TWEET_H
#define ASSIGNMENT2_SENTIMENT_TWEET_H

#include "DSString.h"
#include "Word.h"

class Tweet {
public:
    /* this function calculates the sentiment of each word within the tweet, sums up number of pos/neg
     * words, compares the totals, and assigns a 0 or 4 depending on majority
     *
     * implemented by:
     * referencing a DSVector of type Word
     * creates a stringstream of words from the tweet
     * for while loop: uses getline to receive each word and places it in a temp char array which is then placed in a temp word object
     * checks to see if the word we're looking for is or isn't in classifier
     * if it's not, ignore it
     * if it is, check the sentiment of the word
     * if positive, increment number of positive words
     * if negative, increment number of negative words
     * while loop ends
     * check to see if number of positive words outweighs number of negative words
     * if so, sentiment is 4
     * if number of negative words is greater than or equal to number of positive words, sentiment is 0
     */
    void calculateTweetSentiment(DSVector <Word> &);

    //returns tweet's sentiment
    int getTweetSentiment();

    //add one to num of pos/neg words when called
    void incrementPositiveWords();
    void incrementNegativeWords();

    //returns ID
    DSString returnID();

    /*
     * default constructor:
     * sets tweet as "default constructor"
     * sets ID as "n/a"
     * sets sentiment as 0
     * sets num pos words as 0
     * sets num neg words as 0
     */
    Tweet();
    /*
     * constructor with arguments:
     * sets sentiment to passed-in int sentiment
     * sets ID to passed-in DSString ID
     * sets tweet to passed-in DSString tweetwords
     * sets sentiment to 0
     * sets num pos words to 0
     * sets num neg words to 0
     */
    Tweet(int sentiment, DSString ID, DSString tweetwords);

    // getters and setters for tweet, ID, sentiment, and num pos/neg words
    const DSString &getTweet() const;
    void setTweet(const DSString &tweet);
    const DSString &getId() const;
    void setId(const DSString &id);
    int getSentiment() const;
    void setSentiment(int sentiment);
    int getNumPositiveWords() const;
    void setNumPositiveWords(int numPositiveWords);
    int getNumNegativeWords() const;
    void setNumNegativeWords(int numNegativeWords);

private:
    //tweet and ID of type DSString
    DSString tweet;
    DSString ID;
    //sentiment, num neg words and num pos words as ints
    int sentiment;
    int numPositiveWords;
    int numNegativeWords;
};


#endif //ASSIGNMENT2_SENTIMENT_TWEET_H
