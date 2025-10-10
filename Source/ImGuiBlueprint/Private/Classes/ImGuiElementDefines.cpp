#include "Classes/ImGuiElementDefines.h"
#include <imgui.h>

// ==================== 文本类控件实现 ====================

void UImGuiElement_Text::Draw()
{
	ImGui::Text("%s", TCHAR_TO_ANSI(*Text));
}

void UImGuiElement_TextColored::Draw()
{
	ImGui::TextColored(ImVec4((float)Color.R, (float)Color.G, (float)Color.B, (float)Color.A), "%s", TCHAR_TO_ANSI(*Text));
}

void UImGuiElement_TextDisabled::Draw()
{
	ImGui::TextDisabled("%s", TCHAR_TO_ANSI(*Text));
}

void UImGuiElement_TextWrapped::Draw()
{
	ImGui::TextWrapped("%s", TCHAR_TO_ANSI(*Text));
}

void UImGuiElement_LabelText::Draw()
{
	ImGui::LabelText(TCHAR_TO_ANSI(*Label), "%s", TCHAR_TO_ANSI(*Text));
}

void UImGuiElement_BulletText::Draw()
{
	ImGui::BulletText("%s", TCHAR_TO_ANSI(*Text));
}

void UImGuiElement_Bullet::Draw()
{
	ImGui::Bullet();
}

// ==================== 按钮类控件实现 ====================

void UImGuiElement_Button::Draw()
{
	bClicked = ImGui::Button(TCHAR_TO_ANSI(*Label), ImVec2(Size.X, Size.Y));
	if (bClicked && OnClick.IsBound())
	{
		OnClick.Execute();
	}
}

void UImGuiElement_SmallButton::Draw()
{
	bClicked = ImGui::SmallButton(TCHAR_TO_ANSI(*Label));
	if (bClicked && OnClick.IsBound())
	{
		OnClick.Execute();
	}
}

void UImGuiElement_InvisibleButton::Draw()
{
	bClicked = ImGui::InvisibleButton(TCHAR_TO_ANSI(*StrID), ImVec2(Size.X, Size.Y));
	if (bClicked && OnClick.IsBound())
	{
		OnClick.Execute();
	}
}

void UImGuiElement_ArrowButton::Draw()
{
	bClicked = ImGui::ArrowButton(TCHAR_TO_ANSI(*StrID), (ImGuiDir)Direction);
	if (bClicked && OnClick.IsBound())
	{
		OnClick.Execute();
	}
}

void UImGuiElement_Checkbox::Draw()
{
	bool OldChecked = bChecked;
	ImGui::Checkbox(TCHAR_TO_ANSI(*Label), &bChecked);
	if (OldChecked != bChecked && OnChanged.IsBound())
	{
		OnChanged.Execute(bChecked);
	}
}

void UImGuiElement_RadioButton::Draw()
{
	if (ImGui::RadioButton(TCHAR_TO_ANSI(*Label), bActive))
	{
		bActive = !bActive;
		if (OnClick.IsBound())
		{
			OnClick.Execute();
		}
	}
}

// ==================== 输入类控件实现 ====================

void UImGuiElement_InputText::Draw()
{
	FCStringAnsi::Strncpy(Buffer, TCHAR_TO_ANSI(*Text), sizeof(Buffer) - 1);
	if (ImGui::InputText(TCHAR_TO_ANSI(*Label), Buffer, sizeof(Buffer)))
	{
		FString NewText = FString(ANSI_TO_TCHAR(Buffer));
		if (NewText != Text)
		{
			Text = NewText;
			if (OnTextChanged.IsBound())
			{
				OnTextChanged.Execute(Text);
			}
		}
	}
}

void UImGuiElement_InputTextMultiline::Draw()
{
	FCStringAnsi::Strncpy(Buffer, TCHAR_TO_ANSI(*Text), sizeof(Buffer) - 1);
	if (ImGui::InputTextMultiline(TCHAR_TO_ANSI(*Label), Buffer, sizeof(Buffer), ImVec2(Size.X, Size.Y)))
	{
		FString NewText = FString(ANSI_TO_TCHAR(Buffer));
		if (NewText != Text)
		{
			Text = NewText;
			if (OnTextChanged.IsBound())
			{
				OnTextChanged.Execute(Text);
			}
		}
	}
}

