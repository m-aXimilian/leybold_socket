#include <websocket_initialize.h>

#include <memory>


int main(int argc, char* argv[]){
    
    web::ConfigureSocket configure_hanler;

    configure_hanler.ConfigreFromTomlFile("config/websocket_server.toml");

    std::cout<<configure_hanler.ip_address()<<":"<<
        configure_hanler.port()<<std::endl;

}