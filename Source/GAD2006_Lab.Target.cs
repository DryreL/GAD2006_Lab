// Copyright 2022 © Gökdeniz Çetin

using UnrealBuildTool;
using System.Collections.Generic;

public class GAD2006_LabTarget : TargetRules
{
	public GAD2006_LabTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V5;

		ExtraModuleNames.AddRange( new string[] { "GAD2006_Lab" } );
	}
}
