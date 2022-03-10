struct Obstacle
{
    int _x;
    int _y;
    int** _vecField;
    Obstacle(int** vecField, int x, int y)
    {
        _x = x;
        _y = y;
        _vecField = vecField;
    }
};