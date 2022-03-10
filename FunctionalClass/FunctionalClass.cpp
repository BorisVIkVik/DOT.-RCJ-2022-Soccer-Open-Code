#include <./FunctionalClass.h>

BaseFunctional::BaseFunctional(Robot RC):_RC(RC)
{

}

bool BaseFunctional::checkBall()
{
    return _RC.ball1();
}

void BaseFunctional::dribblerSpeed(int8_t speed)
{
    _RC.updateDribblers(speed);
}

RobotParametrs BaseFunctional::setAngle(RobotParametrs RP, int8_t angle)
{
    RP.angle = angle;
    return RP;
}

RobotParametrs BaseFunctional::turnRC(RobotParametrs RP, int8_t angle, int8_t x, int8_t y)
{
    int8_t tmpX = RP.robot.x - x;
    int8_t tmpY = RP.robot.y - y;
    int8_t turnX = tmpX * cos(angle/57.3) - tmpY * sin(angle/57.3);
    int8_t turnY = tmpX * sin(angle/57.3) + tmpY * cos(angle/57.3);
    turnX = turnX + x;
    turnY = turnY + y;
    RP.robot.x = turnX;
    RP.robot.y = turnY;
    return RP;
}

int8_t BaseFunctional::generateATM(RobotParametrs RP, Object ob, int8_t** vF, vector<Obstacle> obs)
{
    int16_t cX = RP.robot.x - (ob.x - 59);
    int16_t cY = RP.robot.y - (ob.y + 44);

    int16_t vecNum = 120 * (cY - 1) + cX;
    int8_t atm = vF[vecNum][0];
    for(int i = 0; i < obs.size(); i++)
    {
        int16_t cObX = obs[i]._x - (ob.x - 59);
        int16_t cObY = obs[i]._y - (ob.y + 44);

        
    }
}