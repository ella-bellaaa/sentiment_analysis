#include <iostream>
#include <algorithm>

#include "DSString.h"
#include "TweetClassifier.h"

using namespace std;

int main(int argc, char** argv)
{

    for(int i = 0; i < argc; i++)
    {
        cout << "arg " << i << ": " << argv[i] << endl;
    }
    TweetClassifier classifierInstance;
    classifierInstance.inputData(argv);
    classifierInstance.trainClassifier(argv);
    classifierInstance.inputTesting(argv);
    classifierInstance.classifyTesting(argv);
    classifierInstance.output(argv);

    return 0;
}
