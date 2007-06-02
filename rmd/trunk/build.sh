XPI_FILENAME="remember-mismatch_1.4.5.xpi"

COMPONENT_DIRS="platform/WINNT_x86-msvc/components/"
COMPONENT_DIRS=${COMPONENT_DIRS}" platform/Linux_x86-gcc3/components/"
COMPONENT_DIRS=${COMPONENT_DIRS}" platform/Linux_x86_64-gcc3/components/"
COMPONENT_DIRS=${COMPONENT_DIRS}" platform/linux-gnu_x86-gcc3/components/"
COMPONENT_DIRS=${COMPONENT_DIRS}" platform/linux-gnu_x86_64-gcc3/components/"
COMPONENT_DIRS=${COMPONENT_DIRS}" platform/Darwin_x86-gcc3/components/"
COMPONENT_DIRS=${COMPONENT_DIRS}" platform/Darwin_ppc-gcc3/components/"



#create jar
cd chrome
zip -r $PWD/remember-mismatch.jar content skin locale


#create xpi
cd ../
rm ${XPI_FILENAME}
zip -r ${XPI_FILENAME} ${COMPONENT_DIRS} install.rdf install.js chrome.manifest chrome/remember-mismatch.jar components/ defaults/preferences 

# clean up 
rm chrome/remember-mismatch.jar

# xpi
mv ${XPI_FILENAME} xpi
