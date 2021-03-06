#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/1396912672/config.o \
	${OBJECTDIR}/_ext/1396912672/processDaemon.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/speak.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=/opt/festival-2.1/festival/src/lib/libFestival.a /opt/festival-2.1/speech_tools/lib/libestools.a /opt/festival-2.1/speech_tools/lib/libestbase.a /opt/festival-2.1/speech_tools/lib/libeststring.a

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/gspeakdaemon

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/gspeakdaemon: /opt/festival-2.1/festival/src/lib/libFestival.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/gspeakdaemon: /opt/festival-2.1/speech_tools/lib/libestools.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/gspeakdaemon: /opt/festival-2.1/speech_tools/lib/libestbase.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/gspeakdaemon: /opt/festival-2.1/speech_tools/lib/libeststring.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/gspeakdaemon: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/gspeakdaemon ${OBJECTFILES} ${LDLIBSOPTIONS} -lasound -lcurses

${OBJECTDIR}/_ext/1396912672/config.o: /root/NetBeansProjects/gSpeakDaemon/config.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1396912672
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1396912672/config.o /root/NetBeansProjects/gSpeakDaemon/config.cpp

${OBJECTDIR}/_ext/1396912672/processDaemon.o: /root/NetBeansProjects/gSpeakDaemon/processDaemon.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1396912672
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1396912672/processDaemon.o /root/NetBeansProjects/gSpeakDaemon/processDaemon.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/speak.o: speak.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/speak.o speak.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/gspeakdaemon

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
