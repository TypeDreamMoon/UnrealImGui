// Fill out your copyright notice in the Description page of Project Settings.

#include "Classes/ImGuiPainter.h"
#include "Classes/ImGuiBuilder.h"

UImGuiPainter::UImGuiPainter()
	: bDraw(false)
{
}

UImGuiPainter::~UImGuiPainter()
{
}

void UImGuiPainter::Tick(float DeltaTime)
{
	if (!bDraw)
	{
		return;
	}

	// 绘制所有的Builder
	for (UImGuiBuilder* Builder : Builders)
	{
		if (Builder)
		{
			Builder->Draw();
		}
	}
}

UImGuiBuilder* UImGuiPainter::CreateWindow(UObject* WorldContextObject, UImGuiPainter*& ReturnPainter, const FString& InWindowName)
{
	UImGuiPainter* Painter = NewObject<UImGuiPainter>(WorldContextObject);

	// 创建新的Builder
	UImGuiBuilder* NewBuilder = NewObject<UImGuiBuilder>(Painter);
	if (NewBuilder)
	{
		NewBuilder->SetWindowName(InWindowName);
		Painter->Builders.Add(NewBuilder);
	}

	ReturnPainter = Painter;

	return NewBuilder;
}

void UImGuiPainter::StartDraw()
{
	bDraw = true;
}

void UImGuiPainter::StopDraw()
{
	bDraw = false;
}

void UImGuiPainter::ClearAllWindows()
{
	Builders.Empty();
}

UImGuiPainterDynamic* UImGuiPainterDynamic::Create(UObject* WorldContextObject)
{
	return NewObject<UImGuiPainterDynamic>(WorldContextObject);
}

UImGuiBuilder* UImGuiPainterDynamic::Draw(FString InWindowName)
{
	Builder = NewObject<UImGuiBuilder>(this);
	if (Builder)
	{
		Builder->SetWindowName(InWindowName);
	}

	return Builder;
}