void UImGuiElement_InputFloat::Draw()
{
	float OldValue = Value;
	ImGui::InputFloat(TCHAR_TO_ANSI(*Label), &Value, Step, StepFast);
	if (OldValue != Value && OnValueChanged.IsBound())
	{
		OnValueChanged.Execute(Value);
	}
}

void UImGuiElement_InputInt::Draw()
{
	int32 OldValue = Value;
	ImGui::InputInt(TCHAR_TO_ANSI(*Label), &Value, Step, StepFast);
	if (OldValue != Value && OnValueChanged.IsBound())
	{
		OnValueChanged.Execute(Value);
	}
}

void UImGuiElement_InputDouble::Draw()
{
	ImGui::InputDouble(TCHAR_TO_ANSI(*Label), &Value, Step, StepFast);
}

void UImGuiElement_InputFloat2::Draw()
{
	float Values[2] = { (float)Value.X, (float)Value.Y };
	if (ImGui::InputFloat2(TCHAR_TO_ANSI(*Label), Values))
	{
		Value = FVector2D(Values[0], Values[1]);
	}
}

void UImGuiElement_InputFloat3::Draw()
{
	float Values[3] = { (float)Value.X, (float)Value.Y, (float)Value.Z };
	if (ImGui::InputFloat3(TCHAR_TO_ANSI(*Label), Values))
	{
		Value = FVector(Values[0], Values[1], Values[2]);
	}
}

void UImGuiElement_InputFloat4::Draw()
{
	float Values[4] = { (float)Value.X, (float)Value.Y, (float)Value.Z, (float)Value.W };
	if (ImGui::InputFloat4(TCHAR_TO_ANSI(*Label), Values))
	{
		Value = FVector4(Values[0], Values[1], Values[2], Values[3]);
	}
}

void UImGuiElement_InputInt2::Draw()
{
	int Values[2] = { Value.X, Value.Y };
	if (ImGui::InputInt2(TCHAR_TO_ANSI(*Label), Values))
	{
		Value = FIntPoint(Values[0], Values[1]);
	}
}

void UImGuiElement_InputInt3::Draw()
{
	int Values[3] = { Value.X, Value.Y, Value.Z };
	if (ImGui::InputInt3(TCHAR_TO_ANSI(*Label), Values))
	{
		Value = FIntVector(Values[0], Values[1], Values[2]);
	}
}

// ==================== 滑动条类控件实现 ====================

void UImGuiElement_SliderFloat::Draw()
{
	float OldValue = Value;
	ImGui::SliderFloat(TCHAR_TO_ANSI(*Label), &Value, MinValue, MaxValue);
	if (OldValue != Value && OnValueChanged.IsBound())
	{
		OnValueChanged.Execute(Value);
	}
}

void UImGuiElement_SliderInt::Draw()
{
	int32 OldValue = Value;
	ImGui::SliderInt(TCHAR_TO_ANSI(*Label), &Value, MinValue, MaxValue);
	if (OldValue != Value && OnValueChanged.IsBound())
	{
		OnValueChanged.Execute(Value);
	}
}

void UImGuiElement_SliderFloat2::Draw()
{
	float Values[2] = { (float)Value.X, (float)Value.Y };
	if (ImGui::SliderFloat2(TCHAR_TO_ANSI(*Label), Values, MinValue, MaxValue))
	{
		Value = FVector2D(Values[0], Values[1]);
	}
}

void UImGuiElement_SliderFloat3::Draw()
{
	float Values[3] = { (float)Value.X, (float)Value.Y, (float)Value.Z };
	if (ImGui::SliderFloat3(TCHAR_TO_ANSI(*Label), Values, MinValue, MaxValue))
	{
		Value = FVector(Values[0], Values[1], Values[2]);
	}
}

