#include <iostream>
#include <memory>
#include <string>

#include "Common/Constants.hpp"
#include "DataReceiver/DataReceiver.hpp"
#include "DataProcessor/DataProcessor.hpp"
#include "ServerManager.hpp"

using namespace std;
using namespace Eaton::Common;
using namespace Eaton::Server;

// program takes one optional argument: port number the server listens on, cDefaultServerPort by default
// example: Server.exe 1234

int main(int argc, char* argv[])
{
	auto portNum = cDefaultServerPort;

	//get port number from cmd line args
	if (argc > 1)
	{
		portNum = static_cast<uint16_t>(stoi(argv[1]));
	}
	cout << "port: " << portNum << endl;

	// init and run server 
	auto manager = make_unique<ServerManager>(
		make_shared<DataReceiver>(portNum),
		make_shared<DataProcessor>());

	manager->run();

	return 0;
}
