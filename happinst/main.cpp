#include "pch.h"

using namespace winrt;
using namespace Windows::Foundation;

std::string versionString() noexcept;

int main()
{
    winrt::init_apartment();

    std::cout << "Hello World, PoC Version: " << versionString() << std::endl;
    pause();
    return 0;
}

std::string versionString() noexcept try {
    winrt::Windows::ApplicationModel::Package package = winrt::Windows::ApplicationModel::Package::Current();
    winrt::Windows::ApplicationModel::PackageId packageId = package.Id();

    // Gets the MSIX package full version.
    winrt::Windows::ApplicationModel::PackageVersion version = packageId.Version();

    return std::format("{}.{}.{}.{}", version.Major, version.Minor, version.Build,version.Revision);
}
catch (winrt::hresult_error const& err) {
    return std::format("<not versioned> ({})", winrt::to_string(err.message()));
}
catch (...) {
    return "<UNHANDLED EXCEPTION>";
}