#pragma once

#ifdef HWASDKAGENT_EXPORTS
#define HWASDKAGENT_API __declspec(dllexport)
#else
#define HWASDKAGENT_API __declspec(dllimport)
#endif // HWASDKAGENT_EXPORTS

extern "C" 
{
	HWASDKAGENT_API bool IsRegistryValueExist(unsigned int root, const char * subKey, const char * valueName);
}