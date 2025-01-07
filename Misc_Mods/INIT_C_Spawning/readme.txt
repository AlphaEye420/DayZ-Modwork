
MAKE A FOLDER IN MISSIONS FOLDER CALLED "Server"
Put the SpawnObject.c and your Place_ files in there

Make as many lines in the Place_ as you wish, you can also do multiple Place_ .c files. Just make sure you name them correctly at the top of the .c file!

// these # lines go at the top of init.c

#include "$CurrentDir:\\mpmissions\\empty.deerisle\\Server\\SpawnObject.c"
#include "$CurrentDir:\\mpmissions\\empty.deerisle\\Server\\Pub.c"

void main()
{
 // all other stuff
 
 
 // at bottom of main class 

	Place_Pub(); 
}
