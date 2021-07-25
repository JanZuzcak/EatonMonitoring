#include <iostream>
#include <DataModels/DeviceData.hpp>

#include "DataSender.hpp"

namespace Eaton::Device
{
	using namespace DataModels;

	DataSender::DataSender(const DeviceId& deviceId, const std::string& serverIpAddress, std::uint16_t portNum)
		: m_deviceId(deviceId)
		, m_sock(m_ios)
		, m_serverEndpoint(asio::ip::address::from_string(serverIpAddress), portNum)
	{
		m_sock.open(asio::ip::udp::v4());
	}

	bool DataSender::sendData(const std::vector<MeasuredValue>& data)
	{
		try
		{
			DeviceData devData = {m_deviceId, data};
			m_sock.send_to(asio::buffer(serializeToJson(devData)), m_serverEndpoint);
		}
		catch (asio::system_error& e)
		{
			std::cout << "Error occured! Error code = " << e.code()	<< ". Message: " << e.what() << std::endl;
			return false;
		}
		catch (std::exception& e)
		{
			std::cout << "Error occured! Message: " << e.what() << std::endl;
			return false;
		}

		return true;
	}
}