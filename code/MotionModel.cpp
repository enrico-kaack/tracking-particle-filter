
#include "MotionModel.h"
#include <iostream>

  MotionModel::MotionModel(double stdXY_, double stdSize_){
    // IMPLEMENT
    // create nomral distributions using std::normal_distribution<double> class for the motion
    // in x, y, and the change of the window size
    // store the distributions

      stdXY = stdXY_;
      stdSize = stdSize_;

      distributionXY = std::normal_distribution<double>(0, stdXY);
      distributionSize = std::normal_distribution<double>(0, stdSize);
  }


  Particle MotionModel::move(Particle p, std::mt19937& engine){
    Particle result(0,0,0);
	// IMPLEMENT
	// move the particle randomly according to the motion model defined by the stored distributions
	// return the particle
	result.x = p.x + distributionXY(engine);
	result.y = p.y + distributionXY(engine);
	result.size = p.size + distributionSize(engine);
	return result;
  }