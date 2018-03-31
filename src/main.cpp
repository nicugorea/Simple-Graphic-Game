#include "includes.h"
#include "Window.h"
#include "States.h"

int main(int argc, char *argv[]) {
	Window window;
	States states;

	while (!window.isClosed) {
		states.check(window.isClosed);
	}

	exit(0);
	return 0;
}