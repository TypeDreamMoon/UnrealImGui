// 这个文件用来定义所有的ImGui控件元素

#pragma once

#include "CoreMinimal.h"
#include "Classes/ImGuiElement.h"
#include "ImGuiElementDefines.generated.h"

// ==================== 委托声明 ====================
DECLARE_DYNAMIC_DELEGATE(FOnImGuiClick);
DECLARE_DYNAMIC_DELEGATE_OneParam(FOnImGuiCheckboxChanged, bool, bChecked);
DECLARE_DYNAMIC_DELEGATE_OneParam(FOnImGuiFloatChanged, float, Value);
DECLARE_DYNAMIC_DELEGATE_OneParam(FOnImGuiIntChanged, int32, Value);
DECLARE_DYNAMIC_DELEGATE_OneParam(FOnImGuiTextChanged, const FString&, Text);
DECLARE_DYNAMIC_DELEGATE_OneParam(FOnImGuiColorChanged, FLinearColor, Color);
DECLARE_DYNAMIC_DELEGATE_OneParam(FOnImGuiVector2Changed, FVector2D, Value);
DECLARE_DYNAMIC_DELEGATE_OneParam(FOnImGuiVectorChanged, FVector, Value);
DECLARE_DYNAMIC_DELEGATE_OneParam(FOnImGuiComboChanged, int32, SelectedIndex);

// ==================== 文本类控件 ====================

UCLASS()
class IMGUIBLUEPRINT_API UImGuiElement_Text : public UImGuiElement
{
	GENERATED_BODY()
public:
	virtual void Draw() override;
	FString* Text;
};

UCLASS()
class IMGUIBLUEPRINT_API UImGuiElement_TextColored : public UImGuiElement
{
	GENERATED_BODY()
public:
	virtual void Draw() override;
	UPROPERTY() FLinearColor Color;
	UPROPERTY() FString Text;
};

UCLASS()
class IMGUIBLUEPRINT_API UImGuiElement_TextDisabled : public UImGuiElement
{
	GENERATED_BODY()
public:
	virtual void Draw() override;
	UPROPERTY() FString Text;
};

UCLASS()
class IMGUIBLUEPRINT_API UImGuiElement_TextWrapped : public UImGuiElement
{
	GENERATED_BODY()
public:
	virtual void Draw() override;
	UPROPERTY() FString Text;
};

UCLASS()
class IMGUIBLUEPRINT_API UImGuiElement_LabelText : public UImGuiElement
{
	GENERATED_BODY()
public:
	virtual void Draw() override;
	UPROPERTY() FString Label;
	UPROPERTY() FString Text;
};

UCLASS()
class IMGUIBLUEPRINT_API UImGuiElement_BulletText : public UImGuiElement
{
	GENERATED_BODY()
public:
	virtual void Draw() override;
	UPROPERTY() FString Text;
};

UCLASS()
class IMGUIBLUEPRINT_API UImGuiElement_Bullet : public UImGuiElement
{
	GENERATED_BODY()
public:
	virtual void Draw() override;
};

// ==================== 按钮类控件 ====================

UCLASS()
class IMGUIBLUEPRINT_API UImGuiElement_Button : public UImGuiElement
{
	GENERATED_BODY()
public:
	virtual void Draw() override;
	virtual bool GetInteractionResult() const override { return bClicked; }
	UPROPERTY() FString Label;
	UPROPERTY() FVector2D Size = FVector2D::ZeroVector;
	UPROPERTY() FOnImGuiClick OnClick;
protected:
	bool bClicked = false;
};

UCLASS()
class IMGUIBLUEPRINT_API UImGuiElement_SmallButton : public UImGuiElement
{
	GENERATED_BODY()
public:
	virtual void Draw() override;
	virtual bool GetInteractionResult() const override { return bClicked; }
	UPROPERTY() FString Label;
	UPROPERTY() FOnImGuiClick OnClick;
protected:
	bool bClicked = false;
};

UCLASS()
class IMGUIBLUEPRINT_API UImGuiElement_InvisibleButton : public UImGuiElement
{
	GENERATED_BODY()
public:
	virtual void Draw() override;
	virtual bool GetInteractionResult() const override { return bClicked; }
	UPROPERTY() FString StrID;
	UPROPERTY() FVector2D Size;
	UPROPERTY() FOnImGuiClick OnClick;
protected:
	bool bClicked = false;
};

