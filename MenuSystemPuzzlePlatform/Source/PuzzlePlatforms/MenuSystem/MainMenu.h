// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MenuInterface.h"
#include "MainMenu.generated.h"
/**
 * 
 */
UCLASS()
class PUZZLEPLATFORMS_API UMainMenu : public UUserWidget
{
	GENERATED_BODY()
public:
	void SetMenuInterface(IMenuInterface* MenuToInterface);

	void Setup();

	void Teardown();

protected:
	virtual bool Initialize() override; // Method Of UUserWidget

private:
	// Assigned Button By Exact Name
	UPROPERTY(meta = (BindWidget))
	class UButton* HostButton;

	UPROPERTY(meta = (BindWidget))
	class UButton* JoinButton;

	UPROPERTY(meta = (BindWidget))
	class UButton* CancelJoinMenuButton;

	UPROPERTY(meta = (BindWidget))
	class UWidgetSwitcher* MenuSwitcher;

	// Widget Designed MainMenu & JoinMenu
	UPROPERTY(meta = (BindWidget))
	class UWidget* JoinMenu;

	UPROPERTY(meta = (BindWidget))
	class UWidget* MainMenu;

	// Dynamic Delegates
	UFUNCTION()
	void HostServer();

	UFUNCTION()
	void OpenJoinMenu();

	UFUNCTION()
	void OpenMainMenu();

	IMenuInterface* MenuInterface;
};