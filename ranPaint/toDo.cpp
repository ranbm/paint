
#include "pch.h"
#include "toDo.h"

toDo::toDo(CTypedPtrArray<CObArray, Figure2D*>& Figures, Figure2D* Fig)
	:Figures(Figures), Fig(Fig) {}
toDo::~toDo(void) {}