void UImGuiElement_SliderFloat4::Draw()
{
	float Values[4] = { (float)Value.X, (float)Value.Y, (float)Value.Z, (float)Value.W };
	if (ImGui::SliderFloat4(TCHAR_TO_ANSI(*Label), Values, MinValue, MaxValue))
	{
		Value = FVector4(Values[0], Values[1], Values[2], Values[3]);
	}
}

void UImGuiElement_SliderAngle::Draw()
{
	ImGui::SliderAngle(TCHAR_TO_ANSI(*Label), &RadValue, DegMin, DegMax);
}

void UImGuiElement_VSliderFloat::Draw()
{
	ImGui::VSliderFloat(TCHAR_TO_ANSI(*Label), ImVec2(Size.X, Size.Y), &Value, MinValue, MaxValue);
}

void UImGuiElement_VSliderInt::Draw()
{
	ImGui::VSliderInt(TCHAR_TO_ANSI(*Label), ImVec2(Size.X, Size.Y), &Value, MinValue, MaxValue);
}

// ==================== 拖拽类控件实现 ====================

void UImGuiElement_DragFloat::Draw()
{
	float OldValue = Value;
	ImGui::DragFloat(TCHAR_TO_ANSI(*Label), &Value, Speed, MinValue, MaxValue);
	if (OldValue != Value && OnValueChanged.IsBound())
	{
		OnValueChanged.Execute(Value);
	}
}

void UImGuiElement_DragInt::Draw()
{
	int32 OldValue = Value;
	ImGui::DragInt(TCHAR_TO_ANSI(*Label), &Value, Speed, MinValue, MaxValue);
	if (OldValue != Value && OnValueChanged.IsBound())
	{
		OnValueChanged.Execute(Value);
	}
}

void UImGuiElement_DragFloat2::Draw()
{
	float Values[2] = { (float)Value.X, (float)Value.Y };
	if (ImGui::DragFloat2(TCHAR_TO_ANSI(*Label), Values, Speed, MinValue, MaxValue))
	{
		Value = FVector2D(Values[0], Values[1]);
	}
}

void UImGuiElement_DragFloat3::Draw()
{
	float Values[3] = { (float)Value.X, (float)Value.Y, (float)Value.Z };
	if (ImGui::DragFloat3(TCHAR_TO_ANSI(*Label), Values, Speed, MinValue, MaxValue))
	{
		Value = FVector(Values[0], Values[1], Values[2]);
	}
}

void UImGuiElement_DragFloat4::Draw()
{
	float Values[4] = { (float)Value.X, (float)Value.Y, (float)Value.Z, (float)Value.W };
	if (ImGui::DragFloat4(TCHAR_TO_ANSI(*Label), Values, Speed, MinValue, MaxValue))
	{
		Value = FVector4(Values[0], Values[1], Values[2], Values[3]);
	}
}

void UImGuiElement_DragInt2::Draw()
{
	int Values[2] = { Value.X, Value.Y };
	if (ImGui::DragInt2(TCHAR_TO_ANSI(*Label), Values, Speed, MinValue, MaxValue))
	{
		Value = FIntPoint(Values[0], Values[1]);
	}
}

void UImGuiElement_DragInt3::Draw()
{
	int Values[3] = { Value.X, Value.Y, Value.Z };
	if (ImGui::DragInt3(TCHAR_TO_ANSI(*Label), Values, Speed, MinValue, MaxValue))
	{
		Value = FIntVector(Values[0], Values[1], Values[2]);
	}
}

// ==================== 颜色类控件实现 ====================

void UImGuiElement_ColorEdit3::Draw()
{
	float ColorArray[3] = { (float)Color.R, (float)Color.G, (float)Color.B };
	if (ImGui::ColorEdit3(TCHAR_TO_ANSI(*Label), ColorArray))
	{
		FLinearColor NewColor = FLinearColor(ColorArray[0], ColorArray[1], ColorArray[2], Color.A);
		if (Color != NewColor)
		{
			Color = NewColor;
			if (OnColorChanged.IsBound())
			{
				OnColorChanged.Execute(Color);
			}
		}
	}
}

