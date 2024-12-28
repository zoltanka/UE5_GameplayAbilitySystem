// Copyright Zoltán Fekete


#include "Character/AuraEnemy.h"
#include "Aura/Aura.h"


AAuraEnemy::AAuraEnemy()
{
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
}

void AAuraEnemy::HighlightActor()
{
	USkeletalMeshComponent* Mesh = GetMesh();
	
	Mesh->SetRenderCustomDepth(true);
	Mesh->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);

	Weapon->SetRenderCustomDepth(true);
	Weapon->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
	
	bIsHighlighted = true;
}

void AAuraEnemy::UnHighlightActor()
{
	USkeletalMeshComponent* Mesh = GetMesh();
	
	Mesh->SetRenderCustomDepth(false);
	Weapon->SetRenderCustomDepth(false);
	
	bIsHighlighted = false;
}