UCLASS()
class IMGUIBLUEPRINT_API UImGuiElement_ArrowButton : public UImGuiElement
{
	GENERATED_BODY()
public:
	virtual void Draw() override;
	virtual bool GetInteractionResult() const override { return bClicked; }
	UPROPERTY() FString StrID;
	UPROPERTY() int32 Direction = 0; // 0=Left, 1=Right, 2=Up, 3=Down
	UPROPERTY() FOnImGuiClick OnClick;
protected:
	bool bClicked = false;
};

UCLASS()
class IMGUIBLUEPRINT_API UImGuiElement_Checkbox : public UImGuiElement
{
	GENERATED_BODY()
public:
	virtual void Draw() override;
	virtual bool GetInteractionResult() const override { return bChecked; }
	UPROPERTY() FString Label;
	UPROPERTY() bool bChecked = false;
	UPROPERTY() FOnImGuiCheckboxChanged OnChanged;
};

UCLASS()
class IMGUIBLUEPRINT_API UImGuiElement_RadioButton : public UImGuiElement
{
	GENERATED_BODY()
public:
	virtual void Draw() override;
	virtual bool GetInteractionResult() const override { return bActive; }
	UPROPERTY() FString Label;
	UPROPERTY() bool bActive = false;
	UPROPERTY() FOnImGuiClick OnClick;
};

// ==================== 输入类控件 ====================

UCLASS()
class IMGUIBLUEPRINT_API UImGuiElement_InputText : public UImGuiElement
{
	GENERATED_BODY()
public:
	virtual void Draw() override;
	UPROPERTY() FString Label;
	UPROPERTY() FString Text;
	UPROPERTY() FOnImGuiTextChanged OnTextChanged;
	char Buffer[256] = {0};
};

UCLASS()
class IMGUIBLUEPRINT_API UImGuiElement_InputTextMultiline : public UImGuiElement
{
	GENERATED_BODY()
public:
	virtual void Draw() override;
	UPROPERTY() FString Label;
	UPROPERTY() FString Text;
	UPROPERTY() FVector2D Size = FVector2D::ZeroVector;
	UPROPERTY() FOnImGuiTextChanged OnTextChanged;
	char Buffer[1024] = {0};
};

UCLASS()
class IMGUIBLUEPRINT_API UImGuiElement_InputFloat : public UImGuiElement
{
	GENERATED_BODY()
public:
	virtual void Draw() override;
	UPROPERTY() FString Label;
	UPROPERTY() float Value = 0.0f;
	UPROPERTY() float Step = 0.0f;
	UPROPERTY() float StepFast = 0.0f;
	UPROPERTY() FOnImGuiFloatChanged OnValueChanged;
};

UCLASS()
class IMGUIBLUEPRINT_API UImGuiElement_InputInt : public UImGuiElement
{
	GENERATED_BODY()
public:
	virtual void Draw() override;
	UPROPERTY() FString Label;
	UPROPERTY() int32 Value = 0;
	UPROPERTY() int32 Step = 1;
	UPROPERTY() int32 StepFast = 100;
	UPROPERTY() FOnImGuiIntChanged OnValueChanged;
};

UCLASS()
class IMGUIBLUEPRINT_API UImGuiElement_InputDouble : public UImGuiElement
{
	GENERATED_BODY()
public:
	virtual void Draw() override;
	UPROPERTY() FString Label;
	UPROPERTY() double Value = 0.0;
	UPROPERTY() double Step = 0.0;
	UPROPERTY() double StepFast = 0.0;
};

UCLASS()
class IMGUIBLUEPRINT_API UImGuiElement_InputFloat2 : public UImGuiElement
{
	GENERATED_BODY()
public:
	virtual void Draw() override;
	UPROPERTY() FString Label;
	UPROPERTY() FVector2D Value = FVector2D::ZeroVector;
};

UCLASS()
class IMGUIBLUEPRINT_API UImGuiElement_InputFloat3 : public UImGuiElement
{
	GENERATED_BODY()
public:
	virtual void Draw() override;
	UPROPERTY() FString Label;
	UPROPERTY() FVector Value = FVector::ZeroVector;
};

