// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ImGuiElementDefines.h"
#include "UObject/Object.h"
#include "ImGuiBuilder.generated.h"

class UImGuiElement;

/**
 * 这个是一个ImGui的构建器，支持链式调用
 */
UCLASS(BlueprintType)
class IMGUIBLUEPRINT_API UImGuiBuilder : public UObject
{
	GENERATED_BODY()

public:
	void SetWindowName(const FString& InWindowName);
	UFUNCTION(BlueprintCallable)
	void Draw();
	void AddElement(UImGuiElement* Element);

	// ==================== 文本类控件 ====================

	UFUNCTION(BlueprintCallable, Category = "ImGui|Builder|Text", Meta = (AutoCreateRefTerm="InText"))
	UImGuiBuilder* Text(const FString& InText);

	UFUNCTION(BlueprintCallable, Category = "ImGui|Builder|Text", Meta = (AutoCreateRefTerm="InText"))
	UImGuiBuilder* TextRef(UPARAM(ref) FString& InText);

	UFUNCTION(BlueprintCallable, Category = "ImGui|Builder|Text")
	UImGuiBuilder* TextColored(FLinearColor InColor, const FString& InText);

	UFUNCTION(BlueprintCallable, Category = "ImGui|Builder|Text")
	UImGuiBuilder* TextDisabled(const FString& InText);

	UFUNCTION(BlueprintCallable, Category = "ImGui|Builder|Text")
	UImGuiBuilder* TextWrapped(const FString& InText);

	UFUNCTION(BlueprintCallable, Category = "ImGui|Builder|Text")
	UImGuiBuilder* LabelText(const FString& InLabel, const FString& InText);

	UFUNCTION(BlueprintCallable, Category = "ImGui|Builder|Text")
	UImGuiBuilder* BulletText(const FString& InText);

	UFUNCTION(BlueprintCallable, Category = "ImGui|Builder|Text")
	UImGuiBuilder* Bullet();

	// ==================== 按钮类控件 ====================

	UFUNCTION(BlueprintCallable, Category = "ImGui|Builder|Button")
	UImGuiBuilder* Button(const FString& InLabel, FVector2D InSize, FOnImGuiClick OnClick);

	UFUNCTION(BlueprintCallable, Category = "ImGui|Builder|Button")
	UImGuiBuilder* SmallButton(const FString& InLabel, FOnImGuiClick OnClick);

	UFUNCTION(BlueprintCallable, Category = "ImGui|Builder|Button")
	UImGuiBuilder* InvisibleButton(const FString& InStrID, FVector2D InSize, FOnImGuiClick OnClick);

	UFUNCTION(BlueprintCallable, Category = "ImGui|Builder|Button")
	UImGuiBuilder* ArrowButton(const FString& InStrID, int32 InDirection, FOnImGuiClick OnClick);

	UFUNCTION(BlueprintCallable, Category = "ImGui|Builder|Button")
	UImGuiBuilder* Checkbox(const FString& InLabel, bool bInChecked, FOnImGuiCheckboxChanged OnChanged);

	UFUNCTION(BlueprintCallable, Category = "ImGui|Builder|Button")
	UImGuiBuilder* RadioButton(const FString& InLabel, bool bInActive, FOnImGuiClick OnClick);

	// ==================== 输入类控件 ====================

	UFUNCTION(BlueprintCallable, Category = "ImGui|Builder|Input")
	UImGuiBuilder* InputText(const FString& InLabel, const FString& InText, FOnImGuiTextChanged OnTextChanged);

	UFUNCTION(BlueprintCallable, Category = "ImGui|Builder|Input")
	UImGuiBuilder* InputTextMultiline(const FString& InLabel, const FString& InText, FVector2D InSize, FOnImGuiTextChanged OnTextChanged);

	UFUNCTION(BlueprintCallable, Category = "ImGui|Builder|Input")
	UImGuiBuilder* InputFloat(const FString& InLabel, float InValue, float InStep, float InStepFast, FOnImGuiFloatChanged OnValueChanged);

