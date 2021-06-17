#include "BTTaskShoot.h"
#include "AIController.h"
#include "../Characters/Wraith.h"

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

    AWraith *Wraith = Cast<AWraith>(OwnerComp.GetAIOwner()->GetPawn());

    if (Wraith == nullptr)
    {
        return EBTNodeResult::Failed;
    }

    Wraith->Shoot();
    Wraith->ResetCombo();

    return EBTNodeResult::Succeeded;
}