UCLASS()
class IMGUIBLUEPRINT_API UImGuiElement_InputFloat4 : public UImGuiElement
{
	GENERATED_BODY()
public:
	virtual void Draw() override;
	UPROPERTY() FString Label;
	UPROPERTY() FVector4 Value = FVector4(0, 0, 0, 0);
};

UCLASS()
class IMGUIBLUEPRINT_API UImGuiElement_InputInt2 : public UImGuiElement
{
	GENERATED_BODY()
public:
	virtual void Draw() override;
	UPROPERTY() FString Label;
	UPROPERTY() FIntPoint Value = FIntPoint::ZeroValue;
};

UCLASS()
class IMGUIBLUEPRINT_API UImGuiElement_InputInt3 : public UImGuiElement
{
	GENERATED_BODY()
public:
	virtual void Draw() override;
	UPROPERTY() FString Label;
	UPROPERTY() FIntVector Value = FIntVector::ZeroValue;
};

// ==================== 滑动条类控件 ====================

UCLASS()
class IMGUIBLUEPRINT_API UImGuiElement_SliderFloat : public UImGuiElement
{
	GENERATED_BODY()
public:
	virtual void Draw() override;
	UPROPERTY() FString Label;
	UPROPERTY() float Value = 0.0f;
	UPROPERTY() float MinValue = 0.0f;
	UPROPERTY() float MaxValue = 1.0f;
	UPROPERTY() FOnImGuiFloatChanged OnValueChanged;
};

UCLASS()
class IMGUIBLUEPRINT_API UImGuiElement_SliderInt : public UImGuiElement
{
	GENERATED_BODY()
public:
	virtual void Draw() override;
	UPROPERTY() FString Label;
	UPROPERTY() int32 Value = 0;
	UPROPERTY() int32 MinValue = 0;
	UPROPERTY() int32 MaxValue = 100;
	UPROPERTY() FOnImGuiIntChanged OnValueChanged;
};

UCLASS()
class IMGUIBLUEPRINT_API UImGuiElement_SliderFloat2 : public UImGuiElement
{
	GENERATED_BODY()
public:
	virtual void Draw() override;
	UPROPERTY() FString Label;
	UPROPERTY() FVector2D Value = FVector2D::ZeroVector;
	UPROPERTY() float MinValue = 0.0f;
	UPROPERTY() float MaxValue = 1.0f;
};

UCLASS()
class IMGUIBLUEPRINT_API UImGuiElement_SliderFloat3 : public UImGuiElement
{
	GENERATED_BODY()
public:
	virtual void Draw() override;
	UPROPERTY() FString Label;
	UPROPERTY() FVector Value = FVector::ZeroVector;
	UPROPERTY() float MinValue = 0.0f;
	UPROPERTY() float MaxValue = 1.0f;
};

UCLASS()
class IMGUIBLUEPRINT_API UImGuiElement_SliderFloat4 : public UImGuiElement
{
	GENERATED_BODY()
public:
	virtual void Draw() override;
	UPROPERTY() FString Label;
	UPROPERTY() FVector4 Value = FVector4(0, 0, 0, 0);
	UPROPERTY() float MinValue = 0.0f;
	UPROPERTY() float MaxValue = 1.0f;
};

UCLASS()
class IMGUIBLUEPRINT_API UImGuiElement_SliderAngle : public UImGuiElement
{
	GENERATED_BODY()
public:
	virtual void Draw() override;
	UPROPERTY() FString Label;
	UPROPERTY() float RadValue = 0.0f;
	UPROPERTY() float DegMin = -360.0f;
	UPROPERTY() float DegMax = 360.0f;
};

UCLASS()
class IMGUIBLUEPRINT_API UImGuiElement_VSliderFloat : public UImGuiElement
{
	GENERATED_BODY()
public:
	virtual void Draw() override;
	UPROPERTY() FString Label;
	UPROPERTY() FVector2D Size;
	UPROPERTY() float Value = 0.0f;
	UPROPERTY() float MinValue = 0.0f;
	UPROPERTY() float MaxValue = 1.0f;
};

