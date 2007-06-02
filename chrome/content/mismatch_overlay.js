const __doOK = doOK;
const prefs = Components.classes["@mozilla.org/preferences-service;1"].
                    getService(Components.interfaces.nsIPrefBranch);

doOK = function(){
    dump("RMD :: to remember: " + document.getElementById('rmd-checkbox').checked + "\n");

    var document_id = document.getElementsByTagName("dialog")[0].id.toUpperCase(); // "DOMAINMISMATCH" or "SERVERCERTEXPIRED"

    if (document.getElementById('rmd-checkbox').checked){ // don't warn checkbox is selected so remember the pair


        // which prefs are we after
        if (document_id == "DOMAINMISMATCH"){
            pref_name = "remember_mismatched_domains.domain_pairs"; // use domain pairs prefs
        } else if (document_id == "SERVERCERTEXPIRED"){
            pref_name = "remember_mismatched_domains.expired_pairs";  // use expired pairs prefs
        }

        // gather prefs
        var domain_pairs = "";
        if (prefs.getPrefType(pref_name) == prefs.PREF_STRING){
            domain_pairs = prefs.getCharPref(pref_name);
        }

        // queryInteface
        var isupport = pkiParams.getISupportAtIndex(1);
        _cert = isupport.QueryInterface(nsIX509Cert);


        if (document_id == "DOMAINMISMATCH"){
            domain_pairs += escape( dialogParams.GetString(1) ) + ":" + escape( _cert.commonName );
        } else if (document_id == "SERVERCERTEXPIRED"){
            domain_pairs += escape( _cert.validity.notAfter ) + ":" + escape( _cert.commonName );
        }
        domain_pairs += ":" + escape( _cert.sha1Fingerprint ) + ":" + escape( _cert.md5Fingerprint ) + " "; // fingerprints too
        prefs.setCharPref(pref_name, domain_pairs); // store prefs
    }
    __doOK(); // call chrome://pippki/content/domainMismatch.js doOK()
              // *or* chrome://pippki/content/serverCertExpired.js doOK()
}