void UImGuiElement_ColorEdit4::Draw()
{
	float ColorArray[4] = { (float)Color.R, (float)Color.G, (float)Color.B, (float)Color.A };
	if (ImGui::ColorEdit4(TCHAR_TO_ANSI(*Label), ColorArray))
	{
		FLinearColor NewColor = FLinearColor(ColorArray[0], ColorArray[1], ColorArray[2], ColorArray[3]);
		if (Color != NewColor)
		{
			Color = NewColor;
			if (OnColorChanged.IsBound())
			{
				OnColorChanged.Execute(Color);
			}
		}
	}
}

void UImGuiElement_ColorPicker3::Draw()
{
	float ColorArray[3] = { (float)Color.R, (float)Color.G, (float)Color.B };
	if (ImGui::ColorPicker3(TCHAR_TO_ANSI(*Label), ColorArray))
	{
		FLinearColor NewColor = FLinearColor(ColorArray[0], ColorArray[1], ColorArray[2], Color.A);
		if (Color != NewColor)
		{
			Color = NewColor;
			if (OnColorChanged.IsBound())
			{
				OnColorChanged.Execute(Color);
			}
		}
	}
}

void UImGuiElement_ColorPicker4::Draw()
{
	float ColorArray[4] = { (float)Color.R, (float)Color.G, (float)Color.B, (float)Color.A };
	if (ImGui::ColorPicker4(TCHAR_TO_ANSI(*Label), ColorArray))
	{
		FLinearColor NewColor = FLinearColor(ColorArray[0], ColorArray[1], ColorArray[2], ColorArray[3]);
		if (Color != NewColor)
		{
			Color = NewColor;
			if (OnColorChanged.IsBound())
			{
				OnColorChanged.Execute(Color);
			}
		}
	}
}

void UImGuiElement_ColorButton::Draw()
{
	bClicked = ImGui::ColorButton(TCHAR_TO_ANSI(*DescID), ImVec4((float)Color.R, (float)Color.G, (float)Color.B, (float)Color.A), 0, ImVec2(Size.X, Size.Y));
}

// ==================== 树形结构控件实现 ====================

void UImGuiElement_TreeNode::Draw()
{
	bOpen = ImGui::TreeNode(TCHAR_TO_ANSI(*Label));
}

void UImGuiElement_TreePop::Draw()
{
	ImGui::TreePop();
}

void UImGuiElement_CollapsingHeader::Draw()
{
	bOpen = ImGui::CollapsingHeader(TCHAR_TO_ANSI(*Label));
}

void UImGuiElement_SetNextItemOpen::Draw()
{
	ImGui::SetNextItemOpen(bIsOpen);
}

// ==================== 可选择控件实现 ====================

void UImGuiElement_Selectable::Draw()
{
	if (ImGui::Selectable(TCHAR_TO_ANSI(*Label), bSelected, 0, ImVec2(Size.X, Size.Y)))
	{
		bSelected = !bSelected;
	}
}

// ==================== 组合框控件实现 ====================

void UImGuiElement_BeginCombo::Draw()
{
	bOpen = ImGui::BeginCombo(TCHAR_TO_ANSI(*Label), TCHAR_TO_ANSI(*PreviewValue));
}

void UImGuiElement_EndCombo::Draw()
{
	ImGui::EndCombo();
}

// ==================== 列表框控件实现 ====================

void UImGuiElement_BeginListBox::Draw()
{
	bOpen = ImGui::BeginListBox(TCHAR_TO_ANSI(*Label), ImVec2(Size.X, Size.Y));
}

void UImGuiElement_EndListBox::Draw()
{
	ImGui::EndListBox();
}

// ==================== 菜单控件实现 ====================

void UImGuiElement_BeginMenuBar::Draw()
{
	bOpen = ImGui::BeginMenuBar();
}

void UImGuiElement_EndMenuBar::Draw()
{
	ImGui::EndMenuBar();
}

void UImGuiElement_BeginMainMenuBar::Draw()
{
	bOpen = ImGui::BeginMainMenuBar();
}

