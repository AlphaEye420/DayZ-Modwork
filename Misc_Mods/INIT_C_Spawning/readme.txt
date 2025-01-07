
MAKE A FOLDER IN MISSIONS FOLDER CALLED "Server"
Put the SpawnObject.c and your Place_ files in there

// these # lines go at the top of init.c

#include "$CurrentDir:\\mpmissions\\empty.deerisle\\Server\\SpawnObject.c"
#include "$CurrentDir:\\mpmissions\\empty.deerisle\\Server\\Pub.c"

void main()
{
 // all other stuff
 
 
 // at bottom of main class 

	Place_Pub(); 
}
