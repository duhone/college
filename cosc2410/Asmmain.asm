;; AsmMain.asm
;
comment $    ******************************************************
             Author: w colquitt
               Date: Oct 99
            Purpose: This is a test main driver for the Bin2ASCII
                     routine (1st version)
                     does nothing but call the routine and then exit
                     Printing is done by the called routine
        $    ******************************************************
               .nolist
                include bios.inc
               .list

Bin2ASCII    PROTO   near c

               .model    small, c
               .586
               .stack    0250h
               .data
               .code
               .startup
                nop

                @cls
                @setcsrpos 5, 10
                INVOKE   Bin2ASCII

                nop
               .exit
                end
