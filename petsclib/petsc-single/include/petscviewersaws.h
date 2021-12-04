
#if !defined(PETSCVIEWERSAWS_H)
#define PETSCVIEWERSAWS_H

#include <petscviewer.h>
#include <SAWs.h>
PETSC_EXTERN PetscErrorCode PetscViewerSAWsOpen(MPI_Comm,PetscViewer*);
PETSC_EXTERN PetscViewer    PETSC_VIEWER_SAWS_(MPI_Comm);
#define PETSC_VIEWER_SAWS_WORLD PETSC_VIEWER_SAWS_(PETSC_COMM_WORLD)
#define PETSC_VIEWER_SAWS_SELF  PETSC_VIEWER_SAWS_(PETSC_COMM_SELF)

#define PetscStackCallSAWs(func,args) do {PetscErrorCode _ierr; \
    PetscStackPush(#func);_ierr = func args;PetscStackPop; if (_ierr) SETERRQ2(PETSC_COMM_SELF,PETSC_ERR_LIB,"Error in %s() %d",#func,_ierr); \
} while (0)

#endif
