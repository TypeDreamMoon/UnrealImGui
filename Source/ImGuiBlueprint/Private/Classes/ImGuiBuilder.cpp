// Fill out your copyright notice in the Description page of Project Settings.

#include "Classes/ImGuiBuilder.h"
#include "Classes/ImGuiElement.h"
#include "Classes/ImGuiElementDefines.h"
#include <imgui.h>

void UImGuiBuilder::SetWindowName(const FString& InWindowName)
{
	WindowName = InWindowName;
}

void UImGuiBuilder::Draw()
{
	if (WindowName.IsEmpty()) return;

	if (ImGui::Begin(TCHAR_TO_ANSI(*WindowName)))
	{
		for (UImGuiElement* Element : Elements)
		{
			if (Element) Element->Draw();
		}
		ImGui::End();
	}
	else
	{
		ImGui::End();
	}
}

void UImGuiBuilder::AddElement(UImGuiElement* Element)
{
	if (Element) Elements.Add(Element);
}

// ==================== 文本类控件实现 ====================

UImGuiBuilder* UImGuiBuilder::Text(const FString& InText)
{
	auto* Element = NewObject<UImGuiElement_Text>(this);
	Element->Text = const_cast<FString*>(&InText);
	AddElement(Element);
	return this;
}

UImGuiBuilder* UImGuiBuilder::TextRef(FString& InText)
{
	auto* Element = NewObject<UImGuiElement_Text>(this);
	Element->Text = &InText;
	AddElement(Element);
	return this;
}

UImGuiBuilder* UImGuiBuilder::TextColored(FLinearColor InColor, const FString& InText)
{
	auto* Element = NewObject<UImGuiElement_TextColored>(this);
	Element->Color = InColor;
	Element->Text = InText;
	AddElement(Element);
	return this;
}

UImGuiBuilder* UImGuiBuilder::TextDisabled(const FString& InText)
{
	auto* Element = NewObject<UImGuiElement_TextDisabled>(this);
	Element->Text = InText;
	AddElement(Element);
	return this;
}

UImGuiBuilder* UImGuiBuilder::TextWrapped(const FString& InText)
{
	auto* Element = NewObject<UImGuiElement_TextWrapped>(this);
	Element->Text = InText;
	AddElement(Element);
	return this;
}

UImGuiBuilder* UImGuiBuilder::LabelText(const FString& InLabel, const FString& InText)
{
	auto* Element = NewObject<UImGuiElement_LabelText>(this);
	Element->Label = InLabel;
	Element->Text = InText;
	AddElement(Element);
	return this;
}

UImGuiBuilder* UImGuiBuilder::BulletText(const FString& InText)
{
	auto* Element = NewObject<UImGuiElement_BulletText>(this);
	Element->Text = InText;
	AddElement(Element);
	return this;
}

UImGuiBuilder* UImGuiBuilder::Bullet()
{
	AddElement(NewObject<UImGuiElement_Bullet>(this));
	return this;
}

// ==================== 按钮类控件实现 ====================

UImGuiBuilder* UImGuiBuilder::Button(const FString& InLabel, FVector2D InSize, FOnImGuiClick OnClick)
{
	auto* Element = NewObject<UImGuiElement_Button>(this);
	Element->Label = InLabel;
	Element->Size = InSize;
	Element->OnClick = OnClick;
	AddElement(Element);
	return this;
}

UImGuiBuilder* UImGuiBuilder::SmallButton(const FString& InLabel, FOnImGuiClick OnClick)
{
	auto* Element = NewObject<UImGuiElement_SmallButton>(this);
	Element->Label = InLabel;
	Element->OnClick = OnClick;
	AddElement(Element);
	return this;
}

UImGuiBuilder* UImGuiBuilder::InvisibleButton(const FString& InStrID, FVector2D InSize, FOnImGuiClick OnClick)
{
	auto* Element = NewObject<UImGuiElement_InvisibleButton>(this);
	Element->StrID = InStrID;
	Element->Size = InSize;
	Element->OnClick = OnClick;
	AddElement(Element);
	return this;
}

