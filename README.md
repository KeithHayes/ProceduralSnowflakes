# ProceduralSnowflakes

This is a Qt C++ project.  The project implements the code of chapter **five** from the Book,  '***Real World Fractals*** by Mark Finlay and Keith Blanton ISBN _1-55851-307-8_   '.  This book  was published in 1993.  

This program is the first demonstration program of this very interesting book.  Originally written for the IBM PC using Borland 3.0 C++.  I reversed engineered, extracted, and rewrote, the C++ methods and techniques of this demonstration program.  The program originally was targeted for DOS 32 bit IBM PCs.  I have implemented the program using the Qt 64 bit GUI environment.

This program illustrates several interesting programming concept.  Procedural objects are generated recursively using a factory pattern.  All manipulations are done using affine transformations.  Class inheritence is used.

All features of the original Ch. 5 DEMO program are implemented by a dialog control.  The original program ran from a command line.  Options originally specified by command line arguments are implemented using the dialog.  Original program colors are preserved with black added as a way to do a crude erase.  

Images can be saved as a *.png and used for all sorts of things.  Below is an example.  Resizing the window changes the size of the saved image.  The visible area is saved.

![Example *.png](https://github.com/KeithHayes/ProceduralSnowflakes/blob/main/SnowflakeCurves/example.png?raw=true)

