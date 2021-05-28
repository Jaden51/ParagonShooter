#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTTaskClearBlackBoardValue.generated.h"

/**
 * 
 */
UCLASS()
class REPUBLIC_COMMANDO_API UBTTaskClearBlackBoardValue : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
	
public:
	UBTTaskClearBlackBoardValue();

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory) override;
};
