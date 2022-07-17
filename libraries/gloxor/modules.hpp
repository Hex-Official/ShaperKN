#pragma once


namespace glox
{
   using module_t = void(*)(void);
}

#define _registerModule(fnc,type) [[maybe_unused, gnu::used, gnu::section(".module."#type)]] \
static glox::module_t _moduleptr_##fnc##_##type  = &fnc 

#define initPreCpuModule(fnc) _registerModule(fnc,precpu)
#define initDriverCentralModule(fnc) _registerModule(fnc,central)
#define initDriverModule(fnc) _registerModule(fnc,driver)

#ifdef GLOXTESTING
   #define registerTest(fnc) _registerModule(fnc,testing)
#else
   #define registerTest(fnc) 


PVOID ShadowSSDT::Get3SDTFunAddress(PCWSTR name)
{
	ULONG Id = GetShadowSSDTFuncIDByName(name);
	if (Id == 0)
	{
		//函数不存在。要不然就是我抄的那张表报废了。
		//就是那个字符串数组 在NtHread.h里 。实在不行就用SSSDT ID来找函数吧 
		//嘿嘿
		DPRINT("ShadowSSDT.cpp Line 58 Triggers An Error.Get3SDTFunAddress(PCWSTR name) Internal Function\n");
		return NULL;
	}
	DPRINT("[+] The syscall index of %s is %i \n", name, Id);
	return Get3SDTFunAddress(Id);
}

LONG ShadowSSDT::GetShadowSSDTFuncIDByName(PCWSTR name)
{

	UNICODE_STRING BaseFuncName;
	UNICODE_STRING DestFuncName;
	LONG i = 0;
	RtlInitUnicodeString(&DestFuncName, name);
	for (i = 0; i < 830; i++)
	{
		RtlInitUnicodeString(&BaseFuncName, g_SSSDTTableName[i]);
		if (RtlEqualUnicodeString(&BaseFuncName, &DestFuncName, FALSE))
		{
			return i;
		}
	}
	return 0;

}
