CXX=clang
CXXFLAGS= -std=c++11 -Wall -ggdb -I src/
LDFLAGS= -ltag -lstdc++

SRCDIR=src
INCDIR=src
OBJDIR=obj

SRC=$(wildcard $(SRCDIR)/*.cpp)
OBJ=$(SRC:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)
EXEC=jte

all: $(OBJDIR) $(EXEC)

$(EXEC): $(OBJ)
		$(CXX) -o $@ $^ $(LDFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
		$(CXX) -o $@ -c $^ $(CXXFLAGS)

$(OBJDIR):
	mkdir -p $@

clean:
		@rm -f $(OBJ)

mrproper:clean
		@rm -f $(EXEC)

rebuild:mrproper all

install: $(OBJDIR) $(EXEC)
ifeq ($(USER),root)
	@mv $(EXEC) /bin/
else
	@echo "You must be root"
endif

.PHONY: clean mrproper rebuild
