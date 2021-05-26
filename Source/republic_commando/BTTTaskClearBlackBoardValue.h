#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTTTaskClearBlackBoardValue.generated.h"

/**
 * 
 */
UCLASS()
class REPUBLIC_COMMANDO_API UBTTTaskClearBlackBoardValue : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
	
public:
	UBTTTaskClearBlackBoardValue();

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory) override;
};
