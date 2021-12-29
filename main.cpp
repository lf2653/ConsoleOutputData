#include "ConsoleOutputData.h"
#include <windows.h>
#include <string>
int main()
{
    //注册数据
    ConsoleOutputData codSystemTime("SystemTime");
    ConsoleOutputData codLocalTime("LocalTime");

    SYSTEMTIME st, lt;

    while (1)
    {
        GetSystemTime(&st);
        GetLocalTime(&lt);

        std::string systemTime = std::to_string(st.wHour) + ":" + std::to_string(st.wMinute) + ":" +
                                   std::to_string(st.wSecond);

        std::string localTime = std::to_string(lt.wHour) + ":" + std::to_string(lt.wMinute) + ":" +
                                  std::to_string(lt.wSecond);

        codSystemTime.updateDataContent(systemTime);
        codLocalTime.updateDataContent(localTime);

        Sleep(1000);
    }
}
