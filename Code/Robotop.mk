##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Robotop
ConfigurationName      :=Debug
IntermediateDirectory  :=.
OutDir                 := $(IntermediateDirectory)
WorkspacePath          := "/home/eric/.codelite/Robotop"
ProjectPath            := "/home/eric/.codelite/Robotop"
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Eric
Date                   :=06/26/2012
CodeLitePath           :="/home/eric/.codelite"
LinkerName             :=
ArchiveTool            :=
SharedObjectLinkerName :=
ObjectSuffix           :=.cobra.cs
DependSuffix           :=
PreprocessSuffix       :=
DebugSwitch            :=-debug
IncludeSwitch          :=-ref:
LibrarySwitch          :=-reference:
OutputSwitch           :=-out:
LibraryPathSwitch      :=-lib:
PreprocessorSwitch     :=
SourceSwitch           :=-c 
CompilerName           :=cobra.exe
C_CompilerName         :=cobra.exe
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-t:lib
ArchiveOutputSwitch    :=-ert
PreprocessOnlySwitch   :=
MakeDirCommand         :=mkdir -p
CmpOptions             := -debug $(Preprocessors)
LinkOptions            :=  
IncludePath            :=  "$(IncludeSwitch)." "$(IncludeSwitch)." 
RcIncludePath          :=
Libs                   :=
LibPath                := "$(LibraryPathSwitch)." 


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects=

##
## Main Build Targets 
##
all: $(OutputFile)

$(OutputFile): makeDirStep $(Objects)
	@$(MakeDirCommand) $(@D)
	$(LinkerName) $(OutputSwitch)$(OutputFile) $(Objects) $(LibPath) $(Libs) $(LinkOptions)

makeDirStep:
	@test -d . || $(MakeDirCommand) .

PreBuild:


##
## Objects
##
##
## Clean
##
clean:
	$(RM) $(OutputFile)


