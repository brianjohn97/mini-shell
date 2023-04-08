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
        case filesystem::file_type::block:
            cout << "block\n";
            break;
    }
}
void fileInfoHelp(){
    cout << "FILEINFO\n\n"
            "DESCRIPTION\n"
            "\tYou can use this command to print information about the files: such as \n"
            "\tthe inode number used for each linux file, the last time a file was modified\n"
            "\tor the type of a given a file.\n\n"
            "NAME\n"
            "\tfileinfo - this command is to find information about the files on the computer.\n\n"
            "OPTIONS\n"
            "\t-i[filename]\tThis will print the inode number of the given file.\n\n"
            "\t-t[filename]\tThis option will print the given files type.\n\n"
            "\t-m[filename]\tThis will print the last time the given file was modified.\n\n"
            "\tIf no switch is provided then all three pieces of information above will printed.\n\n";
}
void promptHelp(){
    cout << "PROMPT\n\n"
            "DESCRIPTION\n"
            "\tYou can use this command to change the prompt, currently set to cwushell to anything\n"
            "\tof your choosing.\n"
            "NAME\n"
            "\tprompt - This is the name of the word that sits in front of every command.\n\n"
            "OPTIONS\n"
            "\t[new prompt name]\tAfter prompt type in what you want the new prompt to be.\n\n"
            "\tIf no new prompt is provided then the prompt is changed back to the orginal:cwushell.\n\n";
}
void exitHelp(){
    cout << "EXIT\n\n"
            "DESCRIPTION\n"
            "\tUse this command when you want to close out of this terminal. \n"
            "NAME\n"
            "\texit - Will exit the current shell.\n\n"
            "OPTIONS\n"
            "\tnone\n\n";
}
void osInfoHelp(){
    cout << "OSINFO\n\n"
            "DESCRIPTION\n"
            "\tYou can use this command to print information about the OS of the computer. It will show\n"
            "\tyou information about regarding the type of the file system, the total number of blocks and\n"
            "\tthe max amount of characters that you can use to name a file.\n\n"
            "NAME\n"
            "\tosinfo - this command is to find information the computer.\n\n"
            "OPTIONS\n"
            "\t-T\tThis will print the type of filesystem the computer is using.\n\n"
            "\t-b\tThis option will print the total number of blocks in the file system.\n\n"
            "\t-s\tThis will print the max amount of characters that can be used in a filename\n\n";
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
            if(arr[1] == "-h" || arr[1] == "-help"){promptHelp();continue;}
            if (arr.size() < 2) {
                temp = prompt;
                continue;
            }
            temp = arr[1] + "> ";
        }else if(arr[0] == "fileinfo"){
            if(arr.size() < 2){
                cout << "No filename or specifier was given.\n"
                        "Please try again with more information\n"
                        "You can use fileinfo -h or fileinfo -help for more help.\n";
                continue;
            }

            if(arr[1] == "-i"){
                cout << "-i";
            }else if(arr[1] == "-t"){
                determineType(arr[2]);
            }else if(arr[1] == "-m"){

            }else if(arr[1] == "-help" || arr[1] == "-h") { fileInfoHelp(); continue;
            }else{
                    //if no switch is specified print all three above
            }
        }else if(arr[0] == "exit"){
            if(arr[1] == "-h" || arr[1] == "-help"){exitHelp();}
            exit(0);
        }else if (input == "manual") {
            cout << "\t\t\t\tMANUAL\n\n";
            promptHelp();
            fileInfoHelp();
            osInfoHelp();
            exitHelp();
            continue;
        }else if(arr[0] == "osinfo"){
            if(arr.size() < 2){
                cout << "No specifier was given.\n"
                        "Please try again with a specifier.\n"
                        "You can use osinfo -h or osinfo -help for help.\n";
                continue;
            }
            if(arr[1] == "-T"){

            }else if(arr[1] == "-b"){
                filesystem::space_info si = filesystem::space("/");
                cout << "Total number of blocks: " << si.capacity << endl;
            }else if(arr[1] == "-s"){
                cout << "The max amount of characters that can be used for a filename is: " << FILENAME_MAX << endl;
            }else if(arr[1] == "-h" || arr[1] == "-help"){osInfoHelp();continue;}
        }
    }
}