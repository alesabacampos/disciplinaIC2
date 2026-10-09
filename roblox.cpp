#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <iostream>
#include <unistd.h>

int main() {
    // 1. Open connection to the X server (uses $DISPLAY environment variable)
    Display* display = XOpenDisplay(nullptr);
    if (display == nullptr) {
        std::cerr << "Cannot open display. Are you in a graphical environment?" << std::endl;
        return 1;
    }

    // 2. Get the default screen and root window
    int screen = DefaultScreen(display);
    Window rootWindow = RootWindow(display, screen);

    // 3. Create a simple window (Width: 500, Height: 400)
    Window window = XCreateSimpleWindow(
        display, rootWindow, 
        10, 10, 500, 400, 1,
        BlackPixel(display, screen),  // Border color
        BlackPixel(display, screen)   // Background color
    );

    // 4. Set the window title
    XStoreName(display, window, "Native Linux Window (No Install)");

    // 5. Select the types of input events we want to listen to
    // ExposureMask tells us when to redraw; KeyPressMask handles user input
    XSelectInput(display, window, ExposureMask | KeyPressMask);

    // 6. Make the window visible on the screen
    XMapWindow(display, window);

    // 7. Initialize the default Graphics Context (GC) for drawing
    GC gc = DefaultGC(display, screen);

    // 8. Main Event Loop
    XEvent event;
    bool running = true;
    while (running) {
        XNextEvent(display, &event);

        // Redraw content when the window is opened or uncovered
        if (event.type == Expose) {
            // Set drawing color to white
            XSetForeground(display, gc, WhitePixel(display, screen));
            
            // Draw a text string (X: 50, Y: 50)
            std::string text = "Hello Linux! Press any key to exit.";
            XDrawString(display, window, gc, 50, 50, text.c_str(), text.length());

            // Draw a solid square fill (X: 50, Y: 100, W: 150, H: 150)
            XFillRectangle(display, window, gc, 50, 100, 150, 150);
        }

        // Exit the loop if the user presses any key inside the window
        if (event.type == KeyPress) {
            running = false;
        }
    }

    // 9. Clean up and close connection
    XCloseDisplay(display);
    return 0;
}

