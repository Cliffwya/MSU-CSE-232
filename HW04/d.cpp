#include<iostream>
#include<string>

using namespace std;

string SharedLetters(const string & first, const string second, const string *third){
    string final_string{};

    size_t longest_string = first.size();  //Sets the longest string from the three inputed string so we dont index out of bounds using .at()
    if (second.size() > longest_string) {
        longest_string = second.size();
    }
    if (third->size() > longest_string) {
        longest_string = third->size();
    }

    for(size_t i{0}; i<longest_string;++i){  //Index through the longest string
        int matching_char{0};

        if (i < first.size() && i < second.size() && first.at(i) == second.at(i)) {  //Make sure its in range of the first and second and check to see if first and second are the same
            ++matching_char;
        }
        if (i < second.size() && i < third->size() && second.at(i) == third->at(i)) {  //Same as the previous but second and third
            ++matching_char;
        }
        if (i < first.size() && i < third->size() && first.at(i) == third->at(i)) {  //Same but with first and third
            ++matching_char;
        }

        final_string.push_back(matching_char+'0');  //Adds the amount of matching chars to 0 using char math
        final_string.push_back(',');  //Adds the comma after each number
    }

    return final_string;
}

int main(){
    string first, second, third;

    cin >> first;  //Input for each string
    cin >> second;
    cin >> third;

    cout << SharedLetters(first,second,&third) << endl;  //Print the matching words

    return 0;
}