#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTaskShoot.generated.h"

/**
 * 
 */
UCLASS()
class REPUBLIC_COMMANDO_API UBTTaskShoot : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UBTTaskShoot();

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory) override;
};
