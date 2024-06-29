#include    <volk.h>

#include    <iostream>
#include    <vector>

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
int main()
{
    VkResult result = volkInitialize();

    if (result != VK_SUCCESS)
    {
        return -1;
    }

    VkInstance instance;

    VkApplicationInfo appInfo = {};
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pNext = nullptr;
    appInfo.pApplicationName = "Test Volk";
    appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.pEngineName = "No engine";
    appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.apiVersion = VK_VERSION_1_3;


    VkInstanceCreateInfo instCreateInfo = {};
    instCreateInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    instCreateInfo.pNext = nullptr;
    instCreateInfo.pApplicationInfo = &appInfo;
    instCreateInfo.flags = 0;
    instCreateInfo.enabledLayerCount = 0;
    instCreateInfo.ppEnabledLayerNames = nullptr;
    instCreateInfo.enabledExtensionCount = 0;
    instCreateInfo.ppEnabledExtensionNames = nullptr;

    result = vkCreateInstance(&instCreateInfo, nullptr, &instance);

    if (result != VK_SUCCESS)
    {
        return -1;
    }

    volkLoadInstance(instance);

    uint32_t physicalDeviceCount = 0;
    vkEnumeratePhysicalDevices(instance, &physicalDeviceCount, nullptr);

    std::vector<VkPhysicalDevice> physicalDevices(physicalDeviceCount);
    vkEnumeratePhysicalDevices(instance,
                               &physicalDeviceCount,
                               physicalDevices.data());

    for (auto physicalDevice : physicalDevices)
    {
        VkPhysicalDeviceProperties physicalDeviceProperties;
        vkGetPhysicalDeviceProperties(physicalDevice,
                                      &physicalDeviceProperties);

        std::cout << "Find device: "
                  << physicalDeviceProperties.deviceName
                  << ": support Vulkan API v"
                  << VK_VERSION_MAJOR(physicalDeviceProperties.apiVersion)
                  << "."
                  << VK_VERSION_MINOR(physicalDeviceProperties.apiVersion)
                  << "."
                  << VK_VERSION_PATCH(physicalDeviceProperties.apiVersion)
                  << std::endl;
    }

    return 0;
}
