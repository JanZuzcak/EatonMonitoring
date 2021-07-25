#include <iostream>
#include <chrono>
#include <DataModels/DeviceData.hpp>

#include "DataReceiver.hpp"

using namespace std::chrono_literals;

namespace Eaton::Server
{
    using namespace DataModels;

    DataReceiver::DataReceiver(std::uint16_t portNum)
        : m_sock(m_ios)
        , m_recvEndpoint(asio::ip::address::from_string("0.0.0.0"), portNum)//receive device data from anywhere
        , m_shutDown(false)
    {
        m_recvBuffer.reserve(cBufferSize);

        m_sock.open(asio::ip::udp::v4());
        m_sock.bind(m_recvEndpoint);
    }

    void DataReceiver::regDataReceivedClbk(dataCallback clbk)
    {
        m_callbacks.push_back(clbk);
    }

    void DataReceiver::startReceive()
    {
        std::call_once(m_recvStarted, [this] 
        {
            m_workThread = std::thread([this] { handleReceive(); m_ios.run(); }); 
        });
    }

    void DataReceiver::shutDown()
    {
        std::call_once(m_recvFinished, [this]
        {
            m_shutDown = true;
            m_sock.shutdown(asio::socket_base::shutdown_type::shutdown_receive);
            m_ios.stop();

            if (m_workThread.joinable())
            {
                m_workThread.join();
            }
        });
    }

    void DataReceiver::handleReceive()
    {
        if (m_shutDown)
        {
            return;
        }

        try
        {
            m_sock.async_receive_from(
                asio::buffer(&m_recvBuffer[0], cBufferSize), m_devEndPoint,
                [this](asio::error_code error, std::size_t bytesTransferred)
                {
                    if (!error)
                    {
                        auto deviceData = deserializeFromJson(std::string(&m_recvBuffer[0], 0, bytesTransferred));
                        std::for_each(m_callbacks.begin(), m_callbacks.end(), [&](auto clbk) { clbk(deviceData); });
                    }
                    else
                    {
                        std::cout << "Error occured! Socket error code = " << error << std::endl;
                    }

                    handleReceive();
                }
            );
        }
        catch (asio::system_error& e)
        {
            std::cout << "Error occured! Error code = " << e.code() << ". Message: " << e.what() << std::endl;
        }
        catch (std::exception& e)
        {
            std::cout << "Error occured! Message: " << e.what() << std::endl;
        }
    }
}
