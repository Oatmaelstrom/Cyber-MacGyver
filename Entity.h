
class Entity{         //a base class from which all game entities can inherit
int xpos, ypos;

public:
Entity(int initX, int initY): xpos(initX), ypos(initY) { }

//setters
void setX(newX) { xpos = newX; }
void setY(newY) { ypos = newY; }

//getters
int getX() { return xpos; }
int getY() { return ypos; }
}