UImGuiBuilder* UImGuiBuilder::ArrowButton(const FString& InStrID, int32 InDirection, FOnImGuiClick OnClick)
{
	auto* Element = NewObject<UImGuiElement_ArrowButton>(this);
	Element->StrID = InStrID;
	Element->Direction = InDirection;
	Element->OnClick = OnClick;
	AddElement(Element);
	return this;
}

UImGuiBuilder* UImGuiBuilder::Checkbox(const FString& InLabel, bool bInChecked, FOnImGuiCheckboxChanged OnChanged)
{
	auto* Element = NewObject<UImGuiElement_Checkbox>(this);
	Element->Label = InLabel;
	Element->bChecked = bInChecked;
	Element->OnChanged = OnChanged;
	AddElement(Element);
	return this;
}

UImGuiBuilder* UImGuiBuilder::RadioButton(const FString& InLabel, bool bInActive, FOnImGuiClick OnClick)
{
	auto* Element = NewObject<UImGuiElement_RadioButton>(this);
	Element->Label = InLabel;
	Element->bActive = bInActive;
	Element->OnClick = OnClick;
	AddElement(Element);
	return this;
}

// ==================== 输入类控件实现 ====================

UImGuiBuilder* UImGuiBuilder::InputText(const FString& InLabel, const FString& InText, FOnImGuiTextChanged OnTextChanged)
{
	auto* Element = NewObject<UImGuiElement_InputText>(this);
	Element->Label = InLabel;
	Element->Text = InText;
	Element->OnTextChanged = OnTextChanged;
	AddElement(Element);
	return this;
}

UImGuiBuilder* UImGuiBuilder::InputTextMultiline(const FString& InLabel, const FString& InText, FVector2D InSize, FOnImGuiTextChanged OnTextChanged)
{
	auto* Element = NewObject<UImGuiElement_InputTextMultiline>(this);
	Element->Label = InLabel;
	Element->Text = InText;
	Element->Size = InSize;
	Element->OnTextChanged = OnTextChanged;
	AddElement(Element);
	return this;
}

UImGuiBuilder* UImGuiBuilder::InputFloat(const FString& InLabel, float InValue, float InStep, float InStepFast, FOnImGuiFloatChanged OnValueChanged)
{
	auto* Element = NewObject<UImGuiElement_InputFloat>(this);
	Element->Label = InLabel;
	Element->Value = InValue;
	Element->Step = InStep;
	Element->StepFast = InStepFast;
	Element->OnValueChanged = OnValueChanged;
	AddElement(Element);
	return this;
}

UImGuiBuilder* UImGuiBuilder::InputInt(const FString& InLabel, int32 InValue, int32 InStep, int32 InStepFast, FOnImGuiIntChanged OnValueChanged)
{
	auto* Element = NewObject<UImGuiElement_InputInt>(this);
	Element->Label = InLabel;
	Element->Value = InValue;
	Element->Step = InStep;
	Element->StepFast = InStepFast;
	Element->OnValueChanged = OnValueChanged;
	AddElement(Element);
	return this;
}

UImGuiBuilder* UImGuiBuilder::InputDouble(const FString& InLabel, double InValue, double InStep, double InStepFast)
{
	auto* Element = NewObject<UImGuiElement_InputDouble>(this);
	Element->Label = InLabel;
	Element->Value = InValue;
	Element->Step = InStep;
	Element->StepFast = InStepFast;
	AddElement(Element);
	return this;
}

UImGuiBuilder* UImGuiBuilder::InputFloat2(const FString& InLabel, FVector2D InValue)
{
	auto* Element = NewObject<UImGuiElement_InputFloat2>(this);
	Element->Label = InLabel;
	Element->Value = InValue;
	AddElement(Element);
	return this;
}

UImGuiBuilder* UImGuiBuilder::InputFloat3(const FString& InLabel, FVector InValue)
{
	auto* Element = NewObject<UImGuiElement_InputFloat3>(this);
	Element->Label = InLabel;
	Element->Value = InValue;
	AddElement(Element);
	return this;
}

