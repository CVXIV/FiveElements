// Copyright Cvxiv


#include "Tools/CustomAbilitySystemLibrary.h"

TArray<FRotator> UCustomAbilitySystemLibrary::EvenlySpacedRotators(const FVector& Forward, const FVector& Axis,
                                                                   float SpreadInDegree, int32 Nums)
{
	TArray<FRotator> Rotators;
	if (Nums > 1)
	{
		const FVector LeftOfSpread = Forward.RotateAngleAxis(-SpreadInDegree * 0.5f, Axis);
		// 360°特殊情况，起点和终点会重合
		const float DeltaSpread = SpreadInDegree / (SpreadInDegree < 360.f ? Nums - 1 : Nums);
		for (int32 i = 0; i < Nums; ++i)
		{
			const FVector Direction = LeftOfSpread.RotateAngleAxis(DeltaSpread * i, Axis);
			Rotators.Add(Direction.Rotation());
		}
	}
	else
	{
		Rotators.Add(Forward.Rotation());
	}

	return Rotators;
}
