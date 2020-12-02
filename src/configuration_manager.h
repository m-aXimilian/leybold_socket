#ifndef CONFIGURATION_MANAGER
#define CONFIGURATION_MANAGER

#include <boost/filesystem.hpp>

namespace conf{
    namespace fs = boost::filesystem;

    class ConfigurationManager{
        public:
            ConfigurationManager(){} ;
            virtual ~ConfigurationManager(){} ;

            virtual void ConfigreFromTomlFile(fs::path) = 0;
        private:
    }; 
} // namespace conf



#endif