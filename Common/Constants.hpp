#pragma once
#include <chrono>
#include <cstdint>
#include <string>

namespace Eaton::Common
{
    const std::uint16_t cDefaultServerPort = 3333;                  // default port server listens on
    const std::string cDefaultServerIpAddress = "127.0.0.1";        // default server address

    const auto cSendDevDataPeriod = std::chrono::seconds(1);        // the pooling interval for sending data from device to server

    const auto cServerReportPeriod = std::chrono::seconds(5);      // the interval for making report of received data on server
}