	UFUNCTION(BlueprintCallable, Category = "ImGui|Builder|Input")
	UImGuiBuilder* InputInt(const FString& InLabel, int32 InValue, int32 InStep, int32 InStepFast, FOnImGuiIntChanged OnValueChanged);

	UFUNCTION(BlueprintCallable, Category = "ImGui|Builder|Input")
	UImGuiBuilder* InputDouble(const FString& InLabel, double InValue, double InStep, double InStepFast);

	UFUNCTION(BlueprintCallable, Category = "ImGui|Builder|Input")
	UImGuiBuilder* InputFloat2(const FString& InLabel, FVector2D InValue);

	UFUNCTION(BlueprintCallable, Category = "ImGui|Builder|Input")
	UImGuiBuilder* InputFloat3(const FString& InLabel, FVector InValue);

	UFUNCTION(BlueprintCallable, Category = "ImGui|Builder|Input")
	UImGuiBuilder* InputFloat4(const FString& InLabel, FVector4 InValue);

	UFUNCTION(BlueprintCallable, Category = "ImGui|Builder|Input")
	UImGuiBuilder* InputInt2(const FString& InLabel, FIntPoint InValue);

	UFUNCTION(BlueprintCallable, Category = "ImGui|Builder|Input")
	UImGuiBuilder* InputInt3(const FString& InLabel, FIntVector InValue);

	// ==================== 滑动条类控件 ====================

	UFUNCTION(BlueprintCallable, Category = "ImGui|Builder|Slider")
	UImGuiBuilder* SliderFloat(const FString& InLabel, float InValue, float InMin, float InMax, FOnImGuiFloatChanged OnValueChanged);

	UFUNCTION(BlueprintCallable, Category = "ImGui|Builder|Slider")
	UImGuiBuilder* SliderInt(const FString& InLabel, int32 InValue, int32 InMin, int32 InMax, FOnImGuiIntChanged OnValueChanged);

	UFUNCTION(BlueprintCallable, Category = "ImGui|Builder|Slider")
	UImGuiBuilder* SliderFloat2(const FString& InLabel, FVector2D InValue, float InMin, float InMax);

	UFUNCTION(BlueprintCallable, Category = "ImGui|Builder|Slider")
	UImGuiBuilder* SliderFloat3(const FString& InLabel, FVector InValue, float InMin, float InMax);

	UFUNCTION(BlueprintCallable, Category = "ImGui|Builder|Slider")
	UImGuiBuilder* SliderFloat4(const FString& InLabel, FVector4 InValue, float InMin, float InMax);

	UFUNCTION(BlueprintCallable, Category = "ImGui|Builder|Slider")
	UImGuiBuilder* SliderAngle(const FString& InLabel, float InRadValue, float InDegMin, float InDegMax);

	UFUNCTION(BlueprintCallable, Category = "ImGui|Builder|Slider")
	UImGuiBuilder* VSliderFloat(const FString& InLabel, FVector2D InSize, float InValue, float InMin, float InMax);

	UFUNCTION(BlueprintCallable, Category = "ImGui|Builder|Slider")
	UImGuiBuilder* VSliderInt(const FString& InLabel, FVector2D InSize, int32 InValue, int32 InMin, int32 InMax);

	// ==================== 拖拽类控件 ====================

	UFUNCTION(BlueprintCallable, Category = "ImGui|Builder|Drag")
	UImGuiBuilder* DragFloat(const FString& InLabel, float InValue, float InSpeed, float InMin, float InMax, FOnImGuiFloatChanged OnValueChanged);

	UFUNCTION(BlueprintCallable, Category = "ImGui|Builder|Drag")
	UImGuiBuilder* DragInt(const FString& InLabel, int32 InValue, float InSpeed, int32 InMin, int32 InMax, FOnImGuiIntChanged OnValueChanged);

	UFUNCTION(BlueprintCallable, Category = "ImGui|Builder|Drag")
	UImGuiBuilder* DragFloat2(const FString& InLabel, FVector2D InValue, float InSpeed, float InMin, float InMax);

