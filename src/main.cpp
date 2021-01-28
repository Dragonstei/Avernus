// Include standard libraries
#include <iostream>

// Include standard headers
#include <stdio.h>
#include <stdlib.h>

#include "settings.h"

#include "shapes.h"
#include "window.h"

int main(int argc, char* argv[]) {

// Report program version
if (argc < 2) {
    std::cout << argv[0] << " Version " << PropManipulator_VERSION_MAJOR << "."
              << PropManipulator_VERSION_MINOR << std::endl;
}

Window w;
w.initWindow();
w.createWindow(1280, 720, "PropManipulator");

/* General pipeline
while (windowOpen) {
    while (event = newEvent())
        handleEvent(event);

    updateScene();

    drawGraphics();
    presentGraphics();
}
*/

return 0;
}
