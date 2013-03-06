
assign2ps.dll: dlldata.obj assign2_p.obj assign2_i.obj
	link /dll /out:assign2ps.dll /def:assign2ps.def /entry:DllMain dlldata.obj assign2_p.obj assign2_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del assign2ps.dll
	@del assign2ps.lib
	@del assign2ps.exp
	@del dlldata.obj
	@del assign2_p.obj
	@del assign2_i.obj
