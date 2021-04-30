// Copyright Epic Games, Inc. All Rights Reserved.

#include "ExamHUD.h"
#include "Engine/Canvas.h"
#include "Engine/Texture2D.h"
#include "TextureResource.h"
#include "CanvasItem.h"
#include "UObject/ConstructorHelpers.h"
#include <string>
#include <Exam/ExamCharacter.h>
#include <Runtime/Engine/Classes/Kismet/GameplayStatics.h>

AExamHUD::AExamHUD()
{
	// Set the crosshair texture
	static ConstructorHelpers::FObjectFinder<UTexture2D> CrosshairTexObj(TEXT("/Game/FirstPerson/Textures/FirstPersonCrosshair"));
	CrosshairTex = CrosshairTexObj.Object;
}


void AExamHUD::DrawHUD()
{
	Super::DrawHUD();

	// Draw very simple crosshair

	// find center of the Canvas
	const FVector2D Center(Canvas->ClipX * 0.5f, Canvas->ClipY * 0.5f);
	const FVector2D Bg(50, Canvas->ClipY - 50);
	// offset by half the texture's dimensions so that the center of the texture aligns with the center of the Canvas
	const FVector2D CrosshairDrawPosition( (Center.X),
										   (Center.Y + 20.0f));
	// draw the crosshair
	AExamCharacter* MyCharacter = Cast<AExamCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	FString textBall = "BALL :" + FString::FromInt(MyCharacter->nbBalle);
	DrawText(textBall, FLinearColor::Blue, Bg.X, Bg.Y, NULL, 2.0, false);

	FCanvasTileItem TileItem( CrosshairDrawPosition, CrosshairTex->Resource, FLinearColor::White);
	TileItem.BlendMode = SE_BLEND_Translucent;
	Canvas->DrawItem( TileItem );
}
