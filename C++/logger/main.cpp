// The debug logger works only
// when DEBUG_MODE is defined
// for optimization purposes
#define DEBUG_MODE

#include "debug_logger_component.h"
#include "log_categories.h"

int main()
{
    LogManager::GetInstance()->EnableCategory(ELogCategory::Default);

    Debug_Log(ELogCategory::Default, EPrintColor::Red, true, "Loading next level", 69, 420.69);

    Debug_Log("App closing :)");

    return EXIT_SUCCESS;
}

