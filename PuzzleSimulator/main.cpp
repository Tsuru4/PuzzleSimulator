//
//  main.cpp
//  PuzzleSimulator
//
//  Created by Allyn Crane on 5/16/25.
//

#include <iostream>
#include <string>

enum Color {
    BLUE,
    GREEN,
    WHITE,
    YELLOW,
    RED,
    ORANGE
};
enum Orientation {
  UP, DOWN, LEFT, RIGHT, IN, OUT
};

class CubePiece {
public:
    struct side {
        //See comments in the class defintion for RubiksCube:
        //By personal convention, colors and sides should listed in this order where possible: LEFT/RIGHT, UP/DOWN, IN/OUT
        Color sideColor;
        Orientation sideOrientation;
    };
    
};

class SingleSidedPiece : public CubePiece {
public:
    side primarySide;
    SingleSidedPiece(Color primaryColor, Orientation primaryOrientation){
        primarySide = {primaryColor,primaryOrientation};
    }
};

class DoubleSidedPiece : public CubePiece {
public:
    side primarySide, secondarySide;
    DoubleSidedPiece(Color primaryColor, Orientation primaryOrientation, Color secondaryColor, Orientation secondaryOrientation){
        primarySide = {primaryColor, primaryOrientation};
        secondarySide = {secondaryColor, secondaryOrientation};
    }
};

class TripleSidedPiece : public CubePiece {
public:
    side primarySide, secondarySide, tertiarySide;
    TripleSidedPiece(Color primaryColor, Orientation primaryOrientation, Color secondaryColor, Orientation secondaryOrientation, Color tertiaryColor, Orientation tertiaryOrientation){
        primarySide = {primaryColor, primaryOrientation};
        secondarySide = {secondaryColor, secondaryOrientation};
        tertiarySide = {tertiaryColor, tertiaryOrientation};
    }
};


class RubiksCube {
private:
    //I'm not sure if making these enumerations private is actually helpful. I may need to make them public later.
    enum WIDTH {
        LEFTROW, XCENTER, RIGHTROW
    };
    enum DEPTH{
        TOPROW, YCENTER, BOTTOMROW
    };
    enum LENGTH {
        NEARROW, ZCENTER, FARROW
    };
    CubePiece* cube[3][3][3];
public:
    RubiksCube() {
        
        //I am setting a personal convention here for the order I define the sides in each parameter.
        //LEFT/RIGHT, UP/DOWN, IN/OUT
        
        cube[LEFTROW][TOPROW][NEARROW] = new TripleSidedPiece(WHITE,LEFT,BLUE,UP,RED,IN);
        cube[LEFTROW][TOPROW][ZCENTER] = new DoubleSidedPiece(WHITE,LEFT,BLUE,UP);
        cube[LEFTROW][TOPROW][FARROW] = new TripleSidedPiece(WHITE,LEFT,BLUE,UP,ORANGE,OUT);
        
        cube[LEFTROW][YCENTER][NEARROW] = new DoubleSidedPiece(WHITE,LEFT,RED,IN);
        cube[LEFTROW][YCENTER][ZCENTER] = new SingleSidedPiece(WHITE,LEFT);
        cube[LEFTROW][YCENTER][FARROW] = new DoubleSidedPiece(WHITE,LEFT,ORANGE,OUT);
        
        cube[LEFTROW][BOTTOMROW][NEARROW] = new TripleSidedPiece(WHITE,LEFT,GREEN,DOWN,RED,IN);
        cube[LEFTROW][BOTTOMROW][ZCENTER] = new DoubleSidedPiece(WHITE,LEFT,GREEN,DOWN);
        cube[LEFTROW][BOTTOMROW][FARROW] = new TripleSidedPiece(WHITE,LEFT,GREEN,DOWN,ORANGE,OUT);
        
        //XCENTER
        
        cube[XCENTER][TOPROW][NEARROW] = new DoubleSidedPiece(BLUE,UP,RED,IN);
        cube[XCENTER][TOPROW][ZCENTER] = new SingleSidedPiece(BLUE,UP);
        cube[XCENTER][TOPROW][FARROW] = new DoubleSidedPiece(BLUE,UP,ORANGE,OUT);
        
        cube[XCENTER][YCENTER][NEARROW] = new SingleSidedPiece(RED,IN);
        cube[XCENTER][YCENTER][ZCENTER] = nullptr;
        cube[XCENTER][YCENTER][FARROW] = new SingleSidedPiece(ORANGE,OUT);
        
        cube[XCENTER][BOTTOMROW][NEARROW] = new DoubleSidedPiece(GREEN,DOWN,RED,IN);
        cube[XCENTER][BOTTOMROW][ZCENTER] = new SingleSidedPiece(GREEN,DOWN);
        cube[XCENTER][BOTTOMROW][FARROW] = new DoubleSidedPiece(GREEN,DOWN,ORANGE,OUT);
        
        //RIGHTROW
        
        cube[RIGHTROW][TOPROW][NEARROW] = new TripleSidedPiece(YELLOW,RIGHT,BLUE,UP,RED,IN);
        cube[RIGHTROW][TOPROW][ZCENTER] = new DoubleSidedPiece(YELLOW,RIGHT,BLUE,UP);
        cube[RIGHTROW][TOPROW][FARROW] = new TripleSidedPiece(YELLOW,RIGHT,BLUE,UP,ORANGE,OUT);
        
        cube[RIGHTROW][YCENTER][NEARROW] = new DoubleSidedPiece(YELLOW,RIGHT,RED,IN);
        cube[RIGHTROW][YCENTER][ZCENTER] = new SingleSidedPiece(YELLOW,RIGHT);
        cube[RIGHTROW][YCENTER][FARROW] = new DoubleSidedPiece(YELLOW,RIGHT,ORANGE,OUT);
        
        cube[RIGHTROW][BOTTOMROW][NEARROW] = new TripleSidedPiece(YELLOW,RIGHT,GREEN,DOWN,RED,IN);
        cube[RIGHTROW][BOTTOMROW][ZCENTER] = new DoubleSidedPiece(YELLOW,RIGHT,GREEN,DOWN);
        cube[RIGHTROW][BOTTOMROW][FARROW] = new TripleSidedPiece(YELLOW,RIGHT,GREEN,DOWN,ORANGE,OUT);
    
    };
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "What is your name?\n";
    std::string name;
    std::cin >> name;
    std::cout << "Hello, " << name << "!\n";
    RubiksCube cube = RubiksCube();
    return 0;
}
