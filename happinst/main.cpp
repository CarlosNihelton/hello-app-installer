#include "pch.h"

using namespace winrt;
using namespace Windows::Foundation;

std::string versionString() noexcept;

int main()
{
    winrt::init_apartment();

    std::cout << "Hello World, PoC Version: ";
}