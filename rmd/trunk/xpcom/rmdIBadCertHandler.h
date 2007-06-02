/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM rmdIBadCertHandler.idl
 */

#ifndef __gen_rmdIBadCertHandler_h__
#define __gen_rmdIBadCertHandler_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIX509Cert; /* forward declaration */

class nsIInterfaceRequestor; /* forward declaration */


/* starting interface:    rmdIBadCertHandler */
#define RMDIBADCERTHANDLER_IID_STR "5c6846c6-ccf9-11db-8314-0800200c9a66"

#define RMDIBADCERTHANDLER_IID \
  {0x5c6846c6, 0xccf9, 0x11db, \
    { 0x83, 0x14, 0x08, 0x00, 0x20, 0x0c, 0x9a, 0x66 }}

class NS_NO_VTABLE rmdIBadCertHandler : public nsISupports {
 public: 

  NS_DEFINE_STATIC_IID_ACCESSOR(RMDIBADCERTHANDLER_IID)

  /* boolean confirmMismatchDomain (in nsIInterfaceRequestor socketInfo, in AUTF8String targetURL, in nsIX509Cert cert); */
  NS_IMETHOD ConfirmMismatchDomain(nsIInterfaceRequestor *socketInfo, const nsACString & targetURL, nsIX509Cert *cert, PRBool *_retval) = 0;

  /* boolean confirmUnknownIssuer (in nsIInterfaceRequestor socketInfo, in nsIX509Cert cert, out short certAddType); */
  NS_IMETHOD ConfirmUnknownIssuer(nsIInterfaceRequestor *socketInfo, nsIX509Cert *cert, PRInt16 *certAddType, PRBool *_retval) = 0;

  /* boolean confirmCertExpired (in nsIInterfaceRequestor socketInfo, in nsIX509Cert cert); */
  NS_IMETHOD ConfirmCertExpired(nsIInterfaceRequestor *socketInfo, nsIX509Cert *cert, PRBool *_retval) = 0;

  /* void notifyCrlNextupdate (in nsIInterfaceRequestor socketInfo, in AUTF8String targetURL, in nsIX509Cert cert); */
  NS_IMETHOD NotifyCrlNextupdate(nsIInterfaceRequestor *socketInfo, const nsACString & targetURL, nsIX509Cert *cert) = 0;

};

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_RMDIBADCERTHANDLER \
  NS_IMETHOD ConfirmMismatchDomain(nsIInterfaceRequestor *socketInfo, const nsACString & targetURL, nsIX509Cert *cert, PRBool *_retval); \
  NS_IMETHOD ConfirmUnknownIssuer(nsIInterfaceRequestor *socketInfo, nsIX509Cert *cert, PRInt16 *certAddType, PRBool *_retval); \
  NS_IMETHOD ConfirmCertExpired(nsIInterfaceRequestor *socketInfo, nsIX509Cert *cert, PRBool *_retval); \
  NS_IMETHOD NotifyCrlNextupdate(nsIInterfaceRequestor *socketInfo, const nsACString & targetURL, nsIX509Cert *cert); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_RMDIBADCERTHANDLER(_to) \
  NS_IMETHOD ConfirmMismatchDomain(nsIInterfaceRequestor *socketInfo, const nsACString & targetURL, nsIX509Cert *cert, PRBool *_retval) { return _to ConfirmMismatchDomain(socketInfo, targetURL, cert, _retval); } \
  NS_IMETHOD ConfirmUnknownIssuer(nsIInterfaceRequestor *socketInfo, nsIX509Cert *cert, PRInt16 *certAddType, PRBool *_retval) { return _to ConfirmUnknownIssuer(socketInfo, cert, certAddType, _retval); } \
  NS_IMETHOD ConfirmCertExpired(nsIInterfaceRequestor *socketInfo, nsIX509Cert *cert, PRBool *_retval) { return _to ConfirmCertExpired(socketInfo, cert, _retval); } \
  NS_IMETHOD NotifyCrlNextupdate(nsIInterfaceRequestor *socketInfo, const nsACString & targetURL, nsIX509Cert *cert) { return _to NotifyCrlNextupdate(socketInfo, targetURL, cert); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_RMDIBADCERTHANDLER(_to) \
  NS_IMETHOD ConfirmMismatchDomain(nsIInterfaceRequestor *socketInfo, const nsACString & targetURL, nsIX509Cert *cert, PRBool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->ConfirmMismatchDomain(socketInfo, targetURL, cert, _retval); } \
  NS_IMETHOD ConfirmUnknownIssuer(nsIInterfaceRequestor *socketInfo, nsIX509Cert *cert, PRInt16 *certAddType, PRBool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->ConfirmUnknownIssuer(socketInfo, cert, certAddType, _retval); } \
  NS_IMETHOD ConfirmCertExpired(nsIInterfaceRequestor *socketInfo, nsIX509Cert *cert, PRBool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->ConfirmCertExpired(socketInfo, cert, _retval); } \
  NS_IMETHOD NotifyCrlNextupdate(nsIInterfaceRequestor *socketInfo, const nsACString & targetURL, nsIX509Cert *cert) { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyCrlNextupdate(socketInfo, targetURL, cert); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public rmdIBadCertHandler
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_RMDIBADCERTHANDLER

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, rmdIBadCertHandler)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* boolean confirmMismatchDomain (in nsIInterfaceRequestor socketInfo, in AUTF8String targetURL, in nsIX509Cert cert); */
NS_IMETHODIMP _MYCLASS_::ConfirmMismatchDomain(nsIInterfaceRequestor *socketInfo, const nsACString & targetURL, nsIX509Cert *cert, PRBool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean confirmUnknownIssuer (in nsIInterfaceRequestor socketInfo, in nsIX509Cert cert, out short certAddType); */
NS_IMETHODIMP _MYCLASS_::ConfirmUnknownIssuer(nsIInterfaceRequestor *socketInfo, nsIX509Cert *cert, PRInt16 *certAddType, PRBool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean confirmCertExpired (in nsIInterfaceRequestor socketInfo, in nsIX509Cert cert); */
NS_IMETHODIMP _MYCLASS_::ConfirmCertExpired(nsIInterfaceRequestor *socketInfo, nsIX509Cert *cert, PRBool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void notifyCrlNextupdate (in nsIInterfaceRequestor socketInfo, in AUTF8String targetURL, in nsIX509Cert cert); */
NS_IMETHODIMP _MYCLASS_::NotifyCrlNextupdate(nsIInterfaceRequestor *socketInfo, const nsACString & targetURL, nsIX509Cert *cert)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_rmdIBadCertHandler_h__ */
