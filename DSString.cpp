//
//
//

#include "DSString.h"

//destructor
DSString::~DSString() {
    //delete str to clear memory
    delete[] str;
}

//default constructor
DSString::DSString() {
    //str points to char array with 1 character
    str = new char[1];
    //make that character null (empty)
    str[0] = '/0';
}

//copy constructor
DSString::DSString(const DSString & copy) {
    //str points to char array with size of referenced DSString "copy", plus 1 for null character
    str = new char[strlen(copy.str) + 1];
    //copy contents of referenced DSString "copy" into str
    strcpy(str, copy.str);
}

//copy constructor
DSString::DSString(const char * s) {
    //str points to char array with size of passed-in char* "s", plus 1 for null character
    str = new char[strlen(s) + 1];
    //copy contents of passed-in char* "s" into str
    strcpy(str, s);

}

//overloaded assignment operator
DSString &DSString::operator=(const DSString & rhs) {
    //delete str to clear memory
    delete[] str;
    //str points to char array with size of referenced DSString "rhs", plus 1 for null character
    str = new char[strlen(rhs.str) + 1];
    //copy contents of referenced DSString "rhs" into str
    strcpy(str, rhs.str);
    return *this;
}

//overloaded assignment operator
DSString &DSString::operator=(const char * rhs) {
    //delete str to clear memory
    delete[] str;
    //str points to char array with size of passed-in char* "rhs", plus 1 for null character
    str = new char[strlen(rhs) + 1];
    //copy contents of passed-in char* "rhs" into str
    strcpy(str, rhs);
    return *this;
}

//returns ptr with null-terminated c-string holding contents of object
const char *DSString::c_str() const {
    return str;
}

//overloaded stream insertion operator
std::ostream &operator<<(ostream & os, const DSString & s) {
    //print referenced DSString "s" contents to ostream
    os << s.str;
    return os;
}

//operator equals
bool DSString::operator==(const DSString & comp) const {
    //returns true if equal using strcmp to compare
    return strcmp(str, comp.str) == 0;
}

//operator less than
bool DSString::operator<(const DSString & comp) const {
    //returns true if str is less than the referenced DSString "comp"
    return strcmp(str, comp.str) < 0;
}

//overloaded non-modifying string concat
DSString DSString::operator+(const DSString & rhs) const {
    //declare new char array "data" with following size: str's length plus rhs's length plus 1 to account for null character
    char data[1 + strlen(str)+ strlen(rhs.str)];
    //copy str's contents into data
    strcpy(data, str);
    //add rhs's contents to data
    strcat(data, rhs.str);
    return data;

}

//substring method returning a part of the string with start and stop
DSString DSString::substring(size_t start, size_t numChars) const {
    //declare new char array "data" with size of str's length plus one to account for null character
    char data[strlen(str) + 1];
    //copy str's contents into data
    strcpy(data, str);
    //declare new int representing which character to assign
    int i = 0;
    //for loop to iterate through characters from start - stop
    for (int x = start; x <= numChars; x++){
        //assign each character
        data[i] = str[x];
        //iterator
        i++;
    }
    return data;
}
