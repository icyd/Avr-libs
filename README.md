# Avr-libs
## Library for avr
To compile the libraries:
 - Copy the content of the folder inside your project and compile it `gcc -c main.c $(LIBRARY_NAME).c ...`.
 - Use the include option of the compiler `gcc -c main.c $(PATH_TO_LIBRARY)/$(LIBRARY_NAME).c -I $(PATH_TO_LIBRARY)`.
