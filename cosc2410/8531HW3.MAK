ORIGIN = PWB
ORIGIN_VER = 2.1.49
PROJ = 8531hw3
PROJFILE = 8531hw3.mak
DEBUG = 1

ASM  = ml
H2INC  = h2inc
AFLAGS_G  = /Cx /W2 /WX
AFLAGS_D  = /Zi
AFLAGS_R  = /nologo
MAPFILE_D  = NUL
MAPFILE_R  = NUL
LFLAGS_G  = /NOI /BATCH /ONERROR:NOEXE
LFLAGS_D  = /CO /FAR /PACKC
LFLAGS_R  = /EXE /FAR /PACKC
LINKER	= link
ILINK  = ilink
LRF  = echo > NUL
ILFLAGS  = /a /e
BSCMAKE  = bscmake
SBRPACK  = sbrpack
NMAKEBSC1  = set
NMAKEBSC2  = nmake
CVFLAGS  = /25

FILES  = 8531HW3.ASM
OBJS  = 8531HW3.obj
SBRS  = 8531HW3.sbr

all: $(PROJ).exe

.SUFFIXES:
.SUFFIXES:
.SUFFIXES: .obj .sbr .asm

8531HW3.obj : 8531HW3.ASM
!IF $(DEBUG)
	$(ASM) /c $(AFLAGS_G) $(AFLAGS_D) /Fo8531HW3.obj 8531HW3.ASM
!ELSE
	$(ASM) /c $(AFLAGS_G) $(AFLAGS_R) /Fo8531HW3.obj 8531HW3.ASM
!ENDIF

8531HW3.sbr : 8531HW3.ASM
!IF $(DEBUG)
	$(ASM) /Zs $(AFLAGS_G) $(AFLAGS_D) /FR8531HW3.sbr 8531HW3.ASM
!ELSE
	$(ASM) /Zs $(AFLAGS_G) $(AFLAGS_R) /FR8531HW3.sbr 8531HW3.ASM
!ENDIF


$(PROJ).exe : $(OBJS)
!IF $(DEBUG)
	$(LRF) @<<$(PROJ).lrf
$(RT_OBJS: = +^
) $(OBJS: = +^
)
$@
$(MAPFILE_D)
$(LIBS: = +^
) +
$(LLIBS_G: = +^
) +
$(LLIBS_D: = +^
)
$(DEF_FILE) $(LFLAGS_G) $(LFLAGS_D);
<<
!ELSE
	$(LRF) @<<$(PROJ).lrf
$(RT_OBJS: = +^
) $(OBJS: = +^
)
$@
$(MAPFILE_R)
$(LIBS: = +^
) +
$(LLIBS_G: = +^
) +
$(LLIBS_R: = +^
)
$(DEF_FILE) $(LFLAGS_G) $(LFLAGS_R);
<<
!ENDIF
	$(LINKER) @$(PROJ).lrf

$(PROJ).bsc : $(SBRS)
	$(BSCMAKE) @<<
$(BRFLAGS) $(SBRS)
<<


.asm.obj :
!IF $(DEBUG)
	$(ASM) /c $(AFLAGS_G) $(AFLAGS_D) /Fo$@ $<
!ELSE
	$(ASM) /c $(AFLAGS_G) $(AFLAGS_R) /Fo$@ $<
!ENDIF

.asm.sbr :
!IF $(DEBUG)
	$(ASM) /Zs $(AFLAGS_G) $(AFLAGS_D) /FR$@ $<
!ELSE
	$(ASM) /Zs $(AFLAGS_G) $(AFLAGS_R) /FR$@ $<
!ENDIF


run: $(PROJ).exe
	$(PROJ).exe $(RUNFLAGS)

debug: $(PROJ).exe
	CV $(CVFLAGS) $(PROJ).exe $(RUNFLAGS)
