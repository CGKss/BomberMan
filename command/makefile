CXX := g++
PROGNAME := Bomber_Man
OUTDIR := ../build
SRCDIR := ../src/Script
# Update these paths as necessary to match your installation
SDL_LIB = -L../../Lib/SDL2-32/lib -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf -lSDL2_net
SDL_INCLUDE = -I../../Lib/SDL2-32/include
# If your compiler is a bit older you may need to change -std=c++11 to -std=c++0x
CXXFLAGS = -Wall -c -std=c++11 $(SDL_INCLUDE)
LDFLAGS = -lmingw32 -mwindows -mconsole $(SDL_LIB)
SRCS := $(SRCDIR)/main.cpp $(wildcard $(SRCDIR)/*.cpp)
OBJS := $(addprefix $(OUTDIR),$(patsubst $(SRCDIR)%.cpp,%.o,$(SRCS)))
EXE = $(OUTDIR)/$(PROGNAME).exe


.PHONY: all

all: $(EXE)


$(EXE): $(OBJS)

	$(CXX) $^ $(LDFLAGS) -o $@

$(OBJS): 
	$(CXX) $(CXXFLAGS) -c $(patsubst $(OUTDIR)%.o,$(SRCDIR)%.cpp,$@) -o $@