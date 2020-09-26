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
CND_PLATFORM=Cygwin-Windows
CND_DLIB_EXT=dll
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/logic.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/render.o


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
LDLIBSOPTIONS=-L../../../../../../cygwin64/usr/local/lib `pkg-config --libs sdl2`  

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tictactoesdl2.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tictactoesdl2.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.c} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tictactoesdl2 ${OBJECTFILES} ${LDLIBSOPTIONS} -lcygwin -lSDL2main -lSDL2

${OBJECTDIR}/logic.o: logic.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g `pkg-config --cflags sdl2`   -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/logic.o logic.c

${OBJECTDIR}/main.o: main.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g `pkg-config --cflags sdl2`   -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.c

${OBJECTDIR}/render.o: render.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g `pkg-config --cflags sdl2`   -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/render.o render.c

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
