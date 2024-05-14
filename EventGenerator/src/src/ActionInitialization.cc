#include "ActionInitialization.hh"


ActionInitialization::ActionInitialization(DetectorConstruction* detector, HistoManager *hist)
	:	G4VUserActionInitialization(), fDetector(detector), fHistograms(hist)	
{
}

ActionInitialization::~ActionInitialization()
{
}

void ActionInitialization::BuildForMaster() const
{

	fHistograms->Book();	
	RunAction* runAction = new RunAction(fHistograms);
	SetUserAction(runAction);

}

void ActionInitialization::Build() const
{

	PrimaryGeneratorAction *pGen = new PrimaryGeneratorAction();
	SetUserAction(pGen);
	
	RunAction* runAction = new RunAction(fHistograms);
	SetUserAction(runAction);

	EventAction* eventAction = new EventAction(runAction,fHistograms);
	SetUserAction(eventAction);

	SetUserAction(new SteppingAction(eventAction));

}
