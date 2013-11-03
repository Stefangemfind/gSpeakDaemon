#include "processDaemon.h"

#define BUFFER 128 //Line buffer for pipe

/**
 * init
 *
 * Start the daemon.
 * 
 * @param <std::string> config The configuration file you want to use.
 */
void processDaemon::init(std::string config){
    
    //Set the configuration file
    c.setIni(config);
    
    //Initialize the speech software
    s.initSpeak(config);
    
    //Variable declarations
    FILE* pipe = popen(c.getValue("[General]", "Hcidump").c_str(), "r");
    char buffer[BUFFER];
    std::string bufferStr;
    std::size_t found;
    
    //Loop the hcidump tool and wait for the headset button to be pressed
    while(!feof(pipe)){
    	fgets(buffer, BUFFER, pipe);
        bufferStr = buffer;
        
        //If pressed
        found = bufferStr.find(c.getValue("[General]", "KeyPress"));
        if(found!=std::string::npos){
            if(!this->isRunning(c.getValue("[General]", "ProcessName"))){
                s.speakThis(c.getValue("[General]", "ToSay"));
                system(c.getValue("[General]", "ToLaunch").c_str());
            }
        }
    }
    
    //Close pipe
    pclose(pipe);
}

/**
 * isRunning
 *
 * Checks if a process is running or not.
 * 
 * @param <std::string> process The name of the process.
 * @return <int> 1 for true, 0 for false.
 */
int processDaemon::isRunning(std::string process){
    int running = 0;
    
    //Variable declarations
    std::string command = c.getValue("[General]", "Ps") + " aux | " + c.getValue("[General]", "Grep") + " " + process;
    std::string bufferStr;
    std::size_t found;
    FILE* pipe = popen(command.c_str(), "r");
    char buffer[BUFFER];
    
    //Loop the hcidump tool and wait for the headset button to be pressed
    while(!feof(pipe)){
    	fgets(buffer, BUFFER, pipe);
        bufferStr = buffer;
        
        //If found
        found = bufferStr.find("./" + c.getValue("[General]", "ProcessName"));
        if(found!=std::string::npos){
            if(bufferStr[found + c.getValue("[General]", "ProcessName").length() + 2] == '\n'){
                running = 1;
            }
        }
    }
    
    //Close pipe
    pclose(pipe);
    
    return running;
}
