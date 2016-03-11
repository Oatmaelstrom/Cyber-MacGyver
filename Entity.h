
class Entity{         //a base class from which all game entities can inherit
int xpos, ypos;

public:
//setters
void setX(newX) { xpos = newX; }
void setY(newY) { ypos = newY; }

//getters
int getX() { return xpos; }
int getY() { return ypos; }
}
