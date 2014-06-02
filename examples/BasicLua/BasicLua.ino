#include "basetypes.h"
#include "platform.h"
#include "vm.h"
#include "gc.h"
#include <stdio.h>

void testGC()
{
	gcvarpt* num1 = gcNew(VAR_NUMBER);
	gcvarpt* num2 = gcNew(VAR_BOOLEAN);
	gcvarpt* num3 = gcNew(VAR_FLOAT);

	GCVALUE(s32,num1) = 10;
	GCVALUE(u08,num2) = TRUE;
	GCVALUE(float,num3) = 1.5f;
	GCVALUE(u08,num2) = FALSE;

	gcDelete(num2);

	gcvarpt* num4 = gcNew(VAR_FLOAT);
	GCVALUE(float,num4) = 9.99f;

	if(GCVALUE(s32,num1) != 10 || GCVALUE(float,num3) != 1.5f || GCVALUE(float,num4) != 9.99f)
	{
		platformPrintf("GC test failed!");
	}
	gcDump();
}

vm thread;

void setup() {
  Serial.println("µLua started!");
  
  //platformInit(argv[1]);
	vmInit(&thread);
	
	//tests
	//testGC();
	
	vmRun(&thread);

	//gcDump();
}

void loop() {
  
}