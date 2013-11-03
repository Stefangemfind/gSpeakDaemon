#include "config.h"

using namespace std;

/**
 * setIni
 *
 * Set the configuration file.
 * 
 * @param <std::string> ini The configuration file you want to use.
 */
void config::setIni(std::string ini){
    iniFile = ini;
}

/**
 * getValue
 *
 * Retrieve a value from the configuration.
 * 
 * @param <std::string> parent The category of the value you want to retrieve.
 * @param <std::string> value The name of the value you want to retrieve.
 * @return <std::string> The value from the configuration file.
 */
std::string config::getValue(std::string parent, std::string value){
    bool foundParent = false;
    bool foundValue = false;
    
    std::string returnString;
    std::string loop;
    std::string compare;
    
    ifstream in(iniFile.c_str());
    
    while(std::getline(in, loop)) {
        if(loop == parent){
            foundParent = true;
        }
        if(foundParent == true && foundValue != true){
            compare = loop.substr(0, value.length());
            if(compare == value){
                foundValue = true;
                returnString = loop.substr(value.length() + 1);
            }
        }
    }
    
    in.close();
    
    return returnString;
}
