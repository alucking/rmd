#ifndef _RMD_H_
#define _RMD_H_

#include "nsIBadCertListener.h"


#define RMD_CONTRACTID "@mozilla.org/nsBadCertListener;1"
#define RMD_CLASSNAME "RMD implementation of nsIBadCertListener"
		// {5c8fa470-ae3c-11db-abbd-0800200c9a66}
#define RMD_CID  { 0x5c8fa470, 0xae3c, 0x11db, {0xab, 0xbd, 0x08, 0x00, 0x20, 0x0c, 0x9a, 0x66} }


/* Header file */
class rmdBadCertListener : public nsIBadCertListener
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIBADCERTLISTENER

  rmdBadCertListener();


private:
  ~rmdBadCertListener();

protected:
  /* additional members */
};


#endif //_RMD_H_