UImGuiBuilder* UImGuiBuilder::InputFloat4(const FString& InLabel, FVector4 InValue)
{
	auto* Element = NewObject<UImGuiElement_InputFloat4>(this);
	Element->Label = InLabel;
	Element->Value = InValue;
	AddElement(Element);
	return this;
}

UImGuiBuilder* UImGuiBuilder::InputInt2(const FString& InLabel, FIntPoint InValue)
{
	auto* Element = NewObject<UImGuiElement_InputInt2>(this);
	Element->Label = InLabel;
	Element->Value = InValue;
	AddElement(Element);
	return this;
}

UImGuiBuilder* UImGuiBuilder::InputInt3(const FString& InLabel, FIntVector InValue)
{
	auto* Element = NewObject<UImGuiElement_InputInt3>(this);
	Element->Label = InLabel;
	Element->Value = InValue;
	AddElement(Element);
	return this;
}

// ==================== 滑动条类控件实现 ====================

UImGuiBuilder* UImGuiBuilder::SliderFloat(const FString& InLabel, float InValue, float InMin, float InMax, FOnImGuiFloatChanged OnValueChanged)
{
	auto* Element = NewObject<UImGuiElement_SliderFloat>(this);
	Element->Label = InLabel;
	Element->Value = InValue;
	Element->MinValue = InMin;
	Element->MaxValue = InMax;
	Element->OnValueChanged = OnValueChanged;
	AddElement(Element);
	return this;
}

UImGuiBuilder* UImGuiBuilder::SliderInt(const FString& InLabel, int32 InValue, int32 InMin, int32 InMax, FOnImGuiIntChanged OnValueChanged)
{
	auto* Element = NewObject<UImGuiElement_SliderInt>(this);
	Element->Label = InLabel;
	Element->Value = InValue;
	Element->MinValue = InMin;
	Element->MaxValue = InMax;
	Element->OnValueChanged = OnValueChanged;
	AddElement(Element);
	return this;
}

UImGuiBuilder* UImGuiBuilder::SliderFloat2(const FString& InLabel, FVector2D InValue, float InMin, float InMax)
{
	auto* Element = NewObject<UImGuiElement_SliderFloat2>(this);
	Element->Label = InLabel;
	Element->Value = InValue;
	Element->MinValue = InMin;
	Element->MaxValue = InMax;
	AddElement(Element);
	return this;
}

UImGuiBuilder* UImGuiBuilder::SliderFloat3(const FString& InLabel, FVector InValue, float InMin, float InMax)
{
	auto* Element = NewObject<UImGuiElement_SliderFloat3>(this);
	Element->Label = InLabel;
	Element->Value = InValue;
	Element->MinValue = InMin;
	Element->MaxValue = InMax;
	AddElement(Element);
	return this;
}

UImGuiBuilder* UImGuiBuilder::SliderFloat4(const FString& InLabel, FVector4 InValue, float InMin, float InMax)
{
	auto* Element = NewObject<UImGuiElement_SliderFloat4>(this);
	Element->Label = InLabel;
	Element->Value = InValue;
	Element->MinValue = InMin;
	Element->MaxValue = InMax;
	AddElement(Element);
	return this;
}

UImGuiBuilder* UImGuiBuilder::SliderAngle(const FString& InLabel, float InRadValue, float InDegMin, float InDegMax)
{
	auto* Element = NewObject<UImGuiElement_SliderAngle>(this);
	Element->Label = InLabel;
	Element->RadValue = InRadValue;
	Element->DegMin = InDegMin;
	Element->DegMax = InDegMax;
	AddElement(Element);
	return this;
}

UImGuiBuilder* UImGuiBuilder::VSliderFloat(const FString& InLabel, FVector2D InSize, float InValue, float InMin, float InMax)
{
	auto* Element = NewObject<UImGuiElement_VSliderFloat>(this);
	Element->Label = InLabel;
	Element->Size = InSize;
	Element->Value = InValue;
	Element->MinValue = InMin;
	Element->MaxValue = InMax;
	AddElement(Element);
	return this;
}

