#include <websocket_initialize.h>





void web::ConfigureSocket::ConfigreFromTomlFile(web::fs::path config_file_path){
    
    auto config_file = toml::parse_file(config_file_path.c_str());

    auto ip_address = *config_file->get_qualified_as<std::string>("address.ip");
    auto port = *config_file->get_qualified_as<std::string>("address.port");

    ip_address_ = std::move( web::net::ip::make_address(ip_address));
    port_ = std::move(static_cast<uint16_t>(std::stoi(port)));
} 



/*
std::pair<std::string, std::string> web::InitAddressing(web::fs::path config_file_path){

    auto config_file = toml::parse_file(config_file_path.c_str());

    auto ip_address = *config_file->get_qualified_as<std::string>("address.ip");
    auto port_address = *config_file->get_qualified_as<std::string>("address.port");

    return std::make_pair(ip_address, port_address);

} 

*/