UCLASS()
class IMGUIBLUEPRINT_API UImGuiElement_VSliderInt : public UImGuiElement
{
	GENERATED_BODY()
public:
	virtual void Draw() override;
	UPROPERTY() FString Label;
	UPROPERTY() FVector2D Size;
	UPROPERTY() int32 Value = 0;
	UPROPERTY() int32 MinValue = 0;
	UPROPERTY() int32 MaxValue = 100;
};

// ==================== 拖拽类控件 ====================

UCLASS()
class IMGUIBLUEPRINT_API UImGuiElement_DragFloat : public UImGuiElement
{
	GENERATED_BODY()
public:
	virtual void Draw() override;
	UPROPERTY() FString Label;
	UPROPERTY() float Value = 0.0f;
	UPROPERTY() float Speed = 1.0f;
	UPROPERTY() float MinValue = 0.0f;
	UPROPERTY() float MaxValue = 0.0f;
	UPROPERTY() FOnImGuiFloatChanged OnValueChanged;
};

UCLASS()
class IMGUIBLUEPRINT_API UImGuiElement_DragInt : public UImGuiElement
{
	GENERATED_BODY()
public:
	virtual void Draw() override;
	UPROPERTY() FString Label;
	UPROPERTY() int32 Value = 0;
	UPROPERTY() float Speed = 1.0f;
	UPROPERTY() int32 MinValue = 0;
	UPROPERTY() int32 MaxValue = 0;
	UPROPERTY() FOnImGuiIntChanged OnValueChanged;
};

UCLASS()
class IMGUIBLUEPRINT_API UImGuiElement_DragFloat2 : public UImGuiElement
{
	GENERATED_BODY()
public:
	virtual void Draw() override;
	UPROPERTY() FString Label;
	UPROPERTY() FVector2D Value = FVector2D::ZeroVector;
	UPROPERTY() float Speed = 1.0f;
	UPROPERTY() float MinValue = 0.0f;
	UPROPERTY() float MaxValue = 0.0f;
};

UCLASS()
class IMGUIBLUEPRINT_API UImGuiElement_DragFloat3 : public UImGuiElement
{
	GENERATED_BODY()
public:
	virtual void Draw() override;
	UPROPERTY() FString Label;
	UPROPERTY() FVector Value = FVector::ZeroVector;
	UPROPERTY() float Speed = 1.0f;
	UPROPERTY() float MinValue = 0.0f;
	UPROPERTY() float MaxValue = 0.0f;
};

UCLASS()
class IMGUIBLUEPRINT_API UImGuiElement_DragFloat4 : public UImGuiElement
{
	GENERATED_BODY()
public:
	virtual void Draw() override;
	UPROPERTY() FString Label;
	UPROPERTY() FVector4 Value = FVector4(0, 0, 0, 0);
	UPROPERTY() float Speed = 1.0f;
	UPROPERTY() float MinValue = 0.0f;
	UPROPERTY() float MaxValue = 0.0f;
};

UCLASS()
class IMGUIBLUEPRINT_API UImGuiElement_DragInt2 : public UImGuiElement
{
	GENERATED_BODY()
public:
	virtual void Draw() override;
	UPROPERTY() FString Label;
	UPROPERTY() FIntPoint Value = FIntPoint::ZeroValue;
	UPROPERTY() float Speed = 1.0f;
	UPROPERTY() int32 MinValue = 0;
	UPROPERTY() int32 MaxValue = 0;
};

UCLASS()
class IMGUIBLUEPRINT_API UImGuiElement_DragInt3 : public UImGuiElement
{
	GENERATED_BODY()
public:
	virtual void Draw() override;
	UPROPERTY() FString Label;
	UPROPERTY() FIntVector Value = FIntVector::ZeroValue;
	UPROPERTY() float Speed = 1.0f;
	UPROPERTY() int32 MinValue = 0;
	UPROPERTY() int32 MaxValue = 0;
};

// ==================== 颜色类控件 ====================

UCLASS()
class IMGUIBLUEPRINT_API UImGuiElement_ColorEdit3 : public UImGuiElement
{
	GENERATED_BODY()
public:
	virtual void Draw() override;
	UPROPERTY() FString Label;
	UPROPERTY() FLinearColor Color = FLinearColor::White;
	UPROPERTY() FOnImGuiColorChanged OnColorChanged;
};