void UImGuiElement_EndMainMenuBar::Draw()
{
	ImGui::EndMainMenuBar();
}

void UImGuiElement_BeginMenu::Draw()
{
	bOpen = ImGui::BeginMenu(TCHAR_TO_ANSI(*Label), bEnabled);
}

void UImGuiElement_EndMenu::Draw()
{
	ImGui::EndMenu();
}

void UImGuiElement_MenuItem::Draw()
{
	bClicked = ImGui::MenuItem(TCHAR_TO_ANSI(*Label), TCHAR_TO_ANSI(*Shortcut), &bSelected, bEnabled);
	if (bClicked && OnClicked.IsBound())
	{
		OnClicked.Execute();
	}
}

// ==================== 弹出窗口控件实现 ====================

void UImGuiElement_BeginPopup::Draw()
{
	bOpen = ImGui::BeginPopup(TCHAR_TO_ANSI(*StrID));
}

void UImGuiElement_EndPopup::Draw()
{
	ImGui::EndPopup();
}

void UImGuiElement_BeginPopupModal::Draw()
{
	bOpen = ImGui::BeginPopupModal(TCHAR_TO_ANSI(*Name));
}

void UImGuiElement_OpenPopup::Draw()
{
	ImGui::OpenPopup(TCHAR_TO_ANSI(*StrID));
}

void UImGuiElement_CloseCurrentPopup::Draw()
{
	ImGui::CloseCurrentPopup();
}

// ==================== 表格控件实现 ====================

void UImGuiElement_BeginTable::Draw()
{
	bOpen = ImGui::BeginTable(TCHAR_TO_ANSI(*StrID), Column);
}

void UImGuiElement_EndTable::Draw()
{
	ImGui::EndTable();
}

void UImGuiElement_TableNextRow::Draw()
{
	ImGui::TableNextRow(0, MinRowHeight);
}

void UImGuiElement_TableNextColumn::Draw()
{
	bResult = ImGui::TableNextColumn();
}

void UImGuiElement_TableSetColumnIndex::Draw()
{
	ImGui::TableSetColumnIndex(ColumnIndex);
}

void UImGuiElement_TableSetupColumn::Draw()
{
	ImGui::TableSetupColumn(TCHAR_TO_ANSI(*Label), 0, InitWidthOrWeight);
}

void UImGuiElement_TableHeadersRow::Draw()
{
	ImGui::TableHeadersRow();
}

// ==================== 标签页控件实现 ====================

void UImGuiElement_BeginTabBar::Draw()
{
	bOpen = ImGui::BeginTabBar(TCHAR_TO_ANSI(*StrID));
}

void UImGuiElement_EndTabBar::Draw()
{
	ImGui::EndTabBar();
}

void UImGuiElement_BeginTabItem::Draw()
{
	bOpen = ImGui::BeginTabItem(TCHAR_TO_ANSI(*Label));
}

void UImGuiElement_EndTabItem::Draw()
{
	ImGui::EndTabItem();
}

// ==================== 提示框控件实现 ====================

void UImGuiElement_BeginTooltip::Draw()
{
	ImGui::BeginTooltip();
}

void UImGuiElement_EndTooltip::Draw()
{
	ImGui::EndTooltip();
}

void UImGuiElement_SetTooltip::Draw()
{
	ImGui::SetTooltip("%s", TCHAR_TO_ANSI(*Text));
}

// ==================== 布局控件实现 ====================

void UImGuiElement_Spacing::Draw()
{
	ImGui::Spacing();
}

void UImGuiElement_Dummy::Draw()
{
	ImGui::Dummy(ImVec2(Size.X, Size.Y));
}

void UImGuiElement_NewLine::Draw()
{
	ImGui::NewLine();
}

void UImGuiElement_Separator::Draw()
{
	ImGui::Separator();
}

void UImGuiElement_SameLine::Draw()
{
	ImGui::SameLine(OffsetFromStartX, Spacing);
}

void UImGuiElement_Indent::Draw()
{
	ImGui::Indent(IndentWidth);
}

void UImGuiElement_Unindent::Draw()
{
	ImGui::Unindent(IndentWidth);
}

