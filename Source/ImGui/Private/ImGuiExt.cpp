#include "ImGuiExt.h"

#include <map>

#include <imgui.h>
#include <implot.h>
#include <vector>

struct PlotVarData
{
	ImGuiID ID;
	ImVector<float> Data;
	int DataInsertIdx;
	int LastFrame;

	PlotVarData() : ID(0), DataInsertIdx(0), LastFrame(-1)
	{
	}
};

typedef std::map<ImGuiID, PlotVarData> PlotVarsMap;
static PlotVarsMap g_PlotVarsMap;

// Plot value over time
// Call with 'value == FLT_MAX' to draw without adding new value to the buffer
void ImGui::PlotVar(const char* label, float value, float scale_min, float scale_max, size_t buffer_size)
{
	if (buffer_size == 0)
		buffer_size = 120;

	ImGui::PushID(label);
	ImGuiID id = ImGui::GetID("");

	// Lookup O(log N)
	PlotVarData& pvd = g_PlotVarsMap[id];

	// Setup
	if (pvd.Data.capacity() != buffer_size)
	{
		pvd.Data.resize(buffer_size);
		memset(&pvd.Data[0], 0, sizeof(float) * buffer_size);
		pvd.DataInsertIdx = 0;
		pvd.LastFrame = -1;
	}

	// Insert (avoid unnecessary modulo operator)
	if (pvd.DataInsertIdx == buffer_size)
		pvd.DataInsertIdx = 0;
	int display_idx = pvd.DataInsertIdx;
	if (value != FLT_MAX)
		pvd.Data[pvd.DataInsertIdx++] = value;

	// Draw
	int current_frame = ImGui::GetFrameCount();
	if (pvd.LastFrame != current_frame)
	{
		ImGui::PlotLines("##plot", &pvd.Data[0], buffer_size, pvd.DataInsertIdx, NULL, scale_min, scale_max, ImVec2(0, 40));
		ImGui::SameLine();
		ImGui::Text("%s\n%-3.4f", label, pvd.Data[display_idx]); // Display last value in buffer
		pvd.LastFrame = current_frame;
	}

	ImGui::PopID();
}

void ImGui::PlotVarFlushOldEntries()
{
	int current_frame = ImGui::GetFrameCount();
	for (PlotVarsMap::iterator it = g_PlotVarsMap.begin(); it != g_PlotVarsMap.end();)
	{
		PlotVarData& pvd = it->second;
		if (pvd.LastFrame < current_frame - FMath::Max(400, (int)pvd.Data.size()))
			it = g_PlotVarsMap.erase(it);
		else
			++it;
	}
}

void ImGui::DrawCurrentFrameWaveform(const char* name, const TArray<float>& data, float y_min, float y_max, float height)
{
	if (data.IsEmpty()) return;

	// 1. 设置 ImPlot 的 Flag
	// NoInputs: 禁止用户鼠标拖拽缩放（因为你要固定范围）
	// NoTitle: 省略标题栏节省空间
	ImPlotFlags flags = ImPlotFlags_NoInputs | ImPlotFlags_NoTitle | ImPlotFlags_NoLegend;

	// 2. 开始绘图
	if (ImPlot::BeginPlot(name, ImVec2(-1, height), flags))
	{
		// --- 关键步骤 A: 锁定 Y 轴范围 ---
		// ImPlotCond_Always: 每一帧都强制重置范围，防止自动缩放
		ImPlot::SetupAxisLimits(ImAxis_Y1, y_min, y_max, ImPlotCond_Always);

		// --- 关键步骤 B: 锁定 X 轴范围 ---
		// 范围从 0 到 data.size()
		ImPlot::SetupAxisLimits(ImAxis_X1, 0, data.Num(), ImPlotCond_Always);

		// 隐藏 X/Y 轴的刻度文字（可选，为了纯波形视觉效果）
		// ImPlot::SetupAxis(ImAxis_X1, NULL, ImPlotAxisFlags_NoTickLabels);
		// ImPlot::SetupAxis(ImAxis_Y1, NULL, ImPlotAxisFlags_NoTickLabels);

		// --- 关键步骤 C: 绘制线条 ---
		// 只需要传入 Y 值的指针，它会自动对应 X = 0, 1, 2, ...
		ImPlot::PlotLine("Wave", data.GetData(), (int)data.Num());

		// (可选) --- 步骤 D: 填充颜色 ---
		// 让波形看起来更像实体，从 Y=0 的位置开始填充
		// Alpha 0.3f 让填充色半透明
		ImPlot::PushStyleVar(ImPlotStyleVar_FillAlpha, 0.3f);
		ImPlot::PlotShaded("Fill", data.GetData(), (int)data.Num(), 0); // 最后的 0 是基准线(y_ref)
		ImPlot::PopStyleVar();

		ImPlot::EndPlot();
	}
}
