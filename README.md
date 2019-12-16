Below is a simple guide to how this project was made. SDL2 is locally configured in this project library so you don't have to follow any OS steps to configure it in your machine's library frameworks. It goes step by step to get SDL library linked into your project so you can get to the fun stuff (game development) quickly. I made this primarily because most C++ SDL2 configuration videos on youtube were for Xcode. Comments were riddled with complaints about SDL library not being read on #include. Coming from a JS dev background, I dislike Xcode and prefer VSCode, so I wanted a repo to exist for people to just clone this, compile code simply, and start playing around with game development ASAP.

## SETUP
download:
https://marketplace.visualstudio.com/items?itemName=danielpinto8zz6.c-cpp-project-generator

###  1. Install SDL2
In your terminal, run the brew command:
brew install sdl2
This will fetch a compiled version of SDL2, so you don’t need to worry about any of the compilation steps mentioned in the SDL docs (https://wiki.libsdl.org/Installation).

###  2. Create a project
command + shift + p 
search for create C++ file. Create within Designated folder.

In myproject/main.cpp:

```
#include <iostream>
#include <SDL2/SDL.h>
using namespace std;
int main() {
        cout << "Hello World!";
        SDL_Init(SDL_INIT_VIDEO);
        return 0;
    }
```


###  3. Move the SDL files into your project
It might help to use Finder for this part. Navigate to the place where SDL2 installed. For me, that was:
/usr/local/Cellar/sdl2/2.0.5
Copy the contents of
/usr/local/Cellar/sdl2/2.0.5/include/
(It should be a folder called SDL2 that contains a bunch of .h files.)
and paste it into
myproject/include
Then, go to
/usr/local/Cellar/sdl2/2.0.5/lib/
and copy the contents (some folders and some .a and .dylib files) into
/myproject/lib

###  4. Update Your Makefile to compile using SDL2
In myproject/Makefile, change the this assignment to include SDL2. 
```
INCLUDE	:= include -L lib -l SDL2-2.0.0
```
ex:
```
CC		:= g++
C_FLAGS := -std=c++17 -Wall -Wextra -g

BIN		:= bin
SRC		:= src
INCLUDE	:= include -L lib -l SDL2-2.0.0
LIB		:= lib

LIBRARIES	:=

ifeq ($(OS),Windows_NT)
EXECUTABLE	:= main.exe
else
EXECUTABLE	:= main
endif

all: $(BIN)/$(EXECUTABLE)

clean:
	$(RM) $(BIN)/$(EXECUTABLE)

run: all
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/*.cpp
	$(CC) $(C_FLAGS) -I$(INCLUDE) -L$(LIB) $^ -o $@ $(LIBRARIES)
 ```
Note: Flags are used to link SDL2 to your project.
`-I` (i as in include) tells it additional include directories you want to add
`-L` tells it additional library directories you want to add
`-l` (lowercase l as in lib) tells it specific library binaries you want to add

### 5. Make your project & Run
In your project’s directory, in the terminal, run:
```
make all

```
This will compile the game and run it. "make run" will run the game
This step runs the executable created by compiling. If all went well, you should see a nice “Hello World!” print. 