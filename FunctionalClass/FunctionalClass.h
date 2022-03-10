#include <../Robot/Robot.h>
#include <../RobotParametrs/RobotParametrs.h>
#include <stdint.h>
#include <../Obstacle/Obstacle.h>
#include <vector>

using namespace std;

class Functional: public BaseFunctional {};

class BaseFunctional
{
    public:
                            BaseFunctional(Robot RC):_RC(RC);
        void                dribblerSpeed(int8_t speed);
        int8_t              lineAngle();
        void                chargeShooter();
        void                shoot(uint8_t side, uint8_t power);
        RobotParametrs      turnRC(RobotParametrs RP, int8_t angle, int8_t x, int8_t y);
        RobotParametrs      setAngle(RobotParametrs RP, int8_t angle);
        bool                checkBall();
        void                move(int8_t x, int8_t y, RobotParametrs RP);
        void                addObstacle(VecField* vF, VecField oF, int8_t x, int8_t y);
        void                move(VecField vF, RobotParametrs RP, Obstacle ob); 
        int8_t              generateATM(RobotParametrs RP, Object ob, int8_t** vF, vector<Obstacle> obs);
    private:
        Robot _RC;
};