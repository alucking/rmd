* A copy of the Gecko SDK for your platform is required to build the XPCOM component:
http://developer.mozilla.org/en/docs/Gecko_SDK#Get_the_SDK

1. Using the SDK create the rmdIBadCertHandler.xpt
../../gecko-sdk/bin/xpidl -m header -I ../../gecko-sdk/idl rmdIBadCertHandler.idl
../../gecko-sdk/bin/xpidl -m typelib -I ../../gecko-sdk/idl rmdIBadCertHandler.idl

2. Extract the Makefile for your platform (can be found in /Makes) and make the binary.


