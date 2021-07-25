#pragma once
#include <mutex>
#include <unordered_map>
#include <DataModels/DataTypes.hpp>

#include "IDataProcessor.hpp"

namespace Eaton::Server
{
    //the class makes statistics about received data from devices
    class DataProcessor : public IDataProcessor
    {
    public:
        DataProcessor();

        // process data from device
        virtual void processData(const DataModels::DeviceData& data) override;

        //make report of received data
        virtual void makeReport() override;

    private:
        std::uint32_t m_receivedMessages;
        std::uint32_t m_receivedValues;
        std::unordered_map<DataModels::DeviceId, std::pair<std::uint64_t, std::uint64_t>> m_statPerDevice;
        std::mutex m_statMutex;
    };

}