UCLASS()
class IMGUIBLUEPRINT_API UImGuiElement_ColorEdit4 : public UImGuiElement
{
	GENERATED_BODY()
public:
	virtual void Draw() override;
	UPROPERTY() FString Label;
	UPROPERTY() FLinearColor Color = FLinearColor::White;
	UPROPERTY() FOnImGuiColorChanged OnColorChanged;
};

UCLASS()
class IMGUIBLUEPRINT_API UImGuiElement_ColorPicker3 : public UImGuiElement
{
	GENERATED_BODY()
public:
	virtual void Draw() override;
	UPROPERTY() FString Label;
	UPROPERTY() FLinearColor Color = FLinearColor::White;
	UPROPERTY() FOnImGuiColorChanged OnColorChanged;
};

UCLASS()
class IMGUIBLUEPRINT_API UImGuiElement_ColorPicker4 : public UImGuiElement
{
	GENERATED_BODY()
public:
	virtual void Draw() override;
	UPROPERTY() FString Label;
	UPROPERTY() FLinearColor Color = FLinearColor::White;
	UPROPERTY() FOnImGuiColorChanged OnColorChanged;
};

UCLASS()
class IMGUIBLUEPRINT_API UImGuiElement_ColorButton : public UImGuiElement
{
	GENERATED_BODY()
public:
	virtual void Draw() override;
	virtual bool GetInteractionResult() const override { return bClicked; }
	UPROPERTY() FString DescID;
	UPROPERTY() FLinearColor Color = FLinearColor::White;
	UPROPERTY() FVector2D Size = FVector2D::ZeroVector;
protected:
	bool bClicked = false;
};

// ==================== 树形结构控件 ====================

UCLASS()
class IMGUIBLUEPRINT_API UImGuiElement_TreeNode : public UImGuiElement
{
	GENERATED_BODY()
public:
	virtual void Draw() override;
	virtual bool GetInteractionResult() const override { return bOpen; }
	UPROPERTY() FString Label;
protected:
	bool bOpen = false;
};

UCLASS()
class IMGUIBLUEPRINT_API UImGuiElement_TreePop : public UImGuiElement
{
	GENERATED_BODY()
public:
	virtual void Draw() override;
};

UCLASS()
class IMGUIBLUEPRINT_API UImGuiElement_CollapsingHeader : public UImGuiElement
{
	GENERATED_BODY()
public:
	virtual void Draw() override;
	virtual bool GetInteractionResult() const override { return bOpen; }
	UPROPERTY() FString Label;
protected:
	bool bOpen = false;
};

UCLASS()
class IMGUIBLUEPRINT_API UImGuiElement_SetNextItemOpen : public UImGuiElement
{
	GENERATED_BODY()
public:
	virtual void Draw() override;
	UPROPERTY() bool bIsOpen = true;
};

// ==================== 可选择控件 ====================

UCLASS()
class IMGUIBLUEPRINT_API UImGuiElement_Selectable : public UImGuiElement
{
	GENERATED_BODY()
public:
	virtual void Draw() override;
	virtual bool GetInteractionResult() const override { return bSelected; }
	UPROPERTY() FString Label;
	UPROPERTY() bool bSelected = false;
	UPROPERTY() FVector2D Size = FVector2D::ZeroVector;
};

// ==================== 组合框控件 ====================

UCLASS()
class IMGUIBLUEPRINT_API UImGuiElement_BeginCombo : public UImGuiElement
{
	GENERATED_BODY()
public:
	virtual void Draw() override;
	virtual bool GetInteractionResult() const override { return bOpen; }
	UPROPERTY() FString Label;
	UPROPERTY() FString PreviewValue;
protected:
	bool bOpen = false;
};

UCLASS()
class IMGUIBLUEPRINT_API UImGuiElement_EndCombo : public UImGuiElement
{
	GENERATED_BODY()
public:
	virtual void Draw() override;
};

// ==================== 列表框控件 ====================

UCLASS()
class IMGUIBLUEPRINT_API UImGuiElement_BeginListBox : public UImGuiElement
{
	GENERATED_BODY()
public:
	virtual void Draw() override;
	virtual bool GetInteractionResult() const override { return bOpen; }
	UPROPERTY() FString Label;
	UPROPERTY() FVector2D Size = FVector2D::ZeroVector;
protected:
	bool bOpen = false;
};

