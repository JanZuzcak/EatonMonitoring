#include <iostream>
#include <memory>
#include <string>

#include "Common/Constants.hpp"
#include "DataSender/DataSender.hpp"
#include "DeviceManager.hpp"
#include "MeasurementReader/DummyMeasurementReader.hpp"
#include "MeasurementReader/MeasurementReader.hpp"
#include "Utils.hpp"

using namespace std;
using namespace Eaton::Common;
using namespace Eaton::Device;

// program takes three optional arguments:
// 1. device id, random string by default
// 2. ip address of the server, cDefaultServerIpAddress by default
// 3. port number the server listens on, cDefaultServerPort by default
// example: Device.exe Device1 192.168.1.112 1234

int main(int argc, char* argv[])
{
	auto deviceId = genRandomString(10);
	auto serverAddress = cDefaultServerIpAddress;
	auto portNum = cDefaultServerPort;

	//get devce id, server address and port number from cmd line args
	if (argc > 1)
	{
		deviceId = argv[1];
		if (argc > 2)
		{
			serverAddress = argv[2];
			if (argc > 3)
			{
				portNum = static_cast<uint16_t>(stoi(argv[3]));
			}
		}
	}
	cout << "device id: " << deviceId << ", server adress: " << serverAddress << ", port: " << portNum << endl;

	// init and run device 
	auto manager = make_unique<DeviceManager>(
		make_shared<DataSender>(deviceId, serverAddress, portNum),
		make_shared<DummyMeasurementReader>()); //make_shared<MeasurementReader>()	

	manager->run();

	return 0;
}

