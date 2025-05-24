//
//  main.cpp
//  PuzzleSimulator
//
//  Created by Allyn Crane on 5/16/25.
//

#include <iostream>
#include <string>
#include <queue>

//Color and Orientation are global for now because I am using them as parameters in the constructor for CubePiece. I'm not sure if there is a better way to do this.
enum Color {
    BLUE,
    GREEN,
    WHITE,
    YELLOW,
    RED,
    ORANGE,
    BLACK
};
enum Orientation {
    UP,
    DOWN,
    LEFT,
    RIGHT,
    IN,//IN may also mean counterclockwise
    OUT//OUT may mean clockwise
};
struct side {
    //See comments in the class defintion for RubiksCube:
    //By personal convention, colors and sides should listed in this order where possible: LEFT/RIGHT, UP/DOWN, IN/OUT
    Color color;//I want this to be constant, but I need also need to set it up inside a constructors.
    Orientation orientation;
};

//! I want this class to be abstract, but it seems C++ does not have an abstract keyword
class CubePiece {
protected:
    std::vector<side> sides;
    //! This isn't working the way I would like. I need this to be some more flexible kind of data structure.
public:
    
    void printColorAbrievation(Orientation orientation)
    {
        Color color = getColor(orientation);
        switch (color)
        {
            case RED:
            {
                std::cout << "R";
                break;
            }
            case ORANGE:
            {
                std::cout << "O";
                break;
            }
            case YELLOW:
            {
                std::cout << "Y";
                break;
            }
            case GREEN:
            {
                std::cout << "G";
                break;
            }
            case BLUE:
            {
                std::cout << "B";
                break;
            }
            case WHITE:
            {
                std::cout << "W";
                break;
            }
            default:
            {
                std::cout << "0";
            }
        }
    }
    
    Color getColor(Orientation orientation)
    {
        const unsigned long dimentions = sides.size();
        for (int i = 0; i < dimentions; i++)
        {
            if (sides.at(i).orientation == orientation)
            {
                return sides.at(i).color;
            }
        }
        return BLACK;
    }
    void rotate(Orientation direction)
    {
        const unsigned long dimentions = sides.size();
        switch(direction)
        {
            case UP:
            {
                for (int i = 0; i < dimentions;i++)
                {
                    switch (sides.at(i).orientation)
                    {
                        case UP:
                        {
                            sides.at(i).orientation = OUT;
                            break;
                        }
                        case DOWN:
                        {
                            sides.at(i).orientation = IN;
                            break;
                        }
                        case IN:
                        {
                            sides.at(i).orientation = UP;
                            break;
                        }
                        case OUT:
                        {
                            sides.at(i).orientation = DOWN;
                            break;
                        }
                        default:
                        {
                        //Change nothing. This side is already facing the correct way.
                        }
                    }//end of switch
                }//end of for loop
                break;
            }//end of case.
            case DOWN:
            {
                for (int i = 0; i < dimentions;i++)
                {
                    switch (sides.at(i).orientation)
                    {
                        case UP:
                        {
                            sides.at(i).orientation = IN;
                            break;
                        }
                        case DOWN:
                        {
                            sides.at(i).orientation = OUT;
                            break;
                        }
                        case IN:
                        {
                            sides.at(i).orientation = DOWN;
                            break;
                        }
                        case OUT:
                        {
                            sides.at(i).orientation = UP;
                            break;
                        }
                        default:
                        {
                        //Change nothing. This side is already facing the correct way.
                        }
                    }//end of switch
                }//end of for loop
                break;
            }//end of case.
            case IN://rotate counterclockwise
            {
                for (int i = 0; i < dimentions;i++)
                {
                    switch (sides.at(i).orientation)
                    {
                        case UP:
                        {
                            sides.at(i).orientation = LEFT;
                            break;
                        }
                        case DOWN:
                        {
                            sides.at(i).orientation = RIGHT;
                            break;
                        }
                        case LEFT:
                        {
                            sides.at(i).orientation = DOWN;
                            break;
                        }
                        case RIGHT:
                        {
                            sides.at(i).orientation = UP;
                            break;
                        }
                        default:
                        {
                        //Change nothing. This side is already facing the correct way.
                        }
                    }//end of switch
                }//end of for loop
                break;
            }//end of case.
            case OUT://rotate clockwise
            {
                for (int i = 0; i < dimentions;i++)
                {
                    switch (sides.at(i).orientation)
                    {
                        case UP:
                        {
                            sides.at(i).orientation = RIGHT;
                            break;
                        }
                        case DOWN:
                        {
                            sides.at(i).orientation = UP;
                            break;
                        }
                        case LEFT:
                        {
                            sides.at(i).orientation = UP;
                            break;
                        }
                        case RIGHT:
                        {
                            sides.at(i).orientation = DOWN;
                            break;
                        }
                        default:
                        {
                        //Change nothing. This side is already facing the correct way.
                        }
                    }//end of switch
                }//end of for loop
                break;
            }//end of case.
            case LEFT:
            {
                for (int i = 0; i < dimentions;i++)
                {
                    switch (sides.at(i).orientation)
                    {
                        case IN:
                        {
                            sides.at(i).orientation = LEFT;
                            break;
                        }
                        case OUT:
                        {
                            sides.at(i).orientation = RIGHT;
                            break;
                        }
                        case LEFT:
                        {
                            sides.at(i).orientation = OUT;
                            break;
                        }
                        case RIGHT:
                        {
                            sides.at(i).orientation = IN;
                            break;
                        }
                        default:
                        {
                        //Change nothing. This side is already facing the correct way.
                        }
                    }//end of switch
                }//end of for loop
                break;
            }//end of case.
            case RIGHT:
            {
                for (int i = 0; i < dimentions;i++)
                {
                    switch (sides.at(i).orientation)
                    {
                        case IN:
                        {
                            sides.at(i).orientation = RIGHT;
                            break;
                        }
                        case OUT:
                        {
                            sides.at(i).orientation = LEFT;
                            break;
                        }
                        case LEFT:
                        {
                            sides.at(i).orientation = IN;
                            break;
                        }
                        case RIGHT:
                        {
                            sides.at(i).orientation = OUT;
                            break;
                        }
                        default:
                        {
                        //Change nothing. This side is already facing the correct way.
                        }
                    }//end of switch
                }//end of for loop
                break;
            }//end of case.
        }//end of overall switch
    }//end of method

};

