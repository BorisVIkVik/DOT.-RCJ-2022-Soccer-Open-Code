#include <../Robot/Robot.h>
#include <../RobotParametrs/RobotParametrs.h>
#include <stdint.h>
#include <../Obstacle/Obstacle.h>
#include <../VectorToMove/VTM.h>
#include <../VecField/VecField.h>
#include <../StructObject/struct_Object.h>
#include <vector>

using namespace std;

int8_t vecNum = 10800;
int8_t infNum = 2;
int8_t** map = new int8_t*[vecNum];


class Functional: public BaseFunctional {};

class BaseFunctional
{
    public:
                            BaseFunctional(Robot RC):_RC(RC);
        void                dribblerSpeed(int8_t speed);
        void                initVecField();
        int8_t              lineCheck();
        void                chargeShooter();
        void                shoot(uint8_t side, uint8_t power);
        RobotParametrs      turnRC(RobotParametrs RP, int8_t angle, int8_t x, int8_t y);
        RobotParametrs      setAngle(RobotParametrs RP, int8_t angle);
        bool                checkBall();
        void                move(int8_t x, int8_t y, RobotParametrs RP);
        //void                addObstacle(VecField* vF, VecField oF, int8_t x, int8_t y);
        void                move(VectorToMove vtm);
        VectorToMove        genATMPoint(RobotParametrs RP, int8_t x, int8_t y, int8_t vecMod); 
        VectorToMove        genATMVecField(RobotParametrs RP, Object ob, int8_t** vF, vector<Obstacle> obs);
    private:
        Robot _RC;
};