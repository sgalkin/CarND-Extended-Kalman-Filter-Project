#pragma once

#include "model.h"
#include "measurement.h"

struct Radar : MeasurementBase<3> {
  static const char Tag;
  static const Covariance R;   // Measurement covariance matrix

  static Measurement Hp(const Model::x& x);    // Measurement projection
  static Projection Hj(const Model::x& x);     // Jacobian
  static Measurement Normalize(Measurement z); // Normalization
  static Model::Cartesian Cartesian(const Measurement& z);
};