	UFUNCTION(BlueprintCallable, Category = "ImGui|Builder|Drag")
	UImGuiBuilder* DragFloat3(const FString& InLabel, FVector InValue, float InSpeed, float InMin, float InMax);

	UFUNCTION(BlueprintCallable, Category = "ImGui|Builder|Drag")
	UImGuiBuilder* DragFloat4(const FString& InLabel, FVector4 InValue, float InSpeed, float InMin, float InMax);

	UFUNCTION(BlueprintCallable, Category = "ImGui|Builder|Drag")
	UImGuiBuilder* DragInt2(const FString& InLabel, FIntPoint InValue, float InSpeed, int32 InMin, int32 InMax);

	UFUNCTION(BlueprintCallable, Category = "ImGui|Builder|Drag")
	UImGuiBuilder* DragInt3(const FString& InLabel, FIntVector InValue, float InSpeed, int32 InMin, int32 InMax);

	// ==================== 颜色类控件 ====================

	UFUNCTION(BlueprintCallable, Category = "ImGui|Builder|Color")
	UImGuiBuilder* ColorEdit3(const FString& InLabel, FLinearColor InColor, FOnImGuiColorChanged OnColorChanged);

	UFUNCTION(BlueprintCallable, Category = "ImGui|Builder|Color")
	UImGuiBuilder* ColorEdit4(const FString& InLabel, FLinearColor InColor, FOnImGuiColorChanged OnColorChanged);

	UFUNCTION(BlueprintCallable, Category = "ImGui|Builder|Color")
	UImGuiBuilder* ColorPicker3(const FString& InLabel, FLinearColor InColor, FOnImGuiColorChanged OnColorChanged);

	UFUNCTION(BlueprintCallable, Category = "ImGui|Builder|Color")
	UImGuiBuilder* ColorPicker4(const FString& InLabel, FLinearColor InColor, FOnImGuiColorChanged OnColorChanged);

	UFUNCTION(BlueprintCallable, Category = "ImGui|Builder|Color")
	UImGuiBuilder* ColorButton(const FString& InDescID, FLinearColor InColor, FVector2D InSize);

	// ==================== 树形结构控件 ====================

	UFUNCTION(BlueprintCallable, Category = "ImGui|Builder|Tree")
	UImGuiBuilder* TreeNode(const FString& InLabel);

	UFUNCTION(BlueprintCallable, Category = "ImGui|Builder|Tree")
	UImGuiBuilder* TreePop();

	UFUNCTION(BlueprintCallable, Category = "ImGui|Builder|Tree")
	UImGuiBuilder* CollapsingHeader(const FString& InLabel);

	UFUNCTION(BlueprintCallable, Category = "ImGui|Builder|Tree")
	UImGuiBuilder* SetNextItemOpen(bool bIsOpen);

	// ==================== 可选择控件 ====================

	UFUNCTION(BlueprintCallable, Category = "ImGui|Builder|Selectable")
	UImGuiBuilder* Selectable(const FString& InLabel, bool bInSelected, FVector2D InSize);

	// ==================== 组合框控件 ====================

	UFUNCTION(BlueprintCallable, Category = "ImGui|Builder|Combo")
	UImGuiBuilder* BeginCombo(const FString& InLabel, const FString& InPreviewValue);

	UFUNCTION(BlueprintCallable, Category = "ImGui|Builder|Combo")
	UImGuiBuilder* EndCombo();

	// ==================== 列表框控件 ====================

	UFUNCTION(BlueprintCallable, Category = "ImGui|Builder|ListBox")
	UImGuiBuilder* BeginListBox(const FString& InLabel, FVector2D InSize);

	UFUNCTION(BlueprintCallable, Category = "ImGui|Builder|ListBox")
	UImGuiBuilder* EndListBox();

	UFUNCTION(BlueprintCallable, Category = "ImGui|Builder|ListBox")
	UImGuiBuilder* ListBox(const FString& InLabel, const TArray<FString>& InItems, int32 InCurrentItem, int32 InHeightInItems, FOnImGuiIntChanged OnSelectionChanged);

	// ==================== 组合框控件 ====================

	UFUNCTION(BlueprintCallable, Category = "ImGui|Builder|Combo")
	UImGuiBuilder* Combo(const FString& InLabel, const TArray<FString>& InItems, int32 InCurrentItem, FOnImGuiComboChanged OnSelectionChanged);

	// ==================== 菜单控件 ====================

	UFUNCTION(BlueprintCallable, Category = "ImGui|Builder|Menu")
	UImGuiBuilder* BeginMenuBar();

	UFUNCTION(BlueprintCallable, Category = "ImGui|Builder|Menu")
	UImGuiBuilder* EndMenuBar();

	UFUNCTION(BlueprintCallable, Category = "ImGui|Builder|Menu")
	UImGuiBuilder* BeginMainMenuBar();

	UFUNCTION(BlueprintCallable, Category = "ImGui|Builder|Menu")
	UImGuiBuilder* EndMainMenuBar();

	UFUNCTION(BlueprintCallable, Category = "ImGui|Builder|Menu")
	UImGuiBuilder* BeginMenu(const FString& InLabel, bool bEnabled);

	UFUNCTION(BlueprintCallable, Category = "ImGui|Builder|Menu")
	UImGuiBuilder* EndMenu();

	UFUNCTION(BlueprintCallable, Category = "ImGui|Builder|Menu")
	UImGuiBuilder* MenuItem(const FString& InLabel, const FString& InShortcut, bool bSelected, bool bEnabled, FOnImGuiClick OnClicked);

	// ==================== 弹出窗口控件 ====================

	UFUNCTION(BlueprintCallable, Category = "ImGui|Builder|Popup")
	UImGuiBuilder* BeginPopup(const FString& InStrID);

	UFUNCTION(BlueprintCallable, Category = "ImGui|Builder|Popup")
	UImGuiBuilder* EndPopup();

	UFUNCTION(BlueprintCallable, Category = "ImGui|Builder|Popup")
	UImGuiBuilder* BeginPopupModal(const FString& InName);

	UFUNCTION(BlueprintCallable, Category = "ImGui|Builder|Popup")
	UImGuiBuilder* OpenPopup(const FString& InStrID);

	UFUNCTION(BlueprintCallable, Category = "ImGui|Builder|Popup")
	UImGuiBuilder* CloseCurrentPopup();

	// ==================== 表格控件 ====================

	UFUNCTION(BlueprintCallable, Category = "ImGui|Builder|Table")
	UImGuiBuilder* BeginTable(const FString& InStrID, int32 InColumn);

	UFUNCTION(BlueprintCallable, Category = "ImGui|Builder|Table")
	UImGuiBuilder* EndTable();

	UFUNCTION(BlueprintCallable, Category = "ImGui|Builder|Table")
	UImGuiBuilder* TableNextRow(float InMinRowHeight);

	UFUNCTION(BlueprintCallable, Category = "ImGui|Builder|Table")
	UImGuiBuilder* TableNextColumn();

	UFUNCTION(BlueprintCallable, Category = "ImGui|Builder|Table")
	UImGuiBuilder* TableSetColumnIndex(int32 InColumnIndex);

	UFUNCTION(BlueprintCallable, Category = "ImGui|Builder|Table")
	UImGuiBuilder* TableSetupColumn(const FString& InLabel, float InInitWidthOrWeight);

	UFUNCTION(BlueprintCallable, Category = "ImGui|Builder|Table")
	UImGuiBuilder* TableHeadersRow();

	// ==================== 标签页控件 ====================

	UFUNCTION(BlueprintCallable, Category = "ImGui|Builder|Tab")
	UImGuiBuilder* BeginTabBar(const FString& InStrID);

	UFUNCTION(BlueprintCallable, Category = "ImGui|Builder|Tab")
	UImGuiBuilder* EndTabBar();

