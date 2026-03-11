#pragma once
#include <vector>

namespace ImGui
{
	// Plot value over time
	// Pass FLT_MAX value to draw without adding a new value
	void IMGUI_API	PlotVar(const char* label, float value, float scale_min = FLT_MAX, float scale_max = FLT_MAX, size_t buffer_size = 120);

	// Call this periodically to discard old/unused data
	void	PlotVarFlushOldEntries();

	void IMGUI_API DrawCurrentFrameWaveform(const char* name,
							  const TArray<float>& data,
							  float y_min,
							  float y_max,
							  float height = 200.0f);
}