UImGuiBuilder* UImGuiBuilder::VSliderInt(const FString& InLabel, FVector2D InSize, int32 InValue, int32 InMin, int32 InMax)
{
	auto* Element = NewObject<UImGuiElement_VSliderInt>(this);
	Element->Label = InLabel;
	Element->Size = InSize;
	Element->Value = InValue;
	Element->MinValue = InMin;
	Element->MaxValue = InMax;
	AddElement(Element);
	return this;
}

// ==================== 拖拽类控件实现 ====================

UImGuiBuilder* UImGuiBuilder::DragFloat(const FString& InLabel, float InValue, float InSpeed, float InMin, float InMax, FOnImGuiFloatChanged OnValueChanged)
{
	auto* Element = NewObject<UImGuiElement_DragFloat>(this);
	Element->Label = InLabel;
	Element->Value = InValue;
	Element->Speed = InSpeed;
	Element->MinValue = InMin;
	Element->MaxValue = InMax;
	Element->OnValueChanged = OnValueChanged;
	AddElement(Element);
	return this;
}

UImGuiBuilder* UImGuiBuilder::DragInt(const FString& InLabel, int32 InValue, float InSpeed, int32 InMin, int32 InMax, FOnImGuiIntChanged OnValueChanged)
{
	auto* Element = NewObject<UImGuiElement_DragInt>(this);
	Element->Label = InLabel;
	Element->Value = InValue;
	Element->Speed = InSpeed;
	Element->MinValue = InMin;
	Element->MaxValue = InMax;
	Element->OnValueChanged = OnValueChanged;
	AddElement(Element);
	return this;
}

UImGuiBuilder* UImGuiBuilder::DragFloat2(const FString& InLabel, FVector2D InValue, float InSpeed, float InMin, float InMax)
{
	auto* Element = NewObject<UImGuiElement_DragFloat2>(this);
	Element->Label = InLabel;
	Element->Value = InValue;
	Element->Speed = InSpeed;
	Element->MinValue = InMin;
	Element->MaxValue = InMax;
	AddElement(Element);
	return this;
}

UImGuiBuilder* UImGuiBuilder::DragFloat3(const FString& InLabel, FVector InValue, float InSpeed, float InMin, float InMax)
{
	auto* Element = NewObject<UImGuiElement_DragFloat3>(this);
	Element->Label = InLabel;
	Element->Value = InValue;
	Element->Speed = InSpeed;
	Element->MinValue = InMin;
	Element->MaxValue = InMax;
	AddElement(Element);
	return this;
}

UImGuiBuilder* UImGuiBuilder::DragFloat4(const FString& InLabel, FVector4 InValue, float InSpeed, float InMin, float InMax)
{
	auto* Element = NewObject<UImGuiElement_DragFloat4>(this);
	Element->Label = InLabel;
	Element->Value = InValue;
	Element->Speed = InSpeed;
	Element->MinValue = InMin;
	Element->MaxValue = InMax;
	AddElement(Element);
	return this;
}

UImGuiBuilder* UImGuiBuilder::DragInt2(const FString& InLabel, FIntPoint InValue, float InSpeed, int32 InMin, int32 InMax)
{
	auto* Element = NewObject<UImGuiElement_DragInt2>(this);
	Element->Label = InLabel;
	Element->Value = InValue;
	Element->Speed = InSpeed;
	Element->MinValue = InMin;
	Element->MaxValue = InMax;
	AddElement(Element);
	return this;
}

UImGuiBuilder* UImGuiBuilder::DragInt3(const FString& InLabel, FIntVector InValue, float InSpeed, int32 InMin, int32 InMax)
{
	auto* Element = NewObject<UImGuiElement_DragInt3>(this);
	Element->Label = InLabel;
	Element->Value = InValue;
	Element->Speed = InSpeed;
	Element->MinValue = InMin;
	Element->MaxValue = InMax;
	AddElement(Element);
	return this;
}

// ==================== 颜色类控件实现 ====================

