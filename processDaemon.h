#ifndef PROCESSDAEMON_H
#define	PROCESSDAEMON_H

#include "config.h"
#include "speak.h"

class processDaemon{

public:
    void init(std::string); //Initialization function

private:
    int isRunning(std::string); //Checks if URL or IP is alive or dead

    speak s; //Connection to the speak class
    config c; //Connection to the config class
    
};

#endif	/* PROCESSDAEMON_H */
