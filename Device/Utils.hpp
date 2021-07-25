#include <algorithm>
#include <cstdint>
#include <ctime>
#include <string>

namespace Eaton::Device
{
	std::string genRandomString(std::int16_t len)
	{
        const char charset[] =
            "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
        const size_t max_index = (sizeof(charset) - 1);

        std::random_device randDev;
        std::mt19937 gen(randDev());
        std::uniform_int_distribution<> distr(0, max_index);

        std::string str(len, '\0');
        std::generate_n(str.begin(), len, [&] { return charset[distr(gen)]; });

        return str;
    }
}