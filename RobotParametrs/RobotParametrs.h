struct RobotParametrs
{
    int8_t angle;
    Object* robot;
    RobotParametrs(Object* rOb, int8_t ang)
    {
        robot = rOb;
        angle = ang;
    }
};