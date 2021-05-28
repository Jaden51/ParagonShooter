#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "AIControl.generated.h"

UCLASS()
class REPUBLIC_COMMANDO_API AAIControl : public AAIController
{
	GENERATED_BODY()

public:
	virtual void Tick(float DeltaSeconds) override;
	bool IsDead() const;

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere)
	float FollowRadius = 200;

	UPROPERTY(EditAnywhere)
	class UBehaviorTree* AIBehavior;
};