UCLASS()
class IMGUIBLUEPRINT_API UImGuiElement_EndListBox : public UImGuiElement
{
	GENERATED_BODY()
public:
	virtual void Draw() override;
};

// ListBox with array items
UCLASS()
class IMGUIBLUEPRINT_API UImGuiElement_ListBox : public UImGuiElement
{
	GENERATED_BODY()
public:
	virtual void Draw() override;
	UPROPERTY() FString Label;
	UPROPERTY() TArray<FString> Items;
	UPROPERTY() int32 CurrentItem = 0;
	UPROPERTY() int32 HeightInItems = -1;
	UPROPERTY() FOnImGuiIntChanged OnSelectionChanged;
};

// Combo with array items
UCLASS()
class IMGUIBLUEPRINT_API UImGuiElement_Combo : public UImGuiElement
{
	GENERATED_BODY()
public:
	virtual void Draw() override;
	UPROPERTY() FString Label;
	UPROPERTY() TArray<FString> Items;
	UPROPERTY() int32 CurrentItem = 0;
	UPROPERTY() FOnImGuiComboChanged OnSelectionChanged;
};

// ==================== 菜单控件 ====================

UCLASS()
class IMGUIBLUEPRINT_API UImGuiElement_BeginMenuBar : public UImGuiElement
{
	GENERATED_BODY()
public:
	virtual void Draw() override;
	virtual bool GetInteractionResult() const override { return bOpen; }
protected:
	bool bOpen = false;
};

UCLASS()
class IMGUIBLUEPRINT_API UImGuiElement_EndMenuBar : public UImGuiElement
{
	GENERATED_BODY()
public:
	virtual void Draw() override;
};

UCLASS()
class IMGUIBLUEPRINT_API UImGuiElement_BeginMainMenuBar : public UImGuiElement
{
	GENERATED_BODY()
public:
	virtual void Draw() override;
	virtual bool GetInteractionResult() const override { return bOpen; }
protected:
	bool bOpen = false;
};

UCLASS()
class IMGUIBLUEPRINT_API UImGuiElement_EndMainMenuBar : public UImGuiElement
{
	GENERATED_BODY()
public:
	virtual void Draw() override;
};

UCLASS()
class IMGUIBLUEPRINT_API UImGuiElement_BeginMenu : public UImGuiElement
{
	GENERATED_BODY()
public:
	virtual void Draw() override;
	virtual bool GetInteractionResult() const override { return bOpen; }
	UPROPERTY() FString Label;
	UPROPERTY() bool bEnabled = true;
protected:
	bool bOpen = false;
};

UCLASS()
class IMGUIBLUEPRINT_API UImGuiElement_EndMenu : public UImGuiElement
{
	GENERATED_BODY()
public:
	virtual void Draw() override;
};

UCLASS()
class IMGUIBLUEPRINT_API UImGuiElement_MenuItem : public UImGuiElement
{
	GENERATED_BODY()
public:
	virtual void Draw() override;
	virtual bool GetInteractionResult() const override { return bClicked; }
	UPROPERTY() FString Label;
	UPROPERTY() FString Shortcut;
	UPROPERTY() bool bSelected = false;
	UPROPERTY() bool bEnabled = true;
	UPROPERTY() FOnImGuiClick OnClicked;
protected:
	bool bClicked = false;
};

// ==================== 弹出窗口控件 ====================

UCLASS()
class IMGUIBLUEPRINT_API UImGuiElement_BeginPopup : public UImGuiElement
{
	GENERATED_BODY()
public:
	virtual void Draw() override;
	virtual bool GetInteractionResult() const override { return bOpen; }
	UPROPERTY() FString StrID;
protected:
	bool bOpen = false;
};

UCLASS()
class IMGUIBLUEPRINT_API UImGuiElement_EndPopup : public UImGuiElement
{
	GENERATED_BODY()
public:
	virtual void Draw() override;
};

UCLASS()
class IMGUIBLUEPRINT_API UImGuiElement_BeginPopupModal : public UImGuiElement
{
	GENERATED_BODY()
public:
	virtual void Draw() override;
	virtual bool GetInteractionResult() const override { return bOpen; }
	UPROPERTY() FString Name;
protected:
	bool bOpen = false;
};

