const prefs = Components.classes["@mozilla.org/preferences-service;1"].
                    getService(Components.interfaces.nsIPrefBranch);

var domain_pairs;
var expired_certs;

function onload(){

    domain_pairs = [];
    expired_certs = [];

    expired_certs = prefToArray("remember_mismatched_domains.expired_pairs");
    var expired_tree = document.getElementById('rec-tree');
    updatePairsTree(expired_tree, expired_certs, 0);

    domain_pairs = prefToArray("remember_mismatched_domains.domain_pairs");
    var domains_tree = document.getElementById('rdm-tree');
    updatePairsTree(domains_tree, domain_pairs, 0);

}


function deletePair(button_id){
    var tree = null;
    var which_pair = "";
    if (button_id == "delete-rdm-button") {
        tree = document.getElementById('rdm-tree');
        which_pair = "domain_pairs";
    } else if (button_id == "delete-rec-button") {
        tree = document.getElementById('rec-tree');
        which_pair = "expired_certs";
    }
    var index = tree.currentIndex;
    if (index >= 0){
        this[which_pair].splice(index, 1);
        if (index > this[which_pair].length - 1) { index-- };
        updatePairsTree(tree, this[which_pair], index);
    }
}

function ok(){
    updatePrefsString("remember_mismatched_domains.domain_pairs", domain_pairs);
    updatePrefsString("remember_mismatched_domains.expired_pairs", expired_certs);
    window.close();
}

function cancel(){
    window.close();
}



function prefToArray(pref_name){
    var pairs_array = [];
    var result = [];
    if (prefs.getPrefType(pref_name) == prefs.PREF_STRING){
         pairs_array = prefs.getCharPref(pref_name).split(" ");
        pairs_array.pop();
    }
    var len = pairs_array.length;
    for (var i = 0; i < len; i++){
        var page_url = pairs_array[i].split(":")[0];
        page_url = unescape(page_url);
        var cert_url = pairs_array[i].split(":")[1];
        cert_url = unescape(cert_url);
        var cert_fingerprint_sha1 = pairs_array[i].split(":")[2] || "";
        cert_fingerprint_sha1 = unescape(cert_fingerprint_sha1);
        var cert_fingerprint_md5 = pairs_array[i].split(":")[3] || "";
        cert_fingerprint_md5 = unescape(cert_fingerprint_md5);
        result.push([page_url, cert_url, cert_fingerprint_sha1, cert_fingerprint_md5]);
    }
    return result;
}

function updatePrefsString(pref_name, pref_data){
    var pairs_str = "";
    var i = 0;
    while (i < pref_data.length){
        pairs_str += escape( pref_data[i][0] ) + ":";
        pairs_str += escape( pref_data[i][1] ) + ":";
        pairs_str += escape( pref_data[i][2] ) + ":";
        pairs_str += escape( pref_data[i][3] ) + " ";
        i++;
    }
    prefs.setCharPref(pref_name, pairs_str);
}

function updatePairsTree(tree, columns_array, sel){
    var column_ids = [];
    if (tree.id == "rdm-tree"){
        column_ids.push("url-domain");
        column_ids.push("cert-domain");
        column_ids.push("cert-sha1");
        column_ids.push("cert-md5");
    } else if (tree.id == "rec-tree"){
        column_ids.push("expired-date");
        column_ids.push("cert-domain");
        column_ids.push("cert-sha1");
        column_ids.push("cert-md5");
    }

    var tree_view = new Object();
    tree_view.rowCount = columns_array.length;
    tree_view.getCellText = function(row, column){
         // 1.8+ code:
         switch( typeof(column)=="object" ? column.id : column ) {
            case column_ids[0]:
                if (column_ids[0] == "expired-date"){
                    var not_after = Number( columns_array[row][0].substring(0,13) );
                    return new Date(not_after).toLocaleString();
                } else {
                    return columns_array[row][0];
                }
                break;
            case column_ids[1]:
                return columns_array[row][1];
                break;
            case column_ids[2]:
                return columns_array[row][2];
                break;
            case column_ids[3]:
                return columns_array[row][3];
                break;
        }
    }
    tree_view.setTree = function(treebox){ this.treebox = treebox; };
    tree_view.isContainer = function(row){ return false; };
    tree_view.isSeparator = function(row){ return false; };
    tree_view.isSorted = function(row){ return false; };
    tree_view.getLevel = function(row){ return 0; };
    tree_view.getImageSrc = function(row,col){ return null; };
    tree_view.getRowProperties = function(row,props){};
    tree_view.getCellProperties =  function(row,col,props){};
    tree_view.getColumnProperties = function(colid,col,props){};
    tree_view.selection = null;

    tree.view = tree_view;

    tree.view.selection.select(sel);
    tree.focus();
}



