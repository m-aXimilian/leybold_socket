#include <websocket_initialize.h>
#include <cstdlib>


int main(int argc, char* argv[]){

    web::ConfigureSocket configure_hanler;

    configure_hanler.ConfigreFromTomlFile("config/websocket_server.toml");

    std::cout<<configure_hanler.ip_address()<<":"<<
        configure_hanler.port()<<std::endl;

    const char* leybold_source_dir = std::getenv("LEYBOLD_SOURCE_DIR");
    std::cout<<leybold_source_dir<<std::endl;
}