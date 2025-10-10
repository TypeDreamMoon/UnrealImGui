// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ImGuiElement.generated.h"

/**
 * 这个是一个用于定义一个ImGui控件元素的基类
 */
UCLASS(Abstract)
class IMGUIBLUEPRINT_API UImGuiElement : public UObject
{
	GENERATED_BODY()

public:
	// 绘制元素（纯虚函数，子类必须实现）
	virtual void Draw() PURE_VIRTUAL(UImGuiElement::Draw, );

	// 获取最后一次交互的结果（例如按钮是否被点击）
	virtual bool GetInteractionResult() const { return false; }
};
