#include "BTTaskReload.h"
#include "AIController.h"
#include "../Characters/Wraith.h"
#include "../Characters/Revenant.h"
#include "../Characters/PlayableCharacter.h"

UBTTaskReload::UBTTaskReload()
{
    NodeName = "Reload";
}

EBTNodeResult::Type UBTTaskReload::ExecuteTask(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory)
{
    Super::ExecuteTask(OwnerComp, NodeMemory);

    if (OwnerComp.GetAIOwner() == nullptr)
    {
        return EBTNodeResult::Failed;
    }

    ARevenant *Revenant = Cast<ARevenant>(OwnerComp.GetAIOwner()->GetPawn());
    Revenant->Reload();

    return EBTNodeResult::Succeeded;
}