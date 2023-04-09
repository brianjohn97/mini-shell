//
// Created by brian on 4/9/2023.
//
using namespace std;


#ifndef CS470_LIBRARY_H
#define CS470_LIBRARY_H


void determineType(string str){
    filesystem::file_status status = filesystem::status(str);
    filesystem::file_type type = status.type();

    switch(type){
        case filesystem::file_type::regular:
            cout << "This files type is regular.\n";
            break;
        case filesystem::file_type::none:
            cout << "There is no file type.\n";
            break;
        case filesystem::file_type::not_found:
            cout << "The file type was unfortunately not found.\n";
            break;
        case filesystem::file_type::block:
            cout << "The type of the file is block\n";
            break;
        case filesystem::file_type::directory:
            cout << "The file is of type directory.\n";
            break;
        case filesystem::file_type::symlink:
            cout << "The type of this file is symlink.\n";
            break;
        case filesystem::file_type::character:
            cout << "The type of this file is character.\n";
            break;
        case filesystem::file_type::fifo:
            cout << "This files type is fifo.\n";
            break;
        case filesystem::file_type::socket:
            cout << "This file has a socket type.\n";
            break;
        case filesystem::file_type::unknown:
            cout << "The file type of this file is unknown.\n";
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


#endif //CS470_LIBRARY_H