class SingleSidedPiece : public CubePiece {
public:
    SingleSidedPiece(side primarySide){
        sides.push_back(primarySide);
    }
};

class DoubleSidedPiece : public CubePiece {
public:
    DoubleSidedPiece(side primarySide, side secondarySide){
        sides.push_back(primarySide);
        sides.push_back(secondarySide);
    }
};

class TripleSidedPiece : public CubePiece {
public:
    TripleSidedPiece(side primarySide, side secondarySide, side tertiarySide){
        sides.push_back(primarySide);
        sides.push_back(secondarySide);
        sides.push_back(tertiarySide);
    }
};


class RubiksCube {
private:
    //I'm not sure if making these enumerations private is actually helpful. This is my first time using enumerations. I may need to make them public later if I run into issues.
    enum Width {
        LEFTROW, XCENTER, RIGHTROW
    };
    enum Depth{
        TOPROW, YCENTER, BOTTOMROW
    };
    enum Length {
        NEARROW, ZCENTER, FARROW
    };
    enum Proximity {
        NEAR = 0,
        CENTER = 1,
        FAR = 2
    };
    CubePiece* cube[3][3][3];
    

public:
    RubiksCube() {
        
        std::queue<side> sides;
        for (int width = NEAR; width <= FAR; width++)//NEAR=LEFT FAR=RIGHT
        {
            for (int depth = NEAR; depth <= FAR; depth++)//NEAR=TOP FAR=RIGHT
            {
                for (int length = NEAR; length <= FAR; length++)//NEAR=NEAR FAR=FAR
                {
                    switch (width)
                    {
                        case NEAR:
                        {
                            sides.push({WHITE,LEFT});
                            break;
                        }
                        case FAR:
                        {
                            sides.push({YELLOW,RIGHT});
                        }
                        
                    }
                    switch (depth)
                    {
                        case NEAR:
                        {
                            sides.push({BLUE,UP});
                            break;
                        }
                        case FAR:
                        {
                            sides.push({GREEN,DOWN});
                        }
                    }
                    switch (length)
                    {
                        case NEAR:
                        {
                            sides.push({RED,IN});
                            break;
                        }
                        case FAR:
                        {
                            sides.push({ORANGE,OUT});
                        }
                        
                    }
                    switch (sides.size())
                    {
                        case 3:
                        {
                            side side1 = sides.front();
                            sides.pop();
                            side side2 = sides.front();
                            sides.pop();
                            side side3 = sides.front();
                            sides.pop();
                            cube[width][depth][length] = new TripleSidedPiece(side1,side2,side3);
                            break;
                        }
                        case 2:
                        {
                            side side1 = sides.front();
                            sides.pop();
                            side side2 = sides.front();
                            sides.pop();
                            cube[width][depth][length] = new DoubleSidedPiece(side1,side2);
                            break;
                        }
                        case 1:
                        {
                            side side1 = sides.front();
                            sides.pop();
                            cube[width][depth][length] = new SingleSidedPiece(side1);
                            break;
                        }
                        case 0: cube[width][depth][length] = nullptr;
                    }
                    
                }
            }
        }
        
        //I am setting a personal convention here for the order I define the sides in each parameter.
        //LEFT/RIGHT, UP/DOWN, IN/OUT
        
        /* This code snippet extremely redundant.
        The code in this comment has been replaced by the code above.
        I can do the same thing using for loops, counters, and enumerations.
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
        cube[RIGHTROW][BOTTOMROW][FARROW] = new TripleSidedPiece(YELLOW,RIGHT,GREEN,DOWN,ORANGE,OUT);*/

    };
    
