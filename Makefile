VERSION 	=1.00
CC			= g++
DEBUG 		=
CFLAGS		= -Wall -Wextra -Wpedantic
SOURCES	 	=$(wildcard ./Code/Src/*.cpp)
INCLUDES  	= 
LIB_NAMES 	=
LIB_PATH 	= -lm
OBJ			=$(patsubst %.cpp, %.o, $(SOURCES))
TARGET		=Qadratka_

#links
$(TARGET):$(OBJ)
	@mkdir -p progect
	$(CC) $(OBJ) $(LIB_PATH) $(LIB_NAMES) -o ./progect/$(TARGET)$(VERSION)
	@rm -rf $(OBJ)
	
#compile
%.o: %.c
	$(CC) $(INCLUDES) $(DEBUG) -c $(CFLAGS) $< -o $@

.PHONY:clean
clean:
	@echo "Remove linked and compiled files......"
	rm -rf $(OBJ) $(TARGET) output 

