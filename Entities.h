class Entity {    //base class for non-player objects
  int id;
  static int nextid;
public:
  Entity() { id = nextid++; }
  
}

class Ground : public Entity {    //ground class for the floor type
  bool solid, liquid, gas;
  
public:
  Ground() { solid = true; liquid = false; gas = false;} //defaults to solid
  
  //void isVoid() { solid = false; liquid = false; gas = false; }
  void isSolid() { solid = true; liquid = false; gas = false;}
  void isLiquid() { solid = false; liquid = true; gas = false; }
  void isGas() { solid = false; liquid = false; gas = true; }
  //void isQuicksand() { solid = true; liquid = true; gas = false; }
  //void isToxic() { solid = false; liquid = true; gas = true; }
  //void isIrradiated() { solid = true; liquid = false; gas = true; }
  //void isLiving() { solid = true; liquid = true; gas = true;}
  
  bool getSolid() {return solid;}
  bool getLiquid() {return liquid;}
  bool getGas() {return gas;}
}

class Interactive : public Entity {     //objects that the player encounters above the floor
  int x, y, width, height;
  
public:
  Obstacle(int xpos, int ypos, int wide, int hght) : x(xpos), y(ypos), width(wide), hght(height) { }
  
  void setX(int newx) { x = newx; }
  void setY(int newy) { y = newy; }
  void setWidth(int neww) { width = neww; }
  void setHeight(int newh) { height = newh; }
  
  int getX() { return x; }
  int getY() { return y; }
  int getWidth { return width; }
  int getHeight { return height; }
  
}

class Obstacle : public Interactive {   //objects in the player's way
  //to be implemented
}

class Powerup : public Interactive {    //objects to enhance the player
  //to be implemented
}
