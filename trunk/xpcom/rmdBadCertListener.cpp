/* ***** BEGIN LICENSE BLOCK *****
 * Version: MPL 1.1
 *
 * The contents of this file are subject to the Mozilla Public License Version
 * 1.1 (the "License"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 * for the specific language governing rights and limitations under the
 * License.
 *
 * The Original Code is Remember Mismatched Domains
 *
 * The Initial Developer of the Original Code is
 * Andrew Lucking.
 * http://www.andrewlucking.com/
 * Portions created by the Initial Developer are Copyright (C) 2007
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
 *
 * ***** END LICENSE BLOCK ***** */


#include "rmdBadCertListener.h"

#include "nsXPCOM.h"
#include "nsServiceManagerUtils.h"
#include "rmdIBadCertHandler.h"


NS_IMPL_ISUPPORTS1(rmdBadCertListener, nsIBadCertListener)

rmdBadCertListener::rmdBadCertListener() { /*constructor*/ }

rmdBadCertListener::~rmdBadCertListener() { /*destructor*/ }

/* boolean confirmMismatchDomain (in nsIInterfaceRequestor socketInfo, in AUTF8String targetURL, in nsIX509Cert cert); */
NS_IMETHODIMP rmdBadCertListener::ConfirmMismatchDomain(nsIInterfaceRequestor *socketInfo, 
							const nsACString & targetURL, 
							nsIX509Cert *cert, 
							PRBool *_retval) {
	*_retval = PR_FALSE;

	// anyone want to confirm a mismatched domain? ... anyone?
	nsCOMPtr<rmdIBadCertHandler> rmd = do_GetService("@andrewlucking.com/rmdBadCertHandler;1");
	rmd->ConfirmMismatchDomain(socketInfo, targetURL, cert, _retval);

	return NS_OK;
 }


/* boolean confirmCertExpired (in nsIInterfaceRequestor socketInfo, in nsIX509Cert cert); */
NS_IMETHODIMP rmdBadCertListener::ConfirmCertExpired(nsIInterfaceRequestor *socketInfo, 
							nsIX509Cert *cert, 
							PRBool *_retval) {

	*_retval = PR_FALSE;

	// anyone want to confirm an expired cert? ... anyone? ... you?
	nsCOMPtr<rmdIBadCertHandler> rmd = do_GetService("@andrewlucking.com/rmdBadCertHandler;1");
	rmd->ConfirmCertExpired(socketInfo, cert, _retval);

	return NS_OK;
}

/* boolean confirmUnknownIssuer (in nsIInterfaceRequestor socketInfo, in nsIX509Cert cert, out short certAddType); */
NS_IMETHODIMP rmdBadCertListener::ConfirmUnknownIssuer(nsIInterfaceRequestor *socketInfo, 
							nsIX509Cert *cert, 
							PRInt16 *certAddType, 
							PRBool *_retval) {

	*_retval = PR_FALSE;

	// ConfirmUnknownIssuer
	nsCOMPtr<rmdIBadCertHandler> rmd = do_GetService("@andrewlucking.com/rmdBadCertHandler;1");
	rmd->ConfirmUnknownIssuer(socketInfo, cert, certAddType, _retval);

	return NS_OK;
}

/* void notifyCrlNextupdate (in nsIInterfaceRequestor socketInfo, in AUTF8String targetURL, in nsIX509Cert cert); */
NS_IMETHODIMP rmdBadCertListener::NotifyCrlNextupdate(nsIInterfaceRequestor *socketInfo, 
							const nsACString & targetURL, 
							nsIX509Cert *cert) {

	// NotifyCrlNextupdate
	nsCOMPtr<rmdIBadCertHandler> rmd = do_GetService("@andrewlucking.com/rmdBadCertHandler;1");
	rmd->NotifyCrlNextupdate(socketInfo, targetURL, cert);

	return NS_OK;
}

