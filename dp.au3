#cs 
	Script de déploimment de la bibliothèque pour une configuration MakeFiles
#ce
Global $YtLib = "YT_Library"
Global $includeDir = "YT_Library/header"
Global $srcDir = "YT_Library/src"
Global $builDir = "build"
Global $libDir = "build/YT_Library"
Global $libFile = "libArg.a"
Global $destDir = "YT lib"
Global $destLibDir = $destDir & "/" & "lib"
Global $destIncludeDir = $destDir & "/" & "header"
Global $destSrcDir = $destDir & "/" & "src"

Global $CmakeFile = "Cmakelists.txt"
Global $destBuildDir = "build"

Global $CmakeCommand = 'Cmake .. -G" '
Global $CompilerDef = $CmdLine[1]

Move()
Build()

Func Move() 
	If FileExists($destDir) Then
		DirRemove($destDir , 1)
	EndIf
	DirCopy($YtLib , $destDir , 1)
EndFunc

Func Build()
	Local $cmdPID = Run("cmd")
	Sleep(3e3)
	Send("cd " & $destDir & "/" & $destBuildDir & "{ENTER}")
	Sleep(500) 
	Send($CmakeCommand & $CompilerDef & '"' & "{ENTER}")
	Sleep(5e3)
	MsgBox(0 , "msg" , "config finish")
	ProcessClose($cmdPID)
EndFunc