UCLASS()
class IMGUIBLUEPRINT_API UImGuiElement_OpenPopup : public UImGuiElement
{
	GENERATED_BODY()
public:
	virtual void Draw() override;
	UPROPERTY() FString StrID;
};

UCLASS()
class IMGUIBLUEPRINT_API UImGuiElement_CloseCurrentPopup : public UImGuiElement
{
	GENERATED_BODY()
public:
	virtual void Draw() override;
};

// ==================== 表格控件 ====================

UCLASS()
class IMGUIBLUEPRINT_API UImGuiElement_BeginTable : public UImGuiElement
{
	GENERATED_BODY()
public:
	virtual void Draw() override;
	virtual bool GetInteractionResult() const override { return bOpen; }
	UPROPERTY() FString StrID;
	UPROPERTY() int32 Column = 1;
protected:
	bool bOpen = false;
};

UCLASS()
class IMGUIBLUEPRINT_API UImGuiElement_EndTable : public UImGuiElement
{
	GENERATED_BODY()
public:
	virtual void Draw() override;
};

UCLASS()
class IMGUIBLUEPRINT_API UImGuiElement_TableNextRow : public UImGuiElement
{
	GENERATED_BODY()
public:
	virtual void Draw() override;
	UPROPERTY() float MinRowHeight = 0.0f;
};

UCLASS()
class IMGUIBLUEPRINT_API UImGuiElement_TableNextColumn : public UImGuiElement
{
	GENERATED_BODY()
public:
	virtual void Draw() override;
	virtual bool GetInteractionResult() const override { return bResult; }
protected:
	bool bResult = false;
};

UCLASS()
class IMGUIBLUEPRINT_API UImGuiElement_TableSetColumnIndex : public UImGuiElement
{
	GENERATED_BODY()
public:
	virtual void Draw() override;
	UPROPERTY() int32 ColumnIndex = 0;
};

UCLASS()
class IMGUIBLUEPRINT_API UImGuiElement_TableSetupColumn : public UImGuiElement
{
	GENERATED_BODY()
public:
	virtual void Draw() override;
	UPROPERTY() FString Label;
	UPROPERTY() float InitWidthOrWeight = 0.0f;
};

UCLASS()
class IMGUIBLUEPRINT_API UImGuiElement_TableHeadersRow : public UImGuiElement
{
	GENERATED_BODY()
public:
	virtual void Draw() override;
};

// ==================== 标签页控件 ====================

UCLASS()
class IMGUIBLUEPRINT_API UImGuiElement_BeginTabBar : public UImGuiElement
{
	GENERATED_BODY()
public:
	virtual void Draw() override;
	virtual bool GetInteractionResult() const override { return bOpen; }
	UPROPERTY() FString StrID;
protected:
	bool bOpen = false;
};

UCLASS()
class IMGUIBLUEPRINT_API UImGuiElement_EndTabBar : public UImGuiElement
{
	GENERATED_BODY()
public:
	virtual void Draw() override;
};

UCLASS()
class IMGUIBLUEPRINT_API UImGuiElement_BeginTabItem : public UImGuiElement
{
	GENERATED_BODY()
public:
	virtual void Draw() override;
	virtual bool GetInteractionResult() const override { return bOpen; }
	UPROPERTY() FString Label;
protected:
	bool bOpen = false;
};

UCLASS()
class IMGUIBLUEPRINT_API UImGuiElement_EndTabItem : public UImGuiElement
{
	GENERATED_BODY()
public:
	virtual void Draw() override;
};

// ==================== 提示框控件 ====================

UCLASS()
class IMGUIBLUEPRINT_API UImGuiElement_BeginTooltip : public UImGuiElement
{
	GENERATED_BODY()
public:
	virtual void Draw() override;
};

UCLASS()
class IMGUIBLUEPRINT_API UImGuiElement_EndTooltip : public UImGuiElement
{
	GENERATED_BODY()
public:
	virtual void Draw() override;
};

UCLASS()
class IMGUIBLUEPRINT_API UImGuiElement_SetTooltip : public UImGuiElement
{
	GENERATED_BODY()
public:
	virtual void Draw() override;
	UPROPERTY() FString Text;
};

// ==================== 布局控件 ====================

UCLASS()
class IMGUIBLUEPRINT_API UImGuiElement_Spacing : public UImGuiElement
{
	GENERATED_BODY()
public:
	virtual void Draw() override;
};

