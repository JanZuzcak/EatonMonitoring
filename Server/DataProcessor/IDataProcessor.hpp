#pragma once

#include <DataModels/DeviceData.hpp>

namespace Eaton::Server
{
    //the interface defines methods for class that processes data comming from devices
    class IDataProcessor
    {
    public:
        virtual ~IDataProcessor() = default;

        // process data from device
        virtual void processData(const DataModels::DeviceData& data) = 0;

        //make report of received data
        virtual void makeReport() = 0;
    };
}