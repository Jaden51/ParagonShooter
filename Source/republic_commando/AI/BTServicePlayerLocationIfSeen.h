#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "BTServicePlayerLocationIfSeen.generated.h"

/**
 * 
 */
UCLASS()
class REPUBLIC_COMMANDO_API UBTServicePlayerLocationIfSeen : public UBTService_BlackboardBase
{
	GENERATED_BODY()

public:
	UBTServicePlayerLocationIfSeen();

protected:
	virtual void TickNode(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory, float DeltaSeconds) override;
};
