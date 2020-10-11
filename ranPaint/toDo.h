#pragma once
class toDo
{
public:
	toDo(CTypedPtrArray<CObArray, Figure2D*>& Figures, Figure2D* Fig);
	~toDo(void);
	CTypedPtrArray<CObArray, Figure2D*>& Figures;
	Figure2D* Fig;
};