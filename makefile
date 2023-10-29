# CPP Compiler
COMPILER = g++

# Debugging
FLAG_DEBUG = -g -Wall

# Optimized execution
FLAG_OPTIMIZE = -O2

# File to Compile
QUESTION_1_to_5 = Question1_to_5.cpp
QUESTION_5_to_6 = Q5-Q6.cpp

#OutPut File
DEBUG_QUESTION_1_to_5 = QUESTION_1_to_5_Debug_File
OPTIMIZE_QUESTION_1_to_5 = QUESTION_1_to_5_Optimize_File
DEBUG_Q5_Q6 = Q5-Q6_Debug_File
OPTIMIZE_Q5_Q6 = Q5-Q6_Optimize_File

# Compile for Debugging
Debug_File:
	$(COMPILER) $(FLAG_DEBUG) $(QUESTION_1_to_5) -o $(DEBUG_Q5)

# Compile for optimization
Optimize_File:
	$(COMPILER) $(FLAG_OPTIMIZE) $(QUESTION_1_to_5) -o $(OPTIMIZE_Q5)

Debug_File_5_TO_6:
	$(COMPILER) $(FLAG_DEBUG) $(QUESTION_5_to_6) -o $(DEBUG_Q5_Q6)

# Compile for optimization
Optimize_File_5_TO_6:
	$(COMPILER) $(FLAG_OPTIMIZE) $(QUESTION_5_to_6) -o $(OPTIMIZE_Q5_Q6)	