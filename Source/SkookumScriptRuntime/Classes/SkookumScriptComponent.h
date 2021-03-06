//=======================================================================================
// SkookumScript C++ library.
// Copyright (c) 2014 Agog Labs Inc.,
// All rights reserved.
//
// SkookumScript (SS) Unreal Engine (UE) Bindings
// 
// #Author(s):  Conan Reis
//=======================================================================================

#pragma once

//=======================================================================================
// Includes
//=======================================================================================

#include "Components/ActorComponent.h"
#include "SkookumScriptComponent.generated.h"


//=======================================================================================
// Global Defines / Macros
//=======================================================================================


//=======================================================================================
// Global Structures
//=======================================================================================

//---------------------------------------------------------------------------------------
// Adds SkookumScript text-based scripting capabilities to an actor.
UCLASS(classGroup=Script, editinlinenew, BlueprintType, meta=(BlueprintSpawnableComponent), hideCategories=(Object, ActorComponent), EarlyAccessPreview)
class SKOOKUMSCRIPTRUNTIME_API USkookumScriptComponent : public UActorComponent
  {

    GENERATED_UCLASS_BODY()

  public:

  // Public Data Members

    // SkookumScript class type - used to create appropriate Skookum object instance
    // Uses most derived parent class if left blank.
    UPROPERTY(Category = Script, EditAnywhere, BlueprintReadOnly)
    FString ScriptClassName;


  // Methods

    // Gets our SkookumScript instance
    SSInstance * get_instance() const { return m_instance_p; }

    // Calls a script coroutine on this actor (no arguments)
    // Coroutines are durational and used to do time-based / concurrent tasks that can take more than one frame to complete.
    // @param name name of the coroutine 
    UFUNCTION(BlueprintCallable, Category = "Script|Functions")
    virtual void invoke_coroutine(FString name);

    // Calls a script method on this actor (no arguments)
    // Methods complete immediately.
    // @param name name of the method to call
    UFUNCTION(BlueprintCallable, Category = "Script|Functions")
    virtual void invoke_method(FString method_name);

    // Calls a script query/predicate method on this actor (no arguments) and returns true or false
    // @param name name of the query method to call
    UFUNCTION(BlueprintCallable, Category = "Script|Functions")
    virtual bool invoke_query(FString query_name);

    // Begin UActorComponent interface

      virtual void OnRegister() override;
      virtual void InitializeComponent() override;
      virtual void UninitializeComponent() override;
      virtual void OnUnregister() override;

  protected:

  // Internal Data Members

    // Keep the SkookumScript instance belonging to this actor around
    AIdPtr<SSInstance> m_instance_p;

  };  // USkookumScriptComponent


//=======================================================================================
// Inline Functions
//=======================================================================================

