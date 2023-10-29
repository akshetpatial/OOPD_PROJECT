# CPP Compiler
COMPILER = g++

# Debugging
FLAG_DEBUG = -g -Wall

# Optimized execution
FLAG_OPTIMIZE = -O2

# File to Compile
QUESTION_1_to_5 = Question1_to_5.cpp

#OutPut File
DEBUG_QUESTION_1_to_5 = QUESTION_1_to_5_Debug_File
OPTIMIZE_QUESTION_1_to_5 = QUESTION_1_to_5_Optimize_File

# Compile for Debugging
Debug_File:
	$(COMPILER) $(FLAG_DEBUG) $(QUESTION_1_to_5) -o $(DEBUG_QUESTION_1_to_5)

# Compile for optimization
Optimize_File:
	$(COMPILER) $(FLAG_OPTIMIZE) $(QUESTION_1_to_5) -o $(OPTIMIZE_QUESTION_1_to_5)