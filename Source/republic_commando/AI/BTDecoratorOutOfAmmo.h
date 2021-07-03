#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "BTDecoratorOutOfAmmo.generated.h"

/**
 * 
 */
UCLASS()
class REPUBLIC_COMMANDO_API UBTDecoratorOutOfAmmo : public UBTDecorator
{
	GENERATED_BODY()

public:
	UBTDecoratorOutOfAmmo();

protected:
	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory) const;
};
