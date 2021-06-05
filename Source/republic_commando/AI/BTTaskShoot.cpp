#include "BTTaskShoot.h"
#include "AIController.h"
#include "../Characters/PlayableCharacter.h"

UBTTaskShoot::UBTTaskShoot()
{
    NodeName = "Shoot";
}

EBTNodeResult::Type UBTTaskShoot::ExecuteTask(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory)
{
    Super::ExecuteTask(OwnerComp, NodeMemory);

    if (OwnerComp.GetAIOwner() == nullptr)
    {
        return EBTNodeResult::Failed;
    }

    APlayableCharacter* Wraith = Cast<APlayableCharacter>(OwnerComp.GetAIOwner()->GetPawn());

    if (Wraith == nullptr)
    {
        return EBTNodeResult::Failed;
    }

    Wraith->Shoot();

    return EBTNodeResult::Succeeded;
}