UCLASS()
class IMGUIBLUEPRINT_API UImGuiElement_Dummy : public UImGuiElement
{
	GENERATED_BODY()
public:
	virtual void Draw() override;
	UPROPERTY() FVector2D Size;
};

UCLASS()
class IMGUIBLUEPRINT_API UImGuiElement_NewLine : public UImGuiElement
{
	GENERATED_BODY()
public:
	virtual void Draw() override;
};

UCLASS()
class IMGUIBLUEPRINT_API UImGuiElement_Separator : public UImGuiElement
{
	GENERATED_BODY()
public:
	virtual void Draw() override;
};

UCLASS()
class IMGUIBLUEPRINT_API UImGuiElement_SameLine : public UImGuiElement
{
	GENERATED_BODY()
public:
	virtual void Draw() override;
	UPROPERTY() float OffsetFromStartX = 0.0f;
	UPROPERTY() float Spacing = -1.0f;
};

UCLASS()
class IMGUIBLUEPRINT_API UImGuiElement_Indent : public UImGuiElement
{
	GENERATED_BODY()
public:
	virtual void Draw() override;
	UPROPERTY() float IndentWidth = 0.0f;
};

UCLASS()
class IMGUIBLUEPRINT_API UImGuiElement_Unindent : public UImGuiElement
{
	GENERATED_BODY()
public:
	virtual void Draw() override;
	UPROPERTY() float IndentWidth = 0.0f;
};

UCLASS()
class IMGUIBLUEPRINT_API UImGuiElement_BeginGroup : public UImGuiElement
{
	GENERATED_BODY()
public:
	virtual void Draw() override;
};

UCLASS()
class IMGUIBLUEPRINT_API UImGuiElement_EndGroup : public UImGuiElement
{
	GENERATED_BODY()
public:
	virtual void Draw() override;
};

// ==================== 子窗口控件 ====================

UCLASS()
class IMGUIBLUEPRINT_API UImGuiElement_BeginChild : public UImGuiElement
{
	GENERATED_BODY()
public:
	virtual void Draw() override;
	UPROPERTY() FString StrID;
	UPROPERTY() FVector2D Size = FVector2D::ZeroVector;
	UPROPERTY() bool bBorder = false;
};

UCLASS()
class IMGUIBLUEPRINT_API UImGuiElement_EndChild : public UImGuiElement
{
	GENERATED_BODY()
public:
	virtual void Draw() override;
};

// ==================== 进度条控件 ====================

UCLASS()
class IMGUIBLUEPRINT_API UImGuiElement_ProgressBar : public UImGuiElement
{
	GENERATED_BODY()
public:
	virtual void Draw() override;
	UPROPERTY() float Fraction = 0.0f;
	UPROPERTY() FVector2D Size = FVector2D(-1, 0);
	UPROPERTY() FString Overlay;
};

// ==================== 图像控件 ====================

UCLASS()
class IMGUIBLUEPRINT_API UImGuiElement_Image : public UImGuiElement
{
	GENERATED_BODY()
public:
	virtual void Draw() override;
	UPROPERTY() uint64 TextureID = 0;
	UPROPERTY() FVector2D Size;
	UPROPERTY() FVector2D UV0 = FVector2D(0, 0);
	UPROPERTY() FVector2D UV1 = FVector2D(1, 1);
	UPROPERTY() FLinearColor TintColor = FLinearColor::White;
	UPROPERTY() FLinearColor BorderColor = FLinearColor::Transparent;
};

UCLASS()
class IMGUIBLUEPRINT_API UImGuiElement_ImageButton : public UImGuiElement
{
	GENERATED_BODY()
public:
	virtual void Draw() override;
	virtual bool GetInteractionResult() const override { return bClicked; }
	UPROPERTY() FString StrID;
	UPROPERTY() uint64 TextureID = 0;
	UPROPERTY() FVector2D Size;
	UPROPERTY() FVector2D UV0 = FVector2D(0, 0);
	UPROPERTY() FVector2D UV1 = FVector2D(1, 1);
	UPROPERTY() FLinearColor BgColor = FLinearColor::Transparent;
	UPROPERTY() FLinearColor TintColor = FLinearColor::White;
protected:
	bool bClicked = false;
};
