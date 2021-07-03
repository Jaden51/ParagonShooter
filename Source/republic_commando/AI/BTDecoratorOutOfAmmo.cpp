#include "BTDecoratorOutOfAmmo.h"
#include "AIController.h"
#include "../Characters/PlayableCharacter.h"

UBTDecoratorOutOfAmmo::UBTDecoratorOutOfAmmo()
{
    NodeName = "Out of Ammo";
}

bool UBTDecoratorOutOfAmmo::CalculateRawConditionValue(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory) const
{
    Super::CalculateRawConditionValue(OwnerComp, NodeMemory);

    if (OwnerComp.GetAIOwner() == nullptr)
    {
        return EBTNodeResult::Failed;
    }

    APlayableCharacter *Playable = Cast<APlayableCharacter>(OwnerComp.GetAIOwner()->GetPawn());

    if (Playable->GetAmmo() == 0)
    {
        return false;
    }

    return true;
}
