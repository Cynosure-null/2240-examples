#include "NeoPid.h"

NeoPid::NeoPid()
{
  // Set the default values
  m_PID.SetP(m_coef.p);
  m_PID.SetI(m_coef.i);
  m_PID.SetD(m_coef.d);
  m_PID.SetIZone(m_coef.iz);
  m_PID.SetFF(m_coef.ff);
  m_PID.SetOutputRange(m_coef.min, m_coef.max);
}

void
NeoPid::set(double point)
{
  m_PID.SetReference(position, rev::CANSparkMax::ControlType::kPosition);
}

void
tune()
{
  frc::SmartDashboard::PutNumber("P Gain", m_coef.p);
  frc::SmartDashboard::PutNumber("I Gain", m_coef.i);
  frc::SmartDashboard::PutNumber("D Gain", m_coef.d);
  frc::SmartDashboard::PutNumber("FF Gain", m_coef.ff);
  frc::SmartDashboard::PutNumber("Max Output", m_coef.max);
  frc::SmartDashboard::PutNumber("Min Output", m_coef.min);

  m_coef.p = frc::SmartDashboard::GetNumber("P Gain", 0.0);
  m_coef.i = frc::SmartDashboard::GetNumber("I Gain", 0.0);
  m_coef.d = frc::SmartDashboard::GetNumber("D Gain", 0.0);
  m_coef.ff = frc::SmartDashboard::GetNumber("FF Gain", 0.0);
  m_coef.max = frc::SmartDashboard::GetNumber("Max Output", 0.0);
  m_coef.min = frc::SmartDashboard::GetNumber("Min Output", 0.0);
}
