#include "nsIGenericFactory.h"
#include "rmdBadCertListener.h"

NS_GENERIC_FACTORY_CONSTRUCTOR(rmdBadCertListener)

static nsModuleComponentInfo components[] =
{
    {
       RMD_CLASSNAME, 
       RMD_CID,
       RMD_CONTRACTID,
       rmdBadCertListenerConstructor,
    }
};

NS_IMPL_NSGETMODULE("rmdBadCertListenerModule", components) 

