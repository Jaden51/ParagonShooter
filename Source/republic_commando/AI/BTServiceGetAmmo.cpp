#include "BTServiceGetAmmo.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "../Characters/PlayableCharacter.h"

UBTServiceGetAmmo::UBTServiceGetAmmo()
{
    NodeName = "Get Ammo Count";
}

void UBTServiceGetAmmo::TickNode(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory, float DeltaSeconds)
{
    Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

    APlayableCharacter *AICharacter = Cast<APlayableCharacter>(OwnerComp.GetAIOwner()->GetPawn());

    if (AICharacter == nullptr)
        return;

    int32 Ammo = AICharacter->GetAmmo();

    if (Ammo != 0)
    {
        OwnerComp.GetBlackboardComponent()->SetValueAsInt(GetSelectedBlackboardKey(), AICharacter->GetAmmo());
    }
    else
    {
        OwnerComp.GetBlackboardComponent()->SetValueAsInt(GetSelectedBlackboardKey(), 0);
    }
}