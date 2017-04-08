# *********************************************************
#                                                     
#  			SPEV: version 0.0
#                                                     
# *********************************************************

spev:                              # Default target

# ---------------------------------------------------------
#         		Configuration
#          		
# ---------------------------------------------------------
CC        = gcc
CFLAGS    = -c -finline-functions -Winline
# Flags for debugging
#CFLAGS    = -c -g -v -da -Q -enable-checking -finline-functions -Winline 
LDFLAGS   = -bind_at_load -lm

# ---------------------------------------------------------
#         Set headers and object files 
# ---------------------------------------------------------

HEADERS = spev.h func_prototypes.h structs.h bg_macros.h macros.h globals.h 
OBJ =  main.o access_bin.o set_background.o mem_alloc.o \
       set_bg_grid.o access_file.o

# ---------------------------------------------------------
#    		  SPEV target rule
# ---------------------------------------------------------

spev: $(OBJ) 
	$(CC) $(OBJ) $(LDFLAGS) -o $@


# ---------------------------------------------------------
#    		 Clean object files 
# ---------------------------------------------------------
clean:
	@rm -f	*.o
	@echo make clean: done

# ---------------------------------------------------------
#          Dependencies for object files
# ---------------------------------------------------------

$(OBJ):  $(HEADERS)

