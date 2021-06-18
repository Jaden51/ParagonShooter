#include "BTTaskShoot.h"
#include "AIController.h"
#include "../Characters/Wraith.h"
#include "../Characters/Revenant.h"
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

    if (Cast<AWraith>(OwnerComp.GetAIOwner()->GetPawn()) != nullptr)
    {
        AWraith *Wraith = Cast<AWraith>(OwnerComp.GetAIOwner()->GetPawn());
        Wraith->Shoot();
        Wraith->ResetCombo();
    }
    else
    {
        ARevenant *Revenant = Cast<ARevenant>(OwnerComp.GetAIOwner()->GetPawn());
        Revenant->Shoot();
    }

    return EBTNodeResult::Succeeded;
}
