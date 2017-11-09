#pragma once

#include "model.h"
#include "measurement.h"

struct Laser : MeasurementBase<2> {
  static const char Tag;
  static const Covariance R;   // measurement covariance matrix
  
  static Measurement Hp(const Model::x& x); // Measurement projection
  static Projection Hj(const Model::x&);    // H
  static Measurement Normalize(Measurement z); // Normalization (noop)
  static Model::Cartesian Cartesian(const Measurement& z); // Cartezian tranformation (noop)
};
