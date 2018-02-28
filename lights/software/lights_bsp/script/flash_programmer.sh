#!/bin/sh
#
# This file was automatically generated.
#
# It can be overwritten by nios2-flash-programmer-generate or nios2-flash-programmer-gui.
#

#
# Converting Binary File: /acct/wgunn/Downloads/myfile.zip to: "../flash/myfile_cfi_flash_0.flash"
#
/usr/local/3rdparty/altera/quartus12/nios2eds/bin/bin2flash --input="/acct/wgunn/Downloads/myfile.zip" --output="../flash/myfile_cfi_flash_0.flash" --location=0x0 --verbose 

#
# Programming File: "../flash/myfile_cfi_flash_0.flash" To Device: cfi_flash_0
#
/usr/local/3rdparty/altera/quartus12/nios2eds/bin/nios2-flash-programmer "../flash/myfile_cfi_flash_0.flash" --base=0x10800000 --sidp=0x112050C8 --id=0x0 --timestamp=1519399330 --device=1 --instance=0 '--cable=USB-Blaster on localhost [1-2]' --program --verbose 

