#include "BTTTaskClearBlackBoardValue.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTTaskClearBlackBoardValue::UBTTTaskClearBlackBoardValue()
{
    NodeName = TEXT("Clear Blackboard Value");
}

EBTNodeResult::Type UBTTTaskClearBlackBoardValue::ExecuteTask(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory)
{
    Super::ExecuteTask(OwnerComp, NodeMemory);
    OwnerComp.GetBlackboardComponent()->ClearValue(GetSelectedBlackboardKey());
    return EBTNodeResult::Succeeded;
}
