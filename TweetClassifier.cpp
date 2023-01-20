//
// Created by Ella Grace Collard on 9/14/22.
//

#include "TweetClassifier.h"
#include <fstream>
#include <sstream>

void TweetClassifier::inputData(char **args) {
    ifstream input(args[1]);
    char temp[10000];
    input.getline(temp,10000, '\n');
    while(input.getline(temp,10000, '\n')){
        stringstream tweet(temp);
        tweet.getline(temp,10000, ',');
        int sentiment = (temp[0] == '4')? 4 : 0;
        tweet.getline(temp,10000, ',');
        DSString ID = temp;
        tweet.getline(temp,10000, ',');
        tweet.getline(temp,10000, ',');
        tweet.getline(temp,10000, ',');
        tweet.getline(temp,10000, ',');
        DSString tweetwords = temp;
        Tweet addedtweet(sentiment, ID, tweetwords);
        tweets.push_back(addedtweet);
    }
}

void TweetClassifier::trainClassifier(char **args ) {
    for(int i = 0; i < tweets.size(); i++){
        // create a stringstream
        stringstream traintweet(tweets[i].getTweet().c_str());
        // use a while loop to loop through all the words in each tweet
        char temp[10000];
        while(traintweet.getline(temp,10000,' ')){
            auto foundIt = std::find(classifier.begin(), classifier.end(), Word(temp));

            if(foundIt == classifier.end()){
                // if the word is not in the classifier
                Word tempWord(temp);
                if (tweets[i].getSentiment() == 0){
                    tempWord.incrementNegativeOccurrences();
                }
                else{
                    tempWord.incrementPositiveOccurrences();
                }
                this->classifier.push_back(tempWord);
            }
            // if it is already, increment the pos words or neg words in alignment with the tweets sentiment
            else {
                if (tweets[i].getSentiment() == 0){
                    foundIt->incrementNegativeOccurrences();
                }
                else{
                    foundIt->incrementPositiveOccurrences();
                }
            }

        }
        // create word objects for each of the words only if it is not in the classifier already

            // if it isnt', then create a word object and increment the pos words or neg words the same way
    }

}

void TweetClassifier::inputTesting(char **args) {

    ifstream input(args[2]);
    char temp[10000];
    input.getline(temp,10000, '\n');
    while(input.getline(temp,10000, '\n')){
        stringstream tweet(temp);
        tweet.getline(temp,10000, ',');
        DSString ID = temp;
        tweet.getline(temp,10000, ',');
        tweet.getline(temp,10000, ',');
        tweet.getline(temp,10000, ',');
        tweet.getline(temp,10000, ',');
        DSString tweetwords = temp;
        Tweet addedtweet(false, ID, tweetwords);
        testingTweets.push_back(addedtweet);
    }
}

void TweetClassifier::classifyTesting(char **args) {
    for(int i=0; i < testingTweets.size(); i++){
        testingTweets[i].calculateTweetSentiment(classifier);
    }
}

void TweetClassifier::output(char **args) {
    ofstream Output(args[4]);
    for(int i = 0; i < testingTweets.size(); i++){
        Output << testingTweets[i].getSentiment() << ", " << testingTweets[i].getId() << endl;
    }
    Output.close();
    ofstream output2(args[5]);
    ifstream ActualSentiment(args[3]);
    char temp[100];
    DSVector<int> groundTruths;
    double numCorrect = 0;
    double total = 0;
    ActualSentiment.getline(temp, 99);
    for(int i =0; i<testingTweets.size(); i++){
        ActualSentiment.getline(temp,10, ',');
        int ActualSentimentNum = (temp[0] == '4')? 4 : 0;

        ActualSentiment.getline(temp, 99);
        if (testingTweets[i].getSentiment() == ActualSentimentNum){
            numCorrect++;
            total++;
        }
        else{
            total++;
        }
        groundTruths.push_back(ActualSentimentNum);
    }
    double accuracy = numCorrect/total;
    output2 << std::fixed << setprecision(2);
    output2 << accuracy << endl;
    for(int i = 0; i<testingTweets.size(); i++){
        if (testingTweets[i].getSentiment() != groundTruths[i])
        {
            output2 << testingTweets[i].getSentiment() << ", " << groundTruths[i] << ", " << testingTweets[i].getId() << endl;
        }
    }
    output2.close();
}