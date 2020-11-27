# ProceduralSnowflakes

This repository is a C++ project implemented using the Qt development system.  The project implements the demonstration program of chapter five from the Book,  'Real World Fractals'.  This book by Mark Finlay and Keith Blanton ISBN _1-55851-307-8_ was published in 1993.  

This program is the first demonstration program of this very interesting book.  Originally the program was written for the IBM PC using Borland 3.0 C++.  I reversed engineered, extracted, and rewrote, the C++ methods and techniques of the chapter five demonstration program.  The program originally was targeted for 32 bit IBM PCs.  I have implemented it using the modern 64 bit Qt development system for GUI environments.

This program illustrates several interesting concepts as was the original intent.  Specifically procedural objects are generated recursively using a factory pattern.  All manipulations are done using affine transformations implemented through class inheritence.

All features of the original Ch. 5 DEMO program are implemented by the dialog control.  The original program ran from a DOS command line.  Options originally specified by command line arguments are implemented using the dialog.  Original program colors are preserved with black added as a way to do a crude erase.  

Images can be saved as a *.png and used for all sorts of things.  Below is an example.  Resizing the window changes the size of the saved image.  The visible area is saved.

![Example *.png](https://github.com/KeithHayes/ProceduralSnowflakes/blob/main/SnowflakeCurves/example.png?raw=true)

