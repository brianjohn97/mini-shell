#include <iostream>
#include <vector>
#include <sstream>
#include <filesystem>
#include <ostream>
#include <ctime>
using namespace std;

vector <string> arr;
void help() {
    cout << endl;
    cout << "help" << endl;
    cout << "help" << endl;
    cout << "help" << endl;
    cout << "help" << endl;
    cout << "help" << endl;
    cout << endl;

}
void printVector(){
    for (int i = 0; i < arr.size(); ++i) {
        cout << "input"<<i << ": " << arr[i] << endl;
    }
}
void inputString(string str){
    string delim = " ";
    int start = 0;
    int end = str.find(delim);
    while (end != -1) {
        string test = str.substr(start, end - start);

        start = end + delim.size();
        end = str.find(delim, start);
        if (test.empty()){
            continue;
        }
        arr.push_back(test);
    }
    arr.push_back(str.substr(start, end - start));
}
void determineType(string str){
    //current tester
    filesystem::path path = "test.txt";

    filesystem::file_status status = filesystem::status(path);
    filesystem::file_type type = status.type();

    switch(type){
        case filesystem::file_type::regular:
            cout << "reg\n";
            break;
        case filesystem::file_type::none:
            cout << "none\n";
            break;
        case filesystem::file_type::not_found:
            cout << "not found\n";
            break;
    }
}
int main() {

    string prompt = "cwushell> ";
    string temp = prompt;
    string input = "";

    while (true) {

        arr.clear();
        cout << temp;
        getline(cin, input);
        inputString(input);

        if (arr[0] == "prompt") {
            if (arr.size() < 2) {
                temp = prompt;
                continue;
            }
            temp = arr[1] + "> ";
        }else if(arr[0] == "fileinfo"){
            if(arr[1] == "-i"){

            }else if(arr[1] == "-t"){
                determineType(arr[2]);
            }else if(arr[1] == "-m"){

            }
        }else if(arr[0] == "exit"){
            exit(0);
        }else if (input == "-help") {
            help();
            continue;
        }else if(arr[0] == "osinfo"){
            if(arr[1] == "-T"){

            }else if(arr[1] == "-b"){
                filesystem::space_info si = filesystem::space("/");
                cout << "Total number of blocks: " << si.capacity << endl;
            }else if(arr[1] == "-s"){
                cout << "The max amount of characters that can be used for a filename is: " << FILENAME_MAX << endl;

            }
        }
    }
}