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
    int8_t tmpX = RP.robot->_x - x;
    int8_t tmpY = RP.robot->_y - y;
    int8_t turnX = tmpX * cos(angle/57.3) - tmpY * sin(angle/57.3);
    int8_t turnY = tmpX * sin(angle/57.3) + tmpY * cos(angle/57.3);
    turnX = turnX + x;
    turnY = turnY + y;
    RP.robot->_x = turnX;
    RP.robot->_y = turnY;
    return RP;
}

VectorToMove BaseFunctional::genATMVecField(RobotParametrs RP, Object ob, int8_t** vF, vector<Obstacle> obs)
{
    int16_t cX = RP.robot->_x - (ob.x - 59);
    int16_t cY = RP.robot->_y - (ob.y + 44);

    int16_t vecNum = 120 * (cY - 1) + cX;
    int8_t atm = vF[vecNum][0];
    int8_t atmMod = vF[vecNum][1];
    for(int i = 0; i < obs.size(); i++)
    {
        int16_t cObX = obs[i]._x - (ob.x - 59);
        int16_t cObY = obs[i]._y - (ob.y + 44);

        if(abs(cX - cObX) <= (obs[i]._n / 2) && abs(cY - cObY) <= (obs[i]._n / 2))
        {
            int16_t tmpATMX = atmMod * cos(atm) + cObX;
            int16_t tmpATMY = atmMod * sin(atm) + cObY;
            atmMod = sqrt(tmpATMX * tmpATMX + tmpATMY * tmpATMY);
            atm = atan2(tmpATMY, tmpATMX);
        }
    }
    return {atm, atmMod};
}

VectorToMove BaseFunctional::genATMPoint(RobotParametrs RP, int8_t x, int8_t y, int8_t vecMod)
{
    int8_t tmpX = x - RP.robot.x;
    int8_t tmpY = y - RP.robot.y;
    int8_t atm = atan2(tmpY, tmpX);
return {atm, vecMod};
}

void BaseFunctional::move(VectorToMove vtm)
{
    _RC.move(100*vtm._mod, vtm._angle);
}


void BaseFunctional::initVecField()
{
    for(int iter = 0; iter < vecNum; iter++)
    {
        map[iter] = new int8_t[infNum];
    }
    for(int iter = 0; iter < vecNum; iter++)
    {
        for(int jter = 0; jter < infNum; jter++)
        {
            map[iter][jter] = firstField[iter][jter];
        }
    }
}