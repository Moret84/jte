CXX=g++
C=gcc
CXXFLAGS= -std=c++11 -Wall -ggdb
LDFLAGS= -ltag -lstdc++ -lssl -lcrypto

SRCDIR=src
INCDIR=src
OBJDIR=obj

SRC=$(wildcard $(SRCDIR)/*.cpp)
OBJ=$(SRC:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)
EXEC=jte

all: $(EXEC)

$(EXEC): $(OBJ) $(OBJDIR)/base64.o
		$(CXX) -o $@ $^ $(LDFLAGS)

$(OBJDIR)/base64.o:$(SRCDIR)/base64.c $(SRCDIR)/base64.h
	$(C) -o $@ -c $<

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
		$(CXX) -o $@ -c $^ $(CXXFLAGS)

clean:
		@rm -f $(OBJ)

mrproper:clean
		@rm -f $(EXEC)

rebuild:mrproper all

install:
ifeq ($(USER),root)
	@mv $(EXEC) /bin/
else
	@echo "You must be root"
endif

.PHONY: clean mrproper rebuild
