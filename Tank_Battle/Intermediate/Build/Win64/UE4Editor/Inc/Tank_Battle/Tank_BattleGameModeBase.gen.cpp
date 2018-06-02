// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Tank_BattleGameModeBase.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTank_BattleGameModeBase() {}
// Cross Module References
	TANK_BATTLE_API UClass* Z_Construct_UClass_ATank_BattleGameModeBase_NoRegister();
	TANK_BATTLE_API UClass* Z_Construct_UClass_ATank_BattleGameModeBase();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_Tank_Battle();
// End Cross Module References
	void ATank_BattleGameModeBase::StaticRegisterNativesATank_BattleGameModeBase()
	{
	}
	UClass* Z_Construct_UClass_ATank_BattleGameModeBase_NoRegister()
	{
		return ATank_BattleGameModeBase::StaticClass();
	}
	UClass* Z_Construct_UClass_ATank_BattleGameModeBase()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_AGameModeBase,
				(UObject* (*)())Z_Construct_UPackage__Script_Tank_Battle,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
				{ "IncludePath", "Tank_BattleGameModeBase.h" },
				{ "ModuleRelativePath", "Tank_BattleGameModeBase.h" },
				{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
			};
#endif
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<ATank_BattleGameModeBase>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&ATank_BattleGameModeBase::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00900288u,
				nullptr, 0,
				nullptr, 0,
				nullptr,
				&StaticCppClassTypeInfo,
				nullptr, 0,
				METADATA_PARAMS(Class_MetaDataParams, ARRAY_COUNT(Class_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUClass(OuterClass, ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ATank_BattleGameModeBase, 1465425677);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ATank_BattleGameModeBase(Z_Construct_UClass_ATank_BattleGameModeBase, &ATank_BattleGameModeBase::StaticClass, TEXT("/Script/Tank_Battle"), TEXT("ATank_BattleGameModeBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ATank_BattleGameModeBase);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
