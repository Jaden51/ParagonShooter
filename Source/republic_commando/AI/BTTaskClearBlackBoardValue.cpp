#include "BTTaskClearBlackBoardValue.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTaskClearBlackBoardValue::UBTTaskClearBlackBoardValue()
{
    NodeName = TEXT("Clear Blackboard Value");
}

EBTNodeResult::Type UBTTaskClearBlackBoardValue::ExecuteTask(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory)
{
    Super::ExecuteTask(OwnerComp, NodeMemory);
    OwnerComp.GetBlackboardComponent()->ClearValue(GetSelectedBlackboardKey());
    return EBTNodeResult::Succeeded;
}