UImGuiBuilder* UImGuiBuilder::ColorEdit3(const FString& InLabel, FLinearColor InColor, FOnImGuiColorChanged OnColorChanged)
{
	auto* Element = NewObject<UImGuiElement_ColorEdit3>(this);
	Element->Label = InLabel;
	Element->Color = InColor;
	Element->OnColorChanged = OnColorChanged;
	AddElement(Element);
	return this;
}

UImGuiBuilder* UImGuiBuilder::ColorEdit4(const FString& InLabel, FLinearColor InColor, FOnImGuiColorChanged OnColorChanged)
{
	auto* Element = NewObject<UImGuiElement_ColorEdit4>(this);
	Element->Label = InLabel;
	Element->Color = InColor;
	Element->OnColorChanged = OnColorChanged;
	AddElement(Element);
	return this;
}

UImGuiBuilder* UImGuiBuilder::ColorPicker3(const FString& InLabel, FLinearColor InColor, FOnImGuiColorChanged OnColorChanged)
{
	auto* Element = NewObject<UImGuiElement_ColorPicker3>(this);
	Element->Label = InLabel;
	Element->Color = InColor;
	Element->OnColorChanged = OnColorChanged;
	AddElement(Element);
	return this;
}

UImGuiBuilder* UImGuiBuilder::ColorPicker4(const FString& InLabel, FLinearColor InColor, FOnImGuiColorChanged OnColorChanged)
{
	auto* Element = NewObject<UImGuiElement_ColorPicker4>(this);
	Element->Label = InLabel;
	Element->Color = InColor;
	Element->OnColorChanged = OnColorChanged;
	AddElement(Element);
	return this;
}

UImGuiBuilder* UImGuiBuilder::ColorButton(const FString& InDescID, FLinearColor InColor, FVector2D InSize)
{
	auto* Element = NewObject<UImGuiElement_ColorButton>(this);
	Element->DescID = InDescID;
	Element->Color = InColor;
	Element->Size = InSize;
	AddElement(Element);
	return this;
}

// ==================== 树形结构控件实现 ====================

UImGuiBuilder* UImGuiBuilder::TreeNode(const FString& InLabel)
{
	auto* Element = NewObject<UImGuiElement_TreeNode>(this);
	Element->Label = InLabel;
	AddElement(Element);
	return this;
}

UImGuiBuilder* UImGuiBuilder::TreePop()
{
	AddElement(NewObject<UImGuiElement_TreePop>(this));
	return this;
}

UImGuiBuilder* UImGuiBuilder::CollapsingHeader(const FString& InLabel)
{
	auto* Element = NewObject<UImGuiElement_CollapsingHeader>(this);
	Element->Label = InLabel;
	AddElement(Element);
	return this;
}

UImGuiBuilder* UImGuiBuilder::SetNextItemOpen(bool bIsOpen)
{
	auto* Element = NewObject<UImGuiElement_SetNextItemOpen>(this);
	Element->bIsOpen = bIsOpen;
	AddElement(Element);
	return this;
}

// ==================== 可选择控件实现 ====================

UImGuiBuilder* UImGuiBuilder::Selectable(const FString& InLabel, bool bInSelected, FVector2D InSize)
{
	auto* Element = NewObject<UImGuiElement_Selectable>(this);
	Element->Label = InLabel;
	Element->bSelected = bInSelected;
	Element->Size = InSize;
	AddElement(Element);
	return this;
}

// ==================== 组合框控件实现 ====================

UImGuiBuilder* UImGuiBuilder::BeginCombo(const FString& InLabel, const FString& InPreviewValue)
{
	auto* Element = NewObject<UImGuiElement_BeginCombo>(this);
	Element->Label = InLabel;
	Element->PreviewValue = InPreviewValue;
	AddElement(Element);
	return this;
}

UImGuiBuilder* UImGuiBuilder::EndCombo()
{
	AddElement(NewObject<UImGuiElement_EndCombo>(this));
	return this;
}

// ==================== 列表框控件实现 ====================

