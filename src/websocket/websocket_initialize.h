#ifndef WEBSOCKET_INITIALIZE
#define WEBSOCKET_INITIALIZE

#include <boost/asio/ip/tcp.hpp>
#include <boost/beast/core.hpp>
#include <boost/filesystem.hpp>
#include <boost/beast/websocket.hpp>


#include <toml/include/cpptoml.h>

#include <cstdlib>
#include <functional>
#include <iostream>
#include <string>
#include <thread>
#include <utility>


namespace web{ 

namespace beast = boost::beast;
namespace fs = boost::filesystem;
namespace toml = cpptoml;


std::pair<std::string, std::string> InitAddressing(fs::path);

}

#endif //WEBSOCKET_INITIALIZE