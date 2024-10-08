// Copyright 2022 © Gökdeniz Çetin

using UnrealBuildTool;
using System.Collections.Generic;

public class GAD2006_LabEditorTarget : TargetRules
{
	public GAD2006_LabEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V5;
		IncludeOrderVersion = EngineIncludeOrderVersion.Latest;
		//BuildEnvironment = TargetBuildEnvironment.Unique;

		ExtraModuleNames.AddRange( new string[] { "GAD2006_Lab" } );
	}
}
