// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ImGuiPainter.generated.h"

class UImGuiBuilder;

UCLASS(BlueprintType, Blueprintable)
class IMGUIBLUEPRINT_API UImGuiPainter : public UObject, public FTickableGameObject
{
	GENERATED_BODY()

public:
	UImGuiPainter();
	virtual ~UImGuiPainter() override;

	virtual TStatId GetStatId() const override { RETURN_QUICK_DECLARE_CYCLE_STAT(ThisClass, STATGROUP_Tickables); }
	virtual void Tick(float DeltaTime) override;
	virtual bool IsTickable() const override { return bDraw; }

	// 创建一个新窗口并返回Builder用于链式构建
	UFUNCTION(BlueprintCallable, Category = "ImGui", Meta = (WorldContext = "WorldContextObject"))
	static UImGuiBuilder* CreateWindow(UObject* WorldContextObject, UImGuiPainter*& ReturnPainter, const FString& InWindowName);

	// 开始绘制
	UFUNCTION(BlueprintCallable, Category = "ImGui")
	void StartDraw();

	// 停止绘制
	UFUNCTION(BlueprintCallable, Category = "ImGui")
	void StopDraw();

	// 清除所有Builder
	UFUNCTION(BlueprintCallable, Category = "ImGui")
	void ClearAllWindows();

protected:
	// 是否绘制
	UPROPERTY(BlueprintReadWrite, Category = "ImGui")
	bool bDraw;

	// 所有的Builder
	UPROPERTY()
	TArray<TObjectPtr<UImGuiBuilder>> Builders;
};

UCLASS(Blueprintable, BlueprintType)
class UImGuiPainterDynamic : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "ImGui", Meta = (WorldContext = "WorldContextObject"))
	static UImGuiPainterDynamic* Create(UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable)
	UImGuiBuilder* Draw(FString InWindowName);

protected:
	UPROPERTY()
	TObjectPtr<UImGuiBuilder> Builder;
};
