

const int MAX_ROWZ = 100;
const int MAX_COLZ = 100;
const int MAX_SHIPSIZE=5;

typedef char BoardArray[MAX_ROWZ][MAX_COLZ];

enum Orientation {Vertical, Horizontal, None};

struct PositionType
{
    int row;
    int col;
};

struct Ship
{
    int size;
    bool status[MAX_SHIPSIZE];
    PositionType position;
    Orientation orient;
    Ship *ifsunk;
};