UImGuiBuilder* UImGuiBuilder::BeginListBox(const FString& InLabel, FVector2D InSize)
{
	auto* Element = NewObject<UImGuiElement_BeginListBox>(this);
	Element->Label = InLabel;
	Element->Size = InSize;
	AddElement(Element);
	return this;
}

UImGuiBuilder* UImGuiBuilder::EndListBox()
{
	AddElement(NewObject<UImGuiElement_EndListBox>(this));
	return this;
}

UImGuiBuilder* UImGuiBuilder::ListBox(const FString& InLabel, const TArray<FString>& InItems, int32 InCurrentItem, int32 InHeightInItems, FOnImGuiIntChanged OnSelectionChanged)
{
	auto* Element = NewObject<UImGuiElement_ListBox>(this);
	Element->Label = InLabel;
	Element->Items = InItems;
	Element->CurrentItem = InCurrentItem;
	Element->HeightInItems = InHeightInItems;
	Element->OnSelectionChanged = OnSelectionChanged;
	AddElement(Element);
	return this;
}

// ==================== 组合框控件实现 ====================

UImGuiBuilder* UImGuiBuilder::Combo(const FString& InLabel, const TArray<FString>& InItems, int32 InCurrentItem, FOnImGuiComboChanged OnSelectionChanged)
{
	auto* Element = NewObject<UImGuiElement_Combo>(this);
	Element->Label = InLabel;
	Element->Items = InItems;
	Element->CurrentItem = InCurrentItem;
	Element->OnSelectionChanged = OnSelectionChanged;
	AddElement(Element);
	return this;
}

// ==================== 菜单控件实现 ====================

UImGuiBuilder* UImGuiBuilder::BeginMenuBar()
{
	AddElement(NewObject<UImGuiElement_BeginMenuBar>(this));
	return this;
}

UImGuiBuilder* UImGuiBuilder::EndMenuBar()
{
	AddElement(NewObject<UImGuiElement_EndMenuBar>(this));
	return this;
}

UImGuiBuilder* UImGuiBuilder::BeginMainMenuBar()
{
	AddElement(NewObject<UImGuiElement_BeginMainMenuBar>(this));
	return this;
}

UImGuiBuilder* UImGuiBuilder::EndMainMenuBar()
{
	AddElement(NewObject<UImGuiElement_EndMainMenuBar>(this));
	return this;
}

UImGuiBuilder* UImGuiBuilder::BeginMenu(const FString& InLabel, bool bEnabled)
{
	auto* Element = NewObject<UImGuiElement_BeginMenu>(this);
	Element->Label = InLabel;
	Element->bEnabled = bEnabled;
	AddElement(Element);
	return this;
}

UImGuiBuilder* UImGuiBuilder::EndMenu()
{
	AddElement(NewObject<UImGuiElement_EndMenu>(this));
	return this;
}

UImGuiBuilder* UImGuiBuilder::MenuItem(const FString& InLabel, const FString& InShortcut, bool bSelected, bool bEnabled, FOnImGuiClick OnClicked)
{
	auto* Element = NewObject<UImGuiElement_MenuItem>(this);
	Element->Label = InLabel;
	Element->Shortcut = InShortcut;
	Element->bSelected = bSelected;
	Element->bEnabled = bEnabled;
	Element->OnClicked = OnClicked;
	AddElement(Element);
	return this;
}

// ==================== 弹出窗口控件实现 ====================

UImGuiBuilder* UImGuiBuilder::BeginPopup(const FString& InStrID)
{
	auto* Element = NewObject<UImGuiElement_BeginPopup>(this);
	Element->StrID = InStrID;
	AddElement(Element);
	return this;
}

UImGuiBuilder* UImGuiBuilder::EndPopup()
{
	AddElement(NewObject<UImGuiElement_EndPopup>(this));
	return this;
}

UImGuiBuilder* UImGuiBuilder::BeginPopupModal(const FString& InName)
{
	auto* Element = NewObject<UImGuiElement_BeginPopupModal>(this);
	Element->Name = InName;
	AddElement(Element);
	return this;
}

