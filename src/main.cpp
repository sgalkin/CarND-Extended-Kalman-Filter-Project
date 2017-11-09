#include <iostream>
#include <memory>
#include <uWS/uWS.h>

#include "application.h"
#include "protocol.h"

int main(int, char**) // TODO: add options
{
  uWS::Hub h;
  std::unique_ptr<Application<WSProtocol>> app;

  h.onMessage([&app](uWS::WebSocket<uWS::SERVER> ws, char *data, size_t length, uWS::OpCode) {
    try {
      auto message = std::string(data, length);
      auto response = app->ProcessMessage(std::move(message));
      ws.send(response.data(), response.length(), uWS::OpCode::TEXT);
    } catch(std::runtime_error& e) {
      std::cerr << "Error while processing message: " << e.what() << std::endl;
    }
  });

  h.onConnection([&h,&app](uWS::WebSocket<uWS::SERVER>, uWS::HttpRequest) {
    std::cout << "Connected" << std::endl;
    app.reset(new Application<WSProtocol>());
  });

  h.onDisconnection([&h,&app](uWS::WebSocket<uWS::SERVER>, int, char *, size_t) {
    std::cout << "Disconnected" << std::endl;
    app.reset();
  });

  constexpr int port = 4567;
  if (h.listen(port))
  {
    std::cout << "Listening to port " << port << std::endl;
  }
  else
  {
    std::cerr << "Failed to listen to port" << port << std::endl;
    return -1;
  }
  h.run();
  return 0;
}
