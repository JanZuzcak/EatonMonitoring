#include <iomanip>
#include <iostream>
#include <sstream>

#include "DataProcessor.hpp"

using namespace std;

namespace Eaton::Server
{
    DataProcessor::DataProcessor()
        : m_receivedMessages(0)
        , m_receivedValues(0)
    {
    }

    void DataProcessor::processData(const DataModels::DeviceData& data)
    {
        std::lock_guard<std::mutex> lock(m_statMutex);

        // do noting with received data, just simple and stupid statistics about received data at the moment
        m_receivedMessages++;
        m_receivedValues += static_cast<std::uint32_t>(data.values.size());
        //statistics per device
        m_statPerDevice[data.deviceId].first++;
        m_statPerDevice[data.deviceId].second += static_cast<std::uint32_t>(data.values.size());
    }

    void DataProcessor::makeReport()
    {
        std::lock_guard<std::mutex> lock(m_statMutex);

        stringstream ss;
        //make total statistics
        ss << "total number of received messages: " << m_receivedMessages << ", total number of received values: " << m_receivedValues << endl;

        //make statistics per device
        if (!m_statPerDevice.empty())
        {
            ss << "statistics per device" << endl;
            ss << "number of monitored devices: " << m_statPerDevice.size() << endl;
            ss << "  deviceId|num of rec messages|num of rec values" << endl;
            std::for_each(m_statPerDevice.begin(), m_statPerDevice.end(), [&](auto const& kv)
            {
                ss << setw(8) << setfill(' ') << kv.first
                    << setw(20) << setfill(' ') << kv.second.first
                    << setw(18) << setfill(' ') << kv.second.second << endl;
            });
        }

        cout << ss.str() << endl;
    }
}