
class Entity{         //a base class from which all game entities can inherit
int xpos, ypos, id;
static nextId;

public:
Entity(int initX, int initY): xpos(initX), ypos(initY) { id = nextId++; }

//setters
void setX(newX) { xpos = newX; }
void setY(newY) { ypos = newY; }
void setId(newId) { id = newId; }

//getters
int getX() { return xpos; }
int getY() { return ypos; }
int getId() { return id; }
};

class MovableEntity: Public Entity {
  
};

class StationaryEntity: Public Entity {
  
};
