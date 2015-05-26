#!/bin/bash
#---------------------------------------------------------------------------------------------------
# Setup the MitMonoPhoton package adjusting things that are needed for it to compile and run properly.
#
#                                                                   Apr 26, 2015 - V1 Yutaro Iiyama
#---------------------------------------------------------------------------------------------------

echo "*************************"
echo " MitMonoPhoton/bin/setup.sh"
echo "*************************"

# Generate ROOT dictionaries for classes defined in this module
$CMSSW_BASE/src/MitCommon/bin/genDict.sh MitMonoPhoton/Mods

exit 0