    //I will be replacing this method eventually. Do not get used to this method. It is for testing purposes only.
    void showCubeToConsole()
    {
        //create some white space for readablilty
        std::cout << "\n\n";
    
        std::cout << "Top\n";
        for (int i = 0; i <= 2; i++)
        {
            for (int j = 0; j <= 2; j++)
            {
                cube[i][0][j]->printColorAbrievation(UP);
            }
            std::cout << "\n";
        }
        std::cout << "\n";
        
        std::cout << "Left\n";
        for (int i = 0; i <= 2; i++)
        {
            for (int j = 0; j <= 2; j++)
            {
                cube[0][i][j]->printColorAbrievation(LEFT);
            }
            std::cout << "\n";
        }
        std::cout << "\n";
        
        std::cout << "Front\n";
        for (int i = 0; i <= 2; i++)
        {
            for (int j = 0; j <= 2; j++)
            {
                cube[i][j][0]->printColorAbrievation(IN);
            }
            std::cout << "\n";
        }
        std::cout << "\n";
        
        std::cout << "Right\n";
        for (int i = 0; i <= 2; i++)
        {
            for (int j = 0; j <= 2; j++)
            {
                cube[2][i][j]->printColorAbrievation(RIGHT);
            }
            std::cout << "\n";
        }
        std::cout << "\n";
        
        std::cout << "Back\n";
        for (int i = 0; i <= 2; i++)
        {
            for (int j = 0; j <= 2; j++)
            {
                cube[i][j][2]->printColorAbrievation(OUT);
            }
            std::cout << "\n";
        }
        std::cout << "\n";
        
        std::cout << "Bottom\n";
        for (int i = 0; i <= 2; i++)
        {
            for (int j = 0; j <= 2; j++)
            {
                cube[i][2][j]->printColorAbrievation(DOWN);
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }
    
    
    //x == width == 0 axis, y==depth==1 axis, z==length==2axis
    void shiftOnce(int axis, int proximity)
    {
        switch (axis)
        {
            case 0://shifing up
            {//first, set the placeholder. 1,1,1 is already a good placeholder, as it is never used in practical situations and I don't actually care what it's value is.
                cube[1][1][1] = cube[proximity][0][0];
                cube[proximity][0][0] = cube[proximity][2][0];
                cube[proximity][2][0] = cube[proximity][2][2];
                cube[proximity][2][2] = cube[proximity][0][2];
                cube[proximity][0][2] = cube[1][1][1];
             
                //this sets the corners to their new locations, but their orientation will need to be adjusted. I will get to that after I reposition the side pieces.
                
                cube[1][1][1] = cube[proximity][0][1];
                cube[proximity][0][1] = cube[proximity][1][0];
                cube[proximity][1][0] = cube[proximity][2][1];
                cube[proximity][2][1] = cube[proximity][1][2];
                cube[proximity][1][2] = cube[1][1][1];
                
                cube[1][1][1] = nullptr;
                //now the side pieces are also repositioned. All that remains is to reorient the direction of the pieces.
                for (int i = NEAR; i <= FAR; i++)
                {
                    for (int j = NEAR; j <=FAR; j++)
                    {
                        if (i!=CENTER || j!=CENTER)
                        {
                        cube[proximity][i][j]->rotate(UP);
                        }
                    }
                }
                break;
            }
            case 1://shift left
            {//first, set the placeholder. 1,1,1 is already a good placeholder, as it is never used in practical situations and I don't actually care what it's value is.
                cube[1][1][1] = cube[0][proximity][0];
                cube[0][proximity][0] = cube[2][proximity][0];
                cube[2][proximity][0] = cube[2][proximity][2];
                cube[2][proximity][2] = cube[0][proximity][2];
                cube[0][proximity][2] = cube[1][1][1];
             
                //this sets the corners to their new locations, but their orientation will need to be adjusted. I will get to that after I reposition the side pieces.
                
                cube[1][1][1] = cube[0][proximity][1];
                cube[0][proximity][1] = cube[1][proximity][0];
                cube[1][proximity][0] = cube[2][proximity][1];
                cube[2][proximity][1] = cube[1][proximity][2];
                cube[1][proximity][2] = cube[1][1][1];
                
                cube[1][1][1] = nullptr;
                //now the side pieces are also repositioned. All that remains is to reorient the direction of the pieces.
                for (int i = NEAR; i <= FAR; i++)
                {
                    for (int j = NEAR; j <=FAR; j++)
                    {
                        if (i!=CENTER || j!=CENTER)
                        {
                        cube[proximity][i][j]->rotate(LEFT);
                        }
                    }
                }
                break;
            }
            case 2://shifing counterclockwise
            {//first, set the placeholder. 1,1,1 is already a good placeholder, as it is never used in practical situations and I don't actually care what it's value is.
                cube[1][1][1] = cube[0][0][proximity];
                cube[0][0][proximity] = cube[2][0][proximity];
                cube[2][0][proximity] = cube[2][2][proximity];
                cube[2][2][proximity] = cube[0][2][proximity];
                cube[0][2][proximity] = cube[1][1][1];
             
                //this sets the corners to their new locations, but their orientation will need to be adjusted. I will get to that after I reposition the side pieces.
                
                cube[1][1][1] = cube[0][1][proximity];
                cube[0][1][proximity] = cube[1][0][proximity];
                cube[1][0][proximity] = cube[2][1][proximity];
                cube[2][1][proximity] = cube[1][2][proximity];
                cube[1][2][proximity] = cube[1][1][1];
                
                cube[1][1][1] = nullptr;
                //now the side pieces are also repositioned. All that remains is to reorient the direction of the pieces.
                for (int i = NEAR; i <= FAR; i++)
                {
                    for (int j = NEAR; j <=FAR; j++)
                    {
                        if (i!=CENTER || j!=CENTER)
                        {
                        cube[proximity][i][j]->rotate(IN);
                        }
                    }
                }
                break;
            }
        }//end switch

    }//end method
    
    void shiftTwice(int axis, int proximity)
    {
        //I know more effictient ways to do this, but for the purposes of saving time programming this method, this will work for now.
        //ToDo optimize this.
        shiftOnce(axis, proximity);
        shiftOnce(axis, proximity);
    }
    
    void shiftBack(int axis, int proximity)
    {
        //I know more effictient ways to do this, but for the purposes of saving time programming this method, this will work for now.
        //ToDo optimize this.
        shiftOnce(axis, proximity);
        shiftOnce(axis, proximity);
        shiftOnce(axis, proximity);
    }
    
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "What is your name?\n";
    std::string name;
    std::cin >> name;
    std::cout << "Hello, " << name << "!Let's play with a Rubik's Cube!\n";
    RubiksCube cube = RubiksCube();
    short menuInputMain;
    short menuInputParam1;
    short menuInputParam2;
    
    bool menuContinue = true;
    do {
        cube.showCubeToConsole();
        
        std::cout << "Shift once, twice, or thrice (integer input only)\n(0 to exit program):\n";
        std::cin >> menuInputMain;//C++ does not seem to throw any exceptions for bad input here. I don't particularly care in this situation, but it's a good thing to remember that bad input seems to default to 0 for ints.
        std::cout << menuInputMain <<"\n";
        if (menuInputMain != 0)
        {
            std::cout << "Choose your axis! 0 = X, 1 = Y, 2 = Z:\n";
            std::cin >> menuInputParam1;
            std::cout << "Choose the layer! (Top left piece closest to you is considered the closest layer. 0 is closest, 2 is farthest, 1 is center):\n";
            std::cin >> menuInputParam2;
            switch (menuInputMain)
            {
                case 1:
                {
                    cube.shiftOnce(menuInputParam1, menuInputParam2);
                    break;
                }
                case 2:
                {
                    cube.shiftTwice(menuInputParam2, menuInputParam2);
                    break;
                }
                case 3:
                {
                    cube.shiftBack(menuInputParam1, menuInputParam2);
                    break;
                }
                default:
                {
                    std::cout << "Unexpected Input";
                    menuContinue = false;
                }
            }
        }
        else
        {
            menuContinue = false;
        }
        //I want to look up SDL2 in the future, but for now, I will use the console.
    } while (menuContinue);
    
    
    
    return 0;
}