UImGuiBuilder* UImGuiBuilder::OpenPopup(const FString& InStrID)
{
	auto* Element = NewObject<UImGuiElement_OpenPopup>(this);
	Element->StrID = InStrID;
	AddElement(Element);
	return this;
}

UImGuiBuilder* UImGuiBuilder::CloseCurrentPopup()
{
	AddElement(NewObject<UImGuiElement_CloseCurrentPopup>(this));
	return this;
}

// ==================== 表格控件实现 ====================

UImGuiBuilder* UImGuiBuilder::BeginTable(const FString& InStrID, int32 InColumn)
{
	auto* Element = NewObject<UImGuiElement_BeginTable>(this);
	Element->StrID = InStrID;
	Element->Column = InColumn;
	AddElement(Element);
	return this;
}

UImGuiBuilder* UImGuiBuilder::EndTable()
{
	AddElement(NewObject<UImGuiElement_EndTable>(this));
	return this;
}

UImGuiBuilder* UImGuiBuilder::TableNextRow(float InMinRowHeight)
{
	auto* Element = NewObject<UImGuiElement_TableNextRow>(this);
	Element->MinRowHeight = InMinRowHeight;
	AddElement(Element);
	return this;
}

UImGuiBuilder* UImGuiBuilder::TableNextColumn()
{
	AddElement(NewObject<UImGuiElement_TableNextColumn>(this));
	return this;
}

UImGuiBuilder* UImGuiBuilder::TableSetColumnIndex(int32 InColumnIndex)
{
	auto* Element = NewObject<UImGuiElement_TableSetColumnIndex>(this);
	Element->ColumnIndex = InColumnIndex;
	AddElement(Element);
	return this;
}

UImGuiBuilder* UImGuiBuilder::TableSetupColumn(const FString& InLabel, float InInitWidthOrWeight)
{
	auto* Element = NewObject<UImGuiElement_TableSetupColumn>(this);
	Element->Label = InLabel;
	Element->InitWidthOrWeight = InInitWidthOrWeight;
	AddElement(Element);
	return this;
}

UImGuiBuilder* UImGuiBuilder::TableHeadersRow()
{
	AddElement(NewObject<UImGuiElement_TableHeadersRow>(this));
	return this;
}

// ==================== 标签页控件实现 ====================

UImGuiBuilder* UImGuiBuilder::BeginTabBar(const FString& InStrID)
{
	auto* Element = NewObject<UImGuiElement_BeginTabBar>(this);
	Element->StrID = InStrID;
	AddElement(Element);
	return this;
}

UImGuiBuilder* UImGuiBuilder::EndTabBar()
{
	AddElement(NewObject<UImGuiElement_EndTabBar>(this));
	return this;
}

UImGuiBuilder* UImGuiBuilder::BeginTabItem(const FString& InLabel)
{
	auto* Element = NewObject<UImGuiElement_BeginTabItem>(this);
	Element->Label = InLabel;
	AddElement(Element);
	return this;
}

UImGuiBuilder* UImGuiBuilder::EndTabItem()
{
	AddElement(NewObject<UImGuiElement_EndTabItem>(this));
	return this;
}

// ==================== 提示框控件实现 ====================

UImGuiBuilder* UImGuiBuilder::BeginTooltip()
{
	AddElement(NewObject<UImGuiElement_BeginTooltip>(this));
	return this;
}

UImGuiBuilder* UImGuiBuilder::EndTooltip()
{
	AddElement(NewObject<UImGuiElement_EndTooltip>(this));
	return this;
}

UImGuiBuilder* UImGuiBuilder::SetTooltip(const FString& InText)
{
	auto* Element = NewObject<UImGuiElement_SetTooltip>(this);
	Element->Text = InText;
	AddElement(Element);
	return this;
}

// ==================== 布局控件实现 ====================

UImGuiBuilder* UImGuiBuilder::Spacing()
{
	AddElement(NewObject<UImGuiElement_Spacing>(this));
	return this;
}

