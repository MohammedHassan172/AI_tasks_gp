#include "graduation_project_prototype_collect_capi_host.h"
static graduation_project_prototype_collect_host_DataMapInfo_T root;
static int initialized = 0;
__declspec( dllexport ) rtwCAPI_ModelMappingInfo *getRootMappingInfo()
{
    if (initialized == 0) {
        initialized = 1;
        graduation_project_prototype_collect_host_InitializeDataMapInfo(&(root), "graduation_project_prototype_collect");
    }
    return &root.mmi;
}

rtwCAPI_ModelMappingInfo *mexFunction(){return(getRootMappingInfo());}
