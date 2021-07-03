#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "BTServiceGetAmmo.generated.h"

/**
 * 
 */
UCLASS()
class REPUBLIC_COMMANDO_API UBTServiceGetAmmo : public UBTService_BlackboardBase
{
	GENERATED_BODY()

public:
	UBTServiceGetAmmo();

protected:
	virtual void TickNode(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory, float DeltaSeconds) override;
};