	UFUNCTION(BlueprintCallable, Category = "ImGui|Builder|Tab")
	UImGuiBuilder* BeginTabItem(const FString& InLabel);

	UFUNCTION(BlueprintCallable, Category = "ImGui|Builder|Tab")
	UImGuiBuilder* EndTabItem();

	// ==================== 提示框控件 ====================

	UFUNCTION(BlueprintCallable, Category = "ImGui|Builder|Tooltip")
	UImGuiBuilder* BeginTooltip();

	UFUNCTION(BlueprintCallable, Category = "ImGui|Builder|Tooltip")
	UImGuiBuilder* EndTooltip();

	UFUNCTION(BlueprintCallable, Category = "ImGui|Builder|Tooltip")
	UImGuiBuilder* SetTooltip(const FString& InText);

	// ==================== 布局控件 ====================

	UFUNCTION(BlueprintCallable, Category = "ImGui|Builder|Layout")
	UImGuiBuilder* Spacing();

	UFUNCTION(BlueprintCallable, Category = "ImGui|Builder|Layout")
	UImGuiBuilder* Dummy(FVector2D InSize);

	UFUNCTION(BlueprintCallable, Category = "ImGui|Builder|Layout")
	UImGuiBuilder* NewLine();

	UFUNCTION(BlueprintCallable, Category = "ImGui|Builder|Layout")
	UImGuiBuilder* Separator();

	UFUNCTION(BlueprintCallable, Category = "ImGui|Builder|Layout")
	UImGuiBuilder* SameLine(float InOffsetFromStartX, float InSpacing);

	UFUNCTION(BlueprintCallable, Category = "ImGui|Builder|Layout")
	UImGuiBuilder* Indent(float InIndentWidth);

	UFUNCTION(BlueprintCallable, Category = "ImGui|Builder|Layout")
	UImGuiBuilder* Unindent(float InIndentWidth);

	UFUNCTION(BlueprintCallable, Category = "ImGui|Builder|Layout")
	UImGuiBuilder* BeginGroup();

	UFUNCTION(BlueprintCallable, Category = "ImGui|Builder|Layout")
	UImGuiBuilder* EndGroup();

	// ==================== 子窗口控件 ====================

	UFUNCTION(BlueprintCallable, Category = "ImGui|Builder|Child")
	UImGuiBuilder* BeginChild(const FString& InStrID, FVector2D InSize, bool bBorder);

	UFUNCTION(BlueprintCallable, Category = "ImGui|Builder|Child")
	UImGuiBuilder* EndChild();

	// ==================== 进度条控件 ====================

	UFUNCTION(BlueprintCallable, Category = "ImGui|Builder|Widget")
	UImGuiBuilder* ProgressBar(float InFraction, FVector2D InSize, const FString& InOverlay);

	// ==================== 图像控件 ====================

	UFUNCTION(BlueprintCallable, Category = "ImGui|Builder|Image")
	UImGuiBuilder* Image(int64 InTextureID, FVector2D InSize, FVector2D InUV0 = FVector2D(0, 0), FVector2D InUV1 = FVector2D(1, 1), FLinearColor InTintColor = FLinearColor::White, FLinearColor InBorderColor = FLinearColor::Transparent);

	UFUNCTION(BlueprintCallable, Category = "ImGui|Builder|Image")
	UImGuiBuilder* ImageButton(const FString& InStrID, int64 InTextureID, FVector2D InSize, FVector2D InUV0 = FVector2D(0, 0), FVector2D InUV1 = FVector2D(1, 1), FLinearColor InBgColor = FLinearColor::Transparent, FLinearColor InTintColor = FLinearColor::White);

	// ==================== 其他 ====================

	UFUNCTION(BlueprintCallable, Category = "ImGui|Builder")
	UImGuiBuilder* End();

protected:
	UPROPERTY()
	FString WindowName;

	UPROPERTY()
	TArray<TObjectPtr<UImGuiElement>> Elements;
};
