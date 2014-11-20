using namespace std;
#include <iostream>
#include <stdexcept>
#include <fstream>
#include <sstream>

char* getFilNameFromArgs(int argc, char* argv[]) {
        switch(argc) {
            case 2:
                return argv[1];
            case 3:
                return argv[2];
            default:
                throw std::runtime_error("WHAT THE FUCK DID I DO WRING!");
        }
}



int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Usage: ArnoldCpp [-run] [FileToSourceCode]" << endl;
        return 1;
    }
    char *filename;
    try {
        filename = getFilNameFromArgs(argc,argv);
    } catch (std::exception &e) {
        cout << "Too many arguments" << endl;
        return(-1);
    }
    // read the source file
    // sourceCode available as
    // sourceCode.str()
    std::ifstream t(filename);
    std::stringstream sourceCode;
    sourceCode << t.rdbuf();
    
    return 0;
}
    
