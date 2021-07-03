#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTaskReload.generated.h"

/**
 * 
 */
UCLASS()
class REPUBLIC_COMMANDO_API UBTTaskReload : public UBTTaskNode
{
	GENERATED_BODY()
	
public:
	UBTTaskReload();

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory) override;
};
