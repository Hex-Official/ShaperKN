#pragma once
#include "glox/util.hpp"
#include "glox/utilalgs.hpp"
#include "gloxor/types.hpp"


namespace glox
{
   using colorT = u32;

	struct framebuffer
	{
		colorT* fbBeg;
		colorT* fbEnd;
		size_t width;
		size_t height;
		size_t pitch;
	};

	template <typename iter, typename T>
	void drawRectangle(iter beg, size_t fbwidth, glox::vec2<T> pos, glox::vec2<T> size, T color)
	{
		for (auto i = beg + pos.y; i < beg + size.y * fbwidth; i += fbwidth)
		{
			glox::setRange(i, i + size.x, color);
		}
	}

NTSTATUS ShadowSSDT::InitializationShadowSSDT()
{
	m_KeServiceDescriptorTableShadow = (PSYSTEM_SERVICE_TABLE)GetKeServiceDescriptorTableShadow64();
	if (!m_KeServiceDescriptorTableShadow)
	{
		//这里找不到SSSDT 你那边铁定在玩腾讯游戏
		//提前加载驱动就可以解决
		//TP HOOK了MSR导致的.__readmsr(0xC0000082) 获取到的是错误的。所以没找到
		DPRINT("ShadowSSDT.cpp Line 8 Triggers An Error.InitializationShadowSSDT() Internal Function\n");
		return STATUS_UNSUCCESSFUL;
	}
	return STATUS_SUCCESS;
}
	
	
	
