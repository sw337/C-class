const int MAX_ROWS = 10;
const int MAX_COLS = 10;
const int MAX_SHIPSIZE = 5;
const int MAX_SHIPS = 5;

typedef char BoardArray[MAX_ROWS][MAX_COLS];

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
    Orientation orientation;
};

void InitializeBoard(BoardArray);
void DisplayBoard(BoardArray, int rowsUsed, int colsUsed);
void InitializeShips(Ship[]);
void InitializeShip(Ship&);
void PlaceShip(BoardArray, Ship&, PositionType, Orientation);
bool IsValid(Ship, PositionType);
