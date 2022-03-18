#########################################
# Created by Jean-Philippe Legault
# Adapted by Allison Dupuis
#
# This is a comment, a comment always start with `#`
# Indentation is primordial in a Makefile.
# the steps for a target are always indented
#
##########################################

# compile with gcc, change this to clang if you prefer
COMPILER = gcc

# The C flags to pass to gcc
C_FLAGS = -g -Wall -Wextra

# prepend the command with '@' so that Make does not print the command before running it 
help:
	@printf "available command:\n"
	@printf "	make help               (this command)\n"
	@printf "	make testing              (to build your C program)\n"

# link our .o files to make an executable
testing: Strings.o 
	$(COMPILER) $(C_FLAGS) -o testing Strings.o 

# compile the `testing.o` file
#testing.o: Strings.c
#	$(COMPILER) $(C_FLAGS) -c Strings.c
