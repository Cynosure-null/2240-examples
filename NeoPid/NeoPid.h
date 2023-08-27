#ifndef NEOPID_H_
#define NEOPID_H_

#include "Constants.h"
#include "frc/smartdashboard/SmartDashboard.h"
#include <frc/Compressor.h>
#include <frc/Solenoid.h>
#include <iostream>
#include <rev/AbsoluteEncoder.h>
#include <rev/CANSparkMax.h>

class NeoPid
{
    public:
        NeoPid();
        ~NeoPid();
        void set(double point);

        /// Run once per cycle to get data from network tables
        void tune();

    private:
        CONSTANTS::PidCoef m_coef{ 1 /*P*/,  0 /*I*/,   0 /*D*/, 0 /*FF*/,
                0 /*IZ*/, 0 /*min*/, 1 /*max*/ };

        rev::CANSparkMax m_motor{ CONSTANTS::MOTOR_ID,
        rev::CANSparkMax::MotorType::kBrushless };

        rev::SparkMaxPIDController m_PID = m_motor.GetPIDController();
};

#endif // NEOPID_H_
