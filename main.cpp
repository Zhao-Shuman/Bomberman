#include <iostream>

#include "App.h"

int main ()
{
	App app;
	app.runProgramm();

	while (app.works()) {}
	app.exitProgramm();
	return 0;
}