void UImGuiElement_BeginGroup::Draw()
{
	ImGui::BeginGroup();
}

void UImGuiElement_EndGroup::Draw()
{
	ImGui::EndGroup();
}

// ==================== 子窗口控件实现 ====================

void UImGuiElement_BeginChild::Draw()
{
	ImGui::BeginChild(TCHAR_TO_ANSI(*StrID), ImVec2(Size.X, Size.Y), bBorder);
}

void UImGuiElement_EndChild::Draw()
{
	ImGui::EndChild();
}

// ==================== 进度条控件实现 ====================

void UImGuiElement_ProgressBar::Draw()
{
	ImGui::ProgressBar(Fraction, ImVec2(Size.X, Size.Y), Overlay.IsEmpty() ? nullptr : TCHAR_TO_ANSI(*Overlay));
}

// ==================== 图像控件实现 ====================

void UImGuiElement_Image::Draw()
{
	ImGui::Image(
		(ImTextureID)TextureID,
		ImVec2(Size.X, Size.Y),
		ImVec2(UV0.X, UV0.Y),
		ImVec2(UV1.X, UV1.Y),
		ImVec4((float)TintColor.R, (float)TintColor.G, (float)TintColor.B, (float)TintColor.A),
		ImVec4((float)BorderColor.R, (float)BorderColor.G, (float)BorderColor.B, (float)BorderColor.A)
	);
}

void UImGuiElement_ImageButton::Draw()
{
	bClicked = ImGui::ImageButton(
		TCHAR_TO_ANSI(*StrID),
		(ImTextureID)TextureID,
		ImVec2(Size.X, Size.Y),
		ImVec2(UV0.X, UV0.Y),
		ImVec2(UV1.X, UV1.Y),
		ImVec4((float)BgColor.R, (float)BgColor.G, (float)BgColor.B, (float)BgColor.A),
		ImVec4((float)TintColor.R, (float)TintColor.G, (float)TintColor.B, (float)TintColor.A)
	);
}

// ==================== ListBox 实现 ====================

void UImGuiElement_ListBox::Draw()
{
	if (Items.Num() == 0) return;

	// 转换为C字符串数组
	TArray<const char*> CStrings;
	TArray<TArray<char>> Buffers;
	Buffers.SetNum(Items.Num());

	for (int32 i = 0; i < Items.Num(); i++)
	{
		FString Item = Items[i];
		Buffers[i].SetNum(Item.Len() + 1);
		FCStringAnsi::Strcpy(Buffers[i].GetData(), Buffers[i].Num(), TCHAR_TO_ANSI(*Item));
		CStrings.Add(Buffers[i].GetData());
	}

	int32 OldItem = CurrentItem;
	if (ImGui::ListBox(TCHAR_TO_ANSI(*Label), &CurrentItem, CStrings.GetData(), CStrings.Num(), HeightInItems))
	{
		if (OldItem != CurrentItem && OnSelectionChanged.IsBound())
		{
			OnSelectionChanged.Execute(CurrentItem);
		}
	}
}

// ==================== Combo 实现 ====================

void UImGuiElement_Combo::Draw()
{
	if (Items.Num() == 0) return;

	// 转换为C字符串数组
	TArray<const char*> CStrings;
	TArray<TArray<char>> Buffers;
	Buffers.SetNum(Items.Num());

	for (int32 i = 0; i < Items.Num(); i++)
	{
		FString Item = Items[i];
		Buffers[i].SetNum(Item.Len() + 1);
		FCStringAnsi::Strcpy(Buffers[i].GetData(), Buffers[i].Num(), TCHAR_TO_ANSI(*Item));
		CStrings.Add(Buffers[i].GetData());
	}

	int32 OldItem = CurrentItem;
	if (ImGui::Combo(TCHAR_TO_ANSI(*Label), &CurrentItem, CStrings.GetData(), CStrings.Num()))
	{
		if (OldItem != CurrentItem && OnSelectionChanged.IsBound())
		{
			OnSelectionChanged.Execute(CurrentItem);
		}
	}
}
