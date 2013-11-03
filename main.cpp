#include "processDaemon.h"

using namespace std;

int main(int argc, char **argv){

    if(argc != 2){
        cout << "Syntax error!" << endl << "Syntax: " << argv[0] << " <config>" << endl;
        exit(0);
    }
    
    //Connect to the class and start the daemon
    processDaemon pd;
    pd.init(argv[1]);
    
    return 0;
}