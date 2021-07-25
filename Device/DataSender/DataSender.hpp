#pragma once

#include <cstdint>
#include <asio.hpp>

#include "IDataSender.hpp"

namespace Eaton::Device
{
	// sends measured data to server
	class DataSender final : public IDataSender
	{
	public:
		DataSender(const DataModels::DeviceId& deviceId, const std::string& serverIpAddress, std::uint16_t portNum);

		virtual bool sendData(const std::vector<DataModels::MeasuredValue>& data) override;

	private:
		DataModels::DeviceId m_deviceId;

		asio::io_service m_ios;
		asio::ip::udp::socket m_sock;
		asio::ip::udp::endpoint m_serverEndpoint;
	};
}