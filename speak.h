#ifndef SPEAK_H
#define	SPEAK_H

#include <sstream>
#include <alsa/asoundlib.h>
#include <ncurses.h>
#include "/opt/festival-2.1/festival/src/include/festival.h"
#include "config.h"

class speak{

public:
    void initSpeak(std::string);
    void speakThis(std::string);
private:
    void log(std::string);
    void speakFestival(std::string);
    void speakGoogle(std::string);
    int isAlive(std::string);
    config c;
};

#endif	/* SPEAK_H */
