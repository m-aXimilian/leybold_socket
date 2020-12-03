#ifndef WEBSOCKET_INITIALIZE
#define WEBSOCKET_INITIALIZE

#include <configuration_manager.h>

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
namespace http = boost::beast::http;
namespace net = boost::asio;
namespace toml = cpptoml;
namespace websocket = beast::websocket;


//std::pair<std::string, std::string> InitAddressing(fs::path);

class ConfigureSocket : public conf::ConfigurationManager{
    public:

        ConfigureSocket()
        {};
        virtual ~ConfigureSocket()
        {};

        void ConfigreFromTomlFile(fs::path) override;

        inline net::ip::address ip_address(){ return ip_address_; } 
        inline uint16_t port(){ return port_; } 

    private:
        
        //tcp::socket tcp_socket_;
        net::ip::address ip_address_;
        uint16_t port_;
};

} // namespace web

#endif //WEBSOCKET_INITIALIZE