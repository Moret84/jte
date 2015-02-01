CXX=g++
CXXFLAGS= -std=c++11 -Wall -ggdb
LDFLAGS= -ltag -lstdc++

SRCDIR=src
INCDIR=src
OBJDIR=obj

SRC=$(wildcard $(SRCDIR)/*.cpp)
OBJ=$(SRC:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)
EXEC=jte

all: $(EXEC)

$(EXEC): $(OBJ)
		$(CXX) -o $@ $^ $(LDFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
		$(CXX) -o $@ -c $^ $(CXXFLAGS)

clean:
		@rm -f $(OBJ)

mrproper:clean
		@rm -f $(EXEC)

rebuild:mrproper all

install: $(EXEC)
ifeq ($(USER),root)
	@mv $(EXEC) /bin/
else
	@echo "You must be root"
endif

.PHONY: clean mrproper rebuild
