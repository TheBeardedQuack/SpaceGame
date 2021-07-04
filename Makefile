#!make
# This make needs:
# g++
#

# Project name
NAME 		:=$(patsubst %/,%,$(notdir $(CURDIR)))

#The Directories, Source, Includes, Objects, Binary and Resources
SRCDIR		?=$(CURDIR)/src
INCDIR		?=$(CURDIR)/include
LIBDIR		?=$(CURDIT)/lib
BUILDDIR	?=$(CURDIR)/obj
TARGETDIR	?=$(CURDIR)/bin
RESDIR		?=$(CURDIR)/rsc

EXEEXT	:=
LIBEXT	:=.so
SRCEXT	:=.cpp
OBJEXT	:=.o

#The Target Binary Program
TARGET		:=$(TARGETDIR)/$(NAME)$(EXEEXT)

#Compiler and Linker
CXX			:=g++

#Flags, Libraries and Includes
CXXFLAGS	:=-g -ggdb -std=c++17 -m64 -Wall -Wextra -fno-pic -DDEBUG
LIB			:=-L$(TARGETDIR) -lsfml-graphics -lsfml-system -lsfml-window -lsfml-audio -no-pie
INC			:=-I$(INCDIR)

#---------------------------------------------------------------------------------
#DO NOT EDIT BELOW THIS LINE
#---------------------------------------------------------------------------------
SOURCES	:=\
	$(wildcard $(SRCDIR)/*$(SRCEXT))\

OBJECTS	:=$(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:$(SRCEXT)=$(OBJEXT)))

#Defauilt Make
all: $(TARGET) resources

#Remake
remake: clean all

#Setup directory template
template: directories
	mkdir -p $(SRCDIR)
	mkdir -p $(INCDIR)
	mkdir -p $(RESDIR)

#Make the Directories
directories:
	mkdir -p $(TARGETDIR)
	mkdir -p $(BUILDDIR)
	
#Copy Resources from Resources Directory to Target Directory
resources: directories
	cp -rf $(RESDIR) $(TARGETDIR)/

#Clean only project ready for rebuild
clean:
	rm -r $(BUILDDIR)
	rm -r $(TARGETDIR)

#Compile
$(BUILDDIR)/%$(OBJEXT): $(SRCDIR)/%$(SRCEXT) directories
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(INC) -c -o $@ $<

#Link
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(INC) -o $(TARGET) $^ $(LIB)

DEBUG_%:
	$(info $(subst DEBUG_,,$@) = $($(subst DEBUG_,,$@)))

#Non-File Targets
.PHONY: all remake clean resources template
