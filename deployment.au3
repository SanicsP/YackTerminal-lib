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

Move()

Func Move() 
	If FileExists($destDir) = 0 Then
		DirCreate($destDir)
	EndIf

	IF DirCopy($includeDir , $destIncludeDir , 1) = 0 Then 
		MsgBox(0 , "error" , "error in header directory copy")
	EndIf

	IF DirCopy($srcDir , $destSrcDir , 1) = 0 Then 
		MsgBox(0 , "error" , "error in sources files directory copy")
	EndIf

	DirCreate($destLibDir)


	If FileCopy($YtLib & "/" & $CmakeFile , $destDir & "/" & $CmakeFile , 1 ) = 0 Then 
		MsgBox(0 , "error" , "error in Cmake file copy")
	EndIf

	If FileCopy($libDir & "/" & $libFile , $destLibDir & "/" & $libFile , 1) = 0 Then 
		MsgBox(0 , "error" , "error in lib directory copy")
	EndIf
	
	DirCreate($destDir & "/" & $destBuildDir)

EndFunc

Func Build()
	
EndFunc