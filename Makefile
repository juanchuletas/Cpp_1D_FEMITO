#Make file for MACOS
# Juan Jose Garcia Miranda
# Area de Fisicoquimica Teorica
# Departamento de Quimica
# Universidad Autonoma Metropolitana-Iztapalapa
# January 2018
#

SRC = src
INC = include
BIN = bin
RED = \033[1;31m
GREEN = \033[1;32m
BLUE = \033[1;34m
YELLOW = \033[1;33m
NC = \033[1;0m
UNAME := $(shell uname)
ifeq ($(UNAME), Darwin)
LIB = -framework Accelerate
TARGET = FEMITO_macos
endif
ifeq ($(UNAME), Linux)
LIB = -llapack 
TARGET = FEMITO_linux
endif

SOURCE = $(wildcard $(SRC)/*.cpp)

OBJECT = $(patsubst %,$(BIN)/%, $(notdir $(SOURCE:.cpp=.o)))

LIB = -llapack 

CC = g++

ifeq ($(UNAME), Darwin)
SYSNAME:=$(shell sw_vers -productName)
SYSV:=$(shell sw_vers -productVersion)
CFLAGS = -I$(INC)

$(BIN)/$(TARGET) : $(OBJECT)
	@echo "$(RED)LINKING...$(NC)"
	$(CC) -o  $@ $^ $(LIB)
	@echo "$(YELLOW)FINISHED!!!$(NC)"
	@echo "$(YELLOW)SUCCESFULL!!!$(NC)"
	@echo "$(BLUE)OPERATING SISTEM: $(SYSNAME)!!!...$(NC)"

$(BIN)/%.o : $(SRC)/%.cpp
	@echo "$(GREEN)COMPILING...$(NC)"
	@echo  "\033[0;32m [OK] \033[0m       \033[0;33m Compiling:\033[0m" $<
	$(CC) $(CFLAGS) -c $< -o $@ 
endif
ifeq ($(UNAME), Linux)

SYSNAME:=$(shell lsb_release -i)
SYSV:=$(shell lsb_release -r)
CFLAGS = -I$(INC) -std=c++11

$(BIN)/$(TARGET) : $(OBJECT)
	@echo -e "$(RED)LINKING...$(NC)"
	$(CC) -o  $@ $^ -lm $(LIB)
	@echo -e "$(YELLOW)FINISHED!!!$(NC)"
	@echo -e "$(YELLOW)SUCCESFULL!!!$(NC)"
	@echo -e "$(BLUE)OPERATING SISTEM: $(UNAME)!!!...$(NC)"

$(BIN)/%.o : $(SRC)/%.cpp
	@echo -e "$(GREEN)COMPILING...$(NC)"
	@echo -e  "\033[0;32m [OK] \033[0m       \033[0;33m Compiling:\033[0m" $<
	$(CC) $(CFLAGS) -c  $< -o $@

endif

.PHONY : help clean

clean : 
	rm -f $(OBJECT) $(BIN)/$(TARGET) 

help: 
	@echo "src: $(SOURCE)"
	@echo "obj: $(OBJECT)"
info  :
ifeq ($(UNAME),Darwin)
	@echo "Operating System: $(SYSNAME)"
	@echo "System Version: $(SYSV)"
#@echo "Operating System: $(UNAME)"
endif
ifeq ($(UNAME), Linux)
	@echo "Operating System: $(UNAME)"
	@echo "$(SYSNAME)"
	@echo "$(SYSV)"
endif
