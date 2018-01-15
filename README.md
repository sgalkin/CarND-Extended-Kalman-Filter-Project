# Extended Kalman Filter Project
[![Udacity - Self-Driving Car NanoDegree](https://s3.amazonaws.com/udacity-sdc/github/shield-carnd.svg)](http://www.udacity.com/drive)
[![CircleCI](https://circleci.com/gh/sgalkin/CarND-T2P1.svg?style=svg&circle-token=a720a551891f4cfc5bf8c8dc1b1a0bede8377493)](https://circleci.com/gh/sgalkin/CarND-T2P1)

This project implements a Kalman filter to estimate the state of a moving
object of interest with noisy lidar and radar measurements.

Implementation requires obtaining RMSE values that are lower that the tolerance
outlined in the specification.

---

## Usage
```sh
./ExtendedKF
```

## Dependencies
### Runtime
* [Term 2 Simulator](https://github.com/udacity/self-driving-car-sim/releases)

### Tools
* `cmake` >= 3.5
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* `make` >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* `gcc/g++` >= 5.4, clang
  * Linux: gcc/g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

### Libraries not included into the project
* [`uWebSocketIO`](https://github.com/uWebSockets/uWebSockets) == v0.13.0
  * Ubuntu/Debian: the repository includes `install-ubuntu.sh` that can be used to set
    up and install `uWebSocketIO`
  * Mac: the repository includes `install-mac.sh` that can be used to set
    up and install `uWebSocketIO`
  * Windows: use either Docker, VMware, or even [Windows 10 Bash on     Ubuntu](https://www.howtogeek.com/249966/how-to-install-and-use-the-linux-bash-shell-on-windows-10/)

### Libraries included into the project
* [`JSON for Modern C++`](https://github.com/nlohmann/json) - JSON parser
* [`Catch2`](https://github.com/catchorg/Catch2) - Unit-testing framework

## Build
0. Clone this repo.
1. `mkdir build`
2. `cd build`
3. `cmake .. -G "Unix Makefiles"`
4. `make`
5. `make test` - optional

## Protocol
The project uses `uWebSocketIO` request-response protocol to communicate in
communicating with the simulator.

_INPUT_: values provided by the simulator to the c++ program
```json
["sensor_measurement"] => the measurement that the simulator observed (either lidar or radar)
```

_OUTPUT_: values provided by the c++ program to the simulator
```json
["estimate_x"] <= Kalman filter estimated position x
["estimate_y"] <= Kalman filter estimated position y
["rmse_x"]
["rmse_y"]
["rmse_vx"]
["rmse_vy"]
```

---

## TODOs
* Implement program options to filter measurements
* Experiment more with Kalman filter state initialization. Eg. use truncated
  normal distribution with 0 mean to initialize speed
* Add more unit/functional tests
