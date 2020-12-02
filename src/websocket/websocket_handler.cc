#include <websocket_initialize.h>
/*
#include <toml/toml.hpp>


#include <iostream>
#include <string>
*/
int main(int argc, char* argv[]){
    /*
   
    const toml::table config_file = toml::parse("config/websocket_server.toml");
    

    const auto& address = toml::get<toml::table>(config_file.at("address"));

    const auto ip_address = toml::get<std::string>(address.at("ip"));
    const auto port_address = toml::get<std::string>(address.at("port"));

    std::cout<<"configured address:\t"<<ip_address<<":"<<port_address<<std::endl;
*/

    auto address = web::InitAddressing("./config/websocket_server.toml");

    std::cout<<address.first<<":"<<address.second<<std::endl;

}