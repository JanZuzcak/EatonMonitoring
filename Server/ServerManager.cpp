#include <chrono>
#include <thread>

#include "Common/Constants.hpp"
#include "ServerManager.hpp"

using namespace std;
using namespace std::chrono_literals;
using namespace Eaton::Common;
using namespace Eaton::DataModels;

namespace Eaton::Server
{
    ServerManager::ServerManager(shared_ptr<IDataReceiver> dataReceiver, shared_ptr<IDataProcessor> dataProcessor)
        : m_dataReceiver(dataReceiver)
        , m_dataProcessor(dataProcessor)
        , m_shutDown(false)
    {
        //connect data receiver with data processor
        m_dataReceiver->regDataReceivedClbk([this](auto const& data) { m_dataProcessor->processData(data); });
    }

    void ServerManager::run()
    {
        m_dataReceiver->startReceive();

        while (!m_shutDown)
        {
            // make report periodically
            if (auto now = Clock::now(); now - m_lastReportTime > cServerReportPeriod)
            {
                m_lastReportTime = now;
                m_dataProcessor->makeReport();
            }

            this_thread::sleep_for(1ms);
        }
    }

    void ServerManager::shutDown()
    {
        m_shutDown = true;
        m_dataReceiver->shutDown();
    }
}