
comp2ps.dll: dlldata.obj comp2_p.obj comp2_i.obj
	link /dll /out:comp2ps.dll /def:comp2ps.def /entry:DllMain dlldata.obj comp2_p.obj comp2_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del comp2ps.dll
	@del comp2ps.lib
	@del comp2ps.exp
	@del dlldata.obj
	@del comp2_p.obj
	@del comp2_i.obj