UImGuiBuilder* UImGuiBuilder::Dummy(FVector2D InSize)
{
	auto* Element = NewObject<UImGuiElement_Dummy>(this);
	Element->Size = InSize;
	AddElement(Element);
	return this;
}

UImGuiBuilder* UImGuiBuilder::NewLine()
{
	AddElement(NewObject<UImGuiElement_NewLine>(this));
	return this;
}

UImGuiBuilder* UImGuiBuilder::Separator()
{
	AddElement(NewObject<UImGuiElement_Separator>(this));
	return this;
}

UImGuiBuilder* UImGuiBuilder::SameLine(float InOffsetFromStartX, float InSpacing)
{
	auto* Element = NewObject<UImGuiElement_SameLine>(this);
	Element->OffsetFromStartX = InOffsetFromStartX;
	Element->Spacing = InSpacing;
	AddElement(Element);
	return this;
}

UImGuiBuilder* UImGuiBuilder::Indent(float InIndentWidth)
{
	auto* Element = NewObject<UImGuiElement_Indent>(this);
	Element->IndentWidth = InIndentWidth;
	AddElement(Element);
	return this;
}

UImGuiBuilder* UImGuiBuilder::Unindent(float InIndentWidth)
{
	auto* Element = NewObject<UImGuiElement_Unindent>(this);
	Element->IndentWidth = InIndentWidth;
	AddElement(Element);
	return this;
}

UImGuiBuilder* UImGuiBuilder::BeginGroup()
{
	AddElement(NewObject<UImGuiElement_BeginGroup>(this));
	return this;
}

UImGuiBuilder* UImGuiBuilder::EndGroup()
{
	AddElement(NewObject<UImGuiElement_EndGroup>(this));
	return this;
}

// ==================== 子窗口控件实现 ====================

UImGuiBuilder* UImGuiBuilder::BeginChild(const FString& InStrID, FVector2D InSize, bool bBorder)
{
	auto* Element = NewObject<UImGuiElement_BeginChild>(this);
	Element->StrID = InStrID;
	Element->Size = InSize;
	Element->bBorder = bBorder;
	AddElement(Element);
	return this;
}

UImGuiBuilder* UImGuiBuilder::EndChild()
{
	AddElement(NewObject<UImGuiElement_EndChild>(this));
	return this;
}

// ==================== 进度条控件实现 ====================

UImGuiBuilder* UImGuiBuilder::ProgressBar(float InFraction, FVector2D InSize, const FString& InOverlay)
{
	auto* Element = NewObject<UImGuiElement_ProgressBar>(this);
	Element->Fraction = InFraction;
	Element->Size = InSize;
	Element->Overlay = InOverlay;
	AddElement(Element);
	return this;
}

// ==================== 图像控件实现 ====================

UImGuiBuilder* UImGuiBuilder::Image(int64 InTextureID, FVector2D InSize, FVector2D InUV0, FVector2D InUV1, FLinearColor InTintColor, FLinearColor InBorderColor)
{
	auto* Element = NewObject<UImGuiElement_Image>(this);
	Element->TextureID = InTextureID;
	Element->Size = InSize;
	Element->UV0 = InUV0;
	Element->UV1 = InUV1;
	Element->TintColor = InTintColor;
	Element->BorderColor = InBorderColor;
	AddElement(Element);
	return this;
}

UImGuiBuilder* UImGuiBuilder::ImageButton(const FString& InStrID, int64 InTextureID, FVector2D InSize, FVector2D InUV0, FVector2D InUV1, FLinearColor InBgColor, FLinearColor InTintColor)
{
	auto* Element = NewObject<UImGuiElement_ImageButton>(this);
	Element->StrID = InStrID;
	Element->TextureID = InTextureID;
	Element->Size = InSize;
	Element->UV0 = InUV0;
	Element->UV1 = InUV1;
	Element->BgColor = InBgColor;
	Element->TintColor = InTintColor;
	AddElement(Element);
	return this;
}

// ==================== 其他 ====================

UImGuiBuilder* UImGuiBuilder::End()
{
	return this;
}
