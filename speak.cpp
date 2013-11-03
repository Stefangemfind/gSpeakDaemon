#include "speak.h"
#include "config.h"

using namespace std;

/**
 * initSpeak
 *
 * Initialize Festival.
 * 
 * @param <std::string> config The configuration file you want to use.
 */
void speak::initSpeak(std::string config){

    c.setIni(config);
    
    festival_initialize(atoi(c.getValue("[General]", "LoadInitFiles").c_str()), atoi(c.getValue("[General]", "HeapSize").c_str()));

    const char *c_str = c.getValue("[General]", "Voice").c_str();
    const EST_String Voice(c_str);
    festival_eval_command(c_str);

}

/**
 * speakThis
 *
 * Prompt the system to speak a phrase.
 * 
 * @param <std::string> phrase The phrase you want spoken.
 */
void speak::speakThis(string phrase){
    if(phrase == ""){
        return;
    }else{
        if(isAlive(c.getValue("[General]", "SpeechUrl")) == 1){
            speakGoogle(phrase);
        }else{
            speakFestival(phrase);
        }
    }
}

/**
 * speakFestival
 *
 * Prompt the system to use Festival when speaking a phrase.
 * 
 * @param <std::string> phrase The phrase you want Festival to say.
 */
void speak::speakFestival(std::string phrase){
    const char *c_str = phrase.c_str();
    const EST_String Phrase(c_str);

    festival_say_text(Phrase);
}

/**
 * speakGoogle
 *
 * Prompt the system to use Google when speaking a phrase.
 * 
 * @param <std::string> phrase The phrase you want Google to say.
 */
void speak::speakGoogle(std::string phrase){
    std::string command = c.getValue("[General]", "SpeechScript") + " \"" + phrase + "\";";
    system(command.c_str());
}

/**
 * isAlive
 *
 * Checks if a URL or IP is alive by pinging it.
 * 
 * @param <std::string> site The URL or IP you want to ping.
 * @return <int> return 1 if alive, 0 is dead.
 */
int speak::isAlive(std::string site){
    
    std::string command = c.getValue("[General]", "Ping") + " -c 1 " + site;
    FILE* pipe = popen(command.c_str(), "r");
    std::string bufferStr;
    char buffer[128];
    std::size_t found;
    int alive = 0;
    
    while(!feof(pipe)) {
    	fgets(buffer, 128, pipe);
        bufferStr = buffer;
        
        found = bufferStr.find("1 packets transmitted, 1 received");
        if(found!=std::string::npos){
             alive = 1;
        }
        
    }
    pclose(pipe);
    
    return alive;
}
