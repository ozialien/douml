#ok
TEMPLATE    = app
TARGET        = cpp_util
CONFIG(Debug, Debug|Release) {
    CONFIG -= Debug Release
    CONFIG += qt warn_on Debug
    QMAKE_POST_LINK = " "
}
CONFIG(Release, Debug|Release) {
    CONFIG -= Debug Release
    CONFIG += qt Release
    QMAKE_POST_LINK = " "
}
DEFINES        += WITHCPP TRACE
INCLUDEPATH += ../../src
HEADERS        = ./UmlBasePackage.h \
          ./UmlFragmentCompartment.h \
          ./UmlBaseUseCase.h \
          ./TransitionBehavior.h \
          ./aDirection.h \
          ./aMessageKind.h \
          ./UmlBaseComponentView.h \
          ./UmlPseudoState.h \
          ./UmlStereotype.h \
          ./StateBehavior.h \
          ./UmlSequenceDiagramDefinition.h \
          ./SlotAttribute.h \
          ./UmlBaseView.h \
          ./UmlBaseActivityPin.h \
          ./UmlClassDiagram.h \
          ./UmlActivityActionClasses.h \
          ./UmlExpansionRegion.h \
          ./UmlBaseActivityParameter.h \
          ./UmlBaseShallowHistoryPseudoState.h \
          ./aLanguage.h \
          ./UmlJoinPseudoState.h \
          ./UmlTypeSpec.h \
          ./UmlBaseActivityObject.h \
          ./UmlShallowHistoryPseudoState.h \
          ./UmlClass.h \
          ./UmlBaseStateDiagram.h \
          ./UmlSettingsCmd.h \
          ./UmlCollaborationMessage.h \
          ./UmlBaseParameterSet.h \
          ./UmlBaseActivityAction.h \
          ./UmlView.h \
          ./anExpansionKind.h \
          ./UmlDeploymentView.h \
          ./UmlActivityItem.h \
          ./UmlJunctionPseudoState.h \
          ./aRelationKind.h \
          ./UmlBaseClassInstanceReference.h \
          ./UmlBaseExpansionNode.h \
          ./UmlAccessVariableValueAction.h \
          ./UmlClassInstanceReference.h \
          ./JavaSettings.h \
          ./UmlUseCaseDiagram.h \
          ./UmlBaseSequenceDiagramDefinition.h \
          ./UmlActivityPartition.h \
          ./UmlBaseJoinPseudoState.h \
          ./UmlState.h \
          ./UmlChoicePseudoState.h \
          ./IdlSettingsCmd.h \
          ./UmlPinParameter.h \
          ./UmlBaseActivityDiagram.h \
          ./UmlInitialPseudoState.h \
          ./UmlBaseActivityRegion.h \
          ./anItemKind.h \
          ./UmlBaseClassDiagram.h \
          ./UmlParameterSet.h \
          ./UmlBaseSequenceMessage.h \
          ./UmlBaseCollaborationMessage.h \
          ./PhpSettingsCmd.h \
          ./UmlStateDiagram.h \
          ./UmlActivityParameter.h \
          ./UmlBaseClassMember.h \
          ./UmlBaseSequenceDiagram.h \
          ./UmlClassMember.h \
          ./UmlBaseArtifact.h \
          ./UmlBaseState.h \
          ./UmlActivityObject.h \
          ./UmlBaseRelation.h \
          ./UmlBaseAttribute.h \
          ./MiscGlobalCmd.h \
          ./UmlParameter.h \
          ./UmlBaseDeepHistoryPseudoState.h \
          ./UmlActualParameter.h \
          ./PhpSettings.h \
          ./UmlBaseActivityPartition.h \
          ./UmlComponentDiagram.h \
          ./UmlSettings.h \
          ./UmlBaseJunctionPseudoState.h \
          ./UmlBaseDeployment.h \
          ./UmlObjectDiagram.h \
          ./UmlBaseNcRelation.h \
          ./UmlBaseActivity.h \
          ./UmlBaseExitPointPseudoState.h \
          ./UmlBaseComponentDiagram.h \
          ./UmlCom.h \
          ./UmlBaseStateAction.h \
          ./UmlBaseActivityControlNode.h \
          ./UmlBaseActivityActionClasses.h \
          ./UmlBaseRegion.h \
          ./CppSettings.h \
          ./UmlBaseActivityControlNodeClasses.h \
          ./UmlRegion.h \
          ./UmlActivityRegion.h \
          ./PackageGlobalCmd.h \
          ./PythonSettings.h \
          ./UmlActivityDiagram.h \
          ./UmlBaseExtraClassMember.h \
          ./UmlMessage.h \
          ./UmlBaseFragmentCompartment.h \
          ./UmlClassItem.h \
          ./UmlBaseTransition.h \
          ./UmlOperation.h \
          ./UmlBaseActivityNode.h \
          ./UmlInterruptibleActivityRegion.h \
          ./CppSettingsCmd.h \
          ./UmlBaseObjectDiagram.h \
          ./UmlBuiltin.h \
          ./UmlStateAction.h \
          ./UmlSubject.h \
          ./CmdFamily.h \
          ./UmlUseCaseAssociation.h \
          ./UmlBaseMessage.h \
          ./UmlBaseUseCaseReference.h \
          ./UmlExtraClassMember.h \
          ./UmlArtifact.h \
          ./UmlBasePinParameter.h \
          ./FlowBehavior.h \
          ./UmlEntryPointPseudoState.h \
          ./UmlBaseUseCaseDiagram.h \
          ./UmlBaseClassView.h \
          ./UmlComponent.h \
          ./UmlBaseClass.h \
          ./JavaSettingsCmd.h \
          ./UmlBaseParameter.h \
          ./UmlNode.h \
          ./UmlSequenceMessage.h \
          ./UmlNcRelation.h \
          ./UmlClassInstance.h \
          ./OnInstanceCmd.h \
          ./UmlSequenceDiagram.h \
          ./UmlFragment.h \
          ./UmlBaseFlow.h \
          ./UmlUseCaseDiagramDefinition.h \
          ./UmlBaseAccessVariableValueAction.h \
          ./UmlBaseItem.h \
          ./UmlBaseFormalParameter.h \
          ./UmlUseCaseView.h \
          ./UmlBaseUseCaseAssociation.h \
          ./UmlBaseExpansionRegion.h \
          ./UmlBaseActualParameter.h \
          ./UmlFinalState.h \
          ./UmlBaseOperation.h \
          ./UmlBaseSubject.h \
          ./UmlBaseForkPseudoState.h \
          ./UmlBaseOnSignalAction.h \
          ./UmlBaseComponent.h \
          ./aVisibility.h \
          ./UmlCollaborationDiagram.h \
          ./UmlActivity.h \
          ./UmlDeploymentDiagram.h \
          ./UmlCollaborationDiagramDefinition.h \
          ./UmlRelation.h \
          ./UmlExpansionNode.h \
          ./UmlTerminatePseudoState.h \
          ./UmlBaseTerminatePseudoState.h \
          ./aParameterEffectKind.h \
          ./UmlBaseClassInstance.h \
          ./UmlBaseDiagram.h \
          ./UmlBaseNode.h \
          ./UmlItem.h \
          ./anOrdering.h \
          ./UmlPackage.h \
          ./UmlForkPseudoState.h \
          ./IdlSettings.h \
          ./ConstrDestrCopyDialog.h \
          ./SlotRelation.h \
          ./UmlActivityAction.h \
          ./UmlUseCaseReference.h \
          ./UmlAttribute.h \
          ./UmlBaseFragment.h \
          ./UmlBaseInterruptibleActivityRegion.h \
          ./ClassGlobalCmd.h \
          ./UmlBaseEntryPointPseudoState.h \
          ./UmlExitPointPseudoState.h \
          ./UmlBaseDeploymentView.h \
          ./UmlBaseFinalState.h \
          ./UmlStateItem.h \
          ./UmlActivityPin.h \
          ./UmlBaseUseCaseView.h \
          ./UmlOnSignalAction.h \
          ./UmlBaseClassItem.h \
          ./UmlFormalParameter.h \
          ./UmlBaseCollaborationDiagram.h \
          ./UmlUseCase.h \
          ./UmlComponentView.h \
          ./UmlActivityControlNodeClasses.h \
          ./UmlFlow.h \
          ./PythonSettingsCmd.h \
          ./UmlBaseChoicePseudoState.h \
          ./UmlBaseDeploymentDiagram.h \
          ./UmlActivityNode.h \
          ./UmlDiagram.h \
          ./UmlTransition.h \
          ./UmlBaseUseCaseDiagramDefinition.h \
          ./UmlDeepHistoryPseudoState.h \
          ./UmlBaseCollaborationDiagramDefinition.h \
          ./UmlClassView.h \
          ./UmlActivityControlNode.h \
          ./UmlBaseInitialPseudoState.h \
          ./UmlBaseTypeSpec.h \
    Logging/QsLogDest.h \
    Logging/QsLog.h \
    Logging/QsDebugOutput.h \
    gridbox.h \
    hhbox.h \
    vvbox.h
SOURCES        = ./UmlBasePackage.cpp \
          ./UmlFragmentCompartment.cpp \
          ./UmlBaseUseCase.cpp \
          ./TransitionBehavior.cpp \
          ./aDirection.cpp \
          ./aMessageKind.cpp \
          ./UmlBaseComponentView.cpp \
          ./UmlPseudoState.cpp \
          ./UmlStereotype.cpp \
          ./StateBehavior.cpp \
          ./UmlSequenceDiagramDefinition.cpp \
          ./SlotAttribute.cpp \
          ./UmlBaseView.cpp \
          ./UmlBaseActivityPin.cpp \
          ./UmlClassDiagram.cpp \
          ./UmlActivityActionClasses.cpp \
          ./UmlExpansionRegion.cpp \
          ./UmlBaseActivityParameter.cpp \
          ./UmlBaseShallowHistoryPseudoState.cpp \
          ./aLanguage.cpp \
          ./UmlJoinPseudoState.cpp \
          ./UmlTypeSpec.cpp \
          ./UmlBaseActivityObject.cpp \
          ./UmlShallowHistoryPseudoState.cpp \
          ./UmlClass.cpp \
          ./UmlBaseStateDiagram.cpp \
          ./UmlSettingsCmd.cpp \
          ./UmlCollaborationMessage.cpp \
          ./UmlBaseParameterSet.cpp \
          ./UmlBaseActivityAction.cpp \
          ./UmlView.cpp \
          ./anExpansionKind.cpp \
          ./UmlDeploymentView.cpp \
          ./UmlActivityItem.cpp \
          ./UmlJunctionPseudoState.cpp \
          ./aRelationKind.cpp \
          ./UmlBaseClassInstanceReference.cpp \
          ./UmlBaseExpansionNode.cpp \
          ./UmlAccessVariableValueAction.cpp \
          ./UmlClassInstanceReference.cpp \
          ./JavaSettings.cpp \
          ./UmlUseCaseDiagram.cpp \
          ./UmlBaseSequenceDiagramDefinition.cpp \
          ./UmlActivityPartition.cpp \
          ./UmlBaseJoinPseudoState.cpp \
          ./UmlState.cpp \
          ./UmlChoicePseudoState.cpp \
          ./IdlSettingsCmd.cpp \
          ./UmlPinParameter.cpp \
          ./UmlBaseActivityDiagram.cpp \
          ./UmlInitialPseudoState.cpp \
          ./UmlBaseActivityRegion.cpp \
          ./anItemKind.cpp \
          ./UmlBaseClassDiagram.cpp \
          ./UmlParameterSet.cpp \
          ./UmlBaseSequenceMessage.cpp \
          ./UmlBaseCollaborationMessage.cpp \
          ./PhpSettingsCmd.cpp \
          ./UmlStateDiagram.cpp \
          ./UmlActivityParameter.cpp \
          ./UmlBaseClassMember.cpp \
          ./UmlBaseSequenceDiagram.cpp \
          ./UmlClassMember.cpp \
          ./UmlBaseArtifact.cpp \
          ./UmlBaseState.cpp \
          ./UmlActivityObject.cpp \
          ./UmlBaseRelation.cpp \
          ./UmlBaseAttribute.cpp \
          ./MiscGlobalCmd.cpp \
          ./UmlParameter.cpp \
          ./UmlBaseDeepHistoryPseudoState.cpp \
          ./UmlActualParameter.cpp \
          ./PhpSettings.cpp \
          ./UmlBaseActivityPartition.cpp \
          ./UmlComponentDiagram.cpp \
          ./UmlSettings.cpp \
          ./UmlBaseJunctionPseudoState.cpp \
          ./UmlBaseDeployment.cpp \
          ./UmlObjectDiagram.cpp \
          ./UmlBaseNcRelation.cpp \
          ./UmlBaseActivity.cpp \
          ./UmlBaseExitPointPseudoState.cpp \
          ./UmlBaseComponentDiagram.cpp \
          ./UmlCom.cpp \
          ./UmlBaseStateAction.cpp \
          ./UmlBaseActivityControlNode.cpp \
          ./UmlBaseActivityActionClasses.cpp \
          ./UmlBaseRegion.cpp \
          ./CppSettings.cpp \
          ./UmlBaseActivityControlNodeClasses.cpp \
          ./UmlRegion.cpp \
          ./UmlActivityRegion.cpp \
          ./PackageGlobalCmd.cpp \
          ./PythonSettings.cpp \
          ./UmlActivityDiagram.cpp \
          ./UmlBaseExtraClassMember.cpp \
          ./UmlMessage.cpp \
          ./UmlBaseFragmentCompartment.cpp \
          ./UmlClassItem.cpp \
          ./UmlBaseTransition.cpp \
          ./UmlOperation.cpp \
          ./UmlBaseActivityNode.cpp \
          ./UmlInterruptibleActivityRegion.cpp \
          ./CppSettingsCmd.cpp \
          ./UmlBaseObjectDiagram.cpp \
          ./UmlBuiltin.cpp \
          ./UmlStateAction.cpp \
          ./UmlSubject.cpp \
          ./CmdFamily.cpp \
          ./UmlUseCaseAssociation.cpp \
          ./UmlBaseMessage.cpp \
          ./UmlBaseUseCaseReference.cpp \
          ./UmlExtraClassMember.cpp \
          ./UmlArtifact.cpp \
          ./UmlBasePinParameter.cpp \
          ./FlowBehavior.cpp \
          ./UmlEntryPointPseudoState.cpp \
          ./UmlBaseUseCaseDiagram.cpp \
          ./UmlBaseClassView.cpp \
          ./UmlComponent.cpp \
          ./UmlBaseClass.cpp \
          ./JavaSettingsCmd.cpp \
          ./UmlBaseParameter.cpp \
          ./Main.cpp \
          ./UmlNode.cpp \
          ./UmlSequenceMessage.cpp \
          ./UmlNcRelation.cpp \
          ./UmlClassInstance.cpp \
          ./OnInstanceCmd.cpp \
          ./UmlSequenceDiagram.cpp \
          ./UmlFragment.cpp \
          ./UmlBaseFlow.cpp \
          ./UmlUseCaseDiagramDefinition.cpp \
          ./UmlBaseAccessVariableValueAction.cpp \
          ./UmlBaseItem.cpp \
          ./UmlBaseFormalParameter.cpp \
          ./UmlUseCaseView.cpp \
          ./UmlBaseUseCaseAssociation.cpp \
          ./UmlBaseExpansionRegion.cpp \
          ./UmlBaseActualParameter.cpp \
          ./UmlFinalState.cpp \
          ./UmlBaseOperation.cpp \
          ./UmlBaseSubject.cpp \
          ./UmlBaseForkPseudoState.cpp \
          ./UmlBaseOnSignalAction.cpp \
          ./UmlBaseComponent.cpp \
          ./aVisibility.cpp \
          ./UmlCollaborationDiagram.cpp \
          ./UmlActivity.cpp \
          ./UmlDeploymentDiagram.cpp \
          ./UmlCollaborationDiagramDefinition.cpp \
          ./UmlRelation.cpp \
          ./UmlExpansionNode.cpp \
          ./UmlTerminatePseudoState.cpp \
          ./UmlBaseTerminatePseudoState.cpp \
          ./aParameterEffectKind.cpp \
          ./UmlBaseClassInstance.cpp \
          ./UmlBaseDiagram.cpp \
          ./UmlBaseNode.cpp \
          ./UmlItem.cpp \
          ./anOrdering.cpp \
          ./UmlPackage.cpp \
          ./UmlForkPseudoState.cpp \
          ./IdlSettings.cpp \
          ./ConstrDestrCopyDialog.cpp \
          ./SlotRelation.cpp \
          ./UmlActivityAction.cpp \
          ./UmlUseCaseReference.cpp \
          ./UmlAttribute.cpp \
          ./UmlBaseFragment.cpp \
          ./UmlBaseInterruptibleActivityRegion.cpp \
          ./ClassGlobalCmd.cpp \
          ./UmlBaseEntryPointPseudoState.cpp \
          ./UmlExitPointPseudoState.cpp \
          ./UmlBaseDeploymentView.cpp \
          ./UmlBaseFinalState.cpp \
          ./UmlStateItem.cpp \
          ./UmlActivityPin.cpp \
          ./UmlBaseUseCaseView.cpp \
          ./UmlOnSignalAction.cpp \
          ./UmlBaseClassItem.cpp \
          ./UmlFormalParameter.cpp \
          ./UmlBaseCollaborationDiagram.cpp \
          ./UmlUseCase.cpp \
          ./UmlComponentView.cpp \
          ./UmlActivityControlNodeClasses.cpp \
          ./UmlFlow.cpp \
          ./PythonSettingsCmd.cpp \
          ./UmlBaseChoicePseudoState.cpp \
          ./UmlBaseDeploymentDiagram.cpp \
          ./UmlActivityNode.cpp \
          ./UmlDiagram.cpp \
          ./UmlTransition.cpp \
          ./UmlBaseUseCaseDiagramDefinition.cpp \
          ./UmlDeepHistoryPseudoState.cpp \
          ./UmlBaseCollaborationDiagramDefinition.cpp \
          ./UmlClassView.cpp \
          ./UmlActivityControlNode.cpp \
          ./UmlBaseInitialPseudoState.cpp \
          ./UmlBaseTypeSpec.cpp \
    Logging/QsLogDest.cpp \
    Logging/QsLog.cpp \
    Logging/QsDebugOutput.cpp \
    gridbox.cpp \
    hhbox.cpp \
    vvbox.cpp

QT += network widgets
DEFINES += TRUE=true FALSE=false DEBUG
DESTDIR = ../../bin
Release {
    MOC_DIR = $${DESTDIR}/moc_release/cpp_util
    OBJECTS_DIR = $${DESTDIR}/obj_release/cpp_util
}

Debug {
    MOC_DIR = $${DESTDIR}/moc_debug/cpp_util
    OBJECTS_DIR = $${DESTDIR}/obj_debug/cpp_util
}
UI_DIR = src/ui

QMAKE_CXXFLAGS += -std=gnu++11
mac:QMAKE_CXXFLAGS += -mmacosx-version-min=10.7 -stdlib